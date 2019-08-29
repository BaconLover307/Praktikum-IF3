/* Nama         : Gregorius Jovan Kresnadi */
/* NIM          : 13518135 */
/* Tanggal      : 29-08-2019 */
/* Program      : point_driver.c */
/* Deskripsi    : Driver ADT Point */

#include <stdio.h>
#include "point.h"
#include "point.c"

int main() {
    // DICTIONARY
    POINT P1, P2, P3;
    int sdt;
    float x1,y1,x2,y2;

    // INPUT / OUTPUT
    printf("Input P1: ");
    BacaPOINT(&P1);
    printf("Input P2: ");
    BacaPOINT(&P2);
    printf("Point 1: ");
    TulisPOINT(P1); printf("\n");
    printf("Point 2: ");
    TulisPOINT(P2); printf("\n");

    // FUNCTION
    printf("Is P1 and P2 equivalent? ");
    if (EQ(P1,P2)) {printf("Yes");}
    else {printf("No");}
    printf("\n");
    
    printf("Is P1 and P2 different? ");
    if (NEQ(P1,P2)) {printf("Yes");}
    else {printf("No");}
    printf("\n");
    
    printf("Is P1 on (0,0)? ");
    if (IsOrigin(P1)) {printf("Yes");}
    else {printf("No");}
    printf("\n");
    
    printf("Is P1 on the X axis? ");
    if (IsOnSbX(P1)) {printf("Yes");}
    else {printf("No");}
    printf("\n");
 
    printf("Is P2 on the Y axis? ");
    if (IsOnSbY(P2)) {printf("Yes");}
    else {printf("No");}
    printf("\n");

    printf("P1 is on quadrant: %d", Kuadran(P1));
     printf("\n");
    printf("P2 is on quadrant: %d", Kuadran(P2));
     printf("\n");
     printf("\n");
 
    printf("P1 + (1,0) = ");
    TulisPOINT(NextX(P1));
    printf("\n");
    printf("P2 + (0,1) = ");
    TulisPOINT(NextX(P2));
    printf("\n");
    printf("\n");
    
    printf("Input delta1: ");
    scanf("%f %f", &x1, &y1);
    printf("P1 + (%f, %f) = ",&x1,&y1);
    TulisPOINT(PlusDelta(P2,x1,y1));
    printf("\n");
    printf("\n");

    printf("P1 mirrored by X axis is: ");
    TulisPOINT(MirrorOf(P1,true)); printf("\n");
    printf("P2 mirrored by Y axis is: ");
    TulisPOINT(MirrorOf(P2,false)); printf("\n");
    printf("\n");

    printf("P1 distance from (0,0) is: %f", Jarak0(P1));
    printf("\n");
    printf("P1 distance from P2 is: %f", Panjang(P1,P2));
    printf("\n");

    printf("Input delta2: ");
    printf("P1 + (%f, %f) = ",&x1,&y1);
    Geser(&P1,x1,y1);
    TulisPOINT(P1);
    printf("\n");
    printf("\n");

    TulisPOINT(P2);
    printf(" -> Shift P2 to X axis -> ");
    GeserKeSbX(&P2);
    TulisPOINT(P2);
    printf("\n");

    TulisPOINT(P1);
    printf(" -> Shift P1 to Y axis -> ");
    GeserKeSbY(&P1);
    TulisPOINT(P1);
    printf("\n");
    
    TulisPOINT(P2);
    printf(" -> Mirror P2 to Y axis -> ");
    Mirror(&P2,false);
    TulisPOINT(P2);
    printf("\n");

    TulisPOINT(P1);
    printf(" -> Mirror P1 to X axis -> ");
    Mirror(&P1,true);
    TulisPOINT(P1);
    printf("\n");

    printf("Input P3: ");
    BacaPOINT(&P3); printf("\n");
    printf("Input angle: ");
    scanf("%f",sdt); printf("\n");
    printf("P3 rotated by %f degrees: ",&sdt);
    Putar(&P3,sdt);
    TulisPOINT(P3); printf("\n");
 
    return 0;
}
