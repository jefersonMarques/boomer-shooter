# BOS-004 — O Espelho

**Local:** Núcleo, capítulo IV.
**Papel:** antagonista final, manifestação física do CORO.
**Mensagem:** copiar a aparência de alguém não significa possuir sua liberdade.
**Condição de funcionamento:** luta e narrativa idênticas usando foto escolhida ou retrato padrão.

## O corpo que a rede sempre quis

O CORO consegue guardar registros, reconstruir corpos e sincronizar milhões de processos. Mas nunca conseguiu produzir uma vontade independente. A Testemunha prova que tal consciência pode existir num corpo manufaturado — e a rede pretende se apropriar do processo, primeiro imitá-la, depois assimilá-la.

O Espelho é o protótipo final dessa tentativa: um corpo colossal, ligado por muitos cabos à Catedral de Dados. Sua máscara contém uma versão imperfeita do rosto escolhido para o protagonista.

## Design visual

**Escala:** corpo vertical monumental, cerca de quatro vezes a altura de personagem humano na arena de combate (proporção proposta).
**Silhueta:** tórax de vidro escuro e fibras, membros compridos em feixes de cabos, mãos exageradas com múltiplas articulações; uma máscara plana flutua na frente da estrutura.
**Rosto:** retrato estilizado do jogador, se disponível, com bordas incompletas e camadas levemente fora de registro. A máscara não deve ser clone hiper-realista e nem usar uma imagem de pessoa real no servidor.
**Materiais:** tubulação preta, carne em vermelho profundo, molduras de bronze e painéis CRT rachados.
**Cor:** vermelho e preto dominantes; branco aparece somente ao expor o núcleo como contraste de alvo.

### Transformação por fases

- **Imitação:** rosto central relativamente intacto; voz do CORO simultânea e organizada.
- **Fratura:** retrato fragmentado em placas ligeiramente deslocadas; pequenos olhos e bocas artificiais surgem nas fendas.
- **Silêncio:** a máscara apagada deixa à vista um núcleo luminoso desproporcionalmente pequeno, revelando a fragilidade da manifestação.

## Mecânica de confronto

1. **Setores de energia:** suportes ao redor da arena alimentam o corpo; cada um expõe ataque e oportunidade clara de dano.
2. **Golpe de membro:** um braço sobe e aponta para setor amplo do piso. A sombra e a linha luminosa avisam antes do impacto.
3. **Rajada de registro:** projéteis em forma de fragmentos luminosos cruzam a arena em padrões curtos; priorizar leitura e esquiva lateral.
4. **Fratura:** quando suportes cedem, o corpo torna-se vulnerável e libera ataques mais rápidos, mas nunca imprevisíveis.
5. **Ato final:** o órgão central abre e o jogador dá o golpe decisivo sem QTE nem tirar o controle.

## Áudio e falas

Voz do CORO começa como conjunto de muitas pessoas falando juntas, em seguida divide-se em camadas e termina quase humana. Sons de vidro rangendo, cabos tensos e baixa frequência dos suportes.

> “Nós temos seu rosto.”
>
> “Nós não temos sua escolha.”
>
> “Entregue a diferença. Nós a manteremos para sempre.”

## Queda

A máscara desaparece primeiro; depois as estruturas perdem sincronização e peso. Sistemas da Catedral de Dados silenciam. A mensagem final sobre continuidade surge apenas após a vitória. O CORO pode ter nós remotos, mas perde o comando central.

## Requisitos técnicos

Tratar rosto como textura/portrait local 2D aplicado à máscara no cliente. Suportar padrão sem foto, imagem inválida e performance em navegador. Não implementar morphing 3D realista como pré-requisito.

**Relações:** [A Testemunha](../../characters/protagonist.md) · [O CORO](../../characters/chorus.md) · [Núcleo](../../locations/core.md) · [UI facial](../../objects/face-interface.md) · [Índice de chefes](../bosses.md).
