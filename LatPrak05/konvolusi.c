/* Nama         : Gregorius Jovan Kresnadi */
/* NIM          : 13518135 */
/* Tanggal      : 19-09-2019 */
/* Program      : konvolusi.c */
/* Deskripsi    : Konvolusi */

#include <stdio.h>
#include "matriks.h"

int main() {
   // KAMUS
   MATRIKS A,B,C;
   int N,M; // N x M = Ukuran Matriks A
   indeks NB, NK; // Index untuk Matriks A
   int K; // K x K = Ukuran Matriks B
   int i; // Counter
   indeks idx;
   
   // Baca Matriks A & B
   scanf("%d %d\n",&N,&M);
   BacaMATRIKS(&A, N, M);
   scanf("%d\n",&K);
   BacaMATRIKS(&B, K, K);
   
   // Buat Matriks C
   MakeMATRIKS(N,M,&C);
   
   // Operasi Konvolusi
   NB = GetLastIdxBrs(A);
   NK = GetLastIdxKol(A);
   Elmt(C,1,1) = Elmt(A,1,1) * Elmt(B,1,1);
   TulisMATRIKS(C);
   /*
    if (NB>1) {
        for (i=1;i<NB;i++) {
            if (NK>1) {
                for (j=1;j<NK;j++) {
                    scanf("%d ",&Elmt(*M,i,j));
                }
            }
            scanf("%d",&Elmt(*M,i,NK));
            }
    }
    if (NK>1) {
        for (j=1;j<NK;j++) {
            scanf("%d ",&Elmt(*M,NB,j));
        }
    }
    scanf("%d",&Elmt(*M,NB,NK));
   */
   return 0;
}
