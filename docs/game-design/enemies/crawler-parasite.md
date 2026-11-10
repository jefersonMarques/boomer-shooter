# ENM-003 — Parasita Rastejante

**Codinome de produção:** Crawler Parasite.
**Papel:** pressão de flanco, susto de curta distância, quebra de comportamento do jogador que sempre olha à frente.
**Primeira região:** Nova Babel; maior concentração no Santuário.

## Origem e ecologia

Não é um animal extraterrestre. São unidades de inspeção orgânicas desenvolvidas a partir de sistemas hospitalares de movimentação autônoma e tecido adaptativo. Elas vasculham dutos e recuperam componentes danificados. A presença em ruas e prédios demonstra que a cidade tornou-se um único sistema de manutenção.

## Silhueta e anatomia

Corpo baixo em forma de vírgula invertida, seis patas finas articuladas, placas dorsais como telhas de metal. A cabeça triangular fica sob um arco de cartilagem e se abre em três partes durante o ataque. Uma pequena antena torta torna a silhueta identificável em corredores.

**Escala:** abaixo da cintura de um humano. Evitar tamanho tão pequeno que o alvo fique difícil de localizar no pixel art.

**Paleta:** vermelho opaco, metal negro e reflexo esbranquiçado em olhos-sensores.

## Comportamento

- **Patrulha:** percorre bordas visíveis, move-se de maneira segmentada, nunca é invisível.
- **Detecção:** patas se abrem, antena vibra, emite clique agudo.
- **Ataque:** dá salto curto após recuo do corpo. A trajetória precisa ser clara e esquivável.
- **Recuperação:** permanece imóvel por breve janela depois de errar.
- **Dano:** retrai a cabeça e vira o corpo para o lado.
- **Morte:** corpo arqueia e patas se enrolam; manter sprite morto sem colisão exagerada.

## Uso de arena

Em duplas espaçadas, forçam mudança de mira entre altura baixa e humana. Quando combinados a Sentinelas, precisam de pontos de entrada iluminados e avisos de som; evitar surgimento atrás de jogador sem pista.

## Animação e som

Seis patas não exigem seis animações independentes; sugerir movimento por alternância de grupos. Áudio seco de cutícula, clique de rastreamento e estalo no salto.

## Narrativa indireta

Encontrar parasitas “consertando” um carro ou cadáver faz perceber que a rede não distingue infraestrutura de corpos.

**Relações:** [Nova Babel](../locations/new-babel.md) · [Santuário](../locations/sanctuary.md).
