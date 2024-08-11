#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int my_handler(void) { return 5; }

int give_me_a_func(int handler(void)) { return handler(); }

int main(int argc, char *argv[argc + 1]) {
  double A[5] = {
      [0] = 9.0,
      [1] = 2.9,
      [4] = 3.E+25,
      [3] = .00007,
  };
  size_t array_size = sizeof(A) / sizeof(size_t);

  for (size_t i = 0; i < array_size; ++i) {
    printf("element %zu is %g, \tits square is %g\n", i, A[i], A[i] * A[i]);
  }

  const int a = strlen("HHAHAHA");
  printf("len of the string is %d\n", a);
  int result = give_me_a_func(&my_handler);
  // int result = give_me_a_func(NULL);
  printf("my handler returns : %d\n", result);
  return EXIT_SUCCESS;
}
