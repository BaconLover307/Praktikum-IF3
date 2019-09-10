/* Nama         : Gregorius Jovan Kresnadi */
/* NIM          : 13518135 */
/* Tanggal      : 10-09-2019 */
/* Program      : marray.c */
/* Deskripsi    : Array */

#include <stdio.h>
#include "array.h"

int main() {
   // KAMUS
   TabInt T;
   int X; // Masukkan
   int n = 0; // jumlah muncul
   int i ; // Counter
   int idx;
   int median;
   int idxmedian;
   
   // Baca Tulis
   BacaIsi(&T);
   
    // Menerima input
   scanf("%d", &X);
   TulisIsiTab(T);

   idx = Search2(T,X);
   
   if (idx!=IdxUndef) {
      i = idx;
      for (i=1;i<=Neff(T);i++) {
        if (Elmt(T,idx)==Elmt(T,i)) {
          n++;
          }
        }
      printf("\n");
      printf("%d\n", n);
      printf("%d\n", idx);
      
      InsSortAsc(&T);
      if (Neff(T)%2 == 1) {
        idxmedian = (Neff(T)/2)+1;
      } else {
        idxmedian = Neff(T)/2;
      }
      if (X==Elmt(T,IdxMaxTab(T))) {printf("maksimum\n");} 
      if (X==Elmt(T,IdxMinTab(T))) {printf("minimum\n");} 
      if (X==Elmt(T,idxmedian)) {printf("median\n");}
      
    } else {
      printf("\n");
      printf("%d\n", n);
      printf("%d tidak ada\n", X);
    }
    
   return 0;
}
