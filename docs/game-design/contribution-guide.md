# Guia editorial da bíblia de produção

**Objetivo:** manter a documentação rica em detalhes, auditável e útil para escritores, designers, artistas e programadores.

## Regra central: cada “coisa” tem fonte própria

Uma personagem, criatura, local, objeto narrativo ou sistema importante deve ter uma **ficha canônica** em arquivo Markdown específico, com ID permanente e links para documentos relacionados. Agrupar objetos menores em um catálogo é aceitável quando não exigirem narrativa ou comportamento próprio; criar ficha ao ganharem importância.

O documento principal [story.md](story.md) descreve o arco e **aponta para as fichas**, evitando manter dezenas de descrições duplicadas.

## Organização

- [world/](world/glossary.md): cronologia, regras, facções e glossário.
- [characters/](characters/protagonist.md): protagonista, antagonistas, aliados e figuras relevantes.
- [locations/](locations/slaughterhouse.md): áreas e ambientes com história, percurso e arte.
- [enemies/](enemies/README.md): inimigos, estados e chefes.
- [objects/](objects/environment-props.md): armas, terminais, transmissor, HUD e props.
- [narrative/](narrative/campaign-beats.md): sequência de fases, falas, revelações e roteiro jogável.
- [art/](art/asset-guidelines.md): requisitos de produção visual.

## Template obrigatório para novos registros

1. **Título e ID** (CHR, LOC, ENM, BOS, OBJ, WPN, UI, PROP, WLD, NAR ou ART).
2. **Papel na história e na jogabilidade**, com primeira aparição.
3. **Origem, cronologia e relações** com fatos confirmados do mundo.
4. **Descrição visual objetiva:** silhueta, escala, materiais, cores, desgaste, movimento.
5. **Descrição sensorial:** iluminação, som, efeitos e clima, quando aplicável.
6. **Comportamentos/interações** e estados necessários ao jogo.
7. **Cena ou uso concreto** no nível em que aparece.
8. **Segredos, pistas, detalhes opcionais** que ajudem narrativa ambiental.
9. **Limitações técnicas e de escopo**; não confundir sugestão com implementação.
10. **Links relativos** para ficheiros dependentes.

A ficha pode omitir campos que não se aplicam, mas **não pode ser apenas um nome e duas frases** quando a entidade participa ativamente do jogo.

## Cânone e mudanças

- **Definido:** o que a história já estabelece como verdade interna.
- **Proposto:** direção artística, armamento, mecânica ou dimensão ainda a validar.
- **Reservado:** informação desconhecida que não deve ganhar resposta casual (por exemplo, origem da voz de 2123).
- Quando houver mudança de cânone, atualizar ficha principal, cronologia, revelações e roteiros afetados no mesmo conjunto de alterações.
- Se uma mudança impactar segurança, performance, privacidade, escalabilidade ou trabalho substancial, registrar riscos e pedir aprovação antes de implementar sistemas do jogo.

## Convenção

Diretórios e arquivos em inglês, minúsculos e com hífens. IDs estáveis não são reciclados. Títulos narrativos e material descritivo podem estar em português brasileiro. Arquivos devem usar links relativos verificáveis, sem caminhos locais de máquina.

## Checklist antes de fechar uma contribuição

- O conceito é original e não copia IP de jogos de referência?
- Os fatos respeitam [world/rules.md](world/rules.md) e [world/timeline.md](world/timeline.md)?
- Existe link no índice e na história principal para entidades importantes?
- O objeto/personagem tem leitura visual suficiente para design de asset?
- A cena funciona sem a foto personalizada?
- A primeira implementação é realista para C++/WebAssembly?
- Regras narrativas estão separadas de hipóteses de implementação?

Este guia deve acompanhar as próximas expansões do universo.
