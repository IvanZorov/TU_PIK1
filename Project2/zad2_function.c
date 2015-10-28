#include <stdio.h>

int main(){
        float a, b, c, m1, m2;
        float x= 1,y;
        scanf("%f", &a);
        scanf("%f", &b);
        scanf("%f", &c);
        scanf("%f", &m1);
        scanf("%f", &m2);
 
        if(x<=m1){
                y = b + x;
        }
 
        if(m1<=x && x<=m2){
                y = (a*x) / (4 - x);
        }
 
        if(x>=m2){
                y = c + x;
        }
 
        printf("%f", y);
 
        _getche();
        return 0;
}

