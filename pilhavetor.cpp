# include<stdlib.h>
# include<stdio.h>

struct Tpilha{
	int topo;
	int idades[5];
};


Tpilha* esvazia (Tpilha* pilha){
	    pilha->topo=-1;
	    return pilha;
}
bool empilha(Tpilha *pilha,int idade){
       bool result; 
       
       if(pilha->topo<4){
       	pilha->topo=pilha->topo+1;
       	pilha->idades[pilha->topo]=idade;
       	result= true;
	   }else{
	   	result= false;
	   }    
	   return result;	
}
int consulta(Tpilha *pilha){
    int idade=pilha->idades[pilha->topo];
	return idade;
}
int desempilha(Tpilha *pilha){
	int idade=pilha->idades[pilha->topo];
	pilha->topo=pilha->topo-1;
	return idade;
}
int main(){
  int idade;
  Tpilha* pilha;
  pilha=(Tpilha*)malloc(sizeof(Tpilha));
  pilha->topo=-1;
  printf("digite uma idade a ser adionada na pilha");
  scanf("%d",&idade);
  empilha(pilha,idade);
  printf("%d",desempilha(pilha));
  printf("%d",desempilha(pilha));	
	
}
