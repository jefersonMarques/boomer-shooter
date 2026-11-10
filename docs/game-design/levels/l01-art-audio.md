# LVL-001-ART — Guia visual, sonoro e inventário de produção

**Nível:** [L01 Câmara de Descarte](l01-discard-chamber.md).
**Função:** transformar a narrativa em referências concretas para concept art, arte de ambiente, sprites, UI, áudio e efeitos.
**Status:** especificação criativa sujeita a validação técnica no navegador.
**Direção geral:** horror industrial original em FPS retrô; a arte não deve reproduzir telas, armas ou criaturas de jogos existentes.

## Tema artístico

**“Uma máquina continua trabalhando depois que acabou o mundo.”**

A fase não parece um laboratório futurista limpo e nem uma masmorra genérica cheia de sangue. É uma instalação de processamento humano projetada por pessoas comuns: painéis com instruções de segurança, luminárias compradas por atacado, elevadores de carga, extintores, azulejo barato e ferramentas deixadas num turno que nunca terminou.

A invasão do CORO criou uma segunda camada: cabos que se parecem com veias, máquinas alimentadas por tecido orgânico, etiquetas associadas a corpos e anúncios clínicos saindo de alto-falantes sem operadores.

Essa combinação — **banalidade industrial + horror de reconstrução** — deve diferenciar o Matadouro de referências genéricas de zumbis e demônios.

## Paleta de referência (aproximada, não especificação de shader)

| Uso | Cor pretendida | Hex de guia de concept |
| --- | --- | --- |
| Concreto e metal frio | cinza azulado muito escuro | #303942 |
| Metal hospitalar envelhecido | verde oxidado | #52665B |
| Cerâmica médica | branco amarelado | #C2BFB0 |
| Luz interativa / oficina | âmbar industrial | #D49639 |
| Alerta de extermínio | vermelho fechado | #A52B31 |
| Tecidos orgânicos | vinho escuro | #6B2B39 |
| Tela de terminal | branco glacial | #D6E7E7 |

Cores são sugestões para consistência de concept. Texturas, roughness, pixel density e iluminação final devem ser testados no renderer real.

## Arquitetura e escala

- **Sala de despertar:** teto comprimido, linhas horizontais; sensação de confinamento.
- **Posto de segurança:** cantos utilitários, janela grossa e grade industrial; aproxima o perigo.
- **Triagem:** corredor limpo no passado, degradado hoje; placas de orientação são legíveis.
- **Desvio:** caixas e passarela ensinam cobertura, em contraste com área hospitalar.
- **Linha de Separação:** teto alto, vigas, ganchos, esteiras e passarelas formam o quadro mais memorável.
- **Oficina secreta:** calor visual de luz amarela portátil; presença humana pela primeira vez.
- **Elevador:** vão vertical e janelas de observação sugerem grandeza do Matadouro e cidade distante.

### Materiais reusáveis

1. Concreto com umidade, variantes claro/escuro.
2. Azulejo médico com sujeira localizada e quinas gastas.
3. Aço industrial pintado de verde, variantes intacto/descascado.
4. Piso de grade metálica para passarela.
5. Borracha de esteira e roletes.
6. Vidro de segurança sujo, com poucos rachados.
7. Tecido orgânico com costura industrial (usar com parcimônia no primeiro nível).
8. Avisos pintados, numeração e etiquetas como decals reutilizáveis.

## Linguagem de luz

O jogo precisa ser escuro, **não ilegível**.

- **Branco frio:** terminações hospitalares, monitores, identificação.
- **Âmbar:** manutenção, controles interativos, alavanca e áreas seguras.
- **Vermelho:** ordem hostil e contenção; não pintar todo o cenário de vermelho.
- **Verde sujo:** fundo industrial e esteiras.
- **Ritmo das falhas:** fluorescentes irregulares em salas pequenas, não estroboscopia contínua.

