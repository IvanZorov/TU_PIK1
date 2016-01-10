//#include <conio.h>
#include <stdio.h> 
#include <stdlib.h> 
#define size 1000

int main(void){

	int n, i, t, end, big, location=0;
	int ar[size];
	do{

		printf("\n Vuvedete golemina na masiva n=");
		scanf_s("%d", &n);
		if (n>1000 || n<0){
			printf("\n\n Nekorekten razmer na masiva !!! ");
			printf("\n\n za povtorno vuvejdane, natisnete proizvolen klavi6 ");
			getch();
		}
	} while (n>1000 || n <= 0);
	
	for (i = 0; i<n; i++){
		printf("\n Vuvedete stoinost za ar[%d]=", i);
		scanf_s("%d", &ar[i]);
	}
	big = ar[0];

	for (i = 1; i<n; i++){
		if (ar[i]>big){
			big = ar[i];
			location = i;
		}
	}

	printf("\n nai golqmata stoinost v masiva e: %d\n\n", big);
	printf("\n nai - golqmata stoinost stoi v ar[%d]", location);
	
	_getche();
	return 0;
}
