#include <stdio.h>

#define MAX_NUMBERS 12
#define IN_LENGTH 100
int main() {
  unsigned long long int numbers[MAX_NUMBERS];
  int array_current_size = 0;
  char symb;
  do {
    scanf("%llu%c", &numbers[array_current_size++], &symb);
  } while (symb != '\n');
  for (size_t i = 0; i < array_current_size; i++) {
    printf("%llu\n", numbers[i]);
  }
  return 0;
}
