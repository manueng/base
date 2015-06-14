#include<stdlib.h>
#include<stdio.h>
   struct caminho{
	     int cidade;
	     caminho *prox;
	};
   struct pontcaminho{
	   int quantidade;
	   caminho *inicio;
	   caminho *ultimo;
	};
	 struct TElemento{  
	     int custo;
	     pontcaminho *pfila;
	     int final;
	     TElemento *prox;
	};
	 struct Tpilha{
	   TElemento *inicio;
	   TElemento *ultimo;
	};
	
     

		
	caminho* allocacaminho(void){
		caminho *Elemento;
	    Elemento=(caminho*)malloc(sizeof(caminho));
	    return Elemento;
	}
	
	pontcaminho* enfilera(pontcaminho * pfila,caminho *No){
				   int cont=0;
				   caminho *paux=allocacaminho();
				   paux=pfila->inicio;
				   No->prox=paux;
				   pfila->inicio=No;
				   return pfila;			     
   }
  
   
 pontcaminho* preparaenfilera(pontcaminho *pfila,caminho *No, int numero){ 
		No=allocacaminho();
		No->cidade=numero;
		enfilera(pfila,No);
		return pfila;	
	}
  caminho* desenfilera(pontcaminho *pfila){
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
    Tpilha* empilhapilhaexterna(Tpilha *ppilha,TElemento *Elemento){
    	            TElemento *paux;
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
   
   Tpilha*  inicializapilha(Tpilha *ppilha){
   		ppilha=(Tpilha*)malloc(sizeof(Tpilha));
   		ppilha->inicio=NULL;
   		ppilha->ultimo=NULL;
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
	bool contempontofinal(int *final,int contpontofinal){
		bool contem=false;
		int cont=0;	
		while(final[cont]!=-1&&contem==false){
		   if(final[cont]==contpontofinal){
		   	contem=true;
		   }	
		   cont++;
		}
		      
	}
	
   TElemento*	gerenciabuscamelhor(int *distancia,int quantidade,int inicio,int *final){
   	    
		int contpontofinal,cont;
   	    int *valor;
   	    Tpilha *ppilha;
   	    //ppilha=(Tpilha*)malloc(sizeof(Tpilha));
   		ppilha->inicio=NULL;
   		ppilha->ultimo=NULL;
   	    TElemento *Elemento;	
   	    valor=(int*)malloc(2*sizeof(int));
   	    printf("u");
		for(contpontofinal=0;contpontofinal<quantidade;contpontofinal++){
			if(contpontofinal!=inicio&&contempontofinal(final,contpontofinal)==false){
			  valor[1]=distancia[contpontofinal];
			  valor[2]=contpontofinal;
			  ppilha=empilha(ppilha,valor);
		    }
		}
			    	
		  Elemento=buscamelhor(ppilha);
	
		return Elemento;	
		   
    }
   
 int  avaliacaminho(pontcaminho *pfila){
    int cont=0;
    caminho *paux;
   while(paux!=NULL){
	  printf("%d\n",paux->cidade);
	  paux=paux->prox;
	  cont++;
    }
 }
 bool caminhocontem(pontcaminho *pfila,int numero){
     caminho *paux;
     bool contem=false;
	 while(paux!=NULL&&contem==false){
	     if(numero==paux->cidade)
		   contem=true; 	
		 paux=paux->prox;
	 }
     return contem;
 } 
 int ultimacidade(pontcaminho *pfila){
 	caminho* paux,*ultimo;
 	paux=pfila->inicio;
 	while(paux!=NULL){
 	    if(paux->prox==NULL){
 	      ultimo=paux;	
		}
		paux=paux->prox;
	 }
	 
    return ultimo->cidade; 
 }
 
 TElemento* encontraelemento(pontcaminho* pfila,int inicio, int **distancia,int quantidade,int *pontodepartida){
    TElemento *Elemento;

   if(inicio!=ultimacidade(pfila)){
               
		     Elemento=gerenciabuscamelhor(distancia[inicio],quantidade, inicio,pontodepartida);
	}
	return Elemento;
  }
  int* encontrapontodepartida(TElemento *paux, int *pontodepartida){
	int cont=0;
	  while(paux!=NULL){
	  	if(paux->pfila->inicio!=NULL){
          pontodepartida=(int*)realloc(pontodepartida,sizeof(int));   
		  pontodepartida[cont]=ultimacidade(paux->pfila);
		  pontodepartida[cont+1]=-1;
 	      paux=paux->prox; 
		  cont++; 
	    }
	}
	return pontodepartida;
 }
 Tpilha* encontrapilha(Tpilha *ppilha,TElemento *Elemento,int inicio,int**distancia, int quantidade,int *pontodepartida){ 
        return empilhapilhaexterna(ppilha,encontraelemento(Elemento->pfila,inicio,distancia,quantidade,pontodepartida));
 }
 
  caminho* setaNo(int pontofinal){
  	   caminho* no;
  	   no=(caminho*)malloc(sizeof(caminho));
  	   no->cidade=pontofinal;
  	   return no;
  }
 TElemento* encontraElemento(TElemento* paux,Tpilha *ppilha,int inicio, int **distancia, int quantidade,int *pontodepartida){
	Tpilha *puaxpilha;
	puaxpilha=(Tpilha*)malloc(sizeof(Tpilha));
	ppilha=inicializapilha(ppilha);
	TElemento *Elemento;
	Elemento=(TElemento*)malloc(sizeof(TElemento));
	Elemento->pfila->inicio=NULL;
    ppilha=encontrapilha(ppilha,Elemento,inicio,distancia,quantidade,pontodepartida);
   while(avaliacaminho(Elemento->pfila)<quantidade-2){
     	pontodepartida=encontrapontodepartida(paux,pontodepartida);
        while(paux!=NULL){
		  ppilha=encontrapilha(ppilha,Elemento,inicio,distancia,quantidade,pontodepartida);
          paux=paux->prox;
          
		}
		Elemento=buscamelhor(ppilha);
        Elemento->pfila=enfilera(Elemento->pfila,setaNo(Elemento->final));
		ppilha=empilhapilhaexterna(ppilha,Elemento); 	   
   }
   return Elemento;
}
TElemento* gerenciabfs(int quantidade, int inicio,int **distancia){
      int *pontodepartida,cont;
	  TElemento *paux;
      int final;
      final=inicio;
      paux=(TElemento*)malloc(sizeof(TElemento));
      TElemento *Elemento;  
      Elemento=(TElemento*)malloc(sizeof(TElemento));
      Tpilha *ppilha;
      pontodepartida=(int*)malloc(2*sizeof(int));
      paux=ppilha->inicio;
	  paux=NULL;
      pontodepartida=encontrapontodepartida(paux,pontodepartida);
      return encontraElemento(paux,ppilha, inicio,distancia, quantidade,pontodepartida);
    }
   int main(){
   	int **distancia;
   	int  *distancia2; 
   	int inicio=0;
    int quantidade=3;// para adaptar deve-se setar quantidade para  27;
    distancia=geradados(quantidade);
    int cont=0;
   	TElemento *paux;
   	pontcaminho *pfila=inicializafila();
   	TElemento *Elemento;
	Elemento=(TElemento*)malloc(1*sizeof(TElemento));
//	paux->pfila->=pfila->inicio;
    printf("digite o numero da cidade de inicio variando de 0 a 2");
    scanf("%d",&inicio);
    gerenciabfs( quantidade, inicio,distancia);
   }
   
   
   
   
   
	
	
	
	
