# Direção de arte e áudio

**Status:** guia visual inicial, não especificação final de assets.
**Alvo estético:** um FPS aparentemente perdido de 1997, porém com controles, feedback e desempenho modernos.

## Identidade visual

Combinar o ritmo e a apresentação dos FPS dos anos 1990 com um universo próprio de **horror biomecânico e tecnologia religiosa**. A direção visual não deve parecer um FPS moderno com filtro pixelado aplicado por cima.

### Elementos principais

- **Cenários:** geometria 3D legível, grandes formas arquitetônicas, texturas de baixa resolução, detalhes industriais e orgânicos.
- **Personagens e inimigos:** sprites 2D direcionais (billboards), com silhuetas fortes e animações curtas, expressivas e brutais.
- **Armas:** sprites de primeira pessoa grandes e reconhecíveis, disparos com sensação de peso e impacto.
- **Texturas:** pixelização intencional, sujeira, ferrugem, concreto, metal, azulejos hospitalares e carne.
- **Iluminação:** contraste forte, pontos de luz dramáticos, vermelho de emergência, sombras profundas sem comprometer a orientação.
- **Violência estilizada:** sangue exagerado, desmembramento visual quando tecnicamente viável e efeitos de impacto claramente legíveis.

Não reproduzir elementos protegidos de Doom, Quake, Hexen ou outros jogos. Os assets devem ter silhuetas, criaturas e composições originais.

## Paleta e significado

| Família visual | Cores predominantes | Função |
| --- | --- | --- |
| Instalações industriais | cinza, verde oxidado, âmbar sujo | escala, abandono, perigo mecânico |
| Alertas de O CORO | vermelho profundo, branco frio, preto | identificação, controle, hostilidade |
| Cidade destruída | azul dessaturado, laranja de incêndio, concreto | colapso e exposição |
| Estruturas orgânicas | vinho, vermelho escuro, roxo, osso | transformação e horror corporal |
| Núcleo | vermelho saturado, preto, dourado apagado | poder e ritual tecnológico |

As cores identificam perigo e região, mas nunca devem ser a única forma de distinguir inimigos e informações.

## Ambientes por capítulo

### O Matadouro

Corredores baixos, linhas de descarte, mesas cirúrgicas, portas hidráulicas, vapor e maquinário bruto. O jogador deve ler a sala rapidamente: saída, coberturas, obstáculos e inimigos.

### Nova Babel

Ruas arruinadas, passarelas, antenas, veículos, fachadas de propaganda e espaços externos contrastando com os interiores. Criar a sensação de uma cidade que permanece em operação sem pessoas.

### O Santuário

Transição gradual de metal para tecido vivo. Paredes pulsantes, cabos semelhantes a veias, grandes cavidades e maquinaria que parece respirar.

### O Núcleo

Escala monumental, geometria religiosa reinterpretada como sistemas eletrônicos, plataformas e um núcleo central dominante. A arena final deve manter legibilidade mesmo com o chefe enorme e múltiplos efeitos.

## Direção dos inimigos

Arquétipos visuais iniciais, ainda sem nomes definitivos:

1. **Trabalhador convertido:** silhueta humana quebrada, agressivo em curta distância.
2. **Sentinela mecânica:** torso industrial com armas integradas, médio alcance.
3. **Parasita rastejante:** pequeno, rápido e de leitura imediata.
4. **Cultista de transmissão:** humanoide mais alto, efeitos de sinal/energia.
5. **Guardião biomecânico:** massa grande e pesada, leitura de ataques por antecipação.

### Requisitos de sprites

- Identidade consistente entre frente, costas e ângulos laterais.
- Estados principais: idle, walk, attack, pain, death; outros apenas quando úteis.
- Silhueta e área de colisão visualmente coerentes.
- Ataques com telegraph claro, sem depender apenas de áudio.
- Evitar excesso de quadros e direções antes de validar a renderização em WebAssembly.
- Transparência e dimensões padronizadas no pipeline de exportação.

## Armas e efeitos

As armas devem parecer exageradas e mecânicas, com forte resposta audiovisual. A espingarda é candidata a arma-assinatura, mas design e estatísticas exigem testes.

Feedback mínimo: flash, recuo, som, impacto de projétil, reação do inimigo, confirmação de dano e indicação de munição.

## HUD e rosto

A HUD incorpora um retrato 2D do protagonista, com expressões associadas a saúde, danos, perigo e eventos especiais. A imagem enviada pelo jogador é **opcional**; a versão padrão deve ter o mesmo nível de qualidade.

O uso do rosto em monitores e no chefe final é uma meta criativa, não parte obrigatória do primeiro protótipo. Processamento local é a opção padrão desejada; a documentação técnica futura deverá esclarecer formatos de arquivo, limites, consentimento, descarte e fallback.

## Áudio

- **Combate:** metal/industrial, pulsação rápida, agressividade e energia.
- **Exploração:** drones mecânicos, máquinas, alarmes distantes, ruído de transmissão.
- **Armas:** sons graves, secos e distintos, sem mascarar avisos importantes.
- **Inimigos:** vocalizações e sinais próprios para comunicar intenção e distância.
- **Narrativa:** vozes e rádio breves, podendo aparecer durante a exploração.
- **Acessibilidade:** informações essenciais também devem aparecer visualmente.

Música, efeitos e fontes de áudio devem ser originais ou devidamente licenciados.

## Critérios de aceitação artística

A estética é bem-sucedida quando: (1) o jogador reconhece rapidamente inimigos, armas e objetivos; (2) a imagem mantém personalidade em resolução reduzida; (3) cada capítulo é identificável sem texto; (4) a personalização facial não rompe a coesão; (5) o projeto roda com fluidez na plataforma-alvo.

## Fichas de referência para artistas

A especificação visual detalhada agora fica nas **fichas individuais**, e este documento conserva a identidade geral, a paleta e os princípios de legibilidade. Usar [ART-001 Guia de produção de assets](art/asset-guidelines.md) como checklist para concepts, sprites e texturas.

- **Personagens:** [A Testemunha](characters/protagonist.md), [Lídia Varela](characters/lydia-varela.md), [Tomás Neri](characters/tomas-neri.md), [Irmã Zero](characters/sister-zero.md) e [O CORO](characters/chorus.md).
- **Ambientes:** [Matadouro](locations/slaughterhouse.md), [Nova Babel](locations/new-babel.md), [Santuário](locations/sanctuary.md) e [Núcleo](locations/core.md).
- **Inimigos:** [Bestiário](enemies/README.md) e [chefes](enemies/bosses.md); cada criatura comum possui ficha de silhueta, animações, som e comportamento.
- **Objetos e interface:** [Catálogo de props](objects/environment-props.md), [Terminal de Identidade](objects/identity-terminal.md), [Retransmissor](objects/broadcast-relay.md), [V-12 Ruptura](objects/rupture-v12.md) e [Rosto/HUD](objects/face-interface.md).
- **Ordem de produção:** [roteiro L01 e checklist visual](narrative/opening-level.md).

**Fonte única dos detalhes:** alterações de anatomia, composição de objetos ou acontecimentos devem ser feitas primeiro na ficha da entidade e depois refletidas aqui, quando afetarem a identidade visual do universo.
