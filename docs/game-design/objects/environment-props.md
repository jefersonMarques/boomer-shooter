# PROP — Catálogo de objetos de cenário

**Status:** kit de referências para concept art, texturas, props e interações. Cada item tem identificador estável; migrar para ficha própria quando a complexidade justificar.
**Critério:** todo prop importante deve ter silhueta, história, material, estado e utilidade. Nem todo objeto precisa ser interativo.

## Matadouro

### PROP-001 — Maca de descarte

Chassis de ferro verde e colchão selado de vinil claro, com amarras rompidas e carrinhos com rodas pequenas. Identificação “NÃO APROVADO” marcada a quente. Aparece ao lado da Testemunha na primeira sala; **não é arma, não é item coletável**. Visual de abandono reforça a fuga.

### PROP-002 — Esteira de separação

Esteira pesada de borracha preta, guias amarelas, roletes e ganchos que passam por cima. Usa padrão repetitivo de movimento; pode bloquear caminho ou liberar a saída quando desligada. Precisa de estado parado e ativo.

### PROP-003 — Válvula de pressão

Volante amplo de metal pintado de amarelo, tubo grosso e manômetro analógico vibrando. O jogador a encontra em corredores e na fornalha; ativa uma comporta ou interrompe fluxo de vapor. Interação e feedback claros.

### PROP-004 — Etiqueta RETIDO

Adesivo vermelho com tipografia condensada e código de produção ilegível. Colado em caixas, cilindros e corpos. Conta a história de desumanização; pode ser aplicada como decal/textura.

### PROP-005 — Armário dos Pilotos

Armário de manutenção verde de duas portas, marca de três riscos dentro de um círculo vazio, tranca mecânica simples. Guarda munição ou gravação opcional. Exemplo inicial de linguagem de segredo.

## Nova Babel

### PROP-006 — Totem de propaganda

Display vertical de rua, moldura inox amassada, slogans do Consórcio interrompidos pelo CORO. Pode utilizar o retrato local escolhido para a Testemunha em estados avançados da campanha. Variantes quebrado/ativo/com aviso.

### PROP-007 — Semáforo autônomo

Sinal com caixa azul metálica, placas de rua desalinhadas e motor vibrando. Continua funcionando sem veículos; um gesto de rotina urbana fantasmagórica, sem gameplay obrigatório.

### PROP-008 — Gravador “PREGO”

Equipamento portátil cinza de áudio físico, adesivo de chave inglesa e pequenas marcas escritas à mão. Reproduz Tomás Neri, dando pistas opcionais. Não implica que ele esteja vivo em 2147.

### PROP-009 — Carrinho de servidor

Carrinho de aço com rodas grandes, suportes de vidro e garrafas de fluido. Em locais de rede ativa, alguns tubos pulsam. Objeto de cobertura leve ou obstáculo, nunca explodir sem aviso.

## Santuário

### PROP-010 — Cápsula de retorno

Coluna de vidro leitoso com correias metálicas e conexões de tecido vivo. Números de indivíduos anteriores foram riscados e reescritos. Pode conter figura estática sem jumpscare obrigatório.

### PROP-011 — Placa de nomes

Placa de bronze com fileiras comprimidas de nomes e horários, alguns repetidos em diferentes posições. Ambiente narrativo sobre cópias, sem forçar leitura de texto pequeno; usar destaque de dois nomes em prop próximo.

### PROP-012 — Membrana de comando

Órgão em forma de válvula, preso a trilhos de metal, com pulsação âmbar antes de fechar uma porta. Precisa ser claramente distinto das paredes decorativas. Pode servir de interruptor orgânico no fim do capítulo.

## Núcleo

### PROP-013 — Coluna de registros

Pilar de vidro antigo e metal preto com faces abstratas de retratos em pequenos painéis. Em uma coluna específica pode aparecer imagem local do jogador. **Não deve mostrar pessoas reais identificáveis sem asset/licença.**

### PROP-014 — Suporte de continuidade

Estrutura vazia de fixação corporal, com quatro braços mecânicos e lâmpada branca fria. Indica a tentativa do CORO de fabricar um corpo independente. Algumas unidades ganham textura danificada após o chefe.

### PROP-015 — Relógio 03:17

Relógio analógico rachado, parado na hora da Vigília dos Dezessete Segundos. Deve aparecer sutilmente em áreas antigas, não em toda sala. Reforça unidade visual sem explicar diretamente a origem do fenômeno.

## Princípios de implementação

- **Tipos:** decoração estática, animação de ambiente, interação, obstáculo/colisão e objeto narrativo.
- **Estados:** apenas o necessário por item (ex.: ativa/desativada; intacta/rompida).
- **Reuso:** variar material, desgaste e decal; evitar modelar prop do zero por nível.
- **Interação:** contorno/formato inequívoco e retorno sonoro; não esconder ações obrigatórias atrás de textura.
- **Performance:** simular movimento com ciclos de malha/textura sempre que possível; física dinâmica só quando agregar jogabilidade.

## Objetos com ficha própria

- [OBJ-001 Terminal de Identidade](identity-terminal.md)
- [OBJ-002 Retransmissor da Rede](broadcast-relay.md)
- [WPN-001 V-12 Ruptura](rupture-v12.md)
- [UI-001 Sistema de Rosto](face-interface.md)

**Relações:** [Matadouro](../locations/slaughterhouse.md) · [Nova Babel](../locations/new-babel.md) · [Santuário](../locations/sanctuary.md) · [Núcleo](../locations/core.md).
