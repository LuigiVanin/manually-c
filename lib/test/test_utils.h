#define TEST_SECTION(NAME)                                                     \
  printf("\nRunning \"%s\" Section:\n", NAME);                                 \
  if (true)

#define RUN_TEST(test_func)                                                    \
  do {                                                                         \
    test_func();                                                               \
    printf(" - %s [Passed].\n", #test_func);                                   \
  } while (0)

#define TEST(NAME) void NAME(void)

#define DESCRIBE int main(void)