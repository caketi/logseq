#include <stdio.h>

int foo(int x, int y) {
  x >>= (sizeof(int) << y);
  return x;
}

int main() {
  printf("%d\n", foo(1000, 3));
  return 0;
  // gcc ub.c -o0
  // gcc ub.c -o2
}