/* Nama             : Gregorius Jovan Kresnadi */
/* NIM              : 13518135 */
/* Tanggal          : 31-10-2019 */
/* Program          : listsirkuler.c */
/* ADT List Sirkuler dengan elemen terakhir menunjuk pada elemen pertama */
/* Representasi berkait dengan address adalah pointer */
/* infotype adalah integer */

#include "listsirkuler.h"
#include <stdio.h>
#include <stdlib.h>

/*
? typedef int infotype;
? typedef struct tElmtlist *address;
? typedef struct tElmtlist {
?	infotype info;
?	address next;
? } ElmtList;
? typedef struct {
?	address First;
? } List;
*/
/* Definisi list : */
/* List kosong : First(L) = Nil */
/* Setiap elemen dengan address P dapat diacu Info(P), Next(P) */
/* Elemen terakhir list: jika addressnya Last, maka Next(Last)=First(L) */

/* Notasi Akses */
/*
? #define Info(P) (P)->info
? #define Next(P) (P)->next
? #define First(L) ((L).First)
*/
/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L) {
	return (First(L) == Nil);
}
/* Mengirim true jika list kosong. Lihat definisi di atas. */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L) {
	First(*L) = Nil;
}
/* I.S. L sembarang */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */

/****************** Manajemen Memori ******************/
address Alokasi (infotype X) {
	address P = (address) malloc((sizeof(ElmtList)));
    if (P != Nil) {
        Info(P) = X;
        Next(P) = Nil;
    }
    return P;
}
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */

void Dealokasi (address P) {
	free(P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Last(List L) {
	// $ Kamus Lokal
	address P = First(L);
	// $ Algoritma
	if (!IsEmpty(L)) {
		while (Next(P) != First(L)) {
			P = Next(P);
		}
	}
	return P;
}

address Search (List L, infotype X) {
	// $ Kamus Lokal
	address P = First(L);
	// $ Algoritma
	if (!IsEmpty(L)) {
		do {
			if (Info(P) == X) {
				return P;
			}
			P = Next(P);
		} while (P != First(L));
	}
	return Nil;
}
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X) {
	// $ Kamus Lokal
	address P = Alokasi(X);
	// $ Algoritma
	if (P != Nil) {
		InsertFirst(L,P);
	}
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */

void InsVLast (List *L, infotype X) {
	// $ Kamus Lokal
	address P = Alokasi(X);
	// $ Algoritma
	if (P != Nil) {
		InsertLast(L,P);
	}
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype * X) {
	// $ Kamus Lokal
	address dump;
	// $ Algoritma
	DelFirst(L,&dump);
	*X = Info(dump);
	Dealokasi(dump);
}
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLast (List *L, infotype * X) {
	// $ Kamus Lokal
	address dump;
	// $ Algoritma
	DelLast(L,&dump);
	*X = Info(dump);
	Dealokasi(dump);
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P) {
	if (!IsEmpty(*L)) {
		address last = Last(*L);
		Next(P) = First(*L);
		Next(last) = P;
	} else {
		Next(P) = P;
	}	
	First(*L) = P;
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */

void InsertLast (List *L, address P) {
	// $ Kamus Lokal
	address last = Last(*L);
	// $ Algoritma
	if (!IsEmpty(*L)) {
		Next(last) = P;
		Next(P) = First(*L);
	} else {
		First(*L) = P;
		Next(P) = P;
	}
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
void InsertAfter (List *L, address P, address Prec) {
	// $ Kamus Lokal
	address last = Last(*L);
	// $ Algoritma
	if (Prec == last) {    // * jika hanya satu elemen
		InsertLast(L,P);
	} else{  
		Next(P) = Next(Prec);
		Next(Prec) = P;
	}
}
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P) {
	// $ Kamus Lokal
	address last = Last(*L);
	// $ Algoritma
	*P = First(*L);
	if (*P == last) { 	// * jika hanya satu elemen
		First(*L) = Nil;
	} else {
		First(*L)= Next(First(*L));
		Next(last) = First(*L);
	}
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */

void DelLast (List *L, address *P) {
	// $ Kamus Lokal
	address last = Last(*L);
	// $ Algoritma
	*P = Last(*L);
	if (last != First(*L)) {
		address prec = First(*L);
		while (Next(prec) != last) {
			prec = Next(prec);
		}
		Next(prec) = Next(Next(prec));
	} else {
		First(*L) = Nil;
	}
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, */
/* jika ada */
void DelAfter (List *L, address *Pdel, address Prec) {
	*Pdel = Next(Prec);
	if (Next(First(*L)) != First(*L)) {
		if (Next(Next(Prec)) != First(*L)) {
			Next(Prec) = Next(Next(Prec));
		} else {
			Next(Prec) = First(*L);
		}
	} else {
		First(*L) = Nil;
	}
}
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */

void DelP (List *L, infotype X) {
	// $ Kamus Lokal
	address P ;
	address Prec = Nil;
	// $ Algoritma
	if (!IsEmpty(*L)) {
		if (X == Info(First(*L))) { // * elemen pertama
			DelFirst(L,&P);
			Dealokasi(P);
		} else {
			P = First(*L);
			while (Next(P) != First(*L) && Info(P) != X) {
				Prec = P; 
				P = Next(P);
			}
			if (Info(P) == X) {
				DelAfter(L, &P, Prec);
				Dealokasi(P);
			}
		}
	}
}

/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo(List L) {
	// $ Kamus Lokal
	address P = First(L);
	// $ Algoritma
	printf("[");
	if (P != Nil)
	{
		printf("%d", Info(P));
		while (Next(P) != First(L)) {
			P = Next(P);
			printf(",%d", Info(P));
		}
	}
	printf("]");
}
	/* I.S. List mungkin kosong */
	/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
	/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
	/* Jika list kosong : menulis [] */
	/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */