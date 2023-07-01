#include <stdio.h>

int fim = 0;
int inicio = 0;
int quantidade;
int tamanho = 5;
int fila[5];

void inserirFila(int elemento); //Função que insere um "elemento" designado pelo usuário.
int retirarFila();
void mostrarFila();

int filaCheia(); //Função para verificar se a fila está cheia.

//////////////////////////////////////////////////////////
int main()
{
   inserirFila(1);
   inserirFila(2);
   inserirFila(3);
   retirarFila();
   inserirFila(4);
   inserirFila(5);
   
   
   mostrarFila();
    return 0;
}
//////////////////////////////////////////////////////////

int filaCheia(){ //Se a quantidade for maior ou igual a 5 (tamanho da fila), a fila está cheia.
    if(quantidade >= 5){
       return 0;
    }
    else{
    return 1;
    }
}

void inserirFila(int elemento){ //Inserir sempre pelo fim.
	
    if(filaCheia() == 0){ //Se a fila estiver cheia, não será possível inserir mais nada.
        printf("\nFila Cheia\n");
    }
    else{
        fila[fim] = elemento; //Se a fila não estiver cheia, o vetor de index "fim" receberá "elemento".
        fim++; //"fim" avança 1 index, para que o próximo "elemento" seja recebido pelo index seguinte.
        quantidade++; //Quantidade aumenta em 1, pois um "elemento" foi inserido na fila.
       
        if(fim > tamanho -1){ //Quando "fim" for maior que tamanho - 1, "fim" voltará a valer 0 -> (os espaços de index vão de 0 a 4 apenas).
            fim = 0;          //Lembrando: "quantidade" e "tamanho" vão de 1 a 5; "fim" e "inicio" vão de 0 a 4. 
            
        }
    }
    }

int retirarFila(){
	
    if(quantidade == 0){ //Não é possível retirar algo de uma fila vazia.
        printf("Fila Vazia");
        
    }else{
    	int elemento;
        fila[inicio] = elemento;
        inicio++; //"inicio" avança +1 index.
        quantidade--; //"quantidade diminui em 1, devido à retirada.
        
        if(inicio > tamanho - 1){ //Assim como no caso do "fim", sempre que "inicio" ultrapassar o index 4, inicio = 0.
            inicio = 0;
            
        }
    }
   
    }
   
void mostrarFila(){
	
    printf ("\nfila\n");
    
    int iniciofor = inicio; //Valor de "inicio" é dado a um falso inicio para que "inicio" original não sofra alterações.
    
    for(int i = 0; i < tamanho; i++){ //Enquanto i = 0 for menor que "tamanho", o "inicio" de auxiliar será lido e avançará +1 index.
        printf ("%i\n",fila[iniciofor]);
        iniciofor++;
        if(iniciofor>= 5){ //A condição de voltar a 0 quando estourar o limite continua.
            iniciofor =0;
           
        }
}
}
