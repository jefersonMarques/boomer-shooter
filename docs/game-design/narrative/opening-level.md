# NAR-002 — Roteiro jogável L01: Câmara de Descarte

**Objetivo de produção:** orientar level design, iluminação, sprites, som, UI e fluxo de jogo de uma demonstração de 8–15 minutos (alvo provisório).
**Lado técnico:** implementação por incrementos, sem prometer que o protótipo atual possui essas funcionalidades.
**Local canônico:** [O Matadouro](../locations/slaughterhouse.md).

## Abertura — 00:00 a 00:45 (ritmo aproximado)

A tela surge de preto com zumbido elétrico e respiração contida. O jogador já pode mover o olhar. Há teto de concreto baixo; tubos pretos vibram acima de uma maca e pingos caem num balde de metal à esquerda. Uma luz âmbar pisca pelo reflexo de água suja no piso.

A frente está um terminal. A moldura espessa tem dedos marcados no vidro e etiquetas antigas do Consórcio. Quando o jogador aproxima o olhar ou dá um passo, a tela identifica a presença e apresenta a imagem escolhida localmente, ou rosto padrão. Ao lado da foto há campos vazios:

> IDENTIDADE NÃO RECONHECIDA.  
> INDIVÍDUO FORA DA REDE.  
> ORDEM DE EXTERMÍNIO AUTORIZADA.

Um ruído de impressora: a etiqueta **RETIDO** cai no chão, como se o jogador fosse apenas uma peça defeituosa.

**Regra:** o texto não congela controles. Se a pessoa não olhar para o terminal, um som e uma curta marcação visual atraem atenção, mas o progresso não é bloqueado.

## Primeira ameaça — 00:45 a 02:00

Atrás da porta, um Trabalhador Convertido arrasta um gancho pesado. Por uma janela lateral, vê-se seu perfil e o visor sem olhos. O monstro suspende o gancho ao ouvir a abertura. Do outro lado da porta há um segurança morto e a **V-12 Ruptura**.

**Ação:** a arma pode ser apanhada imediatamente. Um mecanismo trava a porta por instante suficiente para a pessoa observar a criatura. O monstro ergue o braço, o som avisa e o primeiro tiro demonstra recuo e impacto.

**Atenção:** não usar jumpscare de surgimento instantâneo na cara do jogador nem tiro obrigatório com munição insuficiente.

## Corredor de triagem — 02:00 a 04:00

A iluminação muda de branco frio para verde. Uma porta em frente pisca em vermelho e fecha quando o sistema reconhece a Testemunha. À direita, setas azuis da manutenção apontam a um desvio. Uma gravação de Lídia aparece em um aparelho simples:

> “O sistema não consegue acessar seus pensamentos. Isso é vantagem. Não desperdice.”

A mensagem dura poucos segundos. O corredor revela uma sentinela em sacada baixa; a lâmpada de preparação ilumina o braço-canhão. O encontro ensina linha de visão e cover.

## Linha de separação — 04:00 a 08:00

Um espaço de teto alto contrasta com os corredores. Há duas passarelas, quatro esteiras, uma ponte entre elas e uma alavanca amarela visível do ponto de entrada. A sala contém um Trabalhador no piso e uma Sentinela acima.

**Combate:** jogadores podem circular ao redor de um carrinho de manutenção. Quando a ameaça termina ou diminui, um feixe âmbar da alavanca ajuda a identificar a interação sem HUD intrusiva.

**Ação obrigatória:** acionar a alavanca interrompe a esteira e abre rota para elevador; o som muda de maquinário para gotejamento, oferecendo contraste emocional.

## Descoberta opcional — 08:00 a 10:00

À esquerda, uma porta semiaberta esconde armário com círculo e três riscos. Ao abrir, a pessoa encontra munição e um gravador “PREGO”:

> “Se isso está tocando, alguma coisa escapou. O elevador de carga é velho. Ainda funciona se a linha parar.”

O jogador pode ignorar e terminar a fase. Este trecho serve de semente para Tomás Neri e Pilotos de Cinza.

## Saída — 10:00 a 15:00

O elevador tem grades grossas, luz fraca e vidro sujo. Um painel de parede ainda indica “CENTRO DE RESTAURAÇÃO HUMANA Nº 04”. O jogador ativa o elevador. Atrás das grades, andares se movem; vemos primeiro trilhos de produção e, por uma janela blindada distante, uma pequena visão de Nova Babel sob céu vermelho. **A plataforma permanece dentro do Matadouro.**

**Fim da demonstração:** finalizar numa tela de conclusão curta ou com volta ao menu. Na campanha, o elevador interno leva à **Ala dos Retornados (L02)**. A passagem à superfície ocorre apenas depois da **Fornalha (L03)**, quando o Superintendente 04 é derrotado. A visão da cidade na demo funciona como prenúncio, não fuga.

## Mapa lógico simplificado

1. Câmara de Descarte → 2. Porta/segurança → 3. Corredor de Triagem → 4. Desvio → 5. Linha de Separação → 6. Alavanca → 7. Elevador de Serviço.

Um único retorno opcional conecta Linha de Separação ao Armário dos Pilotos. Sem labirinto na primeira fase.

## Checklist visual de contratação/arte

- Mecânicas: porta, pickup, tiro, dano, morte/reinício, alavanca, elevador.
- 2 tipos de inimigo: Worker e Sentinel.
- 1 arma: V-12.
- Props: terminal, maca, etiquetas, esteira, carrinho, armário, gravador, alavanca.
- Luz: branco inicial, verde de triagem, vermelho de alerta, âmbar interativo.
- Sons: despertar, impressora, porta, primeiro monstro, arma, alavanca, elevador.
- UI: portrait padrão, vida, munição, orientação de interação.
- Narrativa: três linhas iniciais, uma gravação curta, uma mensagem opcional.

**Referências:** [OBJ-001 Terminal](../objects/identity-terminal.md) · [V-12](../objects/rupture-v12.md) · [Trabalhador](../enemies/converted-worker.md) · [Sentinela](../enemies/industrial-sentinel.md) · [Props](../objects/environment-props.md).

## Documentação de produção detalhada

Este roteiro registra a sequência narrativa inicial. A versão espacial e de produção está separada em três fichas, que passam a ser a referência detalhada do L01:

- [Mapa, percursos, descrição de salas e história ambiental](../levels/l01-discard-chamber.md).
- [Encontros, ritmo, IA mínima, checkpoints e testes](../levels/l01-encounters.md).
- [Brief visual e sonoro, materiais e inventário de assets](../levels/l01-art-audio.md).
