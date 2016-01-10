#include <conio.h>
#include <stdio.h>
#define size 1000

int main(void){

	int n, i, t, end;
	int ar[size];
	float big = 0;

	do{
		printf("\n Vuvedete golemina na masiva n=");
		scanf_s("%d", &n);
		if (n>1000 || n<0){
			printf("\n\n molq vuvedete korektna stoinost ");
			printf("\n\n za povtorno vuvejdane natisnete proizvolen klavi6 ");
			getch();
		}
	} while (n>1000 || n <= 0);

	for (i = 0; i<n; i++){
		printf("\n Vuvedete stoinost za ar[%d]=", i);
		scanf_s("%d", &ar[i]);
	}

	for (i = 0; i<n; i++){
		printf("\n%d element na masiva e %d", i + 1, ar[i]);
	}

	printf("\n\n\n");
	big = ar[0];
	for (i = 1; i<n; i++){
		if (ar[i]>big){
			big = ar[i];
		}
	}
	printf("nai golqmata stoinost v masiva e: %.2f\n\n", big);
	big = big / 2;
	printf("polovinata na nai - golqmata stoinost e :%.2f\n\n", big);
	for (i = 0; i < n; i++){
		if (ar[i]<big){
			ar[i] = 0;
		} else{
			ar[i] = 1;
		}
	}

	for (i = 0; i<n; i++){
		printf("\n%d element na masiva sled obrabotka e %d", i + 1, ar[i]);
	}
	end = n - 1;

	for (i = 0; i<n / 2; i++){
		t = ar[i];
		ar[i] = ar[end];
		ar[end] = t;
		end--;
	}
	printf("\n\n");

	for (i = 0; i<n; i++){
		printf("\n%d element na masiva sled 2-ra obrabotka e %d", i + 1, ar[i]);
	}

	_getche();
	return 0;
}
