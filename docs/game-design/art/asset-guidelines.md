# ART-001 — Guia de produção de assets

**Função:** traduzir a bíblia narrativa em entregáveis para artistas e implementação C++/WebAssembly. Não é uma exigência de software ou pipeline já existente.
**Referência-mãe:** [Direção de arte](../art-direction.md).

## Identidade artística

Um FPS retrô de 1997 imaginário: desenho pixelado deliberado, geometria compacta, contraste alto, horror de fabricação e materiais repetíveis. A arte será **original**, não uma recriação de sprites, texturas, logos ou sons de Doom/Quake/Hexen.

## Entregáveis por entidade

Uma ficha de entidade deve fornecer:

1. **ID e arquivo canônico** com links cruzados.
2. **História resumida**: por que existe e quem a criou.
3. **Silhueta:** o que o jogador vê à distância, sem detalhes.
4. **Proporção e escala relativa:** pequeno, humano, pesado, colossal.
5. **Frente, perfil e costas:** pelo menos conceitos, antes dos sprites finais.
6. **Materiais e paleta:** metal, tecido, pintura, carne, vidro, fontes de luz.
7. **Estados ou animações:** apenas os necessários ao comportamento.
8. **Som e efeito:** como ameaça, objeto ou interação comunica sua presença.
9. **Uso em jogo:** cenário, colisão, ataque, pickup, interface, etc.
10. **Limites:** o que não desenhar, o que pode ser reusado e restrições de custo.

## Direções de sprites

Para personagens 2D em espaço 3D, planejar referências de frente, três quartos, lado e costas. A quantidade final de direções (por exemplo, quatro ou oito), resoluções e frames será escolhida após medir custo visual e desempenho; não impor números arbitrários agora.

**Assimetria:** braços e equipamentos diferentes exigem cuidado ao espelhar.  
**Movimento:** antecipação de golpe deve ser legível sem som.  
**Colisão:** silhueta de dano deve corresponder aproximadamente ao sprite.  
**Morte:** corpo e sangue não devem esconder inimigos vivos ou caminhos.

## Texturas e materiais

- Construir biblioteca pequena de concreto, aço, ferrugem, cerâmica, vidro, tecido e matéria orgânica.
- Reusar superfícies com decals e variações de desgaste.
- Preferir ilusão de profundidade com detalhes pintados e geometria pontual, em vez de objetos densos.
- Verificar legibilidade em resolução interna reduzida.
- Manter emissões luminosas contidas para WebGL2; evitar abuso de pós-processamento caro.

## Ambiente e narrativa

Todo cenário deve ter um **objeto-âncora**: Matadouro = esteira e terminal; Nova Babel = propaganda e transmissor; Santuário = cápsula e membrana; Núcleo = colunas de registros e máscara do Espelho.

A escolha dos objetos demonstra consequências da história. Um letreiro antigo ao lado de equipamento grotesco comunica mais que texto abstrato.

## Pipeline sugerido (não implementado)

- Referências e concept art aprovadas.
- Folha de ângulos/estados e paleta.
- Sprites, texturas ou modelo otimizado.
- Export com nomes de arquivos **em inglês** e convenção consistente.
- Atlas ou organização de quadros conforme engine.
- Teste de leitura, animação e custo real no navegador.
- Licenciamento/autoria registrado para cada asset.

**Convenção sugerida de arquivos:** categorias em inglês e kebab-case, por exemplo: enemy-converted-worker-idle-front.png, prop-identity-terminal-active.png, weapon-rupture-v12-fire-01.png. Isso é padrão proposto, não nomes já utilizados no código.

## Prioridade de arte para o vertical slice

1. Matadouro com cinco a dez materiais reutilizáveis.
2. Worker e Sentinel com silhuetas, ataques e mortes claras.
3. V-12 com disparo, recuperação, munição e impactos.
4. Terminal e retrato padrão, esteira, alavanca, armário e elevador.
5. Três classes de iluminação: ambiente, perigo e interação.
6. Sons de disparo, ataque, máquinas e sistema.

**Relações:** [Bestiário](../enemies/README.md) · [Objetos](../objects/environment-props.md) · [Roteiro L01](../narrative/opening-level.md).
