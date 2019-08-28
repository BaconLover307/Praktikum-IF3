/* Nama     : Gregorius Jovan Kresnadi */
/* NIM      : 13518135 */
/* Program  : jumlahderet */
/* Deskripsi: Menghitung jumlah deret berdasarkan input */

#include <stdio.h>

int main() {
    // KAMUS
    int i,n,total;
    total = 0;
    // ALGORITMA
    scanf("%d",&n); // Input panjang deret
    for(i=0; i<=n; i++) {
        total += i;
    }
    printf("%d\n",total); // Output Jumlah
    return 0;
}