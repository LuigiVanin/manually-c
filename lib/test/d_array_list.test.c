#include "../d_array_list.h"
#include "test_utils.h"
#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define TEST_ARRAY_SIZE 10

typedef struct {
  char *name;
  unsigned id;
  int value;
} Generic;

const Generic VALUES_TO_TEST[TEST_ARRAY_SIZE] = {
    {"alice", 1001, 42}, {"bob", 1002, -17},     {"carol", 1003, 256},
    {"dave", 1004, 0},   {"eve", 1005, 999},     {"frank", 1006, -300},
    {"grace", 1007, 77}, {"heidi", 1008, 12345}, {"ivan", 1009, 555},
    {"judy", 1010, -42}};

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

TEST(ARRAY_LIST_PUSH_INT) {
  auto list = NewArrayList(int);
  auto initial_capacity = list.capacity;

  int values_to_test[TEST_ARRAY_SIZE] = {0};

  for (size_t i = 0; i < TEST_ARRAY_SIZE; i++) {
    values_to_test[i] = (int)rand() % 2000 - 1000;
  }
  for (size_t i = 0; i < TEST_ARRAY_SIZE; i++) {
    assert(list.length == i);
    PushItem(&list, values_to_test[i]);
  }

  for (size_t i = 0; i < TEST_ARRAY_SIZE; i++) {
    auto value = GetAt(int, list, i);
    assert(value == values_to_test[i]);
  }

  assert(initial_capacity * 2 == list.capacity);
}

TEST(ARRAY_LIST_PUSH_STRUCT) {
  Generic values_to_test[TEST_ARRAY_SIZE] = {
      {"alice", 1001, 42}, {"bob", 1002, -17},     {"carol", 1003, 256},
      {"dave", 1004, 0},   {"eve", 1005, 999},     {"frank", 1006, -300},
      {"grace", 1007, 77}, {"heidi", 1008, 12345}, {"ivan", 1009, 555},
      {"judy", 1010, -42}};

  auto list = NewArrayList(Generic);
  auto initial_capacity = list.capacity;
  for (size_t i = 0; i < TEST_ARRAY_SIZE; i++) {
    assert(list.length == i);
    PushItem(&list, values_to_test[i]);
  }

  for (size_t i = 0; i < TEST_ARRAY_SIZE; i++) {
    auto item = GetAt(Generic, list, i);
    assert(item.value == values_to_test[i].value);
    assert(item.id == values_to_test[i].id);
    assert(item.name == values_to_test[i].name);
  }

  assert(initial_capacity * 2 == list.capacity);
}

TEST(ARRAY_LIST_POP_STRUCT) {
  auto list = NewArrayList(Generic);
  auto initial_capacity = list.capacity;

  for (size_t i = 0; i < TEST_ARRAY_SIZE; i++) {
    PushItem(&list, VALUES_TO_TEST[i]);
  }

  auto initial_length = list.length;

  for (size_t i = 0; i < TEST_ARRAY_SIZE; i++) {
    assert(initial_length == list.length);

    for (size_t j = 0; j < list.length; j++) {
      auto item = GetAt(Generic, list, j);
      assert(item.name == VALUES_TO_TEST[j].name);
      assert(item.id == VALUES_TO_TEST[j].id);
      assert(item.name == VALUES_TO_TEST[j].name);
    }

    PopItem(&list);
    initial_length--;
  }

  assert(list.capacity == (initial_capacity * 2));
}

TEST(ARRAY_LIST_REMOVE) {
  auto list = NewArrayList(Generic);
  auto initial_capacity = list.capacity;

  for (size_t i = 0; i < TEST_ARRAY_SIZE; i++) {
    PushItem(&list, VALUES_TO_TEST[i]);
  }

  for (size_t i = 0; i < TEST_ARRAY_SIZE / 2; i++) {
    size_t index_to_remove = rand() % (list.length / 2);
    auto initial_length = list.length;

    RemoveAt(&list, index_to_remove);
    assert(list.length == initial_length - 1);

    auto value_current = GetAt(Generic, list, index_to_remove);

    assert(value_current.id != VALUES_TO_TEST[index_to_remove].id);
    assert(value_current.value != VALUES_TO_TEST[index_to_remove].value);
    assert(value_current.name != VALUES_TO_TEST[index_to_remove].name);
  }

  assert(list.capacity == (initial_capacity * 2));
}

TEST(ARRAY_LIST_REMOVE_BEGINNING) {
  auto list = NewArrayList(Generic);
  auto initial_capacity = list.capacity;

  for (size_t i = 0; i < TEST_ARRAY_SIZE; i++) {
    PushItem(&list, VALUES_TO_TEST[i]);
  }

  for (size_t i = 0; i < TEST_ARRAY_SIZE; i++) {
    auto initial_length = list.length;

    RemoveAt(&list, 0);
    assert(list.length == initial_length - 1);

    for (size_t j = 0; j < list.length; j++) {
      Generic item = GetAt(Generic, list, j);
      assert(VALUES_TO_TEST[j + i + 1].id == item.id);
      assert(VALUES_TO_TEST[j + i + 1].value == item.value);
      assert(VALUES_TO_TEST[j + i + 1].name == item.name);
    }
  }

  assert(list.capacity == (initial_capacity * 2));
}

DESCRIBE {
  TEST_SECTION("Array List Initialization") {
    RUN_TEST(ARRAY_LIST_INITILIZATION);
    RUN_TEST(ARRAY_LIST_INITILIZATION_OVERLOAD);
  }
  TEST_SECTION("Array List Push and Insert") {
    RUN_TEST(ARRAY_LIST_PUSH_INT);
    RUN_TEST(ARRAY_LIST_PUSH_STRUCT);
  }
  TEST_SECTION("Array List Pop and Remove") {
    RUN_TEST(ARRAY_LIST_POP_STRUCT);
    RUN_TEST(ARRAY_LIST_REMOVE);
    RUN_TEST(ARRAY_LIST_REMOVE_BEGINNING);
  }
}