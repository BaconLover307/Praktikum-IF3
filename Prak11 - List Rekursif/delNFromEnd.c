/* Nama         : Gregorius Jovan Kresnadi */
/* NIM          : 13518135 */
/* Tanggal      : 13-11-2019 */
/* Program      : delNFromEnd.c */
/* Deskripsi    : Menghapus element ke N dari belakang*/


#include <stdio.h>
#include "listrek.h"

// $ Kamus Global
int NbElmt = 0;
List LNew;

boolean ListBaru(List L, int N, int X) {
	//  $ Kamus Lokal
	
	if (!IsEmpty(L)) {
		X++;
		NbElmt++;
		ListBaru(Tail(L),N,X);
		if (X == (NbElmt - N)) {
			SetNext(L,LNew);
		}
		if (X == (NbElmt - N + 1)) {
			Dealokasi(L);
			if (NbElmt == N) {
				return false;
			}
		}
		if (X == (NbElmt - N + 2)) {
			LNew = L;
		}
	}
} 


List delNFromEnd(List L, int n) {
    if (!ListBaru(L, n, 0)) {
		return LNew;
	} else {
		return L;
	}
}
