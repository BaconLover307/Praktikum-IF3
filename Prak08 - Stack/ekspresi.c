/* Nama         : Gregorius Jovan Kresnadi */
/* NIM          : 13518135 */
/* Tanggal      : 17-10-2019 */
/* Program      : ekspresi.c */
/* Deskripsi    : Membaca Angka*/

#include <stdio.h>
#include "stackt.h"
#include "mesintoken.h"
#include "math.h"

int main() {
    // KAMUS
	Stack S; // Stack
	int Op1, Op2, operasi; // Bilangan yang akan dioperasikan
	char Opt; // Operator
	
    // ALGORITMA
	STARTTOKEN();
	CreateEmpty(&S);
	if (EndToken) {
		printf("Ekspresi kosong\n");
		return 0;
	}
	while(!EndToken) {
		//SalinToken();
		//printf("<%c,%d>\n",CToken.tkn,CToken.val);
		if (CToken.tkn == 'b') {
			printf("%d\n",CToken.val);
			Push(&S,CToken.val);
		} else if (CToken.val == -1) {
			Pop(&S,&Op2);
			Pop(&S,&Op1);
			printf("%d %c %d\n",Op1,CToken.tkn,Op2);
			if (CToken.tkn == '+') operasi = Op1 + Op2;
			else if (CToken.tkn == '-') operasi = Op1 - Op2;
			else if (CToken.tkn == '*') operasi = Op1 * Op2;
			else if (CToken.tkn == '/') operasi = Op1 / Op2;
			else if (CToken.tkn == '^') operasi = pow(Op1,Op2);
			printf("%d\n",operasi);
			Push(&S,operasi);
		}	
		ADVTOKEN();
    }
    Pop(&S,&Op1);
    printf("Hasil=%d\n",Op1);
	return 0;
}
