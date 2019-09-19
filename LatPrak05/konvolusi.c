/* Nama         : Gregorius Jovan Kresnadi */
/* NIM          : 13518135 */
/* Tanggal      : 19-09-2019 */
/* Program      : konvolusi.c */
/* Deskripsi    : Praktikum Matriks */

#include <stdio.h>
#include "matriks.h"

int main() {
   // KAMUS
   MATRIKS A,B,C;
   int N,M; // N x M = Ukuran Matriks A
   indeks NB, NK; // Index untuk Matriks A
   int K; // K x K = Ukuran Matriks B
   int Pusat; // Pusat Matriks B
   int iA,jA; // Counter Index Matriks A
   int iB1, iB2, jB1, jB2; // Indeks Matriks B
   
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

    Pusat = (K/2) + 1; // * Pusat Matriks B

    for (iA=1;iA<=NB;iA++) {        // * Loop untuk mengisi Matriks C
        for (jA=1;jA<=NK;jA++) {
            iB1 = GetFirstIdxBrs(B) - Pusat + iA; // * Membuat Indeks Baris B sesuai dengan A
            iB2 = GetLastIdxBrs(B) - Pusat + iA;

            for (iB1; iB1 <= iB2; iB1++) {
                jB1 = GetFirstIdxKol(B) - Pusat + jA; // * Membuat Indeks Kolom B sesuai dengan A
                jB2 = GetLastIdxKol(B) - Pusat + jA;
                for (jB1; jB1 <= jB2; jB1++) {
                    if (IsIdxEff(A,iB1,jB1)) { // * Validasi untuk mengisi hanya element yang beririsan
                        Elmt(C,iA,jA) += (Elmt(A,iB1,jB1) * Elmt(B,(iB1-iA+Pusat),(jB1-jA+Pusat)));
                    }
                }
            } 
        }
    }
    TulisMATRIKS(C);

   return 0;
}
