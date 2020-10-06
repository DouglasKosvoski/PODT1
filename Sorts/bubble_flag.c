#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void generate_vetor(int tamanho, char metodo[], int *vetor);
void imprime_lista(int lista[], int tamanho);
void bubble_sort(int *vetor, int tamanho);
void swap(int *a, int *b);

int main(){
  clock_t startTime, endTime;
  double deltaTime;

  // Aleatorio, Crescente or Decrescente
  char metodo[] = "Aleatorio";
  int tamanho = 100000;
  int v[tamanho];

  generate_vetor(tamanho, metodo, &v[0]);
  startTime = clock();
  // imprime_lista(v, tamanho);
  bubble_sort(&v[0], tamanho);
  // imprime_lista(v, tamanho);
  endTime = clock();

  deltaTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;
  printf("Itens=%06d \tMetodo=%s\n", tamanho, metodo);
  // printf("Itens=%06d \tMetodo=%s \t%fs \t%fms\n", tamanho, metodo, deltaTime, deltaTime*1000);
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

void bubble_sort(int *vetor, int tamanho){
  unsigned long long int trocas = 0;
  unsigned long long int comparacoes = 0;

  for (size_t i = tamanho-1; i >= 0; i--) {
    int flag = 0;
    for (size_t j = 0; j < i; j++) {
      comparacoes++;
      if (vetor[j] > vetor[j+1]) {
        trocas++;
        swap(&vetor[j], &vetor[j+1]);
        flag = 1;
      }
    }
    if(flag == 0) {
      printf("Comparacoes:%llu \tTrocas:%llu \t", comparacoes, trocas);
      return;
    }
  }
}

void swap(int *a, int *b) {
  int aux = *a;
  *a = *b;
  *b = aux;
}
