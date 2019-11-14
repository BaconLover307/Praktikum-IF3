/* Nama             : Gregorius Jovan Kresnadi */
/* NIM              : 13518135 */
/* Tanggal          : 13-10-2019 */
/* Program          : bintree_driver.c */
/* Deskripsi        : Driver ADT Binary Tree */
/* Implementasi dengan menggunakan pointer */
/* Penamaan type infotype, type addrNode, dan beberapa fungsi disesuaikan 
   karena melibatkan modul list rekursif. */

#include "listrek.h"
#include "bintree.h"
#include <stdio.h>

int main() {
	// * Kamus
	BinTree Tree1,Tree2,TreeB;
	addrNode P;
	int X, n;
	// * Algoritma
    // $ *** KONSTRUKTOR ***

   // Tree1 = Tree(1,Nil,Nil);
    //AddDaunTerkiri(&Tree1,8);
    //AddDaunTerkiri(&Tree1,9);
    //MakeTree(1,Nil,Nil,&Tree2);
    printf("Anggota tree : ");
    scanf("%d",&n);
    printf("Buat Tree B beranggotakan %d Node : ",n);
    TreeB = BuildBalanceTree(n);
    AddDaunTerkiri(&TreeB,8);
    AddDaunTerkiri(&TreeB,9);

    printf("TreeB:\n");
    PrintTree(TreeB,2);
    PrintInorder(TreeB); printf("\n");
    printf("Inverted TreeB:\n");
    InvertBtree(&TreeB);
    PrintTree(TreeB,2);
    PrintInorder(TreeB);printf("\n");
    
    // $ *** PRINT TRAVERSAL ***
    //PrintTree(Tree1,2); printf("\n");
    /* printf("Tree 1 (Post Order): ");
    PrintPostorder(Tree2); printf("\n");
    if (IsSkewLeft(Tree1)) printf("Tree 1 Skew Left\n");
    printf("------------------------------------------\n");
    //PrintTree(Tree2,2); printf("\n");
    printf("Tree 2 (In Order): ");
    PrintInorder(Tree2); printf("\n");
    if (IsSkewRight(Tree2)) printf("Tree 2 Skew Right\n");
    printf("------------------------------------------\n");
    printf("TreeB (Pre Order): ");
    PrintPreorder(TreeB); printf("\n");
    printf("\n");
    
    printf("----OPERASI PADA TREEB--------------------\n");
    
    if (IsSkewRight(TreeB)) printf("TreeB Skew Right\n");
    // $ *** SEARCHING ***
    if (SearchTree(TreeB,8)) {printf("Terdapat 8 pada TreeB!\n");}

    printf("Jumlah Node TreeB: %d\n",NbElmt(TreeB));
    printf("Jumlah Daun TreeB: %d\n",NbDaun(TreeB));
    X = 7;
    printf("Level Node %d: %d\n",X,Level(TreeB,X));
    printf("Tinggi TreeB: %d\n",X,Tinggi(TreeB));

    printf("\n");
    // $ *** OPERASI ADD ***
    AddDaunTerkiri(&TreeB,1);
    AddDaunTerkiri(&TreeB,2);
    printf("AddDaunTerkiri 1, 2 pada TreeB:\n");
    PrintTree(TreeB,2);
    AddDaun(&TreeB,2,8,false);
    printf("AddDaun(&TreeB,2,8,Kanan):\n");
    PrintTree(TreeB,2);
    
    printf("\n");
    // $ *** OPERASI DEL ***
    infotype DaunDel;
    DelDaunTerkiri(&TreeB,&DaunDel);
    printf("DelDaunTerkiri pada TreeB:\n");
    PrintTree(TreeB,2);


    
    */
	return 0;
}
