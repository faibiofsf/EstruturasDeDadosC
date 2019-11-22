#include <stdio.h>
#include <stdlib.h>

typedef struct no Elemento;

struct no{
	int dado;
	int tamanho;
	struct no *prox;
};

Elemento* criar_no(){
	Elemento *novo_no = (Elemento*)malloc(sizeof(Elemento));	
	return novo_no;
}

Elemento* push(Elemento *pilha, int dado){
	Elemento *novo_no = criar_no();
	novo_no->dado = dado;
	
	if(pilha == NULL){
		pilha = novo_no;
		novo_no->tamanho = 1;
		novo_no->prox = NULL;
	}
	else{
		novo_no->prox = pilha;
		novo_no->tamanho = pilha->tamanho+1;
		pilha = novo_no;
	}
	return pilha;
}

void imprimir_pilha(Elemento *pilha){
	Elemento *auxiliar = pilha;
	
	while(auxiliar!=NULL){
		printf("%d ", auxiliar->dado);
		auxiliar = auxiliar->prox;
	}
	printf("\n");
}


Elemento* pop(Elemento *pilha){
	if(pilha != NULL){
		pilha = pilha->prox;
	}
	return pilha;
}

int main(){
	Elemento *pilha = NULL;	
	pilha = push(pilha,10);
	imprimir_pilha(pilha);
	pilha = push(pilha,20);
	imprimir_pilha(pilha);
	pilha = push(pilha,30);
	imprimir_pilha(pilha);
	printf("%d\n", pilha->tamanho);
	pilha = pop(pilha);
	imprimir_pilha(pilha);
	printf("%d\n", pilha->tamanho);
	printf("Topo: %d\n", pilha->dado);
}
