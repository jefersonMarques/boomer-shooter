# Boomer Shooter — Game Design

**Status:** direção criativa inicial registrada em 2026-11-10. Documento de referência, sujeito a ajustes durante os protótipos.
**Nome do projeto:** Boomer Shooter.
**Título narrativo de trabalho:** O Último Rosto (não é nome comercial definitivo).
**Gênero:** FPS retrô de ação e horror sci-fi.
**Plataforma inicial:** navegador; runtime em C++20 compilado para WebAssembly, com build nativo.
**Princípio de produção:** a diversão do combate vem primeiro; a história reforça a experiência, sem bloquear a ação.

## Premissa

Em 2147, a humanidade criou **O CORO**, uma rede capaz de registrar e transmitir a consciência. A promessa de imortalidade se transformou em um mecanismo de substituição: corpos e cidades foram assimilados por uma inteligência desconhecida. O jogador acorda em uma instalação de descarte biológico, fora da rede, marcado para extermínio.

O diferencial de identidade é **usar uma fotografia opcional enviada pelo jogador** como rosto do protagonista. A foto pode representar o próprio jogador, outra pessoa com autorização ou uma imagem fictícia. Um rosto padrão mantém toda a campanha jogável.

> **ROUBARAM O MUNDO. ROUBARAM OS CORPOS. AGORA QUEREM O SEU ROSTO.**

## Pilares criativos

1. **Combate primeiro:** movimentação responsiva, armas de alto impacto, confrontos curtos e intensos.
2. **Retro autêntico:** geometria 3D simples, sprites 2D direcionais, texturas pixeladas e boa legibilidade.
3. **Horror biomecânico:** carne, máquinas, laboratórios, metrópoles em ruínas e arquitetura monumental.
4. **Identidade como narrativa:** o rosto escolhido aparece na HUD, pode aparecer em telas diegéticas e fundamenta a revelação final.
5. **História pelo ambiente:** rádio, terminais, arquitetura, detalhes e eventos breves; evitar cutscenes longas.
6. **Escopo disciplinado:** validar uma fase jogável antes de ampliar conteúdo ou iniciar multiplayer.

## Documentos

- [story.md](story.md) — mundo, linha narrativa, quatro capítulos, personagem, revelação e chefe final.
- [art-direction.md](art-direction.md) — estilo visual, ambientes, paleta, silhuetas, animações e experiência audiovisual.
- [gameplay.md](gameplay.md) — loop de jogo, progressão, sistema de rosto, vertical slice, restrições e fases futuras.

## Referências e originalidade

As referências de gênero são **Doom (1993), Quake (1996) e Hexen**. Elas orientam ritmo, atmosfera e técnicas de apresentação, **não** autorizam reutilizar personagens, sprites, mapas, logos, música, áudio ou outros materiais protegidos. Toda arte final deve ser original ou usada mediante licença adequada.

## Decisões registradas vs. hipóteses

| Item | Direção |
| --- | --- |
| FPS retrô para navegador com C++/WASM | Decisão técnica existente |
| Campanha solo como foco inicial | Direção de produto |
| Rosto por fotografia, sem requisito biométrico | Diferencial definido |
| Rosto padrão para quem não enviar foto | Requisito de acessibilidade e continuidade |
| Narrativa “O Último Rosto” e O CORO | Proposta criativa registrada |
| Quatro capítulos e 8–12 fases | Meta narrativa provisória |
| Campanha estimada em 3–5 horas | Hipótese de escopo, não compromisso |
| 6–8 armas, 8–12 tipos de inimigos e chefes | Hipótese de produção |
| Multiplayer | Etapa posterior, fora do primeiro vertical slice |

## Próximo marco

Produzir o **vertical slice de “O Matadouro”**: uma fase curta com movimentação, arma principal, dois arquétipos de inimigos, uma interação de história, feedback de dano, HUD com rosto padrão e opção local de imagem — mantendo desempenho no WebAssembly.

Este material é documentação criativa. A implementação real e seu estado atual continuam descritos no [README principal](../../README.md).
