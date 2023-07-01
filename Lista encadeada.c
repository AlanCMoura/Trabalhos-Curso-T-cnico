#include <stdio.h>
#include <stdlib.h>

typedef struct no{ 
    int elemento;
    struct no *proximo; //O ponteiro "proximo" possui um "elemento" e seu próprio ponteiro "proximo".
}no; //Criada uma struct de nome "no". Cada variável no possui um "elemento" que será atribuído a ela e um ponteiro "proximo" que aponta para o próximo nó.

typedef struct controleLista{  //Criada uma struct de controle, que irá indicar o status da fila.
    
    no *fim; // "fim" é do tipo no, logo possui "elemento" e "proximo". 
    no *inicio;  // "inicio" é do tipo no, logo possui "elemento e "próximo".
    int quantidade; 
              //"fim" e "inicio" são ponteiros porque eles apontarão para o conteúdo dos nós, sem alterá-los.
    
    //"fim" e "inicio" são nós, mas não participam diretamente da lista, eles são igualados a outros nós para que a lista não sofra alteração.
    
}controleLista; 

void inicializar(controleLista *lista); 
int inserirInicio(controleLista *lista, int elemento);
int inserirFim(controleLista *lista, int elemento);
int listaVazia(controleLista *lista);
void mostrarLista(controleLista *lista);
//obs: em todas as funções, um "lista" deverá ser recebido para que haja parâmetro de "inicio", "fim" e "quantidade". 

int main()
{
    controleLista *lista; //"lista" é um ponteiro que possui dois outros ponteiros: "fim" e "inicio", pois é do tipo "controleLista".
                          //"lista" da main representa a lista por completo e suas características.
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
//obs: todas as variáveis lista declaradas abaixo são locais e servem para representar o recebimento de valores, portanto são diferentes da presente na main.
void inicializar(controleLista *lista){ //Função que inicializa ou reinicia a lista, zerando o inicio, fim, e quantidade.
    lista->quantidade = 0;
    lista->fim = NULL;
    lista->inicio = NULL;
}

int listaVazia(controleLista *lista){ //Função auxiliar que verifica se a lista está vazia, utilizando "quantidade" como parâmetro.

    if(lista->quantidade == 0){
        return 0; //"0" significa SIM.
    }
    return 1; //"1" significa NÃO.
}

int inserirInicio(controleLista *lista, int elemento){ //Função de inserção no início da lista.
    
    no *novoNo = (no*)malloc(sizeof(no)); //Alocação de memória, declaração de um novo nó, "novoNo".
    if(novoNo == NULL){                   //obs: "novoNo" é declarado como ponteiro porque ele irá guardar um espaço de memória do malloc().
        printf("erro ao alocar memória...");
        return 1;
    }
    
    novoNo->elemento = elemento; //O elemento da struct de "novoNo" recebe o valor do elemento da fórmula, cujo valor será dado na função main().
    
   if(listaVazia(lista) == 0){ //Se a lista estiver vazia: "proximo" de "novoNo" será nulo, e "novoNo" será igual a "inicio" e "fim" da lista.
   	                            
       novoNo->proximo = NULL; 
       lista->inicio = novoNo;
       lista->fim = novoNo;
       
   }else{ //Se a lista não estiver vazia: "proximo" de "novoNo" será igual ao atual "inicio" de "lista" da struct "controleLista".
   
       novoNo->proximo = lista->inicio;
       lista->inicio = novoNo;
       
   }
   
    lista->quantidade++; //Independente de qualquer coisa, "quantidade" de "lista" irá aumentar, pois um novo nó foi criado.
    
}

int inserirFim(controleLista *lista, int elemento){ //Função para inserção no fim da lista.
    
    no *novoNo = (no*)malloc(sizeof(no)); 
    if(novoNo == NULL){
        printf("erro ao alocar memória...");
        return 1;
    }
    
    novoNo->elemento = elemento; //O elemento da struct de "novoNo" recebe o valor do elemento da fórmula, cujo valor será dado na função main().
    
    novoNo->proximo = NULL; //"proximo" de novoNo será nulo, pois o nó será inserido no fim da lista.
    
    if(listaVazia(lista) == 0){  //Mesma situação da função "inserirInicio()".
    	
        lista->inicio = novoNo;
        lista->fim = novoNo;
        
    }else{   //Se a lista não estiver vazia, "proximo" do "fim" de "lista" será igual a "novoNo", e então "fim" de "lista" será igual a "novoNo".
    	
        lista->fim->proximo = novoNo; 
        lista->fim = novoNo;
        
    }
}
//obs: o novo nó sempre deve ser inserido antes de tudo, caso contrário a lista será quebrada.

void mostrarLista(controleLista *lista){ //Função de exibição.
    
    no *inicioAux = lista->inicio;  //Um falso inicio é criado para percorrer toda a lista, sem modificá-la.
    
    while(inicioAux != NULL){ //Enquanto o falso inicio for diferente de nulo, ele irá receber o valor de cada nó da lista.
    
        printf("%i \n",inicioAux->elemento);
        inicioAux = inicioAux->proximo; 
        
    }
    
    
}


