/* Nama         : Gregorius Jovan Kresnadi */
/* NIM          : 13518135 */
/* Tanggal      : 11-09-2019 */
/* Program      : arraydin_driver.c */
/* Deskripsi    : Driver ADT Array Dinamis */

#include <stdio.h>
#include <stdlib.h>
#include "arraydin.h"

int main()
{
    // DICTIONARY
    TabInt T1, T2, T3, T4;
    IdxType i,n;
    boolean bool;
    ElType Mx = 0;
    ElType Mn = 0;
    // INPUT / OUTPUT
    /* #### START ####
    T3 = PlusMinusTab(T1,T2,true);
    TulisIsiTab(T3);
    printf("\n");
    T4 = PlusMinusTab(T1,T2,false);
    TulisIsiTab(T4);
    printf("\n");
    n = Search1(T1,3);
    bool = SearchB(T1,3);
    if (bool) {printf("Found");}
    MaxMin(T1,&Mx,&Mn);
    printf("Max = %d, Min = %d\n",Mx,Mn);
    CopyTab(T1,&T3);
    TulisIsiTab(T3);
    n = CountX(T1,1);
    printf("%d\n",n);
    AddAsLastEl(&T1,99);
    n = 99;
    DelLastEl(&T1,&n);

    MakeEmpty(&T2,10);
    BacaIsi(&T2);
    TulisIsiTab(T2);
    printf("\n");
    bool = IsAllGenap(T1);
    if (!bool) {printf("Beda");} else {printf("Sama");}
    printf("%d\n",MaxEl(T1));
    ShrinkTab(&T1,3);
    printf("%d\n",MaxEl(T1));
    TulisIsiTab(T1);
    printf("\n");
    GrowTab(&T1,5);
    printf("%d\n",MaxEl(T1));
    TulisIsiTab(T1);
    printf("\n");
    CompactTab(&T1);
    printf("%d\n",MaxEl(T1));
    TulisIsiTab(T1);
    printf("\n");
       ####  END  #### */
    MakeEmpty(&T1,10);
    BacaIsi(&T1);
    TulisIsiTab(T1);
    CopyTab(T1,&T2);
    printf("\n");
    Sort(&T1,true);
    TulisIsiTab(T1);
    Sort(&T2,false);
    TulisIsiTab(T2);

    return 0;
}
