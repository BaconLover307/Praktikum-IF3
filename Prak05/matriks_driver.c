/* Nama         : Gregorius Jovan Kresnadi */
/* NIM          : 13518135 */
/* Tanggal      : 17-09-2019 */
/* Program      : matriks_driver.c */
/* Deskripsi    : Driver ADT Matriks */

#include <stdio.h>
#include <stdlib.h>
#include "matriks.h"

int main()
{
    // DICTIONARY
    MATRIKS M1, M2, MPlus, MMin, MKaliX;
    indeks i,n;
    boolean bool;
    ElType Mx = 0;
    ElType Mn = 0;
    // INPUT / OUTPUT
    /* #### START ####
    CopyMATRIKS(M1,&M2);

    MPlus = TambahMATRIKS(M1,M2);
    TulisMATRIKS(MPlus);
    printf("\n");

    MMin = KurangMATRIKS(M1,M2);
    TulisMATRIKS(MMin);
    printf("\n");

    MKaliX = KaliKons(M1,10);
    TulisMATRIKS(MKaliX);
    printf("\n");

       ####  END  #### */
    BacaMATRIKS(&M1,2,2);
    printf("\n");
    TulisMATRIKS(M1);
    printf("\n");
    
    BacaMATRIKS(&M2,2,2);
    printf("\n");
    TulisMATRIKS(M2);
    printf("\n");

    if (EQ(M1,M2)) {printf("sama\n");}
    if (NEQ(M1,M2)) {printf("beda\n");}

    return 0;
}
