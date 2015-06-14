#include<stdlib.h>
#include<stdio.h>
     struct TElemento{  
	     int custo;
	     pontcamainho *pfila;
	     int final;
	     TElemento *prox;
	};
	 struct Tpilha{
	   int quantidade;
	   TElemento *inicio;
	   TElemento *ultimo;
	};
	struct caminhov{
		 int* caminho;
		 int quantidepercorrida;
	};
	 struct caminho{
	     int cidade;
	     TElemento *prox;
	};
	 struct pontcaminho{
	   int quantidade;
	   Tno *inicio;
	   Tno *ultimo;
	};
		
	Tno* allocaNo(void){
		Tno *Elemento;
	    Elemento=(Tno*)malloc(sizeof(Tno));
	    return Elemento;
	}
	
	pontcaminho* enfilera(pontcaminho * pfila,caminho* No){
				   int cont=0;
				   caminho *paux=allocaE();
				   paux=pfila->inicio;
				   No->prox=paux;
				   pfila->inicio=No;
				   return pfila;			     
   }
  
   
 pontcaminho* preparaenfilera(pontcaminho *pfila,caminho *No, int numero){ 
		No=allocaNo();
		No->cidade=numero;
		enfilera(pfila,No);
		return pfila;	
	}
 }
  TNo* desenfilera(pontcaminho *pfila){
  	     caminho* paux;
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
   
  int**	alocamatriz(int quantidade){
  	int **distancia;
  	int cont;
  	 distancia=(int**)malloc(quantidade*sizeof(int*));
  	for(cont=0;cont<quantidade;cont++){
  	   distancia[cont]=(int*)malloc(sizeof(int)); 	
	}
  }
    Tpilha* empilhapilhaexterna(Tpilha *ppilha,TElemento){
    	            TElemento *paux,*Elemento;
					paux=ppilha->inicio;
					Elemento->prox=paux;
					ppilha->inicio=Elemento;	
				    return ppilha;		    
	}     
	
	Tpilha* empilha(Tpilha * ppilha, int *valor){
				   TElemento *paux,*Elemento;
				   Elemento=(TElemento*)malloc(sizeof(TElemento));
				   paux=ppilha->inicio;
				   Elemento->prox=paux;
				   Elemento->custo=valor[1];
				   Elemento->final=valor[2];
				   ppilha->inicio=Elemento;	
				   return ppilha;		     
   }  
 void  mostra(Tpilha *ppilha,int  quantidade){
            int cont;
            TElemento* Elemento;
            Elemento=ppilha->inicio;
            printf("inicio %d\n",ppilha->inicio->final);
           while(Elemento!=NULL){
		    printf("%d\n",Elemento->custo);
		    Elemento=Elemento->prox;
          }
		     
 }		   
  Tpilha* desenfilera(Tpilha *ppilha){
  	     TElemento *paux;
  	     paux=ppilha->inicio;
  	     ppilha->inicio=paux->prox;
  	     //free(paux);	     
		 return ppilha;
  } 
  Tpilha* allocamais(Tpilha *ppilha){
   	   ppilha->quantidade+1;  
   }
   
   Tpilha*  inicializapilha(Tpilha *ppilha){
   		ppilha=(Tpilha*)malloc(sizeof(Tpilha));
   		ppilha->inicio=NULL;
   		ppilha->ultimo=NULL;
    	ppilha->quantidade=5;
    	return ppilha;
   }
    void mostradesempilhando(Tpilha *ppilha,int quantidade){
    	int cont;
		for(cont=0;cont<quantidade;cont++){
	           ppilha=desenfilera(ppilha);
	           printf("%d\n",ppilha->inicio->final);
      }
   }
 
   TElemento* buscamelhor(Tpilha *ppilha){
    TElemento *pauxbest,*pauxposit,*pauxtransfer;
	pauxbest=ppilha->inicio; 
	pauxposit=pauxbest->prox; 
    while(pauxposit!=NULL){
	 if(pauxbest->custo>pauxposit->custo){
	 	pauxbest=pauxposit;
	 
	  }	
      pauxposit=pauxposit->prox;
      if(pauxposit==NULL){
         printf("arquivo chegou ao fim");               
      }
      printf("u");
     }
	 	 return pauxbest;
    }
    
	int** geradados(int quantidade){
	  printf("%d",quantidade);
	  int numero,final,custo,inicio;
	  int contpontodeinicio=0;
	  int contpontofinal=0;
	  int **distancia;
	  distancia= (int**)malloc(quantidade*sizeof(int*)) ;	
	 for(contpontodeinicio=0;contpontodeinicio<quantidade;contpontodeinicio++){
	  distancia[contpontodeinicio]=(int*)malloc(quantidade*sizeof(int)); 
	  for(contpontofinal=0;contpontofinal<quantidade;contpontofinal++){
		  printf("digite o custo do caminho da cidade %d para a cidade%d",contpontodeinicio+1,contpontofinal+1);
		  scanf("%d",&distancia[contpontodeinicio][contpontofinal]);// para addpatar basta colocar a funcao de leitura do arquivo aqui. 	  
      }
	}
    return distancia;
   }
    void mostramatriz(int **distancia,int quantidade){
    	 int contpontodeinicio,contpontofinal;
    for(contpontodeinicio=0;contpontodeinicio<quantidade;contpontodeinicio++){
	  for(contpontofinal=0;contpontofinal<quantidade;contpontofinal++){
	  	printf(" o custo de ir da cidade %d para cidade %d e %d\n", contpontodeinicio,contpontofinal,distancia[contpontodeinicio][contpontofinal]);
	  }	
	}
	}
	
   Elemento*	gerenciabuscamelhor(int *distancia,int quantidade){
   	    int contpontofinal,cont;
   	    int *valor;
   	    Tpilha *ppilha;
   	    TElemento *Elemento;
   	    ppilha=inicializapilha(ppilha);
   	    valor=(int*)malloc(2*sizeof(int));
		for(contpontofinal=0;contpontofinal<quantidade;contpontofinal++){
			valor[1]=distancia[contpontofinal];
			valor[2]=contpontofinal;
			ppilha=empilha(ppilha,valor);
		}
			    	
		  Elemento=buscamelhor(ppilha);
		return Elemento;	   
    }
   
 int  avaliacaminho(pontcaminho *pfila){
    int cont=0;
    Tno *paux;
   while(paux!=NULL){
	  printf("%d\n",Elemento->cidade);
	  paux=paux->prox;
	  cont++;
    }
 }
 bool caminhocontem(pontcaminho *pfila,int numero){
     Tno *paux;
     bool contem=false;
	 while(paux!=NULL&&contem==false){
	     if(numero==paux->cidade)
		   contem=true; 	
		 paux=paux->prox;
	 }
     return contem;
 } 
 int ultimacidade(pontcaminho *pfila){
 	Tno* paux,*ultimo;
 	while(paux!=NULL){
 	    if(paux->prox==NULL){
 	      ultimo=paux;	
		}
		paux=paux->prox;
	 }
    return ultimo->cidade; 
 }
 
 TElemento* encontraelemento(pontcaminho* pfila, int inicio){
    TElemento *Elemento;    
   if(inicio!=ultimacidade(pfila)){
		     pontodepartida=ultimacidade(pfila);  
		     Elemento=gerenciabuscamelhor(distancia[pontodepartida],quantidade);
	}
	return Elemento;
  }
TElemento* gerenciabfs(int quantidade,pontcaminho *pfila, int inicio,int **distancia){
      int pontodepartida,cont,caminho *paux;
      paux=(camainho*)malloc(sizeof(caminho));
      TElemento *Elemento;  
      Tpilha *ppilha;
      inicializapilha(ppilha)
     while(avaliacaminho(pfila)<quantidade){
        for(cont=0;cont<quantidade;cont++){
		  ppilha=empilhapilhaexterna(ppilha,encontraelemento(pfila,inicio));
          Elemento=gerenciabuscamelhor(distancia[inicio],quantidade); 
		}
		Elemento=buscamelhor(ppilha)
		paux->cidade=Elemento->final
        Elemento->pfila=enfilera(Elemento->pfila,paux); 	   
   }
}
   int main(){
   	int **distancia;
   	int  *distancia2; 
   	int inicio=0;
    int quantidade=3;// para adpatar deve-se setar quantidade para  27;
    distancia=geradados(quantidade);
    int quantidade,cont=0;
   	TElemento *paux;
   	pontcaminho *pfila=inicializafila();
   	TElemento *Elemento=allocaE();
	paux=pfila->inicio;
    printf("digite o numero da cidade de inicio variando de 0 a 2");
    scanf("%d",&inicio);
    printf("u");
    
   }
   
   
   
   
   
	
	
	
	
