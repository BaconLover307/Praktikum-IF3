/* Nama             : Gregorius Jovan Kresnadi */
/* NIM              : 13518135 */
/* Tanggal          : 12-11-2019 */
/* Program          : bintree.c */
/* ADT Pohon Biner */
/* Implementasi dengan menggunakan pointer */
/* Penamaan type infotype, type addrNode, dan beberapa fungsi disesuaikan 
   karena melibatkan modul list rekursif. */

#include "bintree.h"
#include <stdio.h>
#include <stdlib.h>

// ? #define Nil NULL /* konstanta Nil sesuai pada modul listrek */

/* *** Definisi Type Pohon Biner *** */
/* typedef int infotype; */ /* type infotype sesuai pada modul listrek */
// ? typedef struct tNode *addrNode;
// ? typedef struct tNode {
// ?   infotype info;
// ?   addrNode left;
// ?   addrNode right;
// * } Node;

// * Definisi PohonBiner :
// ? Pohon Biner kosong : P = Nil
// ? typedef addrNode BinTree;

/* *** PROTOTYPE *** */

// * *** Selektor ***
// ? #define Akar(P) (P)->info
// ? #define Left(P) (P)->left
// ? #define Right(P) (P)->right

// $ *** Konstruktor ***
BinTree Tree(infotype Akar, BinTree L, BinTree R) {
	// * Kamus Lokal
	addrNode P;
	// * Algoritma
	P = AlokNode(Akar);
	if (P != Nil) {
		Left(P) = L;
		Right(P) = R;
	}
	return P;
}
/* Menghasilkan sebuah pohon biner dari A, L, dan R, jika alokasi berhasil */
/* Menghasilkan pohon kosong (Nil) jika alokasi gagal */

void MakeTree(infotype Akar, BinTree L, BinTree R, BinTree *P) {
	(*P) = (BinTree) malloc (sizeof(Node));
	Akar(*P) = Akar;
	if (P != Nil) {
		Left(*P) = L;
		Right(*P) = R;
	}
}
/* I.S. Akar, L, R terdefinisi. P Sembarang */
/* F.S. Membentuk pohon P dengan Akar(P)=Akar, Left(P)=L, dan Right(P)=R
   jika alokasi berhasil. P = Nil jika alokasi gagal. */

BinTree BuildBalanceTree(int n) {
	// * Kamus Lokal
	addrNode P;
	BinTree L,R;
	infotype X;
	int nL, nR;
	// * Algoritma
	if (n == 0) {
		return Nil;
	} else {
		scanf("%d",&X);
		P = AlokNode(X);
		if (P != Nil) { // Partisi sisa node sebagai anak kiri dan anak kanan
			nL = n / 2;
			nR = n - nL - 1;
			L = BuildBalanceTree(nL);
			R = BuildBalanceTree(nR);
			Left(P) = L;
			Right(P) = R;
		}
		return P;
	}
}
/* Menghasilkan sebuah balanced tree dengan n node, nilai setiap node dibaca */
/* Jika n == 0, kembalikan Nil.
   Mula-mula, baca nilai dari root dari stdin, lalu bangun pohon biner di kiri
   (dengan membaca dari stdin) lalu di tree kanan (dengan membaca dari stdin). 
   misal dari stdin: 1, 2, 3, 4, 5, 6, 7, hasilnya:
       1
     2   5
    3 4 6 7
  */

// $ Manajemen Memory
addrNode AlokNode(infotype X) {
	addrNode P;
	P = (addrNode) malloc(sizeof(Node));
	if (P != Nil)
	{
		Akar(P) = X;
		Left(P) = Nil;
		Right(P) = Nil;
	}
	return P;
}
/* Mengirimkan addrNode hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addrNode tidak Nil, dan misalnya menghasilkan P,
  maka Akar(P) = X, Left(P) = Nil, Right(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void DealokNode(addrNode P) {
	free(P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addrNode P */

//  $ *** Predikat-Predikat Penting ***
boolean IsTreeEmpty(BinTree P) {
	return P == Nil;
}
/* Mengirimkan true jika P adalah pohon biner kosong */

boolean IsTreeOneElmt(BinTree P) {
	if (!IsTreeEmpty(P)) {
		return (Left(P) == Nil && Right(P) == Nil);
		} else { return false;}
}
/* Mengirimkan true jika P adalah pohon biner tidak kosong dan hanya memiliki 1 elemen */

boolean IsUnerLeft(BinTree P) {
	if (!IsTreeEmpty(P)) {
		return (Left(P) != Nil && Right(P) == Nil);
	} else { return false;}
} 
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri */

boolean IsUnerRight(BinTree P) {
	if (!IsTreeEmpty(P)) {
		return (Left(P) == Nil && Right(P) != Nil);
	} else { return false;}
}
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan*/

