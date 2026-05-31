#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/*
 * Witness Shield: ))(!)((
 * Defensive local simulation. No network, no exploit logic, no outbound action.
 */

typedef struct {
    int8_t layer[5];              /* {-1, +1, 0, +1, -1} */
    uint16_t seed_packet;         /* witness scar memory */
    uint32_t hits_seen;
    uint32_t hits_absorbed;
    uint32_t hits_reflected;
    uint32_t witness_updates;
    bool active;
} Shield;

typedef struct {
    uint16_t input;
    uint16_t reflected_right;
    uint16_t absorbed_right;
    uint16_t witness_before;
    uint16_t witness_after;
    uint16_t absorbed_left;
    uint16_t reflected_left;
    bool neutralized;
} ShieldReport;

static void shield_init(Shield *s, uint16_t seed) {
    memset(s, 0, sizeof(*s));
    s->layer[0] = -1;
    s->layer[1] = +1;
    s->layer[2] = 0;
    s->layer[3] = +1;
    s->layer[4] = -1;
    s->seed_packet = seed;
    s->active = true;
}

static ShieldReport shield_hit(Shield *s, uint16_t attack) {
    ShieldReport r;
    memset(&r, 0, sizeof(r));

    if (!s || !s->active) {
        r.input = attack;
        r.neutralized = false;
        return r;
    }

    r.input = attack;
    r.witness_before = s->seed_packet;

    /* Outer right collapse shell: local reflection telemetry. */
    r.reflected_right = (uint16_t)(attack ^ 0xFFFFu);

    /* Inner right hide wall: consume known pattern bits. */
    r.absorbed_right = (uint16_t)(attack & s->seed_packet);

    /* Witness core: compress scar into seed memory. */
    s->seed_packet = (uint16_t)(s->seed_packet ^ (attack >> 8));
    r.witness_after = s->seed_packet;

    /* Inner left hide wall rechecks after learning. */
    r.absorbed_left = (uint16_t)(attack & s->seed_packet);

    /* Outer left collapse shell: local reflection telemetry. */
    r.reflected_left = (uint16_t)(attack ^ 0xFFFFu);

    s->hits_seen++;
    if (r.absorbed_right || r.absorbed_left) s->hits_absorbed++;
    if (r.reflected_right || r.reflected_left) s->hits_reflected++;
    s->witness_updates++;

    r.neutralized = true;
    return r;
}

static void print_report(const ShieldReport *r) {
    printf("input=0x%04x reflectR=0x%04x absorbR=0x%04x witness:%04x->%04x absorbL=0x%04x reflectL=0x%04x neutralized=%s\n",
           r->input,
           r->reflected_right,
           r->absorbed_right,
           r->witness_before,
           r->witness_after,
           r->absorbed_left,
           r->reflected_left,
           r->neutralized ? "true" : "false");
}

int main(void) {
    Shield shield;
    shield_init(&shield, 0x00F0u);

    printf("=== Witness Shield ))(!)(( ===\n");
    printf("mode=defensive_simulation boundary=local_only seed=0x%04x\n\n", shield.seed_packet);

    uint16_t samples[] = {0x1200, 0x12F0, 0xAA55, 0x12F0, 0x00F0};
    size_t count = sizeof(samples) / sizeof(samples[0]);

    for (size_t i = 0; i < count; i++) {
        ShieldReport r = shield_hit(&shield, samples[i]);
        print_report(&r);
    }

    printf("\nsummary hits_seen=%u absorbed=%u reflected=%u witness_updates=%u final_seed=0x%04x\n",
           shield.hits_seen,
           shield.hits_absorbed,
           shield.hits_reflected,
           shield.witness_updates,
           shield.seed_packet);

    return 0;
}
