/* Nama             : Gregorius Jovan Kresnadi */
/* NIM              : 13518135 */
/* Tanggal          : 7-11-2019 */
/* Program          : listdp.c */
/* ADT List Rekursif */
/* ADT list linier dengan representasi pointer */
/* Implementasi list linier secara rekursif */

#include "listrek.h"
#include <stdlib.h>
#include <stdio.h>

/*
?    #define Info(P) (P)->info
?   #define Next(P) (P)->next
?    #define Prev(P) (P)->prev
?    #define First(L) ((L).First)
?    #define Last(L) ((L).Last)*/

// ? #define Nil NULL

/* Definisi Type */
/* 
* typedef int infotype;
* typedef struct tElmtlist *address;
* typedef struct tElmtlist
? {
?     infotype info;
?     address next;
* } ElmtList;

? Definisi list :
? List kosong : L = Nil
* typedef address List;

? Deklarasi  nama untuk variabel kerja
?    L : List
?    P : address   
? Maka penulisan First(L) menjadi L
?                P.info menjadi Info(P); P.next menjadi Next(P)

? Selektor
? #define Info(P) (P)->info
? #define Next(P) (P)->next

/* *** Manajemen Memori *** */
address Alokasi(infotype X) {
    address P;
    P = (address)malloc(sizeof(ElmtList));
    if (P != Nil) {
        Info(P) = X;
        Next(P) = Nil;
    }
    return P;
}
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak Nil, dan misalnya menghasilkan P, 
  maka Info(P) = X, Next(P) = Nil */
/* Jika alokasi gagal, mengirimkan Nil */

