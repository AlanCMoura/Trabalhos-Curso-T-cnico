#include <stdio.h>

 int topo = -1; //Topo é -1 porque o ciclo de início dará 0.
 int pilha[5]; //Vetor de 5 espaços.
 
 //Funções da pilha.
 void empilhar(int elemento); //Função que recebe um valor e empilha.
 void desempilhar(); //Função que desempilha, sempre do topo.   // sem variável no parênteses.
 int pilhaVazia();
 int pilhaCheia();
 void mostrarPilha();
 
 //Opcionais.
 void topoPilha();
 void basePilha();
 void pesquisar(int index);
 
////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    empilhar(10);
    empilhar(20);
    empilhar(30);
    empilhar(40);
    empilhar(50);
    
    mostrarPilha();
    
    topoPilha();
    basePilha();
    pesquisar(1);
    

    return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////}
//Função auxiliar.
int pilhaVazia(){ //retorno de 0 é SIM, retorno de 1 é NÃO
     
     if(topo == -1){ //Se "topo" é igual a -1, então a pilha está vazia.
         return 0;
     }
     else{
         return 1;
     }    
     }
//Função auxiliar.
int pilhaCheia(){ //retorno de 0 é SIM, retorno de 1 é NÃO
     
     if(topo == 4){
         return 0;
     }
     else{
         return 1;
     }    
     }
     
void empilhar(int elemento){ //Empilhar (pelo topo) - Recebe "elemento" do usuário.
   
     if(pilhaCheia() == 0){        //Se a pilha estiver cheia, não dá para empilhar.
         printf("\n\nPilha cheia");
     }
     else{   //Se a pilha não estiver cheia, "topo" aumenta 1.
     
         topo++;
     
     pilha[topo] = elemento; //O topo atual recebe  o valor do elemento.
     
     }
}

void desempilhar(){ //Desempilhar (tirar do topo) - topo é reduzido em 1, o espaço que é considerado pilha diminui.
    if(pilhaVazia() == 0){
        printf("\n\nA pilha está vazia!!");
    }
    else{
        pilha[topo] = NULL;
        
        topo--; //topo = topo - 1
        
    }
}

void mostrarPilha(){ //Exibir a pilha usando "topo" como parâmetro.
    
    if(pilhaVazia() == 0)
    {
    	printf("\nFila vazia\n");
	}else{
	
	
    printf("TOPO\n");
    for(int i = topo; i > -1; i--){ //ou seja: enquanto "topo" for maior que -1 ('index' vazio); "topo" diminui 1.
        printf("%i\n", pilha[i]);
    }
    printf("BASE");
}
}

void topoPilha(){

    printf("\n\nTopo atual: %i\n", pilha[topo]);

}

void basePilha(){
	
	if(pilhaVazia() == 0)
    {
    	printf("\nFila vazia\n");
	}else{
		
	printf("\nBase atual: %i\n", pilha[0]);
}
}

void pesquisar(int index){
	
	printf("\nAtual index %i: %i\n", index, pilha[index]);
	
}

//nota: Uma função void não pode ser lida num "printf()".
