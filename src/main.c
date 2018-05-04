
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_NUMBERS 12
#define IN_LENGTH 100
#define N_PROCESS 4

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
  pid_t children[N_PROCESS];
  unsigned long long int numbers[MAX_NUMBERS];
  int array_current_size = 0;
  char symb;
  /* Define memory's protection and visibility flags */
  int protection = PROT_READ | PROT_WRITE;
  int visibility = MAP_SHARED | MAP_ANON;
  /* Create shared memory area */
  int *qty_primes;
  qty_primes = (int*) mmap(NULL, sizeof(int)*100, protection, visibility, 0, 0);
  if ((long int)qty_primes==-1) printf("Erro de alocacao!\n");
  (*qty_primes)=0;
  /* Read the numbers */
  do {
    scanf("%llu%c", &numbers[array_current_size++], &symb);
  } while (symb != '\n');
  /* Create the processes */
  for (int i=0; i<N_PROCESS; i++) {
    children[i] = fork();
    if (children[i] == 0) {
      (*qty_primes) += check_prime(numbers[i]);
      exit(0);
    }
  }
  for (int i=0; i<N_PROCESS; i++) {
    waitpid(children[i], NULL, 0);
  }
  printf("%d\n", *qty_primes);
  return 0;
}
