# include<stdlib.h>
#include<stdio.h>

    struct TElemento{
        int numero;
        TElemento *prox;
		TElemento *ant; 
   };
  struct  TFila{
  	    int quantidade;
        TElemento* ultimo;
		TElemento * inicio;
   };
   
 void enfilera(TFila *pfila,TElemento *Elemento){
        TElemento *paux,*paux2;
	    Elemento->ant=pfila->ultimo;
	    Elemento->prox=NULL;
	    if(pfila->inicio==NULL){
		 pfila->inicio=Elemento;
		}else{
		  pfila->ultimo->prox=Elemento;	
		}
		pfila->ultimo=Elemento;
 }
 
 TElemento* consulta(TFila *pfila){
        TElemento *Elemento;
		return     pfila->inicio;      
 }
  TElemento* desinfilera(TFila* pfila){
 	         TElemento *Elemento;
 	         if(pfila->inicio!=NULL){
			   Elemento=pfila->inicio;
			   pfila->inicio=pfila->inicio->prox;
		     }else{
		     	Elemento=(TElemento*)malloc(sizeof(TElemento));
		     	Elemento->numero=-1;
		      }
			 return Elemento;    
 }
  int   recebei(char* mensagem){
   	   int numero;
   	   printf(mensagem);
   	   scanf("%d",&numero);
   	   return numero;
   }
  void mostrar(TFila* pfila){
      int numero;
      TElemento* paux;
      paux=pfila->inicio;
	  while(paux!=NULL){
	  	printf("%d\n",paux->numero);
		paux=paux->prox;
	  }   	
  }
		
Tfila*	preparaenfileira(void){
        int quantidade;    	
	    pfila->quantidade=2;
	    printf("digite a quantidade de termos que voce desja acrescentar na fila");
	    scanf
	    for(cont=0;cont<2;cont++){
 	     printf("digite o  numero %d: ",cont+1);
	     scanf("%d",&numero);
	     Elemento=(TElemento*)malloc(sizeof(TElemento));
	     Elemento->numero=numero;
	     enfilera(pfila,Elemento);
	    }
   }
   
 int main(){
 	int numero;
 	TFila *pfila;
 	int cont;
 	TElemento *Elemento, *paux;
 	pfila=(TFila*)malloc(sizeof(TFila));
 	paux=(TElemento*)malloc(sizeof(TElemento));  
 	pfila->inicio=NULL;
 	pfila->ultimo=NULL;
 	
 	printf(" digite a a opcao deseja sendo 1 para enfileirar e dois para desenfilerar")
	scanf("%d",&numero);   
 	        switch()
 	
 	
	 }
	 printf("ultimo elemento: %d\n",pfila->ultimo->numero);
     mostrar(pfila);   
 	 for(cont=0;cont<3;cont++){
	  paux=desinfilera(pfila);
 	  printf("%d",paux->numero);
     }
    return 0;
    system("pause");
 	
 	 
 	
 }
 