boolean IsBiner(BinTree P) {
	if (!IsTreeEmpty(P)) {return (Left(P) != Nil && Right(P) != Nil);
	} else { return false;}
}
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan*/

// $ *** Traversal *** 
void PrintPreorder(BinTree P) {
	printf("(");
	if (!IsTreeEmpty(P)) {
		printf("%d",Akar(P));
		PrintPreorder(Left(P));
		PrintPreorder(Right(P));
	}
	printf(")");
}
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara preorder: akar, pohon kiri, dan pohon kanan.
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh:
   (A()()) adalah pohon dengan 1 elemen dengan akar A
   (A(B()())(C()())) adalah pohon dengan akar A dan subpohon kiri (B()()) dan subpohon kanan (C()()) */

void PrintInorder(BinTree P) {
	printf("(");
	if (!IsTreeEmpty(P)) {
		PrintInorder(Left(P));
		printf("%d", Akar(P));
		PrintInorder(Right(P));
	}
	printf(")");
} 
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara inorder: pohon kiri, akar, dan pohon kanan.
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh:
   (()A()) adalah pohon dengan 1 elemen dengan akar A
   ((()B())A(()C())) adalah pohon dengan akar A dan subpohon kiri (()B()) dan subpohon kanan (()C()) */

void PrintPostorder(BinTree P) {
	printf("(");
	if (!IsTreeEmpty(P)) {
		PrintPostorder(Left(P));
		PrintPostorder(Right(P));
		printf("%d", Akar(P));
	}
	printf(")");
}
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara postorder: pohon kiri, pohon kanan, dan akar.
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh:
   (()()A) adalah pohon dengan 1 elemen dengan akar A
   ((()()B)(()()C)A) adalah pohon dengan akar A dan subpohon kiri (()()B) dan subpohon kanan (()()C) */

void PrintTreeLevel(BinTree P,int h, int level) {
	if (!IsTreeEmpty(P)) {
		printf("%d\n",Akar(P));
		if (IsUnerLeft(P) || IsBiner(P)) {
			for (int i=1; i<=h*level; i++) printf(" ");
		}
		PrintTreeLevel(Left(P),h,level+1);
		if (IsUnerRight(P) || IsBiner(P)) {
			for (int i=1; i<=h*level; i++) printf(" ");
		}
		PrintTreeLevel(Right(P),h,level+1);
	}
}

void PrintTree(BinTree P, int h) {
	PrintTreeLevel(P,h,1);
	/*
	if (!IsTreeEmpty(P)) {
		printf("%d\n",Akar(P));
		if (IsUnerLeft(P) || IsUnerRight(P) || IsBiner(P)) {
			for (int i=1; i<=h; i++) printf(" ");
		}
		PrintTree(Left(P),h+h);
		if (IsUnerLeft(P) || IsUnerRight(P) || IsBiner(P)) {
			for (int i=1; i<=h; i++) printf(" ");
		}
		PrintTree(Right(P),h+h);
	}
	*/
}
/* I.S. P terdefinisi, h adalah jarak indentasi (spasi) */
/* F.S. Semua simpul P sudah ditulis dengan indentasi (spasi) */
/* Penulisan akar selalu pada baris baru (diakhiri newline) */
/* Contoh, jika h = 2: 
1) Pohon preorder: (A()()) akan ditulis sbb:
A
2) Pohon preorder: (A(B()())(C()())) akan ditulis sbb:
A
  B
  C
3) Pohon preorder: (A(B(D()())())(C()(E()()))) akan ditulis sbb:
A
  B
    D
  C
    E
*/

//  $ *** Searching ***
boolean SearchTree(BinTree P, infotype X) {
	if (!IsTreeEmpty(P)) {
		if (Akar(P) == X) {
			return true;
		} else {
			return SearchTree(Left(P),X) || SearchTree(Right(P),X);
		}
	} else {
		return false;
	}
}
/* Mengirimkan true jika ada node dari P yang bernilai X */

// $ *** Fungsi-Fungsi Lain ***
int NbElmt(BinTree P) {
	if (IsTreeOneElmt(P)) {
		return 1;
	} else {
		if (IsUnerLeft(P)) {
			return NbElmt(Left(P)) + 1;
		} else if (IsUnerRight(P)) {
			return 1 + NbElmt(Right(P));
		} else if (IsBiner(P)) {
			return NbElmt(Left(P)) + 1 + NbElmt(Right(P));
		}
	}
}
/* Mengirimkan banyaknya elemen (node) pohon biner P */

int NbDaun(BinTree P) {
	if (IsTreeOneElmt(P)) {
		return 1;
	} else {
		if (IsUnerLeft(P)) {
			return NbDaun(Left(P)) ;
		} else if (IsUnerRight(P)) {
			return NbDaun(Right(P));
		} else if (IsBiner(P)) {
			return NbDaun(Left(P)) + NbDaun(Right(P));
		}
	}
}
/* Mengirimkan banyaknya daun (node) pohon biner P */
/* Prekondisi: P tidak kosong */