Objetivos obrigatórios recebem **contraste de forma e cor**, não brilho invasivo. Inimigos continuam distinguíveis quando o jogador está em movimento.

## Brief de concept por sala

### S1 — Câmara de Descarte

Composição principal: maca rompida em primeiro plano, terminal à esquerda ou à frente do caminho, porta de segurança no fundo. O foco da iluminação é a tela. O canto da sala contém dreno, balde e manchas de água no piso; o cartaz “NADA SE PERDE” está quase novo, absurdamente otimista.

**Props críticos:** maca PROP-001, Terminal OBJ-001, etiqueta PROP-004, relógio PROP-015.
**Detalhes de tela:** campos vazios com retrato local/padrão e aviso vermelho.
**Som:** pingos metálicos, transformador, compressor distante, três beeps, estalo de impressora.

### S2 — Posto de Segurança

Composição principal: cabine de vidro grosso e luz lateral, arma V-12 perto do corpo de segurança, grade que deixa ver o Worker. Um rádio quebrado reproduz estática sem voz clara. Faixas amarelas no chão guiam movimento sem seta flutuante.

**Props críticos:** V-12 WPN-001, corpo do guarda como decoração, caixa de munição, grade de segurança.
**Inimigo:** Worker; silhueta curvada e braço assimétrico devem aparecer antes de o monstro atacar.
**Som:** gancho raspando, botas molhadas, destravamento de arma, estampido grave e cartucho.

### S3 — Corredor de Triagem

Composição: corredor em L com uma porta vermelha grande que fecha e uma pequena placa azul “MANUTENÇÃO” indicando desvio. Atrás das janelas, braços cirúrgicos se movimentam sozinhos. Um antigo telefone/gravador do Consórcio reproduz voz de Lídia.

**Props:** sensor, porta, placas direcionais, mesa de cirurgia em cenário não acessível.
**Som:** bip de contenção, rolamento da porta, voz curta de Lídia com pequeno chiado de gravação.

### S4 — Desvio de Manutenção

Composição: espaço intermediário com duas caixas de carga e uma abertura superior para o braço-canhão da Sentinela. O jogador vê o perigo antes de ficar exposto. Tons frios no inimigo e âmbar no aviso de disparo.

**Props:** carrinhos de carga, caixas, corrimão, passarela, lâmpada de inspeção.
**Som:** servo girando, duas notas de detecção, aviso de pressão, disparo, vapor de recuperação.

### S5 — Linha de Separação

**Imagem-chave do primeiro nível.** Uma sala ampla com quatro esteiras que se cruzam visualmente, correntes no teto, guindaste parado e duas passarelas. Centro dominado por carrinho de manutenção, uma grande placa “LINHA 04” e a alavanca amarela próxima à saída.

A câmera do jogador, na entrada superior, deve enquadrar pelo menos uma esteira e a alavanca. A sala parece estar trabalhando, mesmo vazia. Durante combate o Worker se movimenta no piso e a Sentinela ocupa passarela. Ao desligar, as esteiras deixam um silêncio perturbador; um anúncio clínico vazio completa o momento.

**Props:** esteiras PROP-002, válvula PROP-003 decorativa/funcional quando necessário, carrinho PROP-009, alavanca, etiquetas PROP-004.
**Som:** motor/roletes, corrente, gancho, presença inimiga, alavanca, silêncio e anúncio.
**Efeitos:** faíscas breves em metal; impactos orgânicos contidos; vapor não ocultando visão.

### S6 — Oficina Clandestina

Composição: pequeno espaço de manutenção iluminado por luz de emergência **amarela e quente**, destoando da frieza do CORO. Armário da resistência semiaberto, caixa de ferramentas “PREGO”, gravador cinza, mapa desenhado à mão e cartuchos escondidos.

