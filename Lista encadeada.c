#include <stdio.h>
#include <stdlib.h>

typedef struct no{ 
    int elemento;
    struct no *proximo; //O ponteiro "proximo" possui um "elemento" e seu pr�prio ponteiro "proximo".
}no; //Criada uma struct de nome "no". Cada vari�vel no possui um "elemento" que ser� atribu�do a ela e um ponteiro "proximo" que aponta para o pr�ximo n�.

typedef struct controleLista{  //Criada uma struct de controle, que ir� indicar o status da fila.
    
    no *fim; // "fim" � do tipo no, logo possui "elemento" e "proximo". 
    no *inicio;  // "inicio" � do tipo no, logo possui "elemento e "pr�ximo".
    int quantidade; 
              //"fim" e "inicio" s�o ponteiros porque eles apontar�o para o conte�do dos n�s, sem alter�-los.
    
    //"fim" e "inicio" s�o n�s, mas n�o participam diretamente da lista, eles s�o igualados a outros n�s para que a lista n�o sofra altera��o.
    
}controleLista; 

void inicializar(controleLista *lista); 
int inserirInicio(controleLista *lista, int elemento);
int inserirFim(controleLista *lista, int elemento);
int listaVazia(controleLista *lista);
void mostrarLista(controleLista *lista);
//obs: em todas as fun��es, um "lista" dever� ser recebido para que haja par�metro de "inicio", "fim" e "quantidade". 

int main()
{
    controleLista *lista; //"lista" � um ponteiro que possui dois outros ponteiros: "fim" e "inicio", pois � do tipo "controleLista".
                          //"lista" da main representa a lista por completo e suas caracter�sticas.
    lista = (controleLista*)malloc(sizeof(controleLista));
    if(lista == NULL){ 
        return 1;
    }
    
    
    inicializar(lista);
    inserirInicio(lista,10);
    inserirInicio(lista,20);
    inserirInicio(lista,30);
    inserirFim(lista,5);
    
    mostrarLista(lista);
    return 0;
}
//obs: todas as vari�veis lista declaradas abaixo s�o locais e servem para representar o recebimento de valores, portanto s�o diferentes da presente na main.
void inicializar(controleLista *lista){ //Fun��o que inicializa ou reinicia a lista, zerando o inicio, fim, e quantidade.
    lista->quantidade = 0;
    lista->fim = NULL;
    lista->inicio = NULL;
}

int listaVazia(controleLista *lista){ //Fun��o auxiliar que verifica se a lista est� vazia, utilizando "quantidade" como par�metro.

    if(lista->quantidade == 0){
        return 0; //"0" significa SIM.
    }
    return 1; //"1" significa N�O.
}

int inserirInicio(controleLista *lista, int elemento){ //Fun��o de inser��o no in�cio da lista.
    
    no *novoNo = (no*)malloc(sizeof(no)); //Aloca��o de mem�ria, declara��o de um novo n�, "novoNo".
    if(novoNo == NULL){                   //obs: "novoNo" � declarado como ponteiro porque ele ir� guardar um espa�o de mem�ria do malloc().
        printf("erro ao alocar mem�ria...");
        return 1;
    }
    
    novoNo->elemento = elemento; //O elemento da struct de "novoNo" recebe o valor do elemento da f�rmula, cujo valor ser� dado na fun��o main().
    
   if(listaVazia(lista) == 0){ //Se a lista estiver vazia: "proximo" de "novoNo" ser� nulo, e "novoNo" ser� igual a "inicio" e "fim" da lista.
   	                            
       novoNo->proximo = NULL; 
       lista->inicio = novoNo;
       lista->fim = novoNo;
       
   }else{ //Se a lista n�o estiver vazia: "proximo" de "novoNo" ser� igual ao atual "inicio" de "lista" da struct "controleLista".
   
       novoNo->proximo = lista->inicio;
       lista->inicio = novoNo;
       
   }
   
    lista->quantidade++; //Independente de qualquer coisa, "quantidade" de "lista" ir� aumentar, pois um novo n� foi criado.
    
}

int inserirFim(controleLista *lista, int elemento){ //Fun��o para inser��o no fim da lista.
    
    no *novoNo = (no*)malloc(sizeof(no)); 
    if(novoNo == NULL){
        printf("erro ao alocar mem�ria...");
        return 1;
    }
    
    novoNo->elemento = elemento; //O elemento da struct de "novoNo" recebe o valor do elemento da f�rmula, cujo valor ser� dado na fun��o main().
    
    novoNo->proximo = NULL; //"proximo" de novoNo ser� nulo, pois o n� ser� inserido no fim da lista.
    
    if(listaVazia(lista) == 0){  //Mesma situa��o da fun��o "inserirInicio()".
    	
        lista->inicio = novoNo;
        lista->fim = novoNo;
        
    }else{   //Se a lista n�o estiver vazia, "proximo" do "fim" de "lista" ser� igual a "novoNo", e ent�o "fim" de "lista" ser� igual a "novoNo".
    	
        lista->fim->proximo = novoNo; 
        lista->fim = novoNo;
        
    }
}
//obs: o novo n� sempre deve ser inserido antes de tudo, caso contr�rio a lista ser� quebrada.

void mostrarLista(controleLista *lista){ //Fun��o de exibi��o.
    
    no *inicioAux = lista->inicio;  //Um falso inicio � criado para percorrer toda a lista, sem modific�-la.
    
    while(inicioAux != NULL){ //Enquanto o falso inicio for diferente de nulo, ele ir� receber o valor de cada n� da lista.
    
        printf("%i \n",inicioAux->elemento);
        inicioAux = inicioAux->proximo; 
        
    }
    
    
}


