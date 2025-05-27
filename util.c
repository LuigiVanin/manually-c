#include "util.h"
#include <stdio.h>
#include <stdlib.h>

void print_list(int *array, size_t length) {
  printf("[");

  for (size_t i = 0; i < length; i++) {
    printf("%d", array[i]);
    if (i < length - 1)
      printf(", ");
  }

  printf("]\n");
}