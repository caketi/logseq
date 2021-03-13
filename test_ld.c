#include <stdio.h>
int main(void) {
  extern void *_binary_blob_start, *_binary_blob_end;
  void *start = &_binary_blob_start, *end = &_binary_blob_end;
  printf("Data: %p..%p (%zu bytes)\n", start, end, end - start);
  return 0;
}