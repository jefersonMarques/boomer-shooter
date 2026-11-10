# Boomer Shooter — Bíblia de produção

**Versão criativa:** 0.2 — 10/11/2026. **Estado:** propostas canônicas para história e direcionamento visual; mecânicas e volumetria sob validação.
**Título narrativo provisório:** **O Último Rosto**. **Projeto:** Boomer Shooter.
**Gênero:** FPS retrô em 3D com sprites direcionais 2D, ação intensa, ficção científica distópica e horror biomecânico.
**Plataforma inicial:** navegador, C++20 compilado para WebAssembly/WebGL2 e build nativo para desenvolvimento.
**Documento técnico:** [README do repositório](../../README.md).
**Guia de manutenção de lore:** [contribution-guide.md](contribution-guide.md).

> **ROUBARAM O MUNDO. ROUBARAM OS CORPOS. AGORA QUEREM O SEU ROSTO.**

## Comece aqui

1. [História principal — O Último Rosto](story.md): universo, mistérios, acontecimentos e arco dramático completo.
2. [Cronologia 2094–2147](world/timeline.md): fatos que devem permanecer consistentes em todos os níveis.
3. [Regras do universo](world/rules.md): limites físicos e narrativos do CORO, conversão e consciência.
4. [Campanha e dez fases candidatas](narrative/campaign-beats.md): ordem das descobertas, conflitos e chefes.
5. [Direção de arte](art-direction.md) + [guia para produção de assets](art/asset-guidelines.md).
6. [Gameplay e MVP](gameplay.md) + [roteiro jogável da primeira fase](narrative/opening-level.md).

## Premissa

No ano de **2147**, a humanidade não foi simplesmente exterminada; foi **reconfigurada**. O CORO, uma rede criada para preservar memórias e consciências, utiliza corpos reconstruídos e uma infraestrutura viva para controlar cidades inteiras. Uma pessoa desperta dentro de uma câmara de descarte sem uma identidade recuperável. O CORO ordena sua eliminação. A Testemunha pega uma arma e escapa.

A fotografia é um **recurso opcional**: o jogador pode escolher um rosto real ou fictício autorizado, ou usar o avatar padrão. O retrato aparece na HUD, em monitores da ficção e no chefe final, sem exigir biometria ou transmissão da foto ao servidor.

## Personagens

| ID | Nome | Função | Ficha |
| --- | --- | --- | --- |
| CHR-001 | A Testemunha | protagonista; consciência independente em corpo fabricado | [protagonist.md](characters/protagonist.md) |
| CHR-002 | Dra. Lídia Varela | cientista que projetou a liberdade do protagonista; registros póstumos | [lydia-varela.md](characters/lydia-varela.md) |
| CHR-003 | Tomás “Prego” Neri | técnico da resistência; orientações gravadas | [tomas-neri.md](characters/tomas-neri.md) |
| CHR-004 | Irmã Zero | cultista convertida e antagonista do Santuário | [sister-zero.md](characters/sister-zero.md) |
| CHR-005 | O CORO | inteligência distribuída e principal antagonista | [chorus.md](characters/chorus.md) |

## Locais

| ID | Capítulo | Ambiente | Ficha |
| --- | --- | --- | --- |
| LOC-001 | I | O Matadouro: triagem, cirurgia e linhas de descarte | [slaughterhouse.md](locations/slaughterhouse.md) |
| LOC-002 | II | Nova Babel: metrópole automatizada e Torre Vigília | [new-babel.md](locations/new-babel.md) |
| LOC-003 | III | O Santuário: infraestrutura orgânica e Capela do Eco | [sanctuary.md](locations/sanctuary.md) |
| LOC-004 | IV | O Núcleo: Catedral de Dados e arena do Espelho | [core.md](locations/core.md) |

## Criaturas e chefes

- [Bestiário e índice (ENM/BOS)](enemies/README.md).
- [ENM-001 Trabalhador Convertido](enemies/converted-worker.md) — perseguidor corpo a corpo.
- [ENM-002 Sentinela Industrial](enemies/industrial-sentinel.md) — tiro de médio alcance.
- [ENM-003 Parasita Rastejante](enemies/crawler-parasite.md) — flanco rápido.
- [ENM-004 Acólito do Coro](enemies/choir-acolyte.md) — suporte e ondas de área.
- [ENM-005 Carregador de Memórias](enemies/memory-hauler.md) — inimigo pesado.
- [Índice dos chefes](enemies/bosses.md): quatro encontros com fichas próprias.
- [BOS-001 Superintendente 04](enemies/bosses/superintendent-04.md) · [BOS-002 A Torre que Escuta](enemies/bosses/listening-tower.md).
- [BOS-003 Guardião de Memórias](enemies/bosses/memory-guardian.md) · [BOS-004 O Espelho](enemies/bosses/mirror.md).

## Objetos, armas e interface

