#include <stdio.h>
#include <conio.h>
#define SIZE 1000

float sredno(float sum, int num){
	return (float)sum / (float)num;
}

int main(){
	float suma = 0,sr,n,arr[SIZE];
	int i,num = 0;

	printf("\n Vuvedete golemina na masiva: ");
	scanf_s("%f", &n);
	
	for (i = 0; i<n; i++){
		printf("\n Vuvedete stoinost za ar[%d]: ", i);
		scanf_s("%f", &arr[i]);
		suma += arr[i];
	}
	printf("\nSuma = %.2f", suma);
	sr = sredno(suma, n);

	printf("\nSredna stoinost = %.2f", sredno(suma, n));
	_getche();
	return 0;
}
