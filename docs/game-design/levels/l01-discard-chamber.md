# LVL-001 — Câmara de Descarte

**Estado:** layout e roteiro de produção propostos para a primeira fase jogável.
**Campanha:** Capítulo I — O Despertar, nível L01.
**Instalação:** Centro de Restauração Humana nº 04, chamado de O Matadouro.
**Duração-alvo:** 8–15 minutos na primeira experiência, sem depender de textos opcionais.
**Prioridade:** vertical slice C++20 / WebAssembly, não campanha completa.
**Saída:** elevador interno para a **Ala dos Retornados (L02)**; a cidade aparece como prenúncio, não como fuga concluída.
**Referência de roteiro anterior:** [NAR-002 Abertura jogável](../narrative/opening-level.md).

## Objetivo emocional e de jogabilidade

O jogador deve terminar pensando:

1. **“Eu acordei como algo descartável.”** O terminal trata uma pessoa como material fora de catálogo.
2. **“Este mundo funciona sem ninguém.”** Máquinas e anúncios seguem rotinas enquanto os operadores já morreram.
3. **“Eu consigo lutar.”** A espingarda tem impacto e os inimigos são vencidos por movimento e leitura de ataques.
4. **“O que existe nos outros andares?”** Uma instalação maior é vista à distância, sem revelar toda a história.

A primeira fase precisa ser **divertida mesmo que toda fala opcional seja ignorada**. Nenhuma câmera forçada longa; movimento e olhar livres desde a abertura.

## Fatos canônicos respeitados

- Ano 2147; Consórcio Permanência, CORO e Pilotos de Cinza preexistem à fase.
- A Testemunha desperta numa maca de descarte com consciência fora da rede e corpo fabricado.
- Um terminal mostra a imagem de rosto escolhida localmente ou avatar padrão; o CORO autoriza extermínio.
- A V-12 Ruptura foi deixada por um segurança morto e é a primeira arma.
- Trabalhador Convertido ataca corpo a corpo; Sentinela Industrial dispara a média distância.
- A gravação de Lídia introduz apenas a impossibilidade de o CORO ler os pensamentos do protagonista, não sua origem.
- Tomás Neri fala por **gravação antiga**, sem interação ao vivo.
- A saída de L01 não derrota o Superintendente 04; esse chefe fica em L03.

[Regras do mundo](../world/rules.md) · [Cronologia](../world/timeline.md) · [Campanha](../narrative/campaign-beats.md).

## Planta lógica — fluxos, não escala construtiva

