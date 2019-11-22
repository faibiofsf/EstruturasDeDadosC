#include <stdio.h>
#include <stdlib.h>

typedef struct no Elemento;
typedef struct local LocalFim;

struct no{
	int dado;
	struct no *prox;
	struct no *anterior;
};

struct local{
	Elemento *inicio;
	int tamanho;
};

Elemento* criar_elemento(){
	Elemento *novo_elemento = (Elemento*)malloc(sizeof(Elemento));	
	return novo_elemento;
}

Elemento* enqueue(Elemento *fila, int dado, LocalFim *local){
	Elemento *novo_elemento = criar_elemento();
	novo_elemento->dado = dado;
	
	if(fila == NULL){
		fila = novo_elemento;
		novo_elemento->prox = NULL;
		novo_elemento->anterior = NULL;
		local->inicio = novo_elemento;
		local->tamanho = 1;
	}
	else{
		novo_elemento->prox = fila;
		novo_elemento->prox->anterior = novo_elemento;
		fila = novo_elemento;
		local->tamanho = local->tamanho+1;
	}
	return fila;
}

void imprimir_fila(Elemento *fila){
	Elemento *auxiliar = fila;
	
	while(auxiliar!=NULL){
		printf("%d ", auxiliar->dado);
		auxiliar = auxiliar->prox;
	}
	printf("\n");
}


Elemento* dequeue(Elemento *fila, LocalFim *local){
	if(fila != NULL){
		local->inicio = local->inicio->anterior;
		local->tamanho = local->tamanho-1;
		local->inicio->prox = NULL;
	}
	return fila;
}

int main(){
	Elemento *fila = NULL;
	LocalFim *inicio_fila = (LocalFim*)malloc(sizeof(LocalFim));
	printf("Inserir elemento no fim.\n");
	fila = enqueue(fila,10, inicio_fila);
	imprimir_fila(fila);
	printf("Inserir elemento no fim.\n");
	fila = enqueue(fila,20, inicio_fila);
	imprimir_fila(fila);
	printf("Inserir elemento no fim.\n");
	fila = enqueue(fila,30, inicio_fila);
	imprimir_fila(fila);
	printf("Tamanho Atual: %d\n", inicio_fila->tamanho);
	printf("Remover o elemento no inicio.\n");
	fila = dequeue(fila, inicio_fila);
	imprimir_fila(fila);
	printf("Tamanho Atual: %d\n", inicio_fila->tamanho);
	printf("Inserir elemento no fim.\n");
	fila = enqueue(fila,40, inicio_fila);
	imprimir_fila(fila);
	printf("Tamanho Atual: %d\n", inicio_fila->tamanho);
	printf("Remover o elemento no inicio.\n");
	fila = dequeue(fila, inicio_fila);
	imprimir_fila(fila);
	printf("Elemento no Inicio: %d\n", inicio_fila->inicio->dado);
	printf("Tamanho da Fila: %d\n", inicio_fila->tamanho);
}
