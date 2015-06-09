#include<stdlib.h>
#include<stdio.h>
     struct TElemento{
	     int custo;
	     int final;
	     TElemento *prox;
	};
	 struct Tpilha{
	   int quantidade;
	   TElemento *inicio;
	   TElemento *ultimo;
	};
	
	TElemento* allocaE(void){
		TElemento *Elemento;
	    Elemento=(TElemento*)malloc(sizeof(TElemento));
	    return Elemento;
	}
	
	bool empilha(Tpilha * ppilha,TElemento* Elemento){
				   TElemento *paux;
				   paux=ppilha->inicio;
				   Elemento->prox=paux;
				   ppilha->inicio=Elemento;			     
   }  
 Tpilha* preparaempilha(Tpilha *ppilha,TElemento *Elemento, int quantidade){
 	int numero,cont,final,custo;  
	for(cont=0;cont<quantidade;cont++){
		printf("digite o ponto de  final  do elmento %d",cont+1);
		scanf("%d",&final);
		printf("digite o custo do caminho %d",cont+1);
		scanf("%d",&custo);
		Elemento=allocaE();
		Elemento->final=final;
		Elemento->custo=custo;
		empilha(ppilha,Elemento);
		
	}
 }
  TElemento* desenfilera(Tpilha *ppilha){
  	     TElemento * paux;
  	     paux=ppilha->inicio;
  	     ppilha->inicio=paux->prox;   	     
		 return paux;
  } 
  Tpilha* allocamais(Tpilha *ppilha){
   	   ppilha->quantidade+1;  
   }
   
   Tpilha*  incializapilha(Tpilha *ppilha){
   		ppilha=(Tpilha*)malloc(sizeof(Tpilha));
   		ppilha->inicio=NULL;
   		ppilha->ultimo=NULL;
    	ppilha->quantidade=5;
   }
    void mostradesinpilhando(Tpilha *ppilha,int quantidade){
    	int cont;
    	TElemento *Elemento;
		for(cont=0;cont<quantidade;cont++){
	           Elemento=desenfilera(ppilha);
	           printf("%d\n",Elemento->final);
      }
   }
 
   TElemento* buscamelhor(Tpilha *ppilha){
    TElemento *pauxbest,*pauxposit,*pauxtransfer;
	pauxbest=ppilha->inicio;
	pauxposit=pauxbest->prox; 
    while(pauxposit!=NULL){
	 if(pauxbest->custo>pauxposit->custo){
	 	pauxbest=pauxposit;
	 	printf("u");
	 
	 }	
     pauxposit=pauxposit->prox;
   }
	 	 return pauxbest;
     }
	
   int main(){
   	int quantidade;
    Tpilha *ppilha;
   	TElemento *Elemento=allocaE();
   	incializapilha(ppilha); 
   	quantidade=3;
	preparaempilha(ppilha,Elemento,quantidade);
    Elemento=buscamelhor(ppilha);
	printf("%d",Elemento->final);
	return 0;
	system("pause");
   }
   
   
   
   
   
	
	
	
	
