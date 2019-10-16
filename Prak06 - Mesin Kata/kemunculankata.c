/* Nama         : Gregorius Jovan Kresnadi */
/* NIM          : 13518135 */
/* Tanggal      : 01-10-2019 */
/* Program      : kemunculankata.c */
/* Deskripsi    : Membaca Pattern */

#include <stdio.h>
#include"mesinkata.h"

void Salin(Kata* dest, Kata src) {
    (*dest).Length = src.Length;
    for (int i=1; i <= src.Length; i++) {
        (*dest).TabKata[i] = src.TabKata[i];
    }
}
/* Menyalin kata
   I.S. : dest sembarang, src sebuah kata yang valid
   F.S. : dest merupakan kata dengan panjang yang sama dengan src
          dan tiap karakter dest sama dengan src */

int main() {
    int n = 0;
    Kata pattern;
    boolean sama;
    STARTKATA();
    Salin(&pattern,A);
    ADVKATA();
    
    while (!EndKata) {
        for(int i=1;i<=CKata.Length;i++) {
            sama = false;
            int j = 1;
            while ((j<=pattern.Length) && (CKata.TabKata[i]==pattern.TabKata[j])) {
                sama = true;
                i += 1;
                j += 1;
            }
			i = i - j + 1;
			if (j != (pattern.Length)+1) {sama = false;}
            if (sama) {
				n += 1;
			}
        }
        ADVKATA();
    }
    printf("%d\n",n);
    return 0;
}