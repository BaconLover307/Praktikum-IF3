/* Nama         : Gregorius Jovan Kresnadi */
/* NIM          : 13518135 */
/* Tanggal      : 12-09-2019 */
/* Program      : marraydin.c */
/* Deskripsi    : Array Dinamik */

#include <stdio.h>
#include "arraydin.h"

int main() {
   // KAMUS
   TabInt T;
   int maxel; // Max element
   int Q; // jumlah muncul
   int i ; // Counter
   int op; // Operasi
   int num; // Angka yang akan mengoperasi
   
   // Buat array
   scanf("%d", &maxel);
   MakeEmpty(&T,maxel);
   BacaIsi(&T);
   
    // Menerima input Q
   scanf("%d", &Q);
   for (i=1;i<=Q;i++) {
	   scanf("%d",&op);	
	   if (op==1) {
		   scanf("%d",&num);
		   if (IsFull(T)) {printf("array sudah penuh\n");}
		   else {
			   
			   AddAsLastEl(&T,num);
			   printf("%d ",MaxEl(T));
			   TulisIsiTab(T); printf("\n");
		   }
		} else if (op==2) {
			scanf("%d",&num);
			GrowTab(&T,num);
			printf("%d ",MaxEl(T));
			TulisIsiTab(T); printf("\n");
			
		} else if (op==3) {
			scanf("%d",&num);
			if (num>MaxEl(T)) { printf("array terlalu kecil\n");}
			else {
				ShrinkTab(&T,num);
				printf("%d ",MaxEl(T));
			    TulisIsiTab(T); printf("\n");
			}
		} else if (op==4) {
			CompactTab(&T);
			printf("%d ",MaxEl(T));
			TulisIsiTab(T); printf("\n");
		}
	}

   return 0;
}
