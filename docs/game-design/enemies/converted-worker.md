# ENM-001 — Trabalhador Convertido

**Codinome de produção:** Converted Worker.
**Aparece em:** O Matadouro, estações abandonadas e instalações secundárias.
**Papel em combate:** perseguidor de curta distância; ensina o jogador a manter movimento.
**Origem:** antigos auxiliares, carregadores e operários reconstruídos para tarefas de transporte e limpeza.

## Forma e silhueta

Humanoide de altura próxima à do protagonista, coluna dobrada para a frente, ombro direito hipertrofiado, antebraço esquerdo substituído por ferramenta de agarrar. O pescoço tem uma placa de inventário soldada à nuca. Fragmentos de uniforme verde ainda exibem um nome ilegível.

O rosto mantém nariz e boca humanos, mas os olhos foram cobertos por um visor semitransparente. A mandíbula abre como se tentasse falar por trás de uma máscara. Costuras metálicas e grampos evidenciam reconstruções repetidas.

**Paleta:** carne pálida, verde oxidado, metal sujo e luz âmbar intermitente no pescoço.

## Movimento e comportamento

- **Idle:** faz gesto mecânico de apanhar algo inexistente no chão.
- **Detecção:** ergue o tronco, estala as articulações e vira o visor para a Testemunha.
- **Perseguição:** passos irregulares e rápidos, com breve pausa antes de mudar de direção.
- **Ataque:** braço pesado é erguido lateralmente; após um instante reconhecível, executa golpe em arco curto.
- **Dano:** recua e expõe momentaneamente as conexões do ombro.
- **Morte:** cai para o lado pesado, deixando a ferramenta presa ao chão.

**Recurso tático:** é vulnerável à distância, mas perigoso quando aparece em grupo. Não deve teleportar nem avançar sem antecipação.

## Áudio e memória

Som de botas molhadas, respiração comprimida e metal raspando. Uma rara fala residual: “Fim do turno?” — trecho desconectado da consciência anterior. Não confundir essa fala com ameaça principal; o estalo de ombro é o aviso confiável.

**Ficha sonora de produção:** [AUD-ENM-001 — estados, arquivos, sincronização e integração](../audio/enm-001-converted-worker.md). Foram sintetizados quatro eventos originais (idle, attack, scream e death) para testes; a importação dos binários na engine permanece pendente.

## Frames para orçamento de arte

Direções: frente, 3/4, lado e costas conforme resultado técnico; espelhamento apenas quando a assimetria permitir. Estados mínimos: idle, walk, attack, pain, death. Preparar referências front/side/back antes de animar.

## Distribuição

Primeiro inimigo do jogo em corredor sem flancos. Mais tarde aparece em duplas ou com Sentinela, forçando o jogador a circular na sala.

**Relações:** [Matadouro](../locations/slaughterhouse.md) · [Sentinela Industrial](industrial-sentinel.md).
