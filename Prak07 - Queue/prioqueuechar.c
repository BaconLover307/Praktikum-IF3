/* Nama             : Gregorius Jovan Kresnadi */
/* NIM              : 13518135 */
/* Tanggal          : 16-10-2019 */
/* Program          : prioqueuechar.c */
/* Deskripsi        : Implementasi PrioQueueChar */
/* Definisi Queue   : Model Implementasi Versi III dengan circular buffer */

#include "prioqueuechar.h"
#include <stdio.h>
#include <stdlib.h>

/* ********* Prototype ********* */
boolean IsEmpty (PrioQueueChar Q) {
    return (Head(Q) == Nil) && (Tail(Q) == Nil);
}
/* Mengirim true jika Q kosong: lihat definisi di atas */

boolean IsFull (PrioQueueChar Q) {
    return ((Head(Q) == 1) && (Tail(Q) == MaxEl(Q))) || ((Tail(Q) == Head(Q)-1));
}
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */

int NBElmt (PrioQueueChar Q) {
    if (IsEmpty(Q)) {
        return 0;
    } else if (Tail(Q) < Head(Q)) {
        return (Tail(Q) - Head(Q) + MaxEl(Q) + 1);
    } else {return (Tail(Q) - Head(Q) + 1);}
    
}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

/* *** Kreator *** */
void CreateEmpty (PrioQueueChar * Q, int Max) {
    (*Q).T = (infotype *)malloc((Max + 1) * sizeof(infotype));
    if ((*Q).T != NULL) {
        MaxEl(*Q) = Max;
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    } else { //  ! alokasigagal
        MaxEl(*Q) = 0;
    }
}
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */

/* *** Destruktor *** */
void DeAlokasi(PrioQueueChar * Q) {
    MaxEl(*Q) = 0;
    free((*Q).T);
}
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */


/* *** Primitif Add/Delete *** */
void Add (PrioQueueChar * Q, infotype X) {
	 // $ Kamus Lokal
    address i, j;
    // $ Algoritma
    if (IsEmpty(*Q)) {
        Head(*Q) = 1;
        Tail(*Q) = 1;
		InfoTail(*Q) = X;
		
    } else { // * Q tidakkosong
		if (Tail(*Q) == MaxEl(*Q)) {
            Tail(*Q) = 1;
            InfoTail(*Q) = X;
        } else {
			j = Tail(*Q);
			Tail(*Q)++;
			while ((Prio(X) < Prio((*Q).T[j])) && (j>=(Head(*Q)))) {
				(*Q).T[j+1] = (*Q).T[j];
                j--;

			}
			(*Q).T[j+1] = X;
        }
    }
}
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut mengecil berdasarkan prio */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
        TAIL "maju" dengan mekanisme circular buffer; */
void Del (PrioQueueChar * Q, infotype * X){
    *X = InfoHead(*Q);
    if (Head(*Q) == Tail(*Q)) { // * Set menjadi queue kosong
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    } else {
        Head(*Q)++;
    }
}
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */

/* Operasi Tambahan */
void PrintPrioQueueChar (PrioQueueChar Q) {
	if(IsEmpty(Q)) {
		printf("#\n");
	} else {
		for (int i = Head(Q); i <= Tail(Q); i++) {
			printf("%d %c\n",Prio(Q.T[i]),Info(Q.T[i]));
		}
		printf("#\n");
	}
}
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
<prio-1> <elemen-1>
...
<prio-n> <elemen-n>
#
*/

