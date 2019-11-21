/* Nama             : Gregorius Jovan Kresnadi */
/* NIM              : 13518135 */
/* Tanggal          : 21-11-2019 */
/* Program          : inverBtree.c */

#include "bintree.h"
#include <stdio.h>
#include <stdlib.h>

void InvertBtree(BinTree *P) {
	// Kamus Lokal
	BinTree PLtemp, PRtemp;
	// Algoritma
	if(!IsTreeEmpty(*P)) {
		PLtemp = Left(*P);
		PRtemp = Right(*P);
		Left(*P) = PRtemp;
		Right(*P) = PLtemp;
		InvertBtree(&Left(*P));
		InvertBtree(&Right(*P));
	}		
}
/* I.S. Pohon P terdefinisi */
/* F.S. Pohon P diflip secara vertikal */
/*      Contoh:
           1
         2   5
        3 4 6
        Menjadi:
           1
         5   2
          6 4 3 */
