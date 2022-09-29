/* Nama             : Gregorius Jovan Kresnadi */
/* NIM              : 13518135 */
/* Tanggal          : 21-10-2019 */
/* Program          : merkle.c */


#include "listrek.h"
#include "bintree.h"
#include <stdio.h>
//#include <time.h>
int arr[(1 << 21)];

BinTree BikinTree(int x, int y) {
	// Kamus Lokal
	BinTree L, R;
	int mid;
	// Algoritma
	if (x == y) {
		return Tree(arr[x], Nil, Nil);
	} else {
		int mid = (x+y)/2;
		BinTree L = BikinTree(x, mid);
		BinTree R = BikinTree(mid + 1, y);
		return Tree(Akar(L) + Akar(R), L, R);
	}
}

int main() {
	// Kamus
	int N, Ntemp;
	BinTree T;
	// Algoritma
	scanf("%d",&N);
	Ntemp = N;
	if (Ntemp <=0) {
			printf("Jumlah masukan tidak sesuai\n");
			return 0;
	}
	while (Ntemp != 1) {
		if (Ntemp % 2 != 0 && Ntemp != 1) {
			printf("Jumlah masukan tidak sesuai\n");
			return 0;
		}
		Ntemp = Ntemp / 2;
	}

	for (int i=1; i<=N; i++) {
		scanf("%d",arr + i);
	}
	T = BikinTree(1,N);
	PrintTree(T,2);
	return 0;

}
