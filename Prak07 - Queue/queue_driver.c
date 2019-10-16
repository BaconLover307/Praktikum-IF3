#include <stdio.h>
#include "prioqueuechar.h"

int main()
{
    PrioQueueChar Q;
    CreateEmpty(&Q,10);
    infotype X;
    Prio(X) = 2;
    Info(X) = 'o';
    Add(&Q,X);
    Prio(X) = 2;
    Info(X) = 'd';
    Add(&Q,X);
    Prio(X) = 3;
    Info(X) = 'n';
    Add(&Q,X);
    Prio(X) = 1;
    Info(X) = 'c';
    Add(&Q,X);
    Prio(X) = 4;
    Info(X) = 'g';
    Add(&Q,X);
    Prio(X) = 2;
    Info(X) = 'i';
    Add(&Q,X);

    PrintPrioQueueChar(Q);
    return 0;
}
