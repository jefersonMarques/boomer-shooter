# ENM-002 — Sentinela Industrial

**Codinome de produção:** Industrial Sentinel.
**Aparece em:** Matadouro, Nova Babel, Torre Vigília.
**Papel tático:** atirador médio, obriga o jogador a se mover e utilizar cobertura.

## Origem

Unidades de transporte e empilhamento do Consórcio foram equipadas com sensores de vigilância. Durante a conversão receberam tecidos de operador implantados no chassis. Não são robôs limpos: por trás de uma grade frontal há um torso incompleto conectado a cabos e bombas de fluido.

## Forma e assinatura visual

Tronco quadrado sobre duas pernas de pistão, com um braço-canhão comprido e o outro reduzido a um manipulador. A assimetria é a leitura principal. O centro de massa baixo evita silhueta humana. Um pequeno monitor quadrado acima do torso exibe a pupila incompleta do CORO.

**Paleta:** grafite, ferrugem, ferragens amarelas e visor branco frio. Quando prepara disparo, uma lâmpada lateral fica âmbar em vez de vermelho.

## Mecânicas narradas pela arte

- **Idle:** cabeça-monitor vasculha o corredor; pistões acompanham lentamente.
- **Detectar:** sinal curto de duas notas e abertura da grade do canhão.
- **Mira:** o braço gira e uma luz frontal converge por curto período.
- **Disparo:** projétil visível com direção clara; evitar tiros hitscan sem sinal no primeiro protótipo.
- **Recarregar:** braço retorna à base, vapor sai pelas juntas, criando oportunidade.
- **Dano:** faíscas e puxão para trás; partes orgânicas internas pulsam.
- **Morte:** perde estabilidade e cai para a frente; o visor apaga.

## Padrão de combate

Prefere posição intermediária, não persegue o protagonista em labirintos apertados sem pathfinding confiável. Reage a linha de visão e pode ser derrotada por circulação lateral.

A versão inicial não precisa de dezenas de comportamentos: detectar, mirar, disparar, recuperar e morrer bastam.

## Áudio

Pistões pesados, servo de giro, duas notas ao detectar, ruído de pressão no tiro e estouro de vapor na queda. O sinal de disparo deve ser audível mesmo com música intensa.

## Produção de sprites

A assimetria precisa ser mantida em todas as direções. Não usar espelhamento simples se inverter o braço-canhão de modo ilógico; criar frames dedicados ou aceitar uma versão simétrica explicitamente redesenhada para o MVP.

**Relações:** [Trabalhador Convertido](converted-worker.md) · [Matadouro](../locations/slaughterhouse.md) · [Nova Babel](../locations/new-babel.md).
