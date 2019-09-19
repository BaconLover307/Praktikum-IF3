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
    MATRIKS M1, M2, M3, MPlus, MMin, MKali, MKaliX;
    indeks i;
    float n;
    int maxBrs,minBrs,maxKol,minKol;
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

    if (EQ(M1,M2)) {printf("sama\n");}
    if (NEQ(M1,M2)) {printf("beda\n");}

    MKali = KaliMATRIKS(M1,M2);
    TulisMATRIKS(MKali);
    printf("\n");
    
    BacaMATRIKS(&M2,4,5);
    printf("\n");

    M3 = Inverse1(M1);
    TulisMATRIKS(M3);
    printf("Invers1\n");
    printf("\n");
    PInverse1(&M3);
    TulisMATRIKS(M3);
    printf("PInvers1\n");
    ####  END  #### */
    BacaMATRIKS(&M1,3,2);
    printf("\n");

    MaxMinBrs(M1,3,&maxBrs,&minBrs);
    MaxMinKol(M1,2,&maxKol,&minKol);
    printf("Nilai max pada baris 3: %d\n",maxBrs);
    printf("Nilai min pada baris 3: %d\n",minBrs);
    printf("Nilai max pada kolom 2: %d\n",maxKol);
    printf("Nilai min pada kolom 2: %d\n",minKol);
    return 0;
}
