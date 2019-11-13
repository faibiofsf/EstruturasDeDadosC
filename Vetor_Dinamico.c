#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  float *v; //definindo o ponteiro v
  int i, num_componentes;
  
  printf("Informe o numero de componentes do vetor\n");
  scanf("%d", &num_componentes);
  
  /*Calcular o número de bytes necessários
  primeiramente multiplicamos o número de componentes do vetor pela
  quantidade de bytes que é dada pelo comando sizeof,
  portanto temos:
  */
  int quantidade_bytes = num_componentes * sizeof(float);

  /*2 - Reservar a quantidade de memória
  usamos malloc para reservar essa quantidade de memória
  */
  void *mem = malloc(quantidade_bytes);
  
  /* 3 - Converter o ponteiro para o tipo de dados desejado
  como a função malloc retorna um ponteiro do tipo void,
  precisamos converter esse ponteiro para o tipo da nossa variável, no caso float,
  por isso usamos o comando de conversão explicita
  e atribuindo o resultado em v temos o comando abaixo:
  (float *)
  */
  v = (float *) mem;
  
  //Armazenando os dados em um vetor
  for (i = 0; i < num_componentes; i++)
  {
    printf("\nDigite o valor para a posicao %d do vetor: ", i+1);
    scanf("%f",&v[i]);
  }
  
  // ------ Percorrendo o vetor e imprimindo os valores ----------
  printf("\n*********** Valores do vetor dinamico ************\n\n");
  
  for (i = 0;i < num_componentes; i++)
  {
    printf("%.2f\n",v[i]);
  }
  
  int novo_num_componentes;
  printf("Informe o novo numero de componentes do vetor\n");
  scanf("%d", &novo_num_componentes);
  
  
  /* A função realloc() serve para realocar memória.
  A funçao modifica o tamanho da memória previamente alocada apontada por valor
  para aquele especificado por quantidade_bytes.
  O valor de quantidade_bytes pode ser maior ou menor que o original.
  4 - Realocamos memoria para v, como o novo numero de componentes.
  primeiramente calculamos a quantiade de bytes necessáris e então chamamos o realloc()
  */
  quantidade_bytes = novo_num_componentes * sizeof(float);
  realloc(v, quantidade_bytes);
  
  //Armazenando os novos dados no vetor v
  for (i = num_componentes; i < novo_num_componentes; i++)
  {
    printf("\nDigite o valor para a posicao %d do vetor: ", i+1);
    scanf("%f",&v[i]);
  }
  
  for (i = 0;i < novo_num_componentes; i++)
  {
    printf("%.2f\n",v[i]);
  }
  
  //liberando o espaço de memória alocado
  free(v);
  
  return 0;
}

