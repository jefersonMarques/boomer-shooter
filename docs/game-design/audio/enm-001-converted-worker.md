# AUD-ENM-001 — Trabalhador Convertido: identidade sonora

**Entidade:** [ENM-001 Trabalhador Convertido](../enemies/converted-worker.md).
**Primeiro nível:** [L01 Câmara de Descarte](../levels/l01-discard-chamber.md) — S2, posto de segurança; depois S5, Linha de Separação.
**Função:** criatura perseguidora corpo a corpo que combina carne reutilizada, ossos e mecanismo industrial.
**Estado:** quatro sons originais sintetizados e entregues separadamente (WAV + OGG); não ligados à engine e não incorporados como arquivos binários ao Git nesta revisão.
**Pasta de destino proposta:** `assets/audio/enemies/converted-worker/`.

## Identidade acústica

A criatura não deve soar como um zumbi genérico ou um demônio sobrenatural: trata-se de um trabalhador refeito para continuar sua tarefa. A voz preserva restos de emissão humana, interrompidos por garganta comprimida e articulações duras. O pulso orgânico é irregular; o metal tem ressonância curta de oficina. A ameaça vem de três elementos: **respiração molhada**, **arrasto metálico** e, sobretudo, **estalo seco do ombro pesado** antes do ataque.

- **Orgânico:** voz grave de formantes sintetizados, fluxo de ar sujo, gorgolejo e saturação controlada.
- **Mecânico:** ressonadores inarmônicos e raspagem metálica, sem futurismo excessivo.
- **Ambiente:** reflexões curtas de sala industrial; não imprimir uma cauda longa que prejudique localização.
- **Silêncio:** intervalos entre respirações tornam a criatura identificável por seus movimentos, não por um rugido constante.
- **Personalidade:** o grito é quase humano, mas termina como se o equipamento estivesse esmagando o som.

## Arquivos de produção

| Evento | Arquivo (substituir extensão por WAV para master) | Duração | Loop | Significado |
| --- | --- | ---: | --- | --- |
| `enemy.idle` | `enemy-converted-worker-idle.ogg` | 6,40 s | Sim | Respiração presa, pequenos gorgolejos e metal em manutenção |
| `enemy.attack` | `enemy-converted-worker-attack.ogg` | 1,23 s | Não | Ombro trava, ameaça vocal, braço golpeia e faz contato |
| `enemy.scream` | `enemy-converted-worker-scream.ogg` | 2,09 s | Não | Detecção/agressividade; grito com camada de fricção mecânica |
| `enemy.death` | `enemy-converted-worker-death.ogg` | 2,70 s | Não | Falha vocal, queda do lado pesado, ferramenta presa no chão |

**Material auxiliar:** `enemy-converted-worker-preview.ogg` é uma audição sequencial e **não** um evento da engine. `audio-manifest.json` contém durações, hashes SHA-256 e características de exportação. `generate_converted_worker.py`, entregue junto dos arquivos, reproduz os sons por síntese procedural determinística; requer Python, NumPy, SciPy, SoundFile e FFmpeg.

## Sincronização e estados

### Idle

- **Gatilho:** `Idle` e, opcionalmente, presença próxima em estados de baixa movimentação.
- **Execução:** loop de 6,40 s com fronteira silenciosa contínua; manter uma instância por criatura, sem reiniciar em cada frame.
- **Direção:** som discreto e intermitente. A distância, deve revelar presença sem abafar portas, passos e máquinas.
- **Interrupção:** reduzir o volume durante grito ou ataque; encerrar ao morrer.

### Attack — leitura obrigatória

- **Início do áudio:** ao entrar em `AttackWindup`, nunca somente no frame em que o dano é aplicado.
- **~0,07 s:** estalo metálico do ombro, aviso confiável do ataque.
- **~0,20 s:** grunhido e raspagem quando o braço começa a avançar.
- **~0,46 s:** início da varredura do golpe (ar deslocado).
- **~0,72 s:** impacto sonoro principal e contato metálico.
- **Depois:** recuperação curta, já dentro da cauda total de 1,23 s.

