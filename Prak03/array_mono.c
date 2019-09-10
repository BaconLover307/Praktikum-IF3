/* Nama         : Gregorius Jovan Kresnadi */
/* NIM          : 13518135 */
/* Tanggal      : 10-09-2019 */
/* Program      : array_mono.c */
/* Deskripsi    : Array Monotonik */

#include "array.h"
#include <stdio.h>
int main() {
  // KAMUS
  TabInt T;
  int i ; // Counter
  boolean naik = true;
  boolean turun = true;
  boolean sama = true;

  // Baca Tulis
  BacaIsi(&T);
  // Proses
  if (Neff(T)==2) {
    if (Elmt(T,1)>Elmt(T,2)) {printf("Array monotonik tidak membesar\n");}
    else if (Elmt(T,1)<Elmt(T,2)) {printf("Array monotonik tidak mengecil\n");}
    else if (Elmt(T,1)==Elmt(T,2)) {printf("Array monotonik statik\n");}
  } else {
    for (i=2; i<=Neff(T); i++) {
      if (Elmt(T,i)>Elmt(T,i-1)) {
        turun = false;
      }
      if (Elmt(T,i)<Elmt(T,i-1)) {
        naik = false;
      }
      if (Elmt(T,i)!=Elmt(T,i-1)) {
        sama = false;
      }
    }
    if (naik && !turun) {printf("Array monotonik tidak mengecil\n");}
    else if (turun && !naik) {printf("Array monotonik tidak membesar\n");}
    else if (sama) {printf("Array monotonik statik\n");}
    else if (!sama) {printf("Array tidak monotonik\n");}
  } 

  return 0;
}
