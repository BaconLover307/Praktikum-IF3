#include <stdio.h>
#include "jam.h"
#include "jam.c"
int main() {
    // Kamus
    int hh,mm,ss;
    long N;
    JAM J2;

    scanf("%d", &N);
    N = N % 86400;
    // ALOGRITMA
    hh = N / 3600;
    mm = (N % 3600) / 60;
    ss = (N % 3600) % 60;
    J2 = MakeJAM(hh,mm,ss);
    TulisJAM(J2);
}

