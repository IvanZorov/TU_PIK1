#include <stdio.h>

int main(){
	float a, b, c, m1, m2;
	float x = 1, y;
	scanf_s("%f", &a);
	scanf_s("%f", &b);
	scanf_s("%f", &c);
	scanf_s("%f", &m1);
	scanf_s("%f", &m2);

	if (x <= m1){
		y = b + x;
	}

	if (m1 <= x && x <= m2){
		y = (a*x) / (4 - x);
	}

	if (x >= m2){
		y = c + x;
	}

	printf("%.2f", y);

	_getche();
	return 0;
}
