#include<stdlib.h>
#include<stdio.h>
     struct TElemento{
	     int cidade;
	     TElemento *prox;
	};
	 struct pontcaminho{
	   int quantidade;
	   TElemento *inicio;
	   TElemento *ultimo;
	};
	
	TElemento* allocaE(void){
		TElemento *Elemento;
	    Elemento=(TElemento*)malloc(sizeof(TElemento));
	    return Elemento;
	}
	
	pontcaminho* enfilera(pontcaminho * pfila,TElemento* Elemento){
				   int cont=0;
				   TElemento *paux=allocaE();
				   paux=pfila->inicio;
				   Elemento->prox=paux;
				   pfila->inicio=Elemento;
				   return pfila;			     
   }
  TElemento* consulta(pontcaminho *pfila){
    TElemento *Elemento;
	if(pfila!=NULL){
	  Elemento=pfila->inicio;
	}else{
	  Elemento=allocaE();	
	  Elemento->cidade=-1; 
	}
	return Elemento; 
   		
  }
   
 pontcaminho* preparaenfilera(pontcaminho *pfila,TElemento *Elemento, int quantidade){
 	int numero,cont;  
	for(cont=0;cont<quantidade;cont++){
	    printf("digite o numero %d:",cont+1);	
		scanf("%d",&numero);
		Elemento=allocaE();
		Elemento->cidade=numero;
		enfilera(pfila,Elemento);
		
	}
 }
  TElemento* desenfilera(pontcaminho *pfila){
  	     TElemento * paux;
  	     paux=pfila->inicio;
  	     pfila->inicio=paux->prox;   	     
		 return paux;
  } 
   pontcaminho* inicializafila(){
   	pontcaminho *pfila;
   	pfila=(pontcaminho*)malloc(sizeof(pontcaminho));
   	pfila->inicio=NULL;
    pfila->quantidade=5;
    return pfila;
   }
   
   
   int main(){
   	int quantidade,cont=0;
   	TElemento *paux;
   	pontcaminho *pfila=inicializafila();
   	TElemento *Elemento=allocaE();
   	printf("digite a quantidade de numeros");
   	scanf("%d",&quantidade);
	preparaenfilera(pfila,Elemento,quantidade);
	paux=pfila->inicio;
	while(paux!=NULL){
	  Elemento=desenfilera(pfila);
	  printf("%d\n",Elemento->cidade);
	  paux=paux->prox;
    }
	return 0;
	system("pause");
   }
   
   
   
   
   
	
	
	
	
