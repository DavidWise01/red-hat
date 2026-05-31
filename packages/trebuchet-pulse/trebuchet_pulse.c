#include <stdio.h>
#include <stdint.h>
#include <math.h>

#define MOVES 27
#define WRAPS 3

typedef struct {
    double wrap[WRAPS];
    double tension;
    double compressed;
    double release;
} Pulse;

void observe(Pulse *p) {
    p->tension = 0.0;
    p->compressed = 0.0;
    p->release = 0.0;
    for (int i = 0; i < WRAPS; i++) p->wrap[i] = 0.0;
}

void load_27(Pulse *p) {
    for (int m = 0; m < MOVES; m++) {
        int w = m % WRAPS;
        double coil = sin((double)(m + 1) / MOVES * 3.1415926535);
        double accel = (double)(m + 1) / MOVES;
        p->wrap[w] += coil * accel;
        p->tension += coil * accel;
    }
}

void compress_to_zero(Pulse *p) {
    p->compressed = p->tension;
    p->tension = 0.0;
}

void release_dummy(Pulse *p) {
    p->release = p->compressed;
    p->compressed = 0.0;
}

int main(void) {
    Pulse p;
    observe(&p);
    printf("TREBUCHET PULSE SIMULATION\n");
    printf("3 wraps, 27 moves, compress to 0, release to dummy field\n\n");

    load_27(&p);
    printf("Loaded tension: %.4f\n", p.tension);
    printf("Wrap A: %.4f | Wrap B: %.4f | Wrap C: %.4f\n", p.wrap[0], p.wrap[1], p.wrap[2]);

    compress_to_zero(&p);
    printf("Compressed to zero. Stored: %.4f | live tension: %.4f\n", p.compressed, p.tension);

    release_dummy(&p);
    printf("Released into dummy field: %.4f\n", p.release);
    printf("RESET SAFE. No external target.\n");
    return 0;
}
