#include <stdio.h>
#include "mesintoken.h"

int main() {
	STARTTOKEN();
	while(!EndToken) {
		for(int i=1; i<=4; i++) {
			printf("%c",CToken.tkn);
			printf("%d",CToken.val);
		}
		printf("\n");ADVTOKEN();
	}
	return 0;
}
