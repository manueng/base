#include<stdlib.h>
#include<stdio.h>
     struct TElemento{
	     int numero;
	     TElemento *prox;
	};
	 struct TFila{
	   int quantidade;
	   TElemento *inicio;
	   TElemento *ultimo;
	};
	
	TElemento* allocaE(void){
		TElemento *Elemento;
	    Elemento=(TElemento*)malloc(sizeof(TElemento));
	    return Elemento;
	}
	
	bool enfilera(TFila * pfila,TElemento* Elemento){
				   int cont=0;
				   TElemento *paux=allocaE();
				   paux=pfila->inicio;
				   Elemento->prox=paux;
				   pfila->inicio=Elemento;			     
   }
   TElemento* consulta(TFila *pfila){
    TElemento *Elemento;
	if(pfila!=NULL){
	  Elemento=pfila->inicio;
	}else{
	  Elemento=allocaE();	
	  Elemento->numero=-1; 
	}
	return Elemento; 
   		
  }
   
 TFila* preparaenfilera(TFila *pfila,TElemento *Elemento, int quantidade){
 	int numero,cont;  
	for(cont=0;cont<quantidade;cont++){
	    printf("digite o numero %d:",cont+1);	
		scanf("%d",&numero);
		Elemento=allocaE();
		Elemento->numero=numero;
		enfilera(pfila,Elemento);
		
	}
 }
  TElemento* desenfilera(TFila *pfila){
  	     TElemento * paux;
  	     paux=pfila->inicio;
  	     pfila->inicio=paux->prox;   	     
		 return paux;
  } 
   
   
   int main(){
   	int quantidade,cont=0;
   	TFila *pfila;
   	TElemento *Elemento=allocaE();
   	pfila=(TFila*)malloc(sizeof(TFila));
   	pfila->inicio=NULL;
    pfila->ultimo=NULL;
    pfila->quantidade=5;
    printf("digite a quantidade de elemento que deseja incluir na fila");
    scanf("%d",&quantidade);
	preparaenfilera(pfila,Elemento,quantidade);
	for(cont=0;cont<quantidade;cont++){
	  Elemento=desenfilera(pfila);
	  printf("%d\n",Elemento->numero);
    }
	return 0;
	system("pause");
   }
   
   
   
   
   
	
	
	
	
