#include <stdio.h>
#include"mesinkata.h"

int main() {
    STARTKATA();
    while (!EndKata) {
        for(int i=1;i<=CKata.Length;i++) {
            printf("%c",CKata.TabKata[i]);
        }
        printf("\n");
        ADVKATA();
    }
return 0;
}