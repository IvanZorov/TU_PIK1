#include<stdio.h>
#include<conio.h>
#include<math.h>

float circle(float*side1, float side2, int per_cent){
	float surface, circle_surface, radius;
	surface = *side1*side2;
	circle_surface = surface*per_cent / 100;
	radius = sqrt(circle_surface / 3.14);
	return radius;
}

int main(void){
	float i, j, result;
	int percent;
	printf("side1= ");  scanf_s("%f", &i);
	printf("side2= ");  scanf_s("%f", &j);
	printf("percent= "); scanf_s("%d", &percent);
	result = circle(&i, j, percent);
	printf("radius=%.2f", result);
	_getche();
	return 0;
}
