#include <stdio.h>
#include <math.h>

int main(){

	float a, b, c, r1, r2, d;  
	printf("Vavedete stoinosti za a,b i c\n");
	scanf_s("%f%f%f",&a,&b,&c);

	if (a == 0){
		r1 = -c / b;
		printf("Korena e: x=%.2f", r1);
	} else {
		d = b*b - 4 * a*c;

		if (d > 0){
			r1 = (-b + sqrt(d)) / (2 * a);
			r2 = (-b - sqrt(d)) / (2 * a);
			printf("Korenite sa: x1=%.2f i x2=%.2f", r1, r2);
		}
		else if (d == 0){
			r1 = r2 = -b / (2 * a);
			printf("Korenite sa ravni: x1=%.2f i x2=%.2f", r1, r2);
		}
		else {
			printf("Nqma realni koreni");
		}
	}

	_getche();
	return 0;
}
