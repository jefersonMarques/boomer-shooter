# Jogabilidade e escopo de produção

**Status:** proposta de design; números e ordem sujeitos a prototipação.

## Experiência-alvo

FPS de ritmo rápido e brutal, com deslocamento responsivo, exploração curta entre combates, segredos, armas marcantes e inimigos de leitura imediata.

**Loop principal:** entrar em um espaço → entender a ameaça → movimentar e combater → encontrar recursos ou segredos → desbloquear o próximo espaço → descobrir um fragmento da história.

## Princípios

1. **Diversão antes do conteúdo.** Uma sala excelente vale mais que cinco fases medianas.
2. **Movimentação primeiro.** WASD, mouse look, colisões e aceleração precisam ser agradáveis.
3. **Armas com identidade.** Cada arma deve ter função clara, som, recuo e feedback reconhecíveis.
4. **Inimigos complementares.** Comportamentos combinados geram variedade sem exigir dezenas de modelos.
5. **Exploração recompensadora.** Segredos e rotas secundárias concedem recursos, vantagens ou lore.
6. **Sem interrupções extensas.** Objetivos narrativos podem ser compreendidos durante a ação.
7. **Desempenho no navegador.** Evitar efeitos ou processamento que comprometam a experiência em WebAssembly/WebGL2.

## Mecânicas pretendidas

- Movimentação ágil, corrida, strafing e controles precisos.
- Armas de curta, média e longa distância; economia de munição simples.
- Reações de impacto, dano claramente comunicado e mortes visuais marcantes.
- Inimigos com estados idle, patrol (quando necessário), chase, attack, pain e death.
- Portas, interruptores, chaves, elevadores simples e salas secretas.
- Arena de chefe com padrões legíveis e mudança de comportamento entre fases.
- Salvamento/progresso, configurações e acessibilidade conforme maturidade do produto.

O protótipo atual é um **bootstrap técnico**, não um jogo com todas essas mecânicas.

## Sistema de rosto personalizado

O usuário pode escolher uma imagem de rosto, inclusive fictícia, sem prova biométrica de identidade.

### Primeira implementação

- Carregar arquivo de imagem no cliente.
- Validar formato, tamanho e dimensões; tratar erros sem travar o jogo.
- Preparar um retrato 2D estilizado na HUD.
- Aplicar expressões simples ligadas aos eventos de jogo.
- Oferecer um rosto padrão quando não houver foto ou a imagem não puder ser processada.
- Preferir processamento local, sem upload ao servidor por padrão.

### Evoluções, não bloqueadoras do vertical slice

- Rosto exibido em terminais e cartazes do mundo.
- Uso narrativo do rosto em revelações e cenas do CORO.
- Versão grotesca do retrato no chefe final.
- Visualização em partidas multiplayer.

### Cuidados

- Não assumir que a imagem identifica a pessoa que joga.
- Explicar a finalidade e o tratamento da imagem; obter a escolha explícita de quem a envia.
- Não manter nem distribuir imagens sem necessidade e sem consentimento pertinente.
- Ter mecanismos para limitar conteúdo indevido, especialmente se imagens forem compartilhadas ou usadas em multiplayer.
- A foto não pode ser requisito de progressão e não deve exigir serviço externo para funcionar.

## Estrutura da campanha

A proposta narrativa tem **4 capítulos**, com **8–12 fases no total**, duração desejada de **3–5 horas**, **6–8 armas**, **8–12 tipos de inimigos** e chefes. São **metas exploratórias**, não estimativas de custo, cronograma ou volume aprovado para produção.

O multiplayer será considerado somente após o núcleo single-player funcionar. Networking, moderação de imagens, custos de infraestrutura, sincronização e antiabuso aumentam bastante o escopo.

## Primeiro vertical slice — O Matadouro

**Meta:** comprovar em uma fase curta que o jogo é divertido e que o estilo funciona no navegador.

### Conteúdo mínimo

- Uma fase industrial pequena, com início, objetivo, arena e saída.
- Movimentação com colisão consistente.
- Uma arma principal com disparo, munição, recuo e impactos.
- Dois arquétipos de inimigos: próximo e médio alcance.
- Saúde, dano, morte e reinício.
- HUD com retrato padrão; foto local e reações se a camada técnica estiver estável.
- Uma mensagem ambiental ou terminal que estabelece o conflito com O CORO.
- Build WebAssembly testável em navegador e build nativo para desenvolvimento.

### Critérios de validação

- O fluxo completo da fase pode ser concluído sem ferramentas de depuração.
- Controles, hit feedback e inimigos produzem uma experiência divertida em sessões curtas.
- O jogo mantém desempenho adequado no hardware/navegadores definidos nos testes.
- Erros de imagem não impedem jogar com avatar padrão.
- O estilo visual é reconhecível sem replicar assets de jogos existentes.
- O código mantém lógica de jogo separada das integrações de plataforma.

## Sequência de desenvolvimento sugerida

1. Finalizar movimentação e colisão sobre o bootstrap já existente.
2. Introduzir combate e feedback de uma arma.
3. Implementar IA simples e dois arquétipos de inimigos.
4. Montar a fase demonstrativa “O Matadouro”.
5. Integrar HUD reativa e retrato opcional local.
6. Ajustar desempenho, áudio e qualidade de experiência.
7. Só então produzir fases adicionais, arsenal e chefes.
8. Avaliar multiplayer como iniciativa separada.

## Riscos de produção

| Risco | Mitigação |
| --- | --- |
| Escopo narrativo maior que a capacidade de produção | Validar vertical slice antes da campanha completa |
| Arte 2D direcional multiplicar carga de assets | Reutilizar rigs/templates e limitar estados iniciais |
| Foto do usuário gerar problemas de privacidade | Processar localmente por padrão e usar fallback |
| Renderização/efeitos reduzirem FPS no navegador | Medir cedo em WebAssembly/WebGL2 |
| Multiplayer atrasar a experiência principal | Adiar até single-player estabilizado |
| Referências confundidas com licença de conteúdo | Criar assets originais e registrar licenças |

A documentação estabelece o objetivo criativo, mas não substitui especificações técnicas, testes de usabilidade, estimativas nem planejamento de produção.
