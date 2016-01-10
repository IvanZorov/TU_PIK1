#include <stdio.h>
#include <stdarg.h>
#include <conio.h>

double average(int arg, ...){
	int suma = 0, count = 0, val = arg;
	va_list marker;
	printf("\nfunction <average_va> ");
	va_start(marker, arg);
	while (val != 0){
		suma += val;
		count++;
		val = va_arg(marker, int);
	}
	va_end(marker);
	printf(" -> count elements=%d", count);
	return (double)suma / count;
}

int main(){
	int a1 = 5, a2 = 13, a3 = 8, a4 = 2, a5 = -5, a6 = 2, a7 = 10;
	printf(" ->result=%.2f", average(a1, a2, a3, a4, 0));
	printf(" ->result=%.2f", average(a1, a2, a3, a4, a5, a6, 0));  //8.6 5.83
	_getche();
	return 0;
}
