#include <stdio.h>
#include <stdlib.h>

typedef struct no No;

struct no{
	int dado;
	struct no *prox;
};

No* criar_no(){
	No *novo_no = (No*)malloc(sizeof(No));
	
	return novo_no;
}

No* inserir_no_inicio(No *lista, int dado){
	No *novo_no = criar_no();
	novo_no->dado = dado;
	
	if(lista == NULL){
		lista = novo_no;
		novo_no->prox = NULL;
	}
	else{
		novo_no->prox = lista;
		lista = novo_no;
	}
	return lista;
}

void imprimir_lista(No *lista){
	No *auxiliar = lista;
	
	while(auxiliar!=NULL){
		printf("%d ", auxiliar->dado);
		auxiliar = auxiliar->prox;
	}
	printf("\n");
}

No* inserir_no_fim(No *lista, int dado){
	No *novo_no = criar_no();
	novo_no->dado = dado;
	
	No *auxiliar = lista;
	
	while(auxiliar->prox!=NULL){
		auxiliar = auxiliar->prox;
	}
	
	auxiliar->prox = novo_no;
	novo_no->prox = NULL;

	return lista;
}

No* remover_do_inicio(No *lista){
	if(lista != NULL){
		lista = lista->prox;
	}
	return lista;
}

No* inserir_no_indice(No *lista, int dado, int indice){
	No *novo_no = criar_no();
	novo_no->dado = dado;
	
	No *auxiliar = lista;
	int contador = 0;
	
	while(contador < indice-1 && auxiliar->prox!=NULL){
		auxiliar = auxiliar->prox;
		contador++;
	}
	
	novo_no->prox = auxiliar->prox;
	auxiliar->prox = novo_no;

	return lista;
}

No* remover_do_fim(No *lista){
	No *auxiliar = lista;
	
	if(auxiliar->prox == NULL){
		lista = NULL;
	}
	else{
		while(auxiliar->prox->prox!=NULL){
			auxiliar = auxiliar->prox;
	   	}
	   	auxiliar->prox = NULL;
	}

	return lista;
}

No* remover_do_indice(No *lista, int indice){
	No *auxiliar = lista;
	
	int contador = 0;
	if(indice == 0){
		lista = auxiliar->prox;
	}
	else{
		while(contador < indice-1 && auxiliar->prox->prox!=NULL){
			auxiliar = auxiliar->prox;
			contador++;
  	   	}
		auxiliar->prox = auxiliar->prox->prox;

	}

	return lista;
}

int main(){
	No *lista = NULL;
	
	lista = inserir_no_inicio(lista,10);
	imprimir_lista(lista);
	lista = inserir_no_inicio(lista,20);
	imprimir_lista(lista);
	lista = inserir_no_inicio(lista,30);
	imprimir_lista(lista);
	lista = remover_do_inicio(lista);
	imprimir_lista(lista);
	
	lista = inserir_no_fim(lista,40);
	imprimir_lista(lista);
	
	lista = inserir_no_fim(lista,50);
	imprimir_lista(lista);
	
	lista = remover_do_fim(lista);
	imprimir_lista(lista);
	
	lista = inserir_no_indice(lista,60, 2);
	imprimir_lista(lista);
	
	lista = inserir_no_indice(lista,70, 4);
	imprimir_lista(lista);
	
	lista = remover_do_indice(lista, 3);
	imprimir_lista(lista);
}
