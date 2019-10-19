/* Nama         : Gregorius Jovan Kresnadi */
/* NIM          : 13518135 */
/* Tanggal      : 26-09-2019 */
/* Program      : mesintoken.c */
/* Deskripsi    : Mesin Token */

#include "mesintoken.h"
#include <stdio.h>

#define NMax 50
#define BLANK ' '

/* State Mesin Kata */
char CC;
boolean EndToken;
Token CToken;

void IgnoreBlank() {
    while ((CC == BLANK) && (CC != MARK)) {
        ADV();
    }
}
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */

void STARTTOKEN() {
    START();
    IgnoreBlank();
    if (CC == MARK) {
        EndToken = true;
    } else {
        EndToken = false;
        SalinToken();
    }
}
/* I.S. : CC sembarang
   F.S. : EndToken = true, dan CC = MARK;
          atau EndToken = false, CToken adalah Token yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir Token */

void ADVTOKEN() {
    IgnoreBlank();
    if (CC == MARK) {
        EndToken = true;
    } else {
        SalinToken();
        IgnoreBlank();
    }
}
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CToken adalah Token terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, maka EndToken = true
   Proses : Akuisisi kata menggunakan procedure SalinKata */
/*
int BacaAscii(char cc) {
	int val = cc;
	return (val-48);
}
*/
void SalinToken() {
	// $ Kamus Lokal
    int idx = 1; // * Inisialisasi
    int TabToken[NMax + 1];
    int value = 0;
    int pengali = 1;
    int x;
    // $ Algoritma
    while ((CC != MARK) && (CC != BLANK) && (idx <= NMax)) {
        if ((CC == '+') || (CC == '-') || (CC == '*') || (CC == '/') || (CC == '^')) {
			CToken.tkn = CC;
			CToken.val = -1;
			ADV();
			idx++;
		} else {
			
			x = CC;
			TabToken[idx] = x-48;
			CToken.val = 0;
			ADV();
			idx++;
			
		}
    }
    idx--;
    if (CToken.val != -1) {
		int idxfix = idx;
			int k = 1;
		for (idx; idx>=1; idx--) {
			pengali = 1;
			if (idx == 1) {
			value += TabToken[k];
			} else {
					for (int j = 1; j<=idx-1; j++) {
						pengali *= 10;
					}
					value += (TabToken[k] * pengali);
				
			k++;
			}	
		}
		CToken.tkn = 'b';

		CToken.val = value;
	}
	
}
/* Mengakuisisi Token dan menyimpan hasilnya dalam CToken
   I.S. : CC adalah karakter pertama dari Token
   F.S. : CToken berisi Token yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
          