**Contrato de gameplay:** o áudio **não determina** quando o dano acontece: a máquina de estados/animação é a fonte de verdade. O ponto sonoro de ~0,72 s é referência para sincronizar animação e hitbox, não uma exigência de atraso fixo. Se o ataque ficar mais rápido no playtest, retimar ou dividir o arquivo em aviso e impacto sem perder o aviso antecipado.

### Scream

- **Gatilho proposto:** transição `Detect` / primeiro alerta ou reação especial, não a cada passo da perseguição.
- **Camadas:** breve inspiração, grito humano distorcido descendente, raspagem metálica e ar exaurido.
- **Controle:** cooldown para impedir acumulação de gritos em grupos; não usar no mesmo instante em que o telegraph de ataque precisa ser identificado.

### Death

- **Gatilho:** entrada definitiva no estado `Death`; impedir duplicação do evento.
- **Sequência:** voz quebrando, golpe no piso ~0,8 s, ressonância de ferramenta e arrasto até o silêncio.
- **Transição:** parar/atenuar idle, ataque e grito ao morrer; preservar a posição 3D do cadáver até a cauda terminar.
- **Narrativa:** o corpo cai na direção do braço pesado; som de peça metálica presa ao chão.

## Relação com outros sons

- `AUD-L01-006`: movimento — passos molhados e gancho arrastando. **Ainda é um asset separado, não incluído nos quatro arquivos.**
- `AUD-L01-007`: aviso de golpe — atualmente **incorporado ao início** de `enemy.attack`; poderá virar som independente caso seja necessário retimar animações.
- O murmúrio residual **“Fim do turno?”** permanece uma possibilidade narrativa da ficha ENM-001. **Não foi gravado ou sintetizado neste lote**; se criado, deve existir como evento raro separado e legendável.
- O áudio de V-12 e a ambiência da fase precisam continuar mais claros que a base de respiração da criatura.

## Contrato de integração técnica

- **Formato:** WAV PCM assinado de 16 bits, 48 kHz; alternativa OGG Vorbis, mono 48 kHz.
- **Espacialidade:** arquivos mono, prontos para distância/panning no mixer do jogo; nenhuma panorâmica estéreo pré-gravada.
- **Política:** carregar antecipadamente os quatro efeitos do primeiro encontro; utilizar cache de áudio decodificado conforme a biblioteca escolhida e medir memória/latência antes de padronizar.
- **Mix:** categoria `SFX_Enemy`; limitar sobreposição simultânea; priorizar `AttackWindup` e `Death` em relação ao loop `Idle`.
- **Acessibilidade:** manter gesto visual claro do ombro e da arma; jogadores sem áudio devem perceber ameaça e golpe.
- **Teste:** confirmar loop sem clique, ausência de clip, emissão correta por estado, localização à distância, ausência de acúmulo de vozes no encontro S5 e compatibilidade no navegador.
- **Volume:** os arquivos não definem loudness final do jogo. Ajustar ganhos em playtests; evitar deixar o grito mascarar a espingarda ou a detecção de Sentinela.

## Origem e limites

Os efeitos foram construídos proceduralmente com osciladores, ruídos filtrados, ressonâncias, envelopes e saturação, sem copiar áudio de Doom, Quake, Hexen ou outras obras. Os parâmetros e durações são **versão inicial para testes**, não estatísticas imutáveis da criatura. Os arquivos entregues acompanham a conversa; será necessário importar os binários para `assets/audio/enemies/converted-worker/` quando a integração for implementada.

**Referências:** [Bestiário](../enemies/README.md) · [L01 encontros](../levels/l01-encounters.md) · [L01 áudio e arte](../levels/l01-art-audio.md).
