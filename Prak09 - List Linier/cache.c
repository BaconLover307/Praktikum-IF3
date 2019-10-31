/* Nama         : Gregorius Jovan Kresnadi */
/* NIM          : 13518135 */
/* Tanggal      : 30-10-2019 */
/* Program      : cache.c */
/* Deskripsi    : Cache*/


#include <stdio.h>
#include "listlinier.h"

int main() {
	// KAMUS
	int N; // Isi Cache
	int Q; // Jumlah operasi
	int x; // Bilangan untuk operasi
	address dapetadd;
	infotype dapetinf;
	infotype buang;
	List Cache; // Cache
	
	
	// ALGORITMA
	scanf("%d",&N);
	CreateEmpty(&Cache);
	
	for (int i = 1; i<= N; i++) {
		InsVLast(&Cache,i);
	}
	
	scanf("%d",&Q);
	for (int j = 1; j<=Q; j++) {
		scanf("%d",&x);
		dapetadd = Search(Cache,x);
		if (dapetadd != Nil) {
			dapetinf = Info(dapetadd);
			DelP(&Cache,dapetinf);
			InsVFirst(&Cache,dapetinf);
			printf("hit ");
			PrintInfo(Cache);
			printf("\n");
		} else {
			DelVLast(&Cache,&buang);
			InsVFirst(&Cache,x);
			printf("miss ");
			PrintInfo(Cache);
			printf("\n");
		}
	}		

	return 0;
	
}
