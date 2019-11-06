/* Nama         : Gregorius Jovan Kresnadi */
/* NIM          : 13518135 */
/* Tanggal      : 31-10-2019 */
/* Program      : roundrobin.c */
/* Deskripsi    : Roundrobin*/

#include <stdio.h>
#include "listsirkuler.h"

void DeleteRR (List *L, infotype TQ) {
	// Last
		// $ Kamus Lokal
		address last = First(*L);
		// $ Algoritma
		if (!IsEmpty(*L)) {
			while (Next(last) != First(*L)) {
				last = Next(last);
			}
		}	
	// Kamus Lokal
	int temp;
	
	// Algoritma
	if (IsEmpty(*L)) {
		printf("List kosong\n");
	} else {
		if (Info(last) > TQ) {
			printf("%d\n",TQ);
			DelVLast(L,&temp);
			temp = temp - TQ;
			InsVFirst(L,temp);
		} else {
			printf("%d\n",Info(last));
			DelVLast(L,&temp);
		}
	}		
}
/* Jika L tidak kosong, "menghapus" elemen terakhir list L, misal last, sesuai aturan round robin, yaitu:
- jika Info(last)>TQ, maka last "diantrikan" kembali sebagai first elemen dengan Info(last)=Info(last)-TQ
- jika Info(last)<=TQ, maka DeleteLast(L,X) dan menampilkan X ke layar */
/* Jika L kosong, cetak "List kosong" */
/* I.S. TQ terdefinisi sebagai nilai time slice pemrosesan.
L terdefinisi, mungkin kosong. */
/* F.S. Elemen terakhir L diproses sesuai aturan round-robin.
L mungkin menjadi kosong. */

float Average (List L) {
	// Kamus Lokal
	float sum = 0;
	int n = 0;
	float total = 0;
	address P = First(L);
	
	// Algoritma
	do {
		sum += Info(P);
		n++;
		P = Next(P);
	} while (P != First(L));
	total = sum/n;
	return total;

}
/* Menghasilkan nilai rata-rata elemen L. L tidak kosong. */


int main() {
	// KAMUS
	int TQ = 0; // Time slice
	List RR; // List RoundRobin
	char ops; // operasi
	int x; // Bilangan untuk operasi
	
	// ALGORITMA
	do {
		scanf(" %d",&TQ);
	} while (TQ <= 0);
	CreateEmpty(&RR);
	do {
		scanf(" %c",&ops);
		if (ops == 'A') {
			x = 0;
			scanf(" %d",&x);
			if (x > 0) {
				InsVFirst(&RR,x);
			}
		}
		else if (ops == 'D') {
			DeleteRR(&RR,TQ);
		}
		else if (ops == 'F') {
			if (IsEmpty(RR)) {
				printf("Proses selesai\n");
			} else {
				printf("%.2f\n",Average(RR));
			}
		} else {
			printf("Kode salah\n");
		}
	} while (ops != 'F');
	
	return 0;
}

