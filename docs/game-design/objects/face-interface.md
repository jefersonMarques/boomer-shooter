# UI-001 — Sistema de Rosto e Identidade

**Categoria:** interface do protagonista, símbolo narrativo e recurso visual opcional.
**Propriedade-chave:** o jogo funciona integralmente sem fotografia.
**Referência do personagem:** [A Testemunha](../characters/protagonist.md).

## Experiência do jogador

Antes da campanha ou nas configurações, o jogador pode selecionar uma imagem de rosto (própria, fictícia ou outra imagem cuja utilização tenha autorização pertinente). O retrato padrão permite começar imediatamente.

A imagem selecionada é interpretada como o **rosto visual desta sessão**, não como prova de identidade real. Nada na história afirma que uma pessoa enviada na foto possui determinado histórico.

## Jornada de uso sugerida

1. Escolher “Jogar com rosto padrão” ou “Selecionar imagem”.
2. Selecionar arquivo local; apresentar orientação simples de enquadramento e política de tratamento.
3. Validar tipo, tamanho e resolução antes de decodificar; reportar falha e permitir continuar.
4. Converter para retrato estilizado com composição consistente e cores adequadas à HUD.
5. Exibir em estados de combate: neutro, dano, vida crítica, recuperação, vitória e morte.
6. Reutilizar o retrato local, quando viável, nas telas do CORO e na máscara de O Espelho.

A detecção do rosto e a construção automática de expressões são **questões técnicas em aberto**: não prometer fidelidade facial, reconhecimento automático perfeito nem animações naturalistas. O fallback pode aplicar deformações, overlays e transições simples a um retrato estático.

## Direção visual da HUD

O retrato é central, quase como um pequeno ícone vivo entre vida e munição. Bordas metálicas industriais, tipografia legível e variações de iluminação conforme dano. Evitar reproduzir exatamente a HUD de Doom.

### Estados sugeridos

| Estado | Visual | Gatilho |
| --- | --- | --- |
| Neutral | olhar frontal atento, respiração sutil | exploração |
| Alert | sobrancelhas tensionadas/overlays | detecção de inimigo |
| Hurt | desvio brusco, marca temporária | dano |
| Critical | sombra acentuada, respiração pesada | vida baixa |
| Recovery | retorno ao neutro e luz breve | cura |
| Triumph | expressão vigorosa discreta | chefe derrotado |
| Dead | retrato sem movimento e luz apagada | morte |

Valores de gatilho e duração serão definidos após testes. Usuários sensíveis a movimento devem poder reduzir efeitos.

## Privacidade e integridade

- **Padrão desejado:** processar imagem no dispositivo, em memória, sem upload.
- **Sem biometria:** não realizar verificação de pessoa, autenticação por rosto ou comparação de identidade.
- **Sem retenção por padrão:** não salvar fotografia original permanentemente; opções futuras de persistência exigem decisão e informação clara.
- **Limites:** formatos permitidos, tamanho máximo, dimensões, proteção contra arquivos corrompidos e erros de decodificação.
- **Compartilhamento/multiplayer:** exige desenho separado de consentimento, moderação, abuso e proteção de dados.
- **Moderação de experiência:** preservar opção de desabilitar imagens pessoais em telas ou compartilhamento futuro.

## A coerência dentro da ficção

Terminais exibem a imagem do jogador porque **a representação do jogo é renderizada localmente**. É uma licença diegética, não uma alegação de que O CORO acessa uma galeria de fotos real. No chefe final, uma máscara estilizada usa o retrato e seu contorno, sem reconstrução 3D obrigatória.

## Riscos

Foto mal enquadrada, rosto parcialmente oculto, múltiplas pessoas, caricatura, arquivo grande ou imagem sem rosto. Todos os casos devem resultar em tratamento gracioso, opção de ajuste manual ou rosto padrão — **nunca travar a partida**.

**Relações:** [Terminal](identity-terminal.md) · [O Espelho](../enemies/bosses.md#bos-004--o-espelho) · [Arte](../art-direction.md) · [Jogabilidade](../gameplay.md).
