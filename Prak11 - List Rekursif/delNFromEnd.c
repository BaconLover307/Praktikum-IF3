/* Nama         : Gregorius Jovan Kresnadi */
/* NIM          : 13518135 */
/* Tanggal      : 07-11-2019 */
/* Program      : delNFromEnd.c */
/* Deskripsi    : Menghapus element ke N dari belakang*/


#include <stdio.h>
#include "listrek.h"

List delNFromEnd(List L, int n) {
	Dealokasi(L);
	return Nil;
	/*
	 */
	// KAMUS
	/*
	int nEnd = NbElmtList(L) - n + 1;
	address Prec,P,PDel,PSkip;
	address nxt;
	
	
	// ALGORITMA
	if (nEnd == 1 && NbElmtList(L) == 1) {
	Dealokasi(&L);
		return Nil;
	} 
	SetNext(P,P);
	for (int i = 1; i<nEnd; i++) {
		SetNext(P,P);
		SetNext(Prec,Prec);
	}
	SetNext(P,PDel);
	SetNext(Prec,PSkip);
	Dealokasi(Prec);
	SetNext(PSkip,Prec);
	SetNext(Prec,PSkip);
	return L;
	
	
	Prec = First(*L);
        Phead = Next(First(*L));
        while (P != Phead) {
            Phead = Next(Phead); // Jika not Found maka P = Nil
            Prec = Next(Prec); // Jika not Found maka P = Nil
            }
	
	// $ Algoritma
    *Pdel = Next(Prec);
    Next(Prec) = Next(Next(Prec));
    Next(*Pdel) = Nil;


 // $ Kamus Lokal
    address P = Alokasi(*X);
    // $ Algoritma
    DelLast(L, &P);
    *X = Info(P);
    Dealokasi(&P);	
    * */
}