boolean IsSkewLeft(BinTree P) {
	if (IsTreeEmpty(P)) {
		return true;
	} else if (IsTreeOneElmt(P)) {
		return true;
	} else if (IsUnerLeft(P)) {
		return IsSkewLeft(Left(P));
	} else if (IsUnerRight(P) || IsBiner(P)) {
		return false;
	}
}
/* Mengirimkan true jika P adalah pohon condong kiri */
/* Pohon kosong adalah pohon condong kiri */
boolean IsSkewRight(BinTree P) {
	if (IsTreeEmpty(P)) {
		return true;
	} else if (IsTreeOneElmt(P)) {
		return true;
	} else if (IsUnerRight(P)) {
		return IsSkewRight(Right(P));
	} else { return false; }
}
/* Mengirimkan true jika P adalah pohon condong kanan */
/* Pohon kosong adalah pohon condong kanan */
int Level(BinTree P, infotype X) {
	if (Akar(P) == X) {
		return 1;
	} else if (SearchTree(Left(P),X)) {
		return 1 + Level(Left(P),X);
	} else if (SearchTree(Right(P),X)) {
		return Level(Right(P),X) + 1;
	}
}
/* Mengirimkan level dari node X yang merupakan salah satu simpul dari pohon biner P.
   Akar(P) level-nya adalah 1. Pohon P tidak kosong. */
int Tinggi(BinTree P) {
	if (IsTreeEmpty(P)) {
		return 0;
	} else {
		if (Tinggi(Left(P)) > Tinggi(Right(P))) {
			return 1 + Tinggi(Left(P));
		} else {
			return Tinggi(Right(P)) + 1;
		}
	}
}
/* Pohon Biner mungkin kosong. Tinggi pohon kosong = 0.
   Mengirim "height" yaitu tinggi dari pohon */

// $ *** Operasi lain ***
void AddDaunTerkiri(BinTree *P, infotype X) {
	// * Kamus Lokal
	addrNode PLeft; 
	// * Algoritma
	if (IsTreeEmpty(*P)) {
		PLeft = AlokNode(X);
		if (PLeft != Nil) {
			*P = PLeft;
		}
	} else {
		AddDaunTerkiri(&Left(*P),X);
	}
}
/* I.S. P boleh kosong */
/* F.S. P bertambah simpulnya, dengan X sebagai simpul daun terkiri */
void AddDaun(BinTree *P, infotype X, infotype Y, boolean Kiri) {
	if (IsTreeOneElmt(*P)) {
		if (Kiri) {
			Left(*P) = AlokNode(Y);
		} else {
			Right(*P) = AlokNode(Y);
		}
	} else if (SearchTree(Left(*P),X)) {
		AddDaun(&Left(*P), X, Y, Kiri);
	} else if (SearchTree(Right(*P),X)) {
		AddDaun(&Right(*P), X, Y, Kiri);
	}
}
/* I.S. P tidak kosong, X adalah salah satu daun Pohon Biner P */
/* F.S. P bertambah simpulnya, dengan Y sebagai anak kiri X (jika Kiri = true), atau
        sebagai anak Kanan X (jika Kiri = false) */
/*		Jika ada > 1 daun bernilai X, diambil daun yang paling kiri */
void DelDaunTerkiri(BinTree *P, infotype *X) {
	// * Kamus lokal
	addrNode N;
	// * Algoritma
	if (IsTreeOneElmt(*P)) {
		*X = Akar(*P);
		N = *P;
		*P = Nil;
		DealokNode(N);
	} else {
		if (IsUnerRight(*P)) {
			DelDaunTerkiri(&Right(*P),X);
		} else {
			DelDaunTerkiri(&Left(*P),X);
		}
	}
}
/* I.S. P tidak kosong */
/* F.S. P dihapus daun terkirinya, dan didealokasi, dengan X adalah info yang semula
        disimpan pada daun terkiri yang dihapus */
void DelDaun(BinTree *P, infotype X) {
	if (IsTreeOneElmt(*P)) {
		if (Akar(*P) == X) {
			DealokNode(*P);
			(*P) = Nil;
		}
	} else {
		if (!IsTreeEmpty(*P)) {
			DelDaun(&Left(*P), X);
			DelDaun(&Right(*P), X);
		}
	}
}
/* I.S. P tidak kosong, minimum ada 1 daun bernilai X. */
/* F.S. Semua daun bernilai X dihapus dari P. */

