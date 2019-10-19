/* Nama         : Gregorius Jovan Kresnadi */
/* NIM          : 13518135 */
/* Tanggal      : 17-10-2019 */
/* Program      : backspace.c */
/* Deskripsi    : Membaca Angka dan ada Backspace, Membandingkan Sum dari isi 2 Stack*/

#include <stdio.h>
#include "stackt.h"

int main() {
    // KAMUS
    int n,m; // Banyak isi stack
    Stack Sn, Sm; // Stack
    int isin, isim; // Isi Stack
    int sumn, summ; // Hasil dari Stack
    int plusn, plusm; // Pop Stack yang akan ditambah
    int buang; // Hasil backspace
    // ALGORITMA
    scanf("%d %d",&n,&m);
    CreateEmpty(&Sn);
    CreateEmpty(&Sm);
    
    sumn = 0;
    summ = 0;

	// BACA
    for (int i = 1; i<=n; i++) {
		scanf("%d",&isin);
		if (!IsFull(Sn)) {
			if (isin == 0) {
				if (!IsEmpty(Sn)) {
					Pop(&Sn,&buang);
				}
			} else {
				Push(&Sn,isin);
			}
		}
    }
    
    for (int j = 1; j<=m; j++) {
		scanf("%d",&isim);
		if (!IsFull(Sm)) {
			if (isim == 0) {
				if (!IsEmpty(Sm)) {
					Pop(&Sm,&buang);
				}
			} else if (isim != 0) {
				Push(&Sm,isim);
			}
		}
	}
    
    // HITUNG
    while (!IsEmpty(Sn)) {
		Pop(&Sn,&plusn);
		sumn += plusn;
	}
	
    while (!IsEmpty(Sm)) {
		Pop(&Sm,&plusm);
		summ += plusm;
	}
	
	// OUTPUT
	if (sumn == summ) {
		printf("Sama\n");
	} else {
		printf("Tidak sama\n");
	}
	return 0;
}