void Dealokasi(address P) {
    free(P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/* *** Primitif-primitif yang harus direalisasikan *** */

/* Pemeriksaan Kondisi List */
int IsEmpty(List L) {
    if (L == Nil) {
        return 1;
    } else {
        return 0;
    }
}
/* Mengirimkan 1 jika L kosong dan 0 jika L tidak kosong */

int IsOneElmt(List L) {
    if (!IsEmpty(L)) {
        if (Tail(L) == Nil) {
            return 1;
        } else {
            return 0;
        }
    } else {
        return 0;
    } 
}
/* Mengirimkan 1 jika L berisi 1 elemen dan 0 jika > 1 elemen atau kosong */

/* *** Selektor *** */
infotype FirstElmt(List L) {
    return Info(L);
}
/* Mengirimkan elemen pertama sebuah list L yang tidak kosong */
List Tail(List L) {
    return Next(L);
}
/* Mengirimkan list L tanpa elemen pertamanya, mungkin menjadi list kosong */

/* *** Konstruktor *** */
List Konso(infotype e, List L) {
    // $ Kamus Lokal
    address P = Alokasi(e);
    // $ Alogritma
    if (P == Nil) {
        return L;
    } else {
        Next(P) = L;    // * Insert First
        return P;
    }
}
/* Mengirimkan list L dengan tambahan e sebagai elemen pertamanya. 
e dialokasi terlebih dahulu. Jika alokasi gagal, mengirimkan L. */
List KonsB(List L, infotype e) {
    if (IsEmpty(L)) {   // * Insert ke list kosong
        return Alokasi(e);
    } else {
        Next(L) = KonsB(Tail(L), e);
        return L;
    }
}
/* Mengirimkan list L dengan tambahan e sebagai elemen pertamanya */
/* e harus dialokasi terlebih dahulu */
/* Jika alokasi e gagal, mengirimkan L */

/* *** Operasi Lain *** */
List Copy(List L) {
    if (IsEmpty(L)) {   // * BASIS 0
        return Nil;
    } else {        // * REKURENS
        return Konso(FirstElmt(L),Copy(Tail(L)));
    }
}
/* Mengirimkan salinan list L (menjadi list baru) */
/* Jika ada alokasi gagal, mengirimkan L */

void MCopy(List Lin, List *Lout) {
    // $ Kamus Lokal
    List LTemp;
    // $ Algoritma
    if (IsEmpty(Lin)) { // * BASIS 0
        *Lout = Nil;
    } else {        // * REKURENS
        MCopy(Tail(Lin),&LTemp);
        *Lout = Konso(FirstElmt(Lin),LTemp);
    }

}
/* I.S. Lin terdefinisi */
/* F.S. Lout berisi salinan dari Lin */
/* Proses : menyalin Lin ke Lout */

List Concat(List L1, List L2) {
    if (IsEmpty(L1)) {  // * BASIS 0
         return Copy(L2);
    } else {        // * REKURENS
        return Konso(FirstElmt(L1), Concat(Tail(L1),L2));
    }
}
/* Mengirimkan salinan hasil konkatenasi list L1 dan L2 (menjadi list baru) */
/* Jika ada alokasi gagal, menghasilkan Nil */

void MConcat(List L1, List L2, List *LHsl) {
    // $ Kamus Lokal
    List LTemp;
    // $ Algoritma
    if (IsEmpty(L1)) {  // * BASIS 0
        *LHsl = Copy(L2);
    } else {        // * REKURENS
        MConcat(Tail(L1),L2,&LTemp);
        *LHsl = Konso(FirstElmt(L1),LTemp);
    }
}
/* I.S. L1, L2 terdefinisi */
/* F.S. LHsl adalah hasil melakukan konkatenasi L1 dan L2 dengan cara "disalin" */
/* Proses : Menghasilkan salinan hasil konkatenasi list L1 dan L2 */

void PrintList(List L) {
    if (!IsEmpty(L)) {
        printf("%d\n",Info(L));
        PrintList(Tail(L));
    }
}
/* I.S. L terdefinisi. */
/* F.S. Setiap elemen list dicetak. */

int NbElmtList(List L) {
    // $ Kamus Lokal
    int N = 0;
    // $ Algoritma
    if (IsEmpty(L)) {
        return 0;
    } else {
        return 1 + NbElmtList(Tail(L));
    }
}
/* Mengirimkan banyaknya elemen list L, Nol jika L kosong */
boolean Search(List L, infotype X) {
    if (IsEmpty(L)) {
        return false;
    } else {
        if (Info(L) == X) {
            return true;
        } else {
            return Search(Tail(L),X);
        }
    }
}
/* Mengirim true jika X adalah anggota list, false jika tidak */


/*** Pencarian nilai ekstrim ***/
/* Prekondisi untuk Max/Min/Sum/Average : List tidak kosong */
infotype MaxList (List L) {
	// Kamus Lokal
	infotype maks = Info(L);   
	infotype temp;
	// Algoritma
	
	if (IsOneElmt(L)) {
        return maks;
    } else {
		temp = MaxList(Tail(L));
        if (maks <= temp) {
            maks = temp;
        }
        return maks;
    }
}
/* Mengirimkan nilai info(P) yang maksimum */

infotype MinList (List L) {
	// Kamus Lokal
	infotype mins = Info(L);   
	infotype temp;
	// Algoritma
	
	if (IsOneElmt(L)) {
        return mins;
    } else {
		temp = MinList(Tail(L));
        if (mins >= temp) {
            mins = temp;
        }
        return mins;
    }
}
/* Mengirimkan nilai info(P) yang minimum */

infotype SumList (List L) {
	// $ Kamus Lokal

    // $ Algoritma
    if (IsOneElmt(L)) {
        return Info(L);
    } else {
        return Info(L) + SumList(Tail(L));
    }
}
/* Mengirimkan total jumlah elemen List L */

float AverageList (List L) {
	// $ Kamus Lokal
	float sum,n;
    // $ Algoritma
    sum = SumList(L);
    n = NbElmtList(L);
    return sum/n;
}
/* Mengirimkan nilai rata-rata elemen list L */

/*** Operasi-Operasi Lain ***/
List InverseList (List L) {
	// $ Kamus Lokal
	infotype dpn;
	address P;
    // $ Algoritma
    if (IsEmpty(L)) {
		return L;
	} else {
		dpn = Info(L);
		P = Alokasi(dpn);
		if (P == Nil) {
			return L;
		} else {
			return KonsB(InverseList(Tail(L)),dpn);
    	}
    }
}
/* Mengirimkan list baru, hasil invers dari L dengan menyalin semua elemen list.
Semua elemen list baru harus dialokasi */
/* Jika alokasi gagal, hasilnya list kosong */

void SplitPosNeg (List L, List *L1, List *L2) {
	// $ Kamus Lokal
	infotype dpn;
    // $ Algoritma
    if (!IsEmpty(L)) {
		dpn = Info(L);
		if (dpn >=0) {
			*L1 = KonsB(*L1,dpn);
			SplitPosNeg(Tail(L),L1,L2);
		} else {
			*L2 = KonsB(*L2,dpn);
			SplitPosNeg(Tail(L),L1,L2);
		}
	}
}
/* I.S. L mungkin kosong */
/* F.S. Berdasarkan L, dibentuk dua buah list L1 dan L2 */ 
/* L1 berisi semua elemen L yang positif atau 0, sedangkan L2 berisi
semua elemen L yang negatif; semua dengan urutan yang sama seperti di L */
/* L tidak berubah: Semua elemen L1 dan L2 harus dialokasi */
/* Jika L kosong, maka L1 dan L2 kosong */

void SplitOnX (List L, infotype X, List *L1, List *L2) {
	// $ Kamus Lokal
	infotype dpn;
    // $ Algoritma
    if (!IsEmpty(L)) {
		dpn = Info(L);
		if (dpn < X) {
			*L1 = KonsB(*L1,dpn);
			SplitOnX(Tail(L),X,L1,L2);
		} else {
			*L2 = KonsB(*L2,dpn);
			SplitOnX(Tail(L),X,L1,L2);
		}
	}
}
/* I.S. L dan X terdefinisi, L1 dan L2 sembarang. */
/* F.S. L1 berisi semua elemen L yang lebih kecil dari X, dengan urutan
kemunculan yang sama, L2 berisi semua elemen L yang tidak masuk ke
L1, dengan urutan kemunculan yang sama. */

int ListCompare (List L1, List L2) {
	
    
	// $ Kamus Lokal
	int N1 = NbElmtList(L1);
	int N2 = NbElmtList(L2);
	boolean sama;
	infotype dpn;
    // $ Algoritma
    if (IsEmpty(L1)) {
        if (IsEmpty(L2)) {
            return 0;
        } else {
            ----*
        }
		If (N1 = 0) {
			return 0;
		sama = true;
*/		
}
/* Menghasilkan: -1 jika L1 < L2, 0 jika L1 = L2, dan 1 jika L1 > L2 */
/* Jika L[i] adalah elemen L pada urutan ke-i dan |L| adalah panjang L: */
/* L1 = L2: |L1| = |L2| dan untuk semua i, L1[i] = L2[i] */
/* L1 < L2: Jika i adalah urutan elemen yang berbeda yang terkecil
dari L1 dan L2, L1[i]<L2[i] atau: Jika pada semua elemen pada
urutan i yang sama, L1[i]=L2[i], namun |L1|<|L2| */
/* Contoh: [3,5,6,7] < [4,4,5,6]; [1,2,3]<[1,2,3,4] */
/* L1>L2: kebalikan dari L1<L2 */

boolean IsAllExist (List L1, List L2) {
	// Kamus Lokal
	infotype cari;
	boolean found;
	// Algoritma
	if (IsEmpty(L1)) {
		return false;
	} else if (IsOneElmt(L1)) {
		return Search(L2,Info(L1));
	} else {
		return Search(L2,Info(L1)) && IsAllExist(Tail(L1),L2);
	}
}
		
	
	
/* Menghasilkan true jika semua elemen dalam L1 terdapat dalam L2 (tanpa
memperhatikan urutan ataupun banyaknya elemen).
Kedua list mungkin kosong. Jika L1 kosong, maka hasilnya false. */


