/* Nama             : Gregorius Jovan Kresnadi */
/* NIM              : 13518135 */
/* Tanggal          : 14-10-2019 */
/* Program          : merkle.c */


#include "listrek.h"
#include "bintree.h"
#include <stdio.h>
#include <math.h>
//#include <time.h>

void TreeDaun(BinTree *T, List L) {
	// Kamus Lokal
	address PL, PR, Pt;
	List ListL = Nil;
	List ListR = Nil;
	int XL, XR, akar, akarR;
	BinTree TL, TR, TfL, TfR;
	if (NbElmtList(L) == 2) {
		PL = L;
		XL = Info(PL);
		PR = Next(PL);
		XR = Info(PR);
		akar = XL + XR;
		TL = AlokNode(XL);
		TR = AlokNode(XR);
		*T = Tree(akar,TL,TR);
	} else {
		int i = NbElmtList(L)/2;
		Pt = L;
		akarR = 0;
		for (i; i>0; i--) {
			ListL = KonsB(ListL,Info(Pt));
			akarR += Info(Pt);
			Pt = Next(Pt);
		}
		i = NbElmtList(L)/2;
		//akarR = 0;
		for (i; i>0; i--) {
			ListR = KonsB(ListR,Info(Pt));
			akarR += Info(Pt);
			Pt = Next(Pt);
		}
		TreeDaun(&TfL,ListL);
		TreeDaun(&TfR,ListR);
		*T = Tree(akarR,TfL,TfR);
	}
}

int main() {
	// Kamus
	BinTree tree;
	addrNode P;
	List list1 = Nil;
	int N, Ntemp,x;
	// Algoritma
	scanf("%d",&N);
	Ntemp = N;
	if (N <= 0) {
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
		scanf("%d",&x);
		list1 = KonsB(list1,x);
	}
	//clock_t start = clock();
	if (N != 1) {
		TreeDaun(&tree,list1);
	} else {
		tree = Tree(Info(list1),Nil,Nil);
	}
	PrintTree(tree,2);
	// Execuatable code
	//clock_t stop = clock();
	//double elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
	//printf("Time elapsed in ms: %f", elapsed);
	return 0;

}
