#include <stdio.h>
#include <stdlib.h>


int main(){
    int x;
    int *p;
    p = &x;
    x = 5;
    printf("%d %d %d\n",x,p,*p);
}