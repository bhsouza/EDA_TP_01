#include <stdio.h>
#include <stdlib.h>

int main()
{
  //variaveis globais
    FILE *fp,*arquivosaida;
    int QtdLinhas = 0;
    char c;  
    int *vetorDinamico;

  typedef struct Airline{
  int id;
  char airlineCode[2];
  int delay;
}airline;
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
    vetorDinamico = malloc(QtdLinhas*sizeof(airline));
    //printf(*vetorDinamico);
    if (vetorDinamico == NULL) {
		printf("Alocação mal sucedida!");
		exit(1);
    return 0;
	}
	else{
    arquivosaida = fopen("AirlinesSaida.csv","w+");
    if (arquivosaida == NULL){
      printf("Erro na criação do arquivo de saida!");
        exit(1);
        return 0;
    }
    else{

    free(vetorDinamico);
    fclose(arquivosaida);
    }

  }
    
    return 0;
}