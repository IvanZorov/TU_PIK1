#include<stdio.h>
#include<stdio.h>
#include<conio.h>

double suma_dots(double counter, ...){
	double suma;
	double*ptr = &counter;
	printf("\nfunction<suma_dots> call with %lf arguments", counter);
	for (suma = 0, ptr++; counter>0; counter--)
		suma += *ptr++;
	return suma;
}

double suma_null(double arg, ...){
	double suma = 0, count = 0;
	double*ptr = &arg;
	printf("\nfunction,suma_null>");
	while (*ptr)
	{
		count++;
		suma += *ptr++;
	}
	printf("-> count elements=%lf", count);
	return suma;
}

int main(void){
	double a1 = 5, a2 = 13, a3 = 8, a4 = 2, a5 = -5, a6 = 2, a7 = 10;
	printf("->result=%lf", suma_dots(3, a1, a2, a3));
	printf("->result=%lf", suma_dots(6, a1, a2, a3, a4, a5, a6, a7));
	printf("->result=%lf", suma_null(a1, a2, a3, a4, 0));
	printf("->result=%lf\n", suma_null(a1, a2, a3, a4, a5, a6, 0));

	_getche();
	return 0;
}