**Props:** armário PROP-005 e gravador PROP-008; anotações manuscritas reutilizadas em futuras fases.
**Som:** ventilador pequeno, ruído de fita, voz de Tomás e silêncio breve após o áudio.
**Pista:** símbolo círculo vazio com três riscos na parte interna da porta.

### S7 — Elevador de Serviço

Composição: elevador gradeado, correntes grossas, tubos, janelas de visão para linhas remotas de processamento. Ao se mover, a câmera descobre o tamanho do Matadouro: camadas de plataformas e centenas de estruturas sugeridas por silhuetas e emissões.

Uma janela estreita mostra céu vermelho e prédios distantes de Nova Babel, **sem levar o jogador ao exterior**. A cabine chega em acesso marcado “ALA DOS RETORNADOS — ACESSO 02”.

**Props:** botão grande de elevador, grade, correntes, placa de setor, janelas blindadas.
**Som:** relé, motor grave, batida da plataforma, ruído da instalação distante.
**Música:** um pequeno motivo de três notas surge enquanto o elevador revela a escala.

## Personagens e inimigos — assets realmente necessários

| Entidade | Obrigatório na demo | Ficha |
| --- | --- | --- |
| A Testemunha | mãos/luvas de primeira pessoa e retrato HUD padrão | [CHR-001](../characters/protagonist.md) |
| Trabalhador Convertido | frente/laterais/costas conforme técnica, idle, walk, attack, pain, death | [ENM-001](../enemies/converted-worker.md) |
| Sentinela Industrial | frente/laterais/costas, aim/shoot/cooldown, hurt, death | [ENM-002](../enemies/industrial-sentinel.md) |
| V-12 Ruptura | sprite FP: idle, pickup/equip, fire, recover, reload; flash | [WPN-001](../objects/rupture-v12.md) |
| Lídia Varela | **voz curta e/ou retrato em gravação opcional**, não NPC 3D | [CHR-002](../characters/lydia-varela.md) |
| Tomás Neri | voz em fita opcional, não NPC animado | [CHR-003](../characters/tomas-neri.md) |
| O CORO | voz administrativa e UI de terminal, não corpo visível | [CHR-005](../characters/chorus.md) |

O usuário já estabeleceu interesse em sprites de frente, lado direito/esquerdo, costas, ataque e morte. Para o jogo real, fechar direções, espelhamento e resolução só quando o teste de sprites no motor confirmar o custo.

## Inventário de assets para implementação, por prioridade

### P0 — Gameplay mínimo

- [ ] Uma sala inicial e um corredor de teste com colisão.
- [ ] Sprite da V-12 com disparo, recuo e som.
- [ ] Worker com estados mínimos e feedback de morte.
- [ ] Sentinel com mira, disparo e feedback de morte.
- [ ] Vida, munição e hit feedback na HUD.
- [ ] Portas e cobertura que bloqueiam tiros e movimento.
- [ ] Modelo de alavanca ou painel interativo; objetivo de saída.
- [ ] Iluminação e materiais base sem pós-processamento pesado.

### P1 — Identidade do nível

- [ ] Terminal com mensagens e portrait padrão.
- [ ] Maca, grade, cartazes do Consórcio, etiquetas, relógio.
- [ ] Esteiras animadas, passarelas, carrinhos e correntes.
- [ ] Reação audiovisual ao desligar a linha de separação.
- [ ] Elevador com vista em camadas e placa para L02.
- [ ] Estação de manutenção opcional e gravação de Tomás.
- [ ] Gravação de Lídia e legendas curtas.

### P2 — Após validar diversão e desempenho

- [ ] Rosto escolhido por imagem local, com estados de HUD.
- [ ] Texturas adicionais de desgaste e detalhes orgânicos.
- [ ] Ambientes remotos com silhuetas animadas no elevador.
- [ ] Sons ambientais posicionais avançados e música contextual.
- [ ] Variantes visuais de corpos, inscrições e telas secundárias.

