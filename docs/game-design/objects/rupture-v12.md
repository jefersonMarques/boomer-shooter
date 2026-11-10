# WPN-001 — V-12 Ruptura

**Categoria:** espingarda industrial de curto alcance; candidata a arma-assinatura do jogo.
**Primeira obtenção:** segurança morto, ao lado da porta da câmara de descarte.
**Propósito em combate:** oferecer disparo brutal e confiável que recompensa aproximação controlada e movimentação.

## História

A V-12 começou como arma de contenção para proteção de cargas de alto valor do Consórcio. Trabalhadores da resistência apelidaram-na de **Ruptura** porque era uma das poucas ferramentas capazes de quebrar juntas biomecânicas sem exigir energia da rede.

O modelo encontrado no começo apresenta ferrugem, empunhadura remendada com fita isolante e identificação “04” riscada na coronha. Não é uma arma futurista elegante: é uma máquina de oficina feita para sobreviver a pancadas.

## Ficha visual

**Silhueta em primeira pessoa:** cano curto e espesso, bloco de alimentação pesado, alça de armamento lateral e guarda-mato grande. Corpo cinza carvão, detalhes amarelo-industrial e fita vermelha desbotada perto da empunhadura.

O disparo deve ocupar a atenção por um instante, mas a arma não pode cobrir inimigos na metade superior da tela. Recuo visível, cápsula expelida, clarão curto e bombeamento marcante.

## Sensação de combate

- **Ataque:** disparo concentrado a curta distância, com dispersão moderada.
- **Alcance:** perde eficiência a longa distância; não substituir armas de precisão posteriores.
- **Ritmo:** tiro forte → recuo → recuperação audível → pronto para atirar.
- **Munição:** cartuchos industriais; ícone físico claro no HUD.
- **Recarregar:** gesto mecânico expressivo; deve ser cancelável ou protegido de travamentos injustos após teste de combate.
- **Acerto:** reação de inimigo clara; impactos diferenciados em metal e tecido orgânico.

Não fixar valores de dano, pellets, frequência de tiro ou capacidade definitiva antes de testes reais. O MVP usa uma implementação simples, com feedback forte.

## Estados de animação

Idle; equip; fire; recoil; pump/recover; reload; empty; inspect apenas como opção futura. Priorizar fire/recover e reload. Som de cartucho, estampido grave, eco curto industrial e mecanismo seco.

## Papel narrativo

O primeiro encontro com a arma acontece antes de qualquer explicação extensa. Ela dá ao jogador agência contra uma máquina de descarte que o havia classificado como objeto.

## Referências de arte

Detalhes podem ser exagerados e reforçados por highlights para leitura em baixa resolução; manter geometria própria para não se parecer com modelos conhecidos de outros jogos.

**Relações:** [Matadouro](../locations/slaughterhouse.md) · [Arsenal](arsenal.md) · [Trabalhador Convertido](../enemies/converted-worker.md).
