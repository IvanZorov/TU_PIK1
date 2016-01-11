#include <stdio.h>
#include <conio.h>
int main(){
	int i, j;
	char m;
	printf("Vuvedete za subirane(+), za izvajdane(-), za umnojenie(*), delenie(/)\n");
	m = getchar();
	printf("Vuvedete purvi operand ");
	scanf_s("%d", &i);
	printf("Vuvedete vtori operand ");
	scanf_s("%d", &j);
	switch (m){
	case '+':printf("%d+%d=%d\n", i, j, i + j); break;
	case '-':printf("%d-%d=%d\n", i, j, i - j); break;
	case '*':printf("%d*%d=%d\n", i, j, i*j); break;
	case '/':printf("%d/%d=%d\n", i, j, i / j); break;
	default:printf("Greshna operaciq\n");
	}
	_getche();
	return 0;
}
