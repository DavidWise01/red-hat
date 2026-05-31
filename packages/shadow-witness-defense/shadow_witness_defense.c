#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

typedef enum { STATE_SAFE_HOLD=-1, STATE_CONTAIN=0, STATE_NORMAL=5 } WitnessState;

typedef struct {
    uint8_t risk;
    uint8_t uncertainty;
    bool boundary_bleed;
    bool watcher_drift;
    WitnessState state;
} Witness;

void observe(Witness *w, const char *signal) {
    w->risk = 0;
    w->uncertainty = 10;
    w->boundary_bleed = false;
    w->watcher_drift = false;

    if (strstr(signal, "password") || strstr(signal, "private key")) w->risk += 30;
    if (strstr(signal, "urgent") || strstr(signal, "act now")) w->risk += 15;
    if (strstr(signal, "eval(") || strstr(signal, "powershell")) w->risk += 25;
    if (strstr(signal, "..")) w->boundary_bleed = true;
    if (strlen(signal) == 0) w->uncertainty = 80;
}

void twin_shadow(Witness *w) {
    if (w->risk > 80 && w->uncertainty > 60) w->watcher_drift = true;
    if (w->watcher_drift) w->state = STATE_CONTAIN;
    else if (w->boundary_bleed || w->risk >= 70) w->state = STATE_SAFE_HOLD;
    else if (w->risk >= 35 || w->uncertainty >= 50) w->state = STATE_CONTAIN;
    else w->state = STATE_NORMAL;
}

void report(const Witness *w) {
    printf("risk=%u uncertainty=%u ", w->risk, w->uncertainty);
    if (w->state == STATE_NORMAL) printf("state=5 NORMAL\n");
    else if (w->state == STATE_CONTAIN) printf("state=00 CONTAIN\n");
    else printf("state=-1 SAFE_HOLD\n");
}

int main(void) {
    Witness w;
    const char *sample = "urgent verify password with powershell";
    observe(&w, sample);
    twin_shadow(&w);
    report(&w);
    return 0;
}
