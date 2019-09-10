/* Nama         : Gregorius Jovan Kresnadi */
/* NIM          : 13518135 */
/* Tanggal      : 05-09-2019 */
/* Program      : mjam.c */
/* Deskripsi    : Menghitung durasi meeting */

#include <stdio.h>
#include "jam.h"

int main () {
	// KAMUS
	int N; // Input
	JAM Max, Min;
	JAM J1, J2; // Temp
	int i; // Counter
	
	// ALGORITMA
	Max = MakeJAM(0,0,0);		//Inisialisasi
	Min = MakeJAM(23,59,59);	// Inisialisasi
	
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		printf("[%d]\n", i);
		BacaJAM(&J1);
		BacaJAM(&J2);
		
		if (JLT(J1, J2)) {
			printf("%d\n", Durasi(J1, J2));
			if (JLT(J1, Min)) {Min = J1;}
			if (JGT(J2, Max)) {Max = J2;}
		} else { // J1 > J2
			printf("%d\n", Durasi(J2, J1));
			if (JLT(J2, Min)) {Min = J2;}
			if (JGT(J1, Max)) {Max = J1;}
		}
	}
	
	// Range
	TulisJAM(Min);
	printf("\n");
	TulisJAM(Max);
	printf("\n");
	
	return 0;
}
