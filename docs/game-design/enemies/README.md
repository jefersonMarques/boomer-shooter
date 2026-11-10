# Bestiário — índice de criaturas e chefes

**Status:** bíblia de conceito. Estatísticas finais, hitboxes e quantidade de quadros dependem de prototipação.
**Regra:** cada inimigo possui identidade visual original, leitura à distância, antecipação de ataques e função tática distinta.

## Inimigos comuns

| ID | Criatura | Silhueta | Função | Primeira região |
| --- | --- | --- | --- | --- |
| ENM-001 | [Trabalhador Convertido](converted-worker.md) | humanoide curvado, um braço pesado | ameaça corpo a corpo / perseguição | O Matadouro |
| ENM-002 | [Sentinela Industrial](industrial-sentinel.md) | tronco angular, braço-canhão | pressão de médio alcance | O Matadouro |
| ENM-003 | [Parasita Rastejante](crawler-parasite.md) | baixo, múltiplas patas, cabeça em arco | flanco rápido / interrupção | Nova Babel |
| ENM-004 | [Acólito do Coro](choir-acolyte.md) | alto, halo partido de antenas | suporte e ataques de área | Nova Babel / Santuário |
| ENM-005 | [Carregador de Memórias](memory-hauler.md) | grande, costas em gaiola, passos lentos | tanque, bloqueio de rotas | Santuário |

## Chefes

| ID | Encontro | Capítulo | Documento |
| --- | --- | --- | --- |
| BOS-001 | Superintendente 04 | I | [Chefes](bosses.md#bos-001--superintendente-04) |
| BOS-002 | A Torre que Escuta | II | [Chefes](bosses.md#bos-002--a-torre-que-escuta) |
| BOS-003 | Guardião de Memórias | III | [Chefes](bosses.md#bos-003--guardião-de-memórias) |
| BOS-004 | O Espelho | IV | [Chefes](bosses.md#bos-004--o-espelho) |

## Regras visuais compartilhadas

- Silhuetas identificáveis mesmo sem detalhes de textura.
- Antecipação de dano perceptível por pose e som.
- Inimigos humanoides usam sprites direcionais; quantidade de ângulos e quadros deve ser medida, não fixada cedo.
- Um estado morto precisa permanecer identificável sem confundir com inimigo vivo.
- Vermelho de alerta não é a única sinalização; ataques têm gesto/efeito próprio.
- Gore estilizado e efeitos de morte devem ter opção de redução de intensidade caso adotada nas configurações.
- Não mostrar o rosto personalizado do jogador em inimigos comuns por padrão: reservar esse motivo para o clímax.

## Combinações de combate

1. **Trabalhador + Sentinela:** combate de entrada; o primeiro força movimento e a segunda pune ficar parado.
2. **Parasita + Sentinela:** flanco em arenas abertas; sempre indicar origem sonora e visual.
3. **Carregador + Acólito:** prioridade tática (interromper suporte ou contornar tanque).
4. **Trabalhador + Carregador:** multidão e obstáculo móvel; abrir corredores de escape.

O objetivo inicial é construir **dois inimigos sólidos**, não todos simultaneamente.

**Relações:** [Direção de arte](../art-direction.md) · [Regras](../world/rules.md) · [Objetos de cenário](../objects/environment-props.md).
