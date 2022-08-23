#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Airline{
  int id;
  char airlineCode[3];
  int delay;
}airline;

int AloVet(FILE *vArqEnt,airline vetor[])
{
int s=0,i=1;
char c,Linha[14],*result;
printf("Entrou\n");

while (!feof(vArqEnt)){
if (s==0)
{
for (c = getc(vArqEnt); c != EOF; c = getc(vArqEnt))
      if (c == '\n') 
        break;
}


//printf("%d\n", s);

if (!fscanf(vArqEnt,"%d,%[^,],%d",&vetor[s].id,vetor[s].airlineCode, &vetor[s].delay)){
printf("Erro ao Scanear o arquivo."); 
break;
}    

printf("\n%d,%s,%d", vetor[s].id,vetor[s].airlineCode,vetor[s].delay);
s++;
} 
     
 return 0;
}

int main()
{
  //variaveis globais
    FILE *fp,*arquivosaida;
    int QtdLinhas = 0;
    char c;  
    airline *vetorDinamico;

  //abre o arquivo e conta as linhas para alocar um vetor na memoria
    fp = fopen("AirlinesDataSetTeste.csv", "r");
  
    if (fp == NULL)
    {
        printf("Nao foi possivel abrir o arquivo.");
        exit(1);
        return 0;
    }

    for (c = getc(fp); c != EOF; c = getc(fp))
      if (c == '\n') 
        QtdLinhas++;
        fclose(fp);

    printf("O arquivo tem %d linhas\n ", QtdLinhas);
    //alocaçao dinamica na memoria
    vetorDinamico = (airline *)malloc(QtdLinhas*sizeof(airline));
    //printf(*vetorDinamico);
    if (vetorDinamico == NULL) {
		printf("Alocação mal sucedida!");
		exit(1);
    return 0;
	}
	else{
    fp = fopen("AirlinesDataSetTeste.csv", "r");
    AloVet(fp,vetorDinamico); 
    fclose(fp);
    //Func Aqui
    
    /*
    arquivosaida = fopen("AirlinesSaida.csv","w+");
    if (arquivosaida == NULL){
      printf("Erro na criação do arquivo de saida!");
        exit(1);
        return 0;
    }
    else{

    
    fclose(arquivosaida);
    }
    */
    free(vetorDinamico);
    }
    return 0;
}
