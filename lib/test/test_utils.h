#define TEST_SECTION(NAME)                                                     \
  printf("\nRunning \"%s\" Section:\n", NAME);                                 \
  if (true)

#define TEST_RUN(test_func)                                                    \
  do {                                                                         \
    test_func();                                                               \
    printf(" - %s passed.\n", #test_func);                                     \
  } while (0)

#define TEST(NAME) void NAME(void)