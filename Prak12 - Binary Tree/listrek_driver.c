/* Nama             : Gregorius Jovan Kresnadi */
/* NIM              : 13518135 */
/* Tanggal          : 06-10-2019 */
/* Program          : listrek_driver.c */
/* Deskripsi        : Driver ADT List Rekurens */
/* Representasi address dengan pointer */
/* infotype adalah integer */

#include "listrek.h"
#include <stdio.h>

int main() {
	// $ Kamus
	List list1,list2,list11,list22,list3,list4;
	address P;
	int X;
    int isi = 2;
    int Found;
	// $ Algoritma
    list1 = Nil;
    list2 = Nil;
    list11 = Nil;
    list22 = Nil;
    list3 = Nil;
    list4 = Nil;
    printf("Empty = %d\n",IsEmpty(list1));
	list1 = Konso(1,list1);
    printf("One = %d\n",IsOneElmt(list1));
    list1 = Konso(2,list1);
	list1 = Konso(3,list1);
	list1 = Konso(4,list1);
    X = NbElmtList(list1);
    printf("List1: \n");
    PrintList(list1);
    printf("Jumlah = %d\n", X);
    Found = Search(list1,X);
    if (Found) printf("Found\n");
    printf("------------------------------\n");
	infotype maks = MaxList(list1);
	printf("Maximum list 1 = %d\n",maks);
	infotype mins = MinList(list1);
	printf("Minimum list 1 = %d\n",mins);
	infotype sum = SumList(list1);
	printf("Jumlah isi list 1 = %d\n",sum);
    printf("------------------------------\n");
    printf("Inverse List1: \n");
	List inverse = InverseList(list1);
    PrintList(inverse);
    printf("------------------------------\n");
    printf("List2: \n");
	list2 = KonsB(list2, -1);
    list2 = KonsB(list2, 2);
    list2 = KonsB(list2, 3);
    list2 = KonsB(list2, -4);
    list2 = KonsB(list2, -5);
    PrintList(list2);
    printf("------------------------------\n");
	List pos = Nil;
	List neg = Nil;
	SplitPosNeg(list2,&pos,&neg);
    printf("Positif dari List2: \n");
    PrintList(pos);
    printf("Negatif dari List2: \n");
    PrintList(neg);
    printf("------------------------------\n");
	infotype batas = -1;
	List bwh = Nil;
	List atas = Nil;
	SplitOnX(list2,batas,&bwh,&atas);
    printf("Elmt List2 < %d: \n",batas);
    PrintList(bwh);
    printf("Elmt List2 >= %d: \n",batas);
    PrintList(atas);
    printf("------------------------------\n");
	if (IsAllExist(list2,pos)) printf("Ketemu1\n");
	if (IsAllExist(pos,neg)) printf("Ketemu2\n");
	
	
	/*
    list11 = Copy(list1);
    printf("List11: \n");
    PrintList(list11);
    printf("------------------------------\n");
    MCopy(list2,&list22);
    printf("List22: \n");
    PrintList(list22);
    printf("------------------------------\n");
    list3 = Concat(list1,list2);
    printf("List3: \n");
    PrintList(list3);
    printf("------------------------------\n");
    MConcat(list2,list1,&list4);
    printf("List4: \n");
    PrintList(list4);
    printf("------------------------------\n");
	*/
	return 0;
}