**Distinção:** P0/P1/P2 são lotes de produção de arte e recurso, não funcionalidades que já existem no repositório.

## Plano sonoro / eventos

| ID sugerido | Evento | Característica |
| --- | --- | --- |
| AUD-L01-001 | motor distante | loop baixo, sempre ativo em áreas industriais |
| AUD-L01-002 | pingos no balde | irregular, espacial |
| AUD-L01-003 | inicialização do terminal | ruído CRT curto |
| AUD-L01-004 | falha de identidade | três bipes secos e impressora |
| AUD-L01-005 | porta hidráulica | arrasto metálico lento e batida |
| AUD-L01-006 | Worker em movimento | corrente/gancho e respiração comprimida |
| AUD-L01-007 | Worker preparando golpe | estalo de ombro distinto de passos |
| AUD-L01-008 | V-12 tiro | ataque grave, curto e poderoso, sem mascarar demais |
| AUD-L01-009 | V-12 recuperação | metal de mecanismo, cartucho |
| AUD-L01-010 | Sentinel detecta | duas notas mecânicas |
| AUD-L01-011 | Sentinel prepara tiro | pressão crescente e servo |
| AUD-L01-012 | Sentinel dispara | impulso metálico com direção clara |
| AUD-L01-013 | esteiras | motor repetitivo, roletes, corrente |
| AUD-L01-014 | linha parada | decaimento de máquinas até silêncio |
| AUD-L01-015 | voz de Lídia | curta, humana, gravada com ruído leve |
| AUD-L01-016 | voz de Tomás | fita mais antiga, um pouco distorcida |
| AUD-L01-017 | elevador | relé, motor, vibração e parada |
| AUD-L01-018 | tema de encerramento | três notas originais, discretas |

**Não criar sons com material protegido de jogos existentes.** A espingarda, chuva, gotejamento e máquinas precisam de efeitos originais ou licenças próprias. Sons de perigo têm precedência sobre música/ambiente. Oferecer ajuste independente de volume para efeitos, música e vozes quando o sistema de áudio suportar.

### Sons do primeiro inimigo — produção inicial

Os quatro efeitos originais do **Trabalhador Convertido** foram produzidos para revisão de gameplay: respiração em loop (idle), ataque com estalo de ombro antecipado (attack), grito de alerta (scream) e morte com colapso metálico (death). Os arquivos são WAV/OGG mono; a integração no C++/WebAssembly ainda é uma etapa futura. Ver [AUD-ENM-001 — especificação detalhada](../audio/enm-001-converted-worker.md). A integração precisa manter a relação com **AUD-L01-006** e **AUD-L01-007** e sincronizar o aviso do golpe com a animação.

## Narração de interface e acessibilidade

- O aviso de identidade aparece em texto, não apenas em fala.
- Os bipes de sentinela são complementados por pose/luz.
- A alavanca tem forma distinta e sinal de interação, não somente cor amarela.
- Legendas de gravações curtas e de anúncios essenciais.
- Ausência de fotografia não muda o roteiro.
- Efeitos de tela e câmera moderados com futura opção de redução.
- Não usar flicker intenso de luz ou estroboscopia para sustentar o medo.

## Contratos técnicos a validar (não decisões fechadas)

- Pipeline de imagem com atlas e transparência.
- Convenção para pivôs, escala, largura de hitboxes e alturas de renderização.
- Suporte de áudio posicional e mixagem em browser.
- Uso de luz dinâmica versus emissivos/texturas.
- Budget de sprites, texturas, partículas e tempo de frame em dispositivos-alvo.
- Resolução interna, filtro de pixels e opção de escala.
- Importação de arquivos de imagem locais apenas quando a HUD base for estável.

**Relações:** [Mapa L01](l01-discard-chamber.md) · [Encontros](l01-encounters.md) · [Direção geral](../art-direction.md) · [ART-001](../art/asset-guidelines.md) · [Objetos](../objects/environment-props.md).
