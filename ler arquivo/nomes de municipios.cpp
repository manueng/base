# include <stdlib.h>
# include<stdio.h>
 struct Tdado{
 	       Tdado *ida[28];
 	       Tdado *retorno[28];
 }; 




 char** leprimeiralinha(FILE *arq){
              int cont,cont2=0;
              char **nome;
              nome=(char**)malloc(28*sizeof(char*));
              for(cont=0;cont<28;cont++){
                 nome[cont]=(char*)malloc(20*sizeof(char));
              }
             for(cont=0;cont<28;cont++){
              while((nome[cont][cont2]=fgetc(arq))!=' '){
                  cont2++;
			  }
		     }
			 for(cont=0;cont<28;cont++){
			     printf("%s",nome[cont]);   
			 } 
              return nome;			  
             }
 int**  lenumeros(FILE *arq){
 	     int contaux,contletra=0,contmunicipios;
		 int **distancias;
		 char numero[4];
		 int *distancia;
		 distancias=(int**)malloc(27*sizeof(int*));
		 for(contaux=0;contaux<28;contaux++){
		 	distancias[contaux]=(int*)malloc(20*sizeof(int));
	     }
	    for(contmunicipios=0;contmunicipios<28;contmunicipios++){
	     for(contaux=0;contaux<28;contaux++){
	        while((numero[contletra]=fgetc(arq))!=' '){
	        	contletra++;
			}  
			arq++;
			if(numero[0]!='x'){
			    *distancia=atoi(numero);
			    printf("%d",*distancia);
			}
			printf("u");	
	      }
		 }
	  return distancias;  
 	
 }
             


FILE* abriarquivo(FILE* arq){
	bool result;
	arq=fopen("distancias_TSAIII2.txt","r");
	if(arq==NULL){
		printf("o arquivo nao foi aberto");
		result=false;
	}else{
		printf("o arquivo foi aberto com sucesso");
		result=true;
	}
	return arq;
}



int main(){
	FILE *arq;
	arq=NULL;
	char **nome;
	arq=abriarquivo(arq);
	if(arq!=NULL){
	 nome=leprimeiralinha(arq);
	 lenumeros(arq);
    }
    return 0;
}


