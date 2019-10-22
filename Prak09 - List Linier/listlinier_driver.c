/* Nama             : Gregorius Jovan Kresnadi */
/* NIM              : 13518135 */
/* Tanggal          : 20-10-2019 */
/* Program          : listlinier_driver.c */
/* Deskripsi        : Driver ADT List Linier */
/* Representasi address dengan pointer */
/* infotype adalah integer */

#include "listlinier.h"
#include <stdio.h>

int main() {
	// $ Kamus
	List list;
	address P;
	int X = 10;
	// $ Algoritma
	CreateEmpty(&list);
	P = Search(list,X);
	printf("%d\n",P);


	return 0;
}