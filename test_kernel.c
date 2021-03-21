#include <stdlib.h>
#include <stdio.h>


// int **b ---> b = malloc(sizeof(int*) * 5);


typedef int (*operation_ptr)(int, int);
int add(int a, int b){return a + b;}


int do_operation(operation_ptr op, int x, int y){
    return op(x,y);
}

int main(int argc, char **argv){
    int result = do_operation(add, 4, 4);
  

    printf("addr: %d \n", result);

}