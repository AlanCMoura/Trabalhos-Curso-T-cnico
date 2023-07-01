#include <stdio.h>

int fim = 0;
int inicio = 0;
int quantidade;
int tamanho = 5;
int fila[5];

void inserirFila(int elemento); //Fun��o que insere um "elemento" designado pelo usu�rio.
int retirarFila();
void mostrarFila();

int filaCheia(); //Fun��o para verificar se a fila est� cheia.

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

int filaCheia(){ //Se a quantidade for maior ou igual a 5 (tamanho da fila), a fila est� cheia.
    if(quantidade >= 5){
       return 0;
    }
    else{
    return 1;
    }
}

void inserirFila(int elemento){ //Inserir sempre pelo fim.
	
    if(filaCheia() == 0){ //Se a fila estiver cheia, n�o ser� poss�vel inserir mais nada.
        printf("\nFila Cheia\n");
    }
    else{
        fila[fim] = elemento; //Se a fila n�o estiver cheia, o vetor de index "fim" receber� "elemento".
        fim++; //"fim" avan�a 1 index, para que o pr�ximo "elemento" seja recebido pelo index seguinte.
        quantidade++; //Quantidade aumenta em 1, pois um "elemento" foi inserido na fila.
       
        if(fim > tamanho -1){ //Quando "fim" for maior que tamanho - 1, "fim" voltar� a valer 0 -> (os espa�os de index v�o de 0 a 4 apenas).
            fim = 0;          //Lembrando: "quantidade" e "tamanho" v�o de 1 a 5; "fim" e "inicio" v�o de 0 a 4. 
            
        }
    }
    }

int retirarFila(){
	
    if(quantidade == 0){ //N�o � poss�vel retirar algo de uma fila vazia.
        printf("Fila Vazia");
        
    }else{
    	int elemento;
        fila[inicio] = elemento;
        inicio++; //"inicio" avan�a +1 index.
        quantidade--; //"quantidade diminui em 1, devido � retirada.
        
        if(inicio > tamanho - 1){ //Assim como no caso do "fim", sempre que "inicio" ultrapassar o index 4, inicio = 0.
            inicio = 0;
            
        }
    }
   
    }
   
void mostrarFila(){
	
    printf ("\nfila\n");
    
    int iniciofor = inicio; //Valor de "inicio" � dado a um falso inicio para que "inicio" original n�o sofra altera��es.
    
    for(int i = 0; i < tamanho; i++){ //Enquanto i = 0 for menor que "tamanho", o "inicio" de auxiliar ser� lido e avan�ar� +1 index.
        printf ("%i\n",fila[iniciofor]);
        iniciofor++;
        if(iniciofor>= 5){ //A condi��o de voltar a 0 quando estourar o limite continua.
            iniciofor =0;
           
        }
}
}
