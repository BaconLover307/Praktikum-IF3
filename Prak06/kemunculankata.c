#include <stdio.h>
#include "mesintoken.h"

int main() {
	STARTTOKEN();
	while(!EndToken) {
		for(int i=1; i<=1; i++) {
			printf("%c\n",CToken.tkn);
			printf("%d\n",CToken.val);
		}
		printf("\n");
		ADVTOKEN();
	}
	return 0;
}
