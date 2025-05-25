#include "util.h"
#include <stdio.h>
#include <stdlib.h>

void InsertAt(int *x, int pos, int value) {
  x[pos] = value;

  printf("Value at %d is equal %d as asked(%d)", pos, x[pos], value);
}

void print_list(int *array, size_t length) {
  printf("[");

  for (size_t i = 0; i < length; i++) {
    printf("%d", array[i]);
    if (i < length - 1)
      printf(", ");
  }

  printf("]\n");
}