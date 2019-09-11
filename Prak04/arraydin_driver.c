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
    IdxType i;
    boolean bool;
    // INPUT / OUTPUT
    /* #### START ####
    BacaIsi(&T1);
    T3 = PlusTab(T1,T2);
    T3 = MinusTab(T1,T2);
    T3 = KaliTab(T1,T2);
    T4 = KaliKons(T1,3);
    printf("\n");
    TulisIsiTab(T3);
    printf("\n");
    TulisIsiTab(T4);
    BacaIsi(&T2);
    TulisIsiTab(T2);
    if (IsLess(T1,T2)) {printf("Less");} else {printf("MORE");} 
    bool = SearchB(T1,4);
    if (bool) {
    printf("Ada");
    } else {printf("Ga");}
    printf("%d",IdxMinTab(T1));
    T3 = InverseTab(T1);
    TulisIsiTab(T3);
    if (IsSimetris(T1)) {printf("Simetris");} else {printf("Kagak");}
    MaxSortDesc(&T1);
    AddAsLastEl(&T1,99);
       ####  END  #### */
    MakeEmpty(&T1,10);
    MakeEmpty(&T2,10);
    BacaIsi(&T1);
    TulisIsiTab(T1);
    printf("\n");
    BacaIsi(&T2);
    TulisIsiTab(T1);
    printf("\n");

    T3 = PlusMinusTab(T1,T2,true);
    TulisIsiTab(T3);
    printf("\n");
    T4 = PlusMinusTab(T1,T2,false);
    TulisIsiTab(T4);
    printf("\n");

    return 0;
}
