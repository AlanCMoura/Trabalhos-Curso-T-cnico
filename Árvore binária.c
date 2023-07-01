#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	
	int conteudo;
	struct no *esquerda;
	struct no *direita;
	
}No;


typedef struct arv{
	
	No *raiz;
	
}Arv;

void inserirEsquerda(No *no, int valor);
void inserirDireita(No *no, int valor);
void inserir(Arv *arv, int valor);
void imprimir(No *raiz);
	
int main() {
	Arv *arvx = (Arv*)malloc(sizeof(Arv));
		arvx->raiz = NULL;
		
	inserir(arvx, 30);
	inserir(arvx, 10);
	inserir(arvx, 20);
	imprimir(arvx->raiz);
	
	return 0;
} 

void inserirEsquerda(No *no, int valor){ //Nesse caso, "No *no" recebe a "raiz".
	if(no->esquerda == NULL){
		
		No *novoNo = (No*)malloc(sizeof(No));
		 novoNo->conteudo = valor;
		 novoNo->esquerda = NULL;
		 novoNo->direita = NULL;
		no->esquerda = novoNo;
		
	}else{
		
		if(valor < no->esquerda->conteudo){
			
		inserirEsquerda(no->esquerda, valor);
		
		}else{
		
		inserirDireita(no->esquerda, valor);
		
	}
	
}
}
void inserirDireita(No *no, int valor){
	if(no->esquerda == NULL){
		
		No *novoNo = (No*)malloc(sizeof(No));
		 novoNo->conteudo = valor;
		 novoNo->esquerda = NULL;
		 novoNo->direita = NULL;
		no->direita = novoNo;
		
    }else{
    	if(valor > no->direita->conteudo){
    		
    		inserirDireita(no->direita, valor);
    		
		}else{
			
			inserirEsquerda(no->direita, valor);
			
		}
	
}
	
}

void inserir(Arv *arv, int valor){
	
	if(arv->raiz == NULL){
		
		No *novoNo = (No*)malloc(sizeof(No));
		novoNo->conteudo = valor;
		novoNo->esquerda = NULL;
		novoNo->direita = NULL;
		arv->raiz = novoNo;
		
	}else{
		
		if(valor < arv->raiz->conteudo){
			
			inserirEsquerda(arv->raiz, valor);
			
		}else{
			
			inserirDireita(arv->raiz, valor);
			
		}
		}
	}
	
	void imprimir(No *no){ //Esse "*no" recebe a raiz para que dê certo.
		if(no != NULL ){
			imprimir(no->esquerda);
			printf("%d ", no->conteudo);			
			imprimir(no->direita);
		}
	}
