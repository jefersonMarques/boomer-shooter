# Audio — Sound design e assets

**Projeto:** Boomer Shooter / O Último Rosto.
**Status:** direção sonora e efeitos prototipados; a integração no runtime C++/WebAssembly ainda não foi realizada.
**Regra:** efeitos originais, legíveis no combate e compatíveis com áudio posicional no navegador.

## Fichas de som por entidade

| ID | Entidade | Ficha | Disponibilidade |
| --- | --- | --- | --- |
| AUD-ENM-001 | ENM-001 Trabalhador Convertido | [enm-001-converted-worker.md](enm-001-converted-worker.md) | quatro efeitos produzidos: idle, attack, scream, death; WAV/OGG entregues separadamente, binários ainda não importados para o repositório |

## Padrão inicial

- **Export master:** WAV PCM 16-bit, 48 kHz, mono para fontes posicionais.
- **Formato otimizado:** OGG Vorbis para distribuição; manter WAV para edição e contingência.
- **Nomeação:** `enemy-converted-worker-<event>.ogg` e correspondente `.wav`, sempre em inglês.
- **Pasta planejada no jogo:** `assets/audio/enemies/converted-worker/`; criar/importar na fase de integração.
- **Uso:** distinguir `loop` (ambiente/idle) de `one-shot` (detecção, golpe, morte).
- **Mixagem:** sons de ameaça devem permanecer audíveis sobre música, chuva e máquinas; limitar vozes simultâneas, usar atenuação por distância e testar em caixas comuns e fones.
- **Fonte:** síntese procedural original; nenhuma gravação de terceiros, arquivo protegido ou som de jogos de referência foi utilizado.
- **Cuidado:** não assumir que o protótipo já reproduz os efeitos; validar decodificação OGG, latência, eventos e controle de volume no WebAssembly.

**Documentos relacionados:** [Guia de áudio/arte do nível 01](../levels/l01-art-audio.md) · [Bestiário](../enemies/README.md) · [Direção de arte](../art-direction.md).
