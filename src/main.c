
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_NUMBERS 12
#define IN_LENGTH 100

int check_prime(unsigned long long int number){
  if (number <= 1 || (number != 2 && number % 2 == 0)){
    return 0;
  }
  else {
    int d = 3;
    while (d <= number / 2) {
      if (number % d == 0){
        return 0;
      }
      d = d + 2;
    }
  }
  return 1;
}

int main() {
  unsigned long long int numbers[MAX_NUMBERS];
  int array_current_size = 0;
  char symb;
  /* Definir flags de protecao e visibilidade de memoria */
  int protection = PROT_READ | PROT_WRITE;
  int visibility = MAP_SHARED | MAP_ANON;

  /* Criar area de memoria compartilhada */
  int *qty_primes;
  qty_primes = (int*) mmap(NULL, sizeof(int)*100, protection, visibility, 0, 0);
  if ((long int)qty_primes==-1) printf("Erro de alocacao!\n");
  (*qty_primes)=0;

  do {
    scanf("%llu%c", &numbers[array_current_size++], &symb);
  } while (symb != '\n');
  for (size_t i = 0; i < array_current_size; i++) {
    printf("%d\n", check_prime(numbers[i]));
  }
  return 0;
}
