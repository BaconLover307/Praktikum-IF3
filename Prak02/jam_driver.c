/* Nama         : Gregorius Jovan Kresnadi */
/* NIM          : 13518135 */
/* Tanggal      : 29-08-2019 */
/* Program      : jam_driver.c */
/* Deskripsi    : Driver ADT Jam */

#include <stdio.h>
#include "jam.h"
#include "jam.c"

int main() {
    // DICTIONARY
    JAM J1, J2;
    long d;

    // INPUT / OUTPUT
    printf("Input Jam 1: ");
    BacaJAM(&J1);
    printf("Input Jam 2: ");
    BacaJAM(&J2);
    printf("Jam 1: ");
    TulisJAM(J1); printf("\n");
    printf("Jam 2: ");
    TulisJAM(J2); printf("\n");

    // FUNCTION
    printf("Is J1 and J2 equivalent? ");
    if (JEQ(J1,J2)) {printf("Yes");}
    else {printf("No");}
    printf("\n");
    
    printf("Is J1 and J2 different? ");
    if (JNEQ(J1,J2)) {printf("Yes");}
    else {printf("No");}
    printf("\n");
    
    printf("Is J1 less than J2? ");
    if (JLT(J1,J2)) {printf("Yes");}
    else {printf("No");}
    printf("\n");
    
    printf("Is J1 greater than J2? ");
    if (JGT(J1,J2)) {printf("Yes");}
    else {printf("No");}
    printf("\n");

    printf("There are %d seconds in J1", JAMToDetik(J1));
    printf("\n");
    
    printf("One second after J1 is: ");
    TulisJAM(NextDetik(J1));
    printf("\n");
    printf("One second before J2 is: ");
    TulisJAM(PrevDetik(J2));
    printf("\n");

    printf("Input duration in seconds: ");
    scanf("%d", &d);
    printf("%d seconds after J1 is: ", d);
    TulisJAM(NextNDetik(J1,d));
    printf("\n");
 

    printf("%d seconds before J2 is: ", d);
    TulisJAM(PrevNDetik(J2,d));
    printf("\n");

    printf("The duration between J1 and J2 is: %d seconds.",Durasi(J1,J2));
    printf("\n");
 
    return 0;
}