List MakeListDaun(BinTree P) {
	// * Kamus Lokal
	address E;  // Address List
	// * Algoritma
	if (IsTreeEmpty(P)) {
		return Nil;
	} else if (IsTreeOneElmt(P)) {
		E = Alokasi(Akar(P));
		if (E != Nil) {
			return E;		
		} else {
			return Nil;
		}
	} else {
		return Concat(MakeListDaun(Left(P)),MakeListDaun(Right(P)));
	}		
}
/* Jika P adalah pohon kosong, maka menghasilkan list kosong. */
/* Jika P bukan pohon kosong: menghasilkan list yang elemennya adalah semua daun pohon P,
   jika semua alokasi list berhasil.
   Daun terkiri menjadi elemen pertama dari list, diikuti elemen kanannya, dst.
   Menghasilkan list kosong jika ada alokasi yang gagal. */
List MakeListPreorder(BinTree P) {
	// * Kamus Lokal
	address E;	// Address List
	// * Algoritma
	if (IsTreeEmpty(P)) {
		return Nil;
	} else {
		E = Alokasi(Akar(P));
		if (E != Nil) {
			Next(E) = MakeListPreorder(Left(P));
			return Concat(E,MakeListPreorder(Right(P)));
		} else {
			return Nil;
		}
	}
}
/* Jika P adalah pohon kosong, maka menghasilkan list kosong. */
/* Jika P bukan pohon kosong: menghasilkan list yang elemennya adalah semua elemen pohon P
   dengan urutan preorder, jika semua alokasi berhasil.
   Menghasilkan list kosong jika ada alokasi yang gagal. */
List MakeListLevel(BinTree P, int N) {
	// * Kamus Lokal
	address E;	// Address List
	// * Algoritma
	if (IsTreeEmpty(P)) {
		return Nil;
	} else if (Level(P,Akar(P)) == N) {
		E = Alokasi(Akar(P));
		if (E != Nil) {
			return E;
		} else {
			return Nil;
		}
	} else {
		return Concat(MakeListLevel(Left(P), N-1), MakeListLevel(Right(P), N-1));
	}
}
/* Jika P adalah pohon kosong, maka menghasilkan list kosong. */
/* Jika P bukan pohon kosong: menghasilkan list yang elemennya adalah semua elemen pohon P
   yang levelnya=N, jika semua alokasi berhasil.
   Elemen terkiri menjadi elemen pertama dari list, diikuti elemen kanannya, dst.
   Menghasilkan list kosong jika ada alokasi yang gagal. */

// $ *** Binary  Search  Tree  ***
boolean BSearch(BinTree P, infotype X) {
	if (IsTreeEmpty(P)) {
		return false;
	} else {
		if (Akar(P) == X) {
			return true;
		} else {
			if (X < Akar(P)) {
				return BSearch(Left(P),X);
			} else {
				return BSearch(Right(P),X);
			}
		}
	}
}
/* Mengirimkan true jika ada node dari P yang bernilai X */

void InsSearch(BinTree *P, infotype X) {
	if (IsTreeEmpty(*P)) {
		(*P) = AlokNode(X);
	} else {
		if (X > Akar(*P)) {
			InsSearch(&Right(*P), X);
		} else if (X < Akar(*P)) {
			InsSearch(&Left(*P), X);
		}
	}
}
/* Menghasilkan sebuah pohon Binary Search Tree P dengan tambahan simpul X. Belum ada simpul P yang bernilai X. */

void DelBtree(BinTree *P, infotype X) {
	// * Kamus Lokal
	addrNode Pt;
	// * Algoritma
	if (X < Akar(*P)) {
		DelBtree(&Left(*P), X);
	} else if (X > Akar(*P)) {
		DelBtree(&Right(*P),X);
	} else if (X == Akar(*P)) {
		if (IsTreeOneElmt(*P)) {
			DelDaun(P, X);
		} else if (IsUnerLeft(*P)) {
			(*P) = Left(*P);
		} else if (IsUnerRight(*P)) {
			(*P) = Right(*P);
		} else if (IsBiner(*P)) {
			Pt = (*P);
			(*P) = Left(Pt);
			Right(*P) = Right(Pt);
		}
	}
}
/* I.S. Pohon P tidak  kosong */
/* F.S. Nilai X yang dihapus pasti ada */
/* Sebuah node dengan nilai X dihapus */


void InvertBtree(BinTree *P) {
	// Kamus Lokal
	BinTree PLtemp, PRtemp;
	// Algoritma
	if(!IsTreeOneElmt(*P)) {
		PLtemp = Left(*P);
		PRtemp = Right(*P);
		InvertBtree(&PLtemp);
		InvertBtree(&PRtemp);
		Left(*P) = PRtemp;
		Right(*P) = PLtemp;
	}		
}
/* I.S. Pohon P terdefinisi */
/* F.S. Pohon P diflip secara vertikal */
/*      Contoh:
           1
         2   5
        3 4 6
        Menjadi:
           1
         5   2
          6 4 3 */

