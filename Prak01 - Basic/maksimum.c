/* Nama     : Gregorius Jovan Kresnadi */
/* NIM      : 13518135 */
/* Program  : maksimum */
/* Deskripsi: Mengoutput nilai terbesar di antara 3 integer */

#include <stdio.h>

int main() {
    // KAMUS
    int a,b,c;

    // ALGORITMA
    scanf("%d",&a); // Input a
    scanf("%d",&b); // Input b
    scanf("%d",&c); // Input c
    if (a<b) {
        /* Compare a b */
        a=b;
    }
    if (a<c) {
        /* Compare a c */
        a=c;
    }
    printf("%d\n",a); // Jumlah
    return 0;
}