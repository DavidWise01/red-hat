# Witness Shield Enterprise Package

Files:

- `index.html` — local-first visual shield simulator
- `shield.md` — polished defensive specification
- `witness_shield.kernel` — minimal kernel spec
- `witness_shield.machine` — fictional machine encoding
- `witness_shield.c` — auditable C reference model

Run C model:

```bash
gcc -std=c99 -Wall -Wextra -O2 -o witness_shield witness_shield.c
./witness_shield
```

Open `index.html` in a browser for the local simulator.
