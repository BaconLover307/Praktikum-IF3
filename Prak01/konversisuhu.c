/* Nama     : Gregorius Jovan Kresnadi */
/* NIM      : 13518135 */
/* Program  : konversisuhu */
/* Deskripsi: Mengubah suhu dari celcius ke jenis lain */

#include <stdio.h>

int main() {
    // KAMUS
    float t;
    char k;
    // ALGORITMA
    scanf("%f\n",&t); // Input suhu
    scanf("%c",&k); // Input jenis suhu
    
    if (k == 'R') { // Ubah ke reamur
        t = 0.8 * t;
    } else if (k == 'F') { // Ubah ke Fahrenheit
        t = 1.8 * t + 32;
    } else /* k == 'K' */ { // Ubah ke Kelvin
        t = t + 273.15;
    }
    printf("%.2f\n",t); // Output Suhu
    return 0;
}