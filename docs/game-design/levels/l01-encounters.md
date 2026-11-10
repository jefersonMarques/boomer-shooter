# LVL-001-ENC — Encontros, ritmo e comportamento

**Local:** [LVL-001 Câmara de Descarte](l01-discard-chamber.md).
**Objetivo:** transformar a primeira fase em uma sequência divertida, verificável e econômica em sistemas.
**Estado:** proposta de tuning, sem números finais de dano ou tempos de ataque.

## Loop de aprendizado

- **Observar:** um ruído, uma silhueta ou uma luz antecipam o problema.
- **Agir:** atirar, mover, recuar ou interagir.
- **Confirmar:** animação, som, mudança de estado e objetivo visível indicam resultado.
- **Respirar:** transição de intensidade antes do desafio seguinte.

O jogador precisa entender a linguagem antes de enfrentar dois arquétipos ao mesmo tempo. O primeiro combate é fácil; a arena S5 testa as habilidades aprendidas.

## Distribuição proposta

| Encontro | Setor | Inimigos | Aprendizado | Condição |
| --- | --- | --- | --- | --- |
| E01 | S2 Posto de segurança | 1 Trabalhador Convertido | pegar arma, mirar, impacto, recuo | entrada no posto/visão do Worker |
| E02 | S4 Desvio | 1 Sentinela Industrial | telegraph de tiro, cobertura e esquiva | entrada em linha de visão controlada |
| E03 | S5 Linha de separação | 1 Trabalhador + 1 Sentinela | pressão combinada, circulação e prioridade | entrar na arena |
| Reserva E04 | S5 saída para elevador | 1 Trabalhador opcional | reforçar combate se o teste apontar baixa pressão | **não ativar no primeiro build** |

**Total inicial:** quatro inimigos em três encontros, duas espécies. **Máximo simultâneo previsto:** dois. Ajustar após playtest. O jogo não deve gerar inimigos atrás do jogador sem fonte visível e aviso.

## E01 — Primeiro confronto: Trabalhador Convertido

### Preparação

O jogador escuta arrasto de metal e vê uma silhueta curvada através de vidro industrial. O inimigo ainda está a vários passos de distância. Ao pegarmos a V-12, o Worker percebe movimento, ergue o corpo, faz estalo de ombro e entra na rota do jogador.

**Comportamento de tutorial sem placa:** o primeiro Worker não deve atacar no primeiro frame da detecção. Tem curta preparação visível, deslocamento progressivo e golpe anunciável.

### Estados mínimos

Idle → Detect → Chase → AttackWindup → Attack → Recovery; Hurt e Death podem interromper estados apropriados.

**Sem lógica elaborada:** não exige investigação, patrulha procedural, saltos, grupos ou percepção auditiva simulada. Basta visão/distância e movimentação simples compatível com o corredor.

### Resultado esperado

O jogador dispara 1–3 vezes dependendo do balanceamento e vê resposta significativa. Se recuar, há espaço; se errar, não fica sem munição automaticamente. Ao morrer, o Worker deixa o corredor livre, com sua ferramenta presa no chão.

### Falhas a testar

- Ataque começa antes da animação de preparação.
- Sprite é muito alto/baixo na distância de combate.
- Hitbox e sprite não correspondem.
- O jogador pode passar pelo inimigo como se ele não existisse ou ficar preso junto à parede.
- Ao morrer, o inimigo bloqueia a porta ou captura o mouse de forma incorreta.

## E02 — Primeira Sentinela: linha de visão

### Preparação

Do início do corredor o jogador vê um braço-canhão em uma plataforma de inspeção. Um par de notas mecânicas avisa a detecção. A Sentinela mira antes de disparar; o projetil e/ou trajetória são reconhecíveis.

### Comportamento

Idle scan → Detect → Aim → Shoot → Cooldown → Aim; Hurt/Death quando aplicável. Sem perseguição complexa no primeiro vertical slice: a Sentinela pode permanecer dentro da região que defende, girando de forma limitada.

**Cobertura:** duas caixas de carga deixam uma área sem exposição. O jogador pode reentrar na linha de visão, disparar e retornar à proteção. Fazer a cobertura funcionar exige regra física simples e robusta.

### Resultado esperado

A Sentinela fica vulnerável no cooldown; o jogador compreende o aviso luminoso + som. Tiro não nasce atrás do jogador; nenhuma fumaça esconde o projetil.

### Falhas a testar

- Tiro atravessa geometria sólida inesperadamente.
- A mira dispara sem preparação.
- O inimigo não consegue mirar por diferenças de altura.
- O cooldown não é aparente.
- O jogador consegue eliminar a Sentinela sem sequer perceber que ela existe (posição precisa ser ajustada, não torná-la invulnerável).

## E03 — Linha de Separação: primeiro duelo combinado

### Cenário

A sala começa com visão de cima para baixo, oferecendo um segundo para localizar as duas ameaças. Um Trabalhador circula uma esteira, e uma Sentinela ocupa passarela do outro lado. A alavanca de saída brilha em âmbar discreto.

