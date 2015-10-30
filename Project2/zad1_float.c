#include <Visual_2013.h>
#include <stdio.h>
#include <conio.h>
 
int main(void){
        float i, j;
        i = 5.7; j = -2.4;
 
        printf("\n format specifications for float values in language C");
        printf("\n-----------------------------------------------------");
        printf("\n\n printing variables i=5.7,j=2.4\n\n");
        printf("\nformat specification %cf and %c6f ->|%f|%f|%6f|%6f|", '%', '%', i, j, i, j);
        printf("\nnformat specification %c.6f %c1f ->|%.6f|%.6f|%1f|%1f|", '%', '%', i, j, i, j);
        printf("\normat specification %c+6f ->|%+6f|%+6f|", '%', i, j);
        printf("\nformat specification %c-6f ->|%+06f|%-06f|", '%', i, j);
        printf("\nformat specification %c+06f ->|%+06f|%+06f|", '%', i, j);
        printf("\nformat specification %c-06f ->|%-06f|%-06f|", '%', i, j);
        printf("\nformat specification %c+.06f ->|%+.06f|%+.06f|", '%', i, j);
        printf("\nformat specification %c4x ->|%4x|%4x|", '%', i, j);
        printf("\nformat specification %c4X ->|%4x|%4x|", '%', i, j);
        printf("\nformat specification %c#4x ->|%#4x|%#4x|", '%', i, j);
        printf("\nformat specification %c#04x ->|%#04x|%#04x|", '%', i, j);
        printf("\nformat specification %c#6o ->|%#6o|%#6o|", '%', i, j);
        printf("\nformat specification %c#6u ->|%6u|%6u|", '%', i, j);
 
        printf("\n\nPess any key to continue");
        _getch();
        return 0;
}
