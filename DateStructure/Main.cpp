#include"stdio.h"
#include"squeue.h"
#include"Windows.h"


int main() {
	cqueue L;
	initcqueue(&L);
	push(&L, 5);
	push(&L, 4);
	push(&L, 3);
	getlen(&L);
	list(&L);
	push(&L, 2);
	push(&L, 1);
	push(&L, 0);
	getlen(&L);
	list(&L);
	pop(&L);
	getlen(&L);
	list(&L);
	system("pause");
	return 0;
}