\`\`\`text
                      NÍVEL SUPERIOR / PASSARELA
              +-------------------------------------+
              |  S4: VISOR DA INSPEÇÃO             |
              |  Sentinela observando linha abaixo |
              +------------------+------------------+
                                 |
+------------------+    +--------v---------+   +----------------------+
| S1: CÂMARA DE    |--->| S2: POSTO DE     |-->| S3: CORREDOR DE     |
| DESCARTE         |    | SEGURANÇA        |   | TRIAGEM              |
| maca / terminal  |    | V-12 / Worker    |   | porta fechada        |
+------------------+    +------------------+   +----------+-----------+
                                                            |
                                             +--------------v--------+
                                             | S4: DESVIO DE         |
                                             | MANUTENÇÃO / Sentinel |
                                             +--------------+--------+
                                                            |
                          +---------------------------------v--------+
                          | S5: LINHA DE SEPARAÇÃO                   |
                          | esteiras / Worker + Sentinel / alavanca  |
                          +----------+-------------------+-----------+
                                     |                   |
                          +----------v---------+   +-----v-------------+
                          | S6: OFICINA        |   | S7: ELEVADOR     |
                          | CLANDESTINA        |   | INTERNO          |
                          | segredo opcional   |   | destino L02      |
                          +--------------------+   +-------------------+
\`\`\`

**Observação:** S4 aparece como desvio de manutenção e visor superior do mesmo conjunto; o visor permite antecipar a Sentinela antes do encontro. A numeração final dos setores pode ser consolidada em editor quando existir o mapa real.

### Regras de conectividade

- Um caminho obrigatório principal, sem atalhos ocultos para continuar.
- Uma sala secreta opcional conectada à arena, com retorno óbvio.
- Nenhum puzzle exige leitura de texto pequeno, foto personalizada ou arma secundária.
- A primeira arma está em local incontornável e imediatamente alcançável.
- O elevador é uma saída **interna** para L02. É possível ver a escala vertical da instalação e uma nesga da cidade por janela blindada, mas não sair ao exterior.
- Não usar teleporte arbitrário, labirinto de portas iguais ou cinemática que impeça locomoção.

## S1 — Câmara de Descarte

**Função:** apresentar ambiente, identidade e primeiro medo sem ataque imediato.
**Forma sugerida:** sala estreita aproximadamente retangular; teto mais baixo que o resto do mapa; porta principal ao fundo e janela estreita lateral para o corredor.
**Ponto de despertar:** ao lado de maca de alumínio velho; faixa de contenção rompida no pulso e saco de descarte aberto. Jogador começa em pé ou conclui uma transição visual curtíssima ainda com controle imediato.
**Âncoras visuais:** terminal CRT grande na parede à frente, impressora de etiquetas, lâmpada âmbar irregular, dreno em piso molhado, relógio parado 03:17.
**Iluminação:** zona quase neutra com branco frio no terminal e amarelo opaco no restante; nunca escuro a ponto de não encontrar porta.
**Som:** motor distante de esteira, vazamento pingando num balde, respiração contida e transformador vibrando. Primeiro grande contraste: a voz clínica da rede em sala vazia.

### Evento essencial

Quando o personagem se move ou a cena é estabilizada, o terminal faz três bipes, mostra o retrato local/padrão e exibe:

> IDENTIDADE NÃO RECONHECIDA.
> INDIVÍDUO FORA DA REDE.
> ORDEM DE EXTERMÍNIO AUTORIZADA.

A etiqueta “RETIDO” sai da impressora e cai no chão. Uma porta de segurança do setor seguinte abre em resposta à ordem.

**Fallback:** se a pessoa não olhar para a tela, o som e uma seta contextual discreta orientam por poucos segundos; o roteiro não bloqueia avançar.

**História ambiental opcional:** na parede, um cartaz intacto diz “NADA SE PERDE”, contradizendo os objetos de descarte.

## S2 — Posto de Segurança / Primeira arma

**Função:** primeiro combate solo, mostrar agência e impacto da V-12.
**Geometria:** pequeno corredor de controle com grade à frente, cabine de vidro lateral e espaço suficiente para recuar cerca de alguns passos.
**Props:** corpo de segurança, arma apoiada ou caída junto à mão, estojo de cartuchos, rádio partido, monitor apagado.
**Ameaça anunciada:** além do vidro o Trabalhador Convertido arrasta um gancho; o som chega antes de ele entrar na linha de tiro.

### Gatilho e sensação

A pessoa passa pelo posto e pega a V-12 (pickup automático ao encostar, ou comando “interagir” se o sistema exigir). O inimigo aparece à frente em distância confortável e em movimento lateral perceptível, não colado ao jogador. Ele ergue o braço pesado, estala articulações e avança.

O primeiro disparo produz **som forte, clarão curto, recuo, impacto evidente e reação do inimigo**. O objetivo não é dificuldade: é demonstrar que a arma funciona.

**Proteção contra travamento:** a arma está no único caminho possível; munição inicial cobre várias tentativas; a grade não prende a pessoa dentro da sala durante ataque; se o jogador ignorar a arma, a rota ainda permite alcançá-la.

**Easter detail:** o segurança ainda carrega cartão de identificação sem fotografia, enquanto a V-12 tem “04” riscado na coronha.

## S3 — Corredor de Triagem / Porta de contenção

**Função:** ensinar linguagem de bloqueio e orientação ambiental.
**Formato:** corredor em L, com porta grande ao fundo marcada “PROCESSAMENTO” e desvio lateral indicado por placas azuis “MANUTENÇÃO”.
**Visual:** azulejos hospitalares sujos migrando para paredes de concreto; janelas mostram mesas cirúrgicas e braços mecânicos trabalhando sozinhos.
**Evento:** sensores detectam a Testemunha, luz de alarme fica vermelha e a porta principal se fecha lentamente. O desvio lateral permanece iluminado em âmbar.

Uma gravação de Lídia é reproduzida por um terminal antigo na rota:

> “O sistema não consegue acessar seus pensamentos. Isso é vantagem. Não desperdice.”

A mensagem é curta, legendada e **não interrompe o jogo**. O jogador não precisa interagir para ouvi-la; pode encontrar o arquivo completo depois em área opcional.

**Objetivo legível:** seguir para MANUTENÇÃO. Não adicionar item de chave, código de teclado ou senha.

## S4 — Desvio de manutenção / Primeira Sentinela

**Função:** ensinar ataque à distância, linha de visão, sinal de tiro e cobertura.
**Geometria:** pequeno corredor com abertura para uma galeria e duas caixas de carga criando cobertura natural. Um visor superior mostra uma sentinela orientando seu braço-canhão antes que ela tenha linha direta para disparar.
**Visual:** corrimãos, caixas amarelas, iluminação branca fria perto do atirador; detalhes vermelhos ficam em áreas de alarme, não no projétil todo.
**Encontro:** a Sentinela detecta, emite duas notas e prepara arma com lâmpada âmbar e mira visível. O jogador pode disparar em movimento, recuar atrás da caixa ou contornar a linha de visão.

**Regra:** não usar tiro instantâneo sem aviso, nem colocar a sentinela acima do limite confortável de mira vertical. Se o jogador se esconder, o inimigo faz pausa de recarga que abre janela de ataque.

**Saída:** passarela curta e rampa larga dão visão da sala de separação abaixo.

## S5 — Linha de Separação / Arena principal

**Função:** demonstrar a essência do jogo: movimentação, dois tipos complementares de inimigos e ambiente industrial legível.
**Volume:** sala mais larga e alta da fase; duas passarelas, quatro esteiras (algumas decorativas), carrinho metálico central e alavanca amarela visível do ponto de entrada.
**Foco visual:** alavanca amarela ao lado da comporta do elevador; grande letreiro “LINHA 04”. O jogador deve perceber logo que a sala tem um objetivo, não apenas inimigos.

**Ritmo do encontro:** Trabalhador na parte baixa aproxima primeiro, Sentinela da passarela prepara tiro depois. A arena permite círculos largos, desvios e visão clara dos dois. Não fechar a saída de entrada sem avisar; o jogador deve poder recuar.

**Objetivo após combate:** a alavanca de manutenção interrompe as esteiras, abre a comporta para o elevador e muda radicalmente o som: de ronco contínuo para gotas e pequenos estalos de metal. Não exigir matar todos os inimigos para acionar a alavanca se isso não fizer sentido com a mecânica.

**História ambiental:** centenas de etiquetas “RETIDO” saem de uma máquina sem caixas para recebê-las. Uma mesa de alimentação tem prato com comida ressecada e cartão de ponto de alguém que nunca voltou.

**Detalhe memorável:** quando as esteiras param, uma voz gravada anuncia com gentileza: “Sua integridade é nossa prioridade”. O silêncio seguinte causa mais desconforto que um monstro novo.

## S6 — Oficina Clandestina / Segredo

**Função:** recompensar curiosidade e introduzir uma pessoa da resistência.
**Acesso:** porta de manutenção parcialmente encoberta por armários, mas visualmente detectável; símbolo pequeno de círculo vazio com três riscos.
**Interior:** ferramentas etiquetadas manualmente, caixa de munição, luz amarela portátil, mapa de tubulações com risco de lápis e gravador antigo marcado “PREGO”.
**Fala:** gravação de Tomás Neri:

> “Se isso está tocando, alguma coisa escapou. O elevador de carga é velho. Ainda funciona se a linha parar.”

Esse áudio já existia antes de 2147. Não simular interlocutor ao vivo.

**Retorno:** porta conduz de volta à arena, evitando que a pessoa se perca. Não tornar acesso obrigatório para descobrir a alavanca ou a saída.

## S7 — Elevador de Serviço / Encerramento

**Função:** oferecer recompensa visual de escala e transição para L02.
**Construção:** plataforma pesada de grade metálica, correntes, pistões e luz âmbar fraca; painel manual grande.
**Ação:** jogador aciona elevador; a plataforma desce/sobe um trecho **interno** (definir orientação vertical na planta física). Através de janelas da caixa de elevador, observa centenas de compartimentos da instalação: passarelas, macas, linhas de produção, tubulações e luzes vermelhas ao longe.

Por uma janela de inspeção superior é possível ver **uma pequena fatia do céu vermelho sobre Nova Babel**, prenúncio do capítulo II. O jogador ainda está dentro do complexo. A plataforma chega a um corredor com placa **ALA DOS RETORNADOS — ACESSO 02**.

**Demo:** corte curto para “Fim da demonstração” ou menu de retorno.  
**Campanha completa:** o corredor abre diretamente L02; a fuga definitiva ao exterior fica após o Superintendente 04, em L03.

## Ritmo visual / contraste entre salas

| Sala | Volume | Intensidade | Emoção | Cor dominante |
| --- | --- | --- | --- | --- |
| S1 Câmara | pequeno | quase zero | desorientação | branco sujo / âmbar |
| S2 Posto | médio e estreito | primeiro tiro | reação | cinza / verde |
| S3 Triagem | corredor | bloqueio sem combate | perseguição | vermelho pontual / azul |
| S4 Manutenção | médio com cobertura | tiro à distância | aprendizagem | grafite / branco |
| S5 Linha | maior volume | combate principal | poder e urgência | verde / âmbar |
| S6 Oficina | pequeno / opcional | descanso | curiosidade | amarelo quente |
| S7 Elevador | vertical | zero após objetivo | escala e mistério | preto / vermelho distante |

## Segurança, usabilidade e coerência

- Falha de foto, ausência de áudio ou abandono da gravação não impedem o progresso.
- Mensagens importantes são legíveis e legendadas; não depender de apenas cor ou som.
- Sem água mortal inesperada, armadilha instantânea, ataque por trás sem sinal ou porta que prenda o jogador sem arma.
- Sucesso da fase independe de encontrar a oficina opcional.
- Depois de morrer, retorno próximo sem repetir toda a abertura nem áudio obrigatório.
- Em desktop/teclado, o caminho deve ser compreensível sem mapa minimizado permanente.
- O horror depende de detalhes e contraste, não da exposição incessante a sangue.
- O capítulo I continua incluindo L02 e L03; o chefe do Matadouro não é removido.

## Fichas proprietárias

- [Planta baixa em escala de blockout, coordenadas e segredo único](l01-floor-plan.md) — [visual SVG](l01-floor-plan.svg) e [geometria JSON](l01-layout.json).
- [Ritmo, encontros, gatilhos e testes do L01](l01-encounters.md).
- [Arte, iluminação, efeitos, som e inventário do L01](l01-art-audio.md).
- [A Testemunha](../characters/protagonist.md), [Lídia](../characters/lydia-varela.md) e [Tomás](../characters/tomas-neri.md).
- [Trabalhador Convertido](../enemies/converted-worker.md) e [Sentinela Industrial](../enemies/industrial-sentinel.md).
- [V-12 Ruptura](../objects/rupture-v12.md), [Terminal](../objects/identity-terminal.md), [HUD facial](../objects/face-interface.md) e [Props](../objects/environment-props.md).
