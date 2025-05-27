#include "../d_array_list.h"
#include "test_utils.h"
#include <assert.h>
#include <stddef.h>
#include <stdio.h>

#define TEST_ARRAY_SIZE 10

TEST(ARRAY_LIST_INITILIZATION) {
  auto list = NewArrayList(int);

  assert(list.length == 0);
  assert(list.capacity == 8);
  assert(list.element_size == sizeof(int));
  assert(list.data != NULL);
}

TEST(ARRAY_LIST_INITILIZATION_OVERLOAD) {
  auto list = NewArrayList(long int, 16);

  assert(list.length == 0);
  assert(list.capacity == 16);
  assert(list.element_size == sizeof(long int));
  assert(list.data != NULL);
}

TEST(PUSH_INT_ARRAY_LIST_TEST) {
  auto list = NewArrayList(int);

  int values_to_test[TEST_ARRAY_SIZE] = {100, 24, 903, 700, 11,
                                         8,   90, 110, 847, 1000};

  for (size_t i = 0; i < TEST_ARRAY_SIZE; i++) {
    PushItem(&list, values_to_test[i]);
  }
}

TEST(PUSH_STRUCT_ARRAY_LIST_TEST) {
  typedef struct {
    char *name;
    unsigned id;
    int value;
  } Generic;

  auto list = NewArrayList(Generic);

  Generic data = {.name = "opa opa", .id = 10927373, .value = 10};
  PushItem(&list, data);
}

int main() {
  TEST_SECTION("Array List Initialization") {
    TEST_RUN(ARRAY_LIST_INITILIZATION);
    TEST_RUN(ARRAY_LIST_INITILIZATION_OVERLOAD);
  }

  TEST_SECTION("Array List Push") {
    TEST_RUN(PUSH_INT_ARRAY_LIST_TEST);
    TEST_RUN(PUSH_STRUCT_ARRAY_LIST_TEST);
  }
  return 0;
}