### Coreografia emergente desejada

1. Worker percebe o jogador e tenta encurtar a distância.
2. Sentinel acompanha com braço-canhão e anuncia disparo.
3. Jogador move-se pelo espaço circular, escolhendo eliminar primeiro a ameaça próxima ou procurar cobertura para controlar o atirador.
4. Assim que a arena abre, pode alcançar a alavanca e interromper a produção.
5. A mudança sonora sinaliza que a área foi controlada, mesmo se ainda houver inimigo sobrevivente.

**Importante:** não codificar coreografia rígida de vitória. O loop deve permitir estilos diferentes; o design de espaço cria a situação. A alavanca pode ser acionada durante o combate, se fisicamente acessível.

### Layout de combate

- Carrinho central pode bloquear projéteis mas não criar ponto de invulnerabilidade absoluto.
- Esteiras decorativas não prendem jogador; se houver movimento efetivo, prever bordas e avisos.
- A Sentinela deve ter ângulo de ataque previsível; jogador deve poder quebrar linha de visão.
- As rotas laterais precisam acomodar movimentação rápida sem esbarrões frequentes em props.
- O espaço da alavanca deve manter área livre para interação.
- A saída permanece óbvia após a esteira parar.

### Riscos

Se a espingarda for eficaz demais à distância, a Sentinela perde função; se for ineficaz e a plataforma inacessível, cria-se combate frustrante. Ajustar distância, altura e geometria primeiro, e só então balancear queda de dano.

## Pacing — curva emocional

| Momento | Intensidade esperada | Ação |
| --- | --- | --- |
| 0–1 min | baixa | despertar / terminal / ruídos |
| 1–3 min | média | arma + Worker |
| 3–5 min | média | desvio / Sentinel |
| 5–9 min | alta | Worker + Sentinel / arena |
| 9–12 min | baixa | alavanca, oficina opcional |
| 12–15 min | baixa crescendo em mistério | elevador, visão da instalação e saída |

Esses tempos são aproximações **não vinculantes**, e não instruções para spawn programado. O percurso se adapta ao jogador sem relógio de pressão.

## Economia e recuperação

- O jogador começa com vida cheia e sem arma; obtém a V-12 antes do primeiro combate.
- Munição inicial deve permitir erros e diversas tentativas; pequenos reforços surgem em rota principal, não apenas no segredo.
- Item de cura pequeno pode estar no posto de segurança ou perto da arena, mas não deve existir como cura forçada de roteiro.
- Oficina fornece recompensa opcional, sem ser necessária à vitória.
- Não exigir headshots nem escolha de dificuldade exata para completar a demo.
- Se munição ou vida acabarem, o jogador deve poder tentar novamente por checkpoint justo.

## Checkpoints e reinício

**CP-00:** início da fase; não repetir animação longa de despertar em reentrada.
**CP-01 (recomendado):** após derrotar o primeiro Trabalhador e obter a V-12.
**CP-02 (opcional após testes):** entrada da Linha de Separação, se a fase ficar longa ou a morte em E03 for frequente.

O salvamento do estado completo do mundo **não é obrigatório** para o primeiro vertical slice; checkpoints podem ser reinício de cenários fixos a partir de ponto conhecido. Manter consistência de inventário, vida e inimigos ao reiniciar.

## Objetivos e estados de fase

- **Start:** jogador tem controle e terminal reage.
- **WeaponObtained:** V-12 disponível, introdução de combate liberada.
- **CorridorRedirected:** porta de triagem fecha, desvio permanece acessível.
- **SortingLineStopped:** alavanca foi acionada, elevador disponível.
- **SecretDiscovered:** opcional, não obrigatório para saída.
- **LevelComplete:** elevador chega ao corredor da Ala dos Retornados.

Esses nomes são **identificadores sugeridos para documentação**, não prescrição de implementação em código.

## Critérios de aceitação

1. O jogador termina a fase sem conhecer previamente a lore ou ter foto.
2. Não há softlock por arma ignorada, munição, porta, alavanca ou segredo.
3. Todos os ataques possuem indicação visível, com áudio complementar.
4. Os inimigos não atravessam paredes ou se prendem em colisão comum.
5. Tiro, impacto, dor, morte e recarga apresentam feedback claro.
6. O jogador entende a saída sem mapa automático.
7. A demo funciona no browser e no build nativo com controles equivalentes.
8. Não há travamento após morrer ou recarregar a página.
9. FPS, memória, desenho de sprites e spritesheets serão medidos nos dispositivos-alvo antes de metas rígidas.
10. Nenhuma fala longa interrompe o combate; legendas e textos podem ser ignorados sem perder o objetivo imediato.

## Documentos de apoio

[Mapa da fase](l01-discard-chamber.md) · [Arte e som](l01-art-audio.md) · [Worker](../enemies/converted-worker.md) · [Sentinel](../enemies/industrial-sentinel.md) · [V-12](../objects/rupture-v12.md) · [Regras de gameplay](../gameplay.md).
