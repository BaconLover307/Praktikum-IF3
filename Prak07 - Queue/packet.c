int main() {
    int n;
    PrioQueueChar Q;
    infotype x;
    scanf("%d",&n);
	if (n == 0) {
		return 0;
	} else {
		CreateEmpty(&Q,n);
		int i = 1, detik = 1;
		
		while(!IsFull(Q)) {
			scanf("%d %c",&Prio(x),&Info(x));
			Add(&Q,x);
			if (Prio(x) == i) {
				do {
					printf("%d %c\n",detik,Info(Elmt(Q,i)));
					i++;
				}
				while (Prio(Elmt(Q,i)) == i);
			}
			detik++;
		}
		return 0;
	}
}