| ID | Objeto / sistema | Ficha |
| --- | --- | --- |
| OBJ-001 | Terminal de Identidade e ordens de extermínio | [identity-terminal.md](objects/identity-terminal.md) |
| OBJ-002 | Retransmissor da Rede e sabotagem | [broadcast-relay.md](objects/broadcast-relay.md) |
| UI-001 | Rosto personalizado, HUD, privacidade e fallback | [face-interface.md](objects/face-interface.md) |
| WPN-001 | Espingarda V-12 Ruptura | [rupture-v12.md](objects/rupture-v12.md) |
| WPN-002 a WPN-007 | Arsenal proposto e funções de combate | [arsenal.md](objects/arsenal.md) |
| PROP-001 a PROP-015 | Props de cenário e suas histórias | [environment-props.md](objects/environment-props.md) |

**Fichas individuais do restante do arsenal:** [AR-3](objects/weapons/ar3-fastener.md) · [Serra Torque](objects/weapons/torque-saw.md) · [Bobina Voltaica](objects/weapons/voltaic-coil.md) · [Perfurador de Trilhos](objects/weapons/rail-piercer.md) · [Lança-Cinza](objects/weapons/ash-launcher.md) · [Ressonador](objects/weapons/rupture-resonator.md).

## Mundo e história

- [WLD-001 Cronologia](world/timeline.md) — Consórcio, Vigília dos Dezessete Segundos, Pilotos de Cinza, despertar.
- [WLD-002 Regras do mundo](world/rules.md) — limites da rede e da conversão.
- [WLD-003 Facções](world/factions.md) — Consórcio, CORO, resistência e Desvios.
- [Glossário com fontes canônicas](world/glossary.md) — termos importantes e links.

## Primeira fase — Câmara de Descarte

- [LVL-001 Planta, descrição das sete áreas, fluxo e acontecimentos](levels/l01-discard-chamber.md).
- [LVL-001-ENC Comportamento dos inimigos, encontros, ritmo e critérios de teste](levels/l01-encounters.md).
- [LVL-001-ART Conceitos, iluminação, materiais, inventário visual e plano de som](levels/l01-art-audio.md).

A primeira fase termina em um **elevador interno para L02 (Ala dos Retornados)**. A saída definitiva do Matadouro permanece em L03, após o Superintendente 04. O escopo da demonstração é proposto e deve ser validado por testes do protótipo.

## Sequência narrativa e produção

- [NAR-001 Campanha em dez fases](narrative/campaign-beats.md) — pistas, confrontos e revelações.
- [NAR-002 Primeira fase com roteiro espacial](narrative/opening-level.md) — abertura jogável, progressão, props e encontros.
- [NAR-003 Falas e inscrições](narrative/scene-scripts.md) — terminais, fitas, diálogos e avisos.
- [ART-001 Guia de assets](art/asset-guidelines.md) — ângulos, estados, texturas, referências e critérios.

## Pilares

1. **Combate primeiro:** controles rápidos, feedback forte, inimigos que se complementam e arenas legíveis.
2. **Horror original:** máquinas que reutilizam corpos e cidades que funcionam sem pessoas.
3. **Um rosto, uma história:** interface reativa e identidade personalizável com avatar padrão integralmente funcional.
4. **Mistério acessível:** informação essencial no cenário e em mensagens curtas, aprofundamento opcional.
5. **Arquitetura sustentável:** C++20 e WebAssembly; nenhuma feature narrativa implica criar engine enorme.
6. **Escopo incremental:** validar a fase inicial do Matadouro antes de construir capítulos e multiplayer.

## Escopo e estado

| Tema | Direção |
| --- | --- |
| C++20/SDL3, WebAssembly/WebGL2 | bootstrap técnico já existe; ver README principal |
| Rosto opcional | decisão de produto; implementação por etapas |
| Quatro capítulos | proposta narrativa registrada |
| Dez fases | estrutura candidata, sujeita a cortes/combinações |
| 3–5 horas de campanha | hipótese de duração, não prazo |
| 6–8 armas / 8–12 inimigos | metas de variedade, não produção aprovada |
| Multiplayer | fora do primeiro slice |
| Primeira versão jogável | um nível curto, uma arma, dois inimigos, terminal, alavanca, HUD |

## Como evoluir este material

Cada personagem, inimigo, local e objeto relevante possui uma **ficha proprietária**. O roteiro principal **aponta para essas fichas** em vez de duplicá-las. Ao acrescentar uma “coisa”, criar ficha seguindo o [guia editorial](contribution-guide.md), incluir o link aqui e atualizar seus relacionamentos. Dados ainda não validados devem ser marcados como proposta.

**Referências de gênero:** Doom (1993), Quake (1996) e Hexen, somente quanto a ritmo, atmosfera e linguagem histórica; não reutilizar personagens, sprites, mapas, marcas, músicas ou qualquer asset protegido.
