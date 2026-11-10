# BOS-002 — A Torre que Escuta

**Local:** Torre Vigília, Nova Babel, capítulo II.
**Categoria:** chefe-estrutura, parcialmente imóvel.
**Tema:** vigilância, reconhecimento e falha da coordenação.
**Fonte do cenário:** [Nova Babel](../../locations/new-babel.md).

## História

A Torre Vigília era um transmissor civil de emergência. O CORO transformou a matriz em um sistema que observa milhões de registros e redistribui ordens de captura. Ela não vê o passado da Testemunha, mas consegue rastrear movimento e criar tentativas de identificação visual.

O jogador já viu sua imagem em outdoors antes de alcançar a torre: isso prepara o confronto com um sistema que reconhece aparência mas não entende vontade.

## Aparência

**Silhueta dominante:** antena central vertical com uma esfera de painéis quadrados, três braços suspensos e fibras vermelhas envolvendo isoladores de porcelana. A base se abre como uma flor mecânica.
**Materiais:** concreto grafite, metal oxidado, vidro de monitor, cobre e tecido vivo.
**Detalhes:** dezenas de pequenas telas giram para acompanhar a posição do jogador, mas **apenas três módulos grandes são alvos críticos**, evitando confusão visual.

**Luz:** pulso branco quando observa; três anéis âmbar quando uma descarga está prestes a acontecer; vermelho após perda de transmissor.

## Confronto

A arena é um anel com três setores e rotas largas. Há pontos de cobertura e duas passarelas que permitem circundar o eixo. O chefe não precisa caminhar: ataque vem do posicionamento de emissores e unidades de apoio.

1. **Varredura:** um setor do chão acende de branco e âmbar; depois recebe pulso de energia. Tempo para sair da área.
2. **Braço de contenção:** um dos braços aponta por instante e bate num segmento frontal; a recuperação abre oportunidade.
3. **Suporte:** uma sentinela surge de acesso lateral já visível; limitar quantidade para preservar FPS e clareza.
4. **Objetivo:** desligar três retransmissores periféricos de maneira livre; cada ruptura elimina um padrão e expõe o eixo.
5. **Clímax:** com o último módulo desligado, o eixo central se abre. O jogador dispara contra o núcleo e interrompe a rede local.

## Efeitos de vitória

Outdoors distantes mostram estática; os semáforos param; por um instante a cidade parece vazia. Depois a voz da Irmã Zero aparece em um canal ainda funcional e orienta a história para o subterrâneo.

## Produção

O corpo principal pode ser geometria de cenário e animação de textura. Não exige sprite colossal girando. Ações de chefe usam objetos separados com estados, emissões e colisões simples.

**Relações:** [Retransmissor](../../objects/broadcast-relay.md) · [O CORO](../../characters/chorus.md) · [Índice de chefes](../bosses.md).
