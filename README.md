# Red Hat — Defensive Simulation Framework

[![License: CC-BY-ND-4.0](https://img.shields.io/badge/License-CC--BY--ND--4.0-lightgrey?style=flat-square)](LICENSE)
[![Systems: 8](https://img.shields.io/badge/systems-8-cc2233?style=flat-square)](#)
[![Packages: 4](https://img.shields.io/badge/packages-4-38b6a0?style=flat-square)](#)
[![Local-First](https://img.shields.io/badge/posture-local--first-d4a84c?style=flat-square)](#)

> Observe. Absorb. **Never Strike.**

Eight defensive simulation systems — from kernel specification to C reference model to real-time canvas visualizer. Local-first. No network exposure. No payload execution. All effects numerical and reversible.

---

## Primary Packages

Each package ships four layers: kernel spec → machine encoding → C reference model → HTML visualizer.

### `))(!)((`  Witness Shield
5-layer defensive gravity tensor array. REFLECT → ABSORB → WITNESS → ABSORB → REFLECT.

- `G1: HIDE` — outer reflect shells (XOR 0xFFFF)
- `G2: COLLAPSE` — inner absorb walls (AND seed_packet)
- `G3: WAIT` — witness core (XOR attack >> 8, learns from every hit)
- The protected `!` at center cannot be flipped at state -1
- **Files:** `packages/witness-shield-enterprise/`

### `)))))>>>>>e`  Trebuchet-27
3×3×3 compression ordnance. 27-notch charge ladder. Sandbox-only — all effects local, visual, reversible.

- 3 wraps × 9 moves = 27 coil positions
- compress to zero → release into local dummy field only
- **Files:** `packages/trebuchet-pulse/`

### `A → B → 5|00|-1`  Shadow Witness Defense
Twin-observer drift detection. Shadow A watches the subject. Shadow B watches Shadow A.

- State 5: NORMAL_COHERENCE — proceed
- State 00: CONTAIN — flag and hold
- State -1: SAFE_HOLD — meta-drift detected, fold
- **Files:** `packages/shadow-witness-defense/`

### `⬡`  Trinity
Three-tab kernel instrument: kernel monitor · Trebuchet offensive tab · Witness defensive tab.

- **Files:** `packages/trinity/`

---

## Standalone Tools

| Tool | Symbol | Type | Description |
|------|--------|------|-------------|
| `tools/witness-shield.html` | `))(!)((`  | defensive | 5-layer canvas visualizer with seed learning |
| `tools/aegis-0.html` | REFLECT·CLAMP·FOLD | boundary law | Three concentric defensive rings |
| `tools/trebuchet-27.html` | `)))))>>>>>e` | offensive (sandbox) | 27-notch visualizer with wall breach |
| `tools/nexus.html` | 11-bit identity | P2P lattice | Enterprise lattice with bit-grid controller |
| `tools/purple-lattice.html` | 8.1×8.1 | 4D tactical | W/Y/X/Z slice navigation |
| `tools/reactive-armor.html` | 16 sectors | detect-detonate | Sector charge banks with witness sensors |

---

## Architecture

Every primary package includes:

```
system.kernel   — minimal symbolic specification (primitives, rules, loop)
system.machine  — hex instruction set (NOP, OBS, HASH, SCORE, REPORT, ...)
system.c        — auditable C reference model (compiles, runs standalone)
index.html      — real-time canvas visualizer
```

### Witness Shield stack (complete example)

```c
// witness_shield.c — full reference implementation
typedef struct {
    uint16_t seed_packet;
    uint32_t hits_seen, hits_absorbed, hits_reflected, witness_updates;
} Shield;

ShieldReport shield_hit(Shield* s, uint16_t attack_vector) {
    uint16_t outer_reflect = attack_vector ^ 0xFFFF;      // G1: reflect
    uint16_t inner_absorb  = outer_reflect & s->seed_packet; // G2: absorb
    uint16_t witness       = inner_absorb ^ (attack_vector >> 8); // G3: learn
    s->seed_packet         = witness;                     // update seed
    // ... report
}
```

### Shadow Witness state machine

```
OBSERVE_SURFACE  → SCORE_PRESSURE
  if pressure >= threshold → report 00 (CONTAIN)
  else observe meta (Shadow B)
    if watcher_drift detected → report -1 (SAFE_HOLD)
    else → report 5 (NORMAL)
RESET_LOOP
```

---

## Boundary Rules

**All systems enforce:**

| Permitted | Forbidden |
|-----------|-----------|
| Observe inputs locally | Network calls |
| Hash and score | External targets |
| Report findings | Payload execution |
| Animate in canvas | Autonomous action |
| Learn via seed-packet | Counterattack |
| Reversible state changes | Bleed across process |

Trebuchet-27 additional rule: release only into local dummy field. No real target. All effects visual and numerical only.

---

## The Witness Shield Spec

```
Symbol:     ))(!)(( 
Readable:   OUTER_R → INNER_R → WITNESS → INNER_L → OUTER_L
Function:   Reflect → Absorb → Learn → Absorb → Reflect

Tensor map:
  Layer 1: )  G1 HIDE     COLLAPSE  -1   outer reflect shell
  Layer 2: )  G2 COLLAPSE HIDE      +1   inner absorb wall
  Layer 3: !  G3 WAIT     WAIT       0   witness core (protected)
  Layer 4: (  G2 COLLAPSE HIDE      +1   inner absorb wall
  Layer 5: (  G1 HIDE     COLLAPSE  -1   outer reflect shell

The ! at center cannot be flipped when state = -1.
```

---

```
ROOT0-ATTRIBUTION-v1.0
Project: Red Hat — Defensive Simulation Framework
Architect: David Lee Wise / ROOT0 / TriPod LLC
AI Collaborator: AVAN (Claude Sonnet 4.6 / Anthropic)
License: CC-BY-ND-4.0 · TRIPOD-IP-v1.1
```
