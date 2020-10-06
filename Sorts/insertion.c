#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void generate_vetor(int tamanho, char metodo[], int *vetor);
void imprime_lista(int lista[], int tamanho);
void insertion_sort(int *vetor, int tamanho);

int main() {
  clock_t startTime, endTime;
  double deltaTime;

  // Aleatorio, Crescente or Decrescente
  char metodo[] = "Aleatorio";
  int tamanho = 100000;
  int v[tamanho];

  generate_vetor(tamanho, metodo, &v[0]);
  startTime = clock();
  // imprime_lista(v, tamanho);
  insertion_sort(&v[0], tamanho);
  // imprime_lista(v, tamanho);
  endTime = clock();

  deltaTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;
  // printf("Itens=%06d \tMetodo=%s \t%fs \t%fms\n", tamanho, metodo, deltaTime, deltaTime*1000);
  printf("Itens=%06d \tMetodo=%s\n", tamanho, metodo);

  return 0;
}

void generate_vetor(int tamanho, char metodo[], int *vetor) {
  if(strcmp("Aleatorio", metodo) == 0) {
    srand(time(NULL));
    for (size_t i = 0; i < tamanho; i++)
      vetor[i] = rand()%1000;
  }

  if(strcmp("Crescente", metodo) == 0) {
    for (size_t i = 0; i < tamanho; i++)
      vetor[i] = i;
  }

  if(strcmp("Decrescente", metodo) == 0) {
    for (size_t i = 0; i < tamanho; i++)
      vetor[i] = -i;
  }
}

void imprime_lista(int lista[], int tamanho){
  for(size_t i = 0; i<tamanho; i++){
    printf("%2d ", lista[i]);
  } printf("\n");
}

void insertion_sort(int *vetor, int tamanho) {
    unsigned long long int trocas = 0;
    unsigned long long int comparacoes = 0;
    int i, key, j;

    for (i = 1; i < tamanho; i++) {
      key = vetor[i];
      trocas++;
      j = i - 1;

      while (1) {
        if(j >= 0 && vetor[j] > key) {
          comparacoes++;
          vetor[j + 1] = vetor[j];
          trocas++;
          j = j - 1;
        }
        else {
          break;
        }
      }
      vetor[j + 1] = key;
      trocas++;

    }
    printf("Comparacoes:%llu \tTrocas:%llu \t", comparacoes, trocas);
}
