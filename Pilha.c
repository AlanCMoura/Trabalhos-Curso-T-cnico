#include <stdio.h>

 int topo = -1; //Topo � -1 porque o ciclo de in�cio dar� 0.
 int pilha[5]; //Vetor de 5 espa�os.
 
 //Fun��es da pilha.
 void empilhar(int elemento); //Fun��o que recebe um valor e empilha.
 void desempilhar(); //Fun��o que desempilha, sempre do topo.   // sem vari�vel no par�nteses.
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
//Fun��o auxiliar.
int pilhaVazia(){ //retorno de 0 � SIM, retorno de 1 � N�O
     
     if(topo == -1){ //Se "topo" � igual a -1, ent�o a pilha est� vazia.
         return 0;
     }
     else{
         return 1;
     }    
     }
//Fun��o auxiliar.
int pilhaCheia(){ //retorno de 0 � SIM, retorno de 1 � N�O
     
     if(topo == 4){
         return 0;
     }
     else{
         return 1;
     }    
     }
     
void empilhar(int elemento){ //Empilhar (pelo topo) - Recebe "elemento" do usu�rio.
   
     if(pilhaCheia() == 0){        //Se a pilha estiver cheia, n�o d� para empilhar.
         printf("\n\nPilha cheia");
     }
     else{   //Se a pilha n�o estiver cheia, "topo" aumenta 1.
     
         topo++;
     
     pilha[topo] = elemento; //O topo atual recebe  o valor do elemento.
     
     }
}

void desempilhar(){ //Desempilhar (tirar do topo) - topo � reduzido em 1, o espa�o que � considerado pilha diminui.
    if(pilhaVazia() == 0){
        printf("\n\nA pilha est� vazia!!");
    }
    else{
        pilha[topo] = NULL;
        
        topo--; //topo = topo - 1
        
    }
}

void mostrarPilha(){ //Exibir a pilha usando "topo" como par�metro.
    
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

//nota: Uma fun��o void n�o pode ser lida num "printf()".
