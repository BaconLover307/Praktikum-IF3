#include <stdio.h>
#include"mesinkata.h"

void Salin(Kata* dest, Kata src) {
    while (CC != BLANK) {
        for (int i=1; i <= src.Length; i++) {
            (*dest).TabKata[i] = src.TabKata[i];        }
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
    Salin(&pattern,CKata);
    STARTKATA();
        for(int i=1;i<=pattern.Length;i++) {
                printf("%c",CKata.TabKata[i]);
            }
    ADVKATA();
    while (!EndKata) {
        sama = true;
        for(int i=1;i<=pattern.Length;i++) {
            if (CKata.TabKata[i] != pattern.TabKata[i]) {
                printf("%c",CKata.TabKata[i]);
                sama = false;
                ADVKATA();
            }
        if (sama) 
            n += 1;
            ADVKATA();
        }
    }
    printf("n\n");
    return 0;
}