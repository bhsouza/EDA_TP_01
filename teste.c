#include <stdio.h>
#include <stdlib.h>

typedef struct Airline{
  int id;
  char airlineCode[2];
  int delay;
}airline;
int AloVet(FILE *vArqEnt,airline *vetor)
{
int s,i=1;
char c,Linha[7],*result;
fflush(vArqEnt);
printf("Entrou");
while (!feof(vArqEnt))
  {
	// Lê uma linha (inclusive com o '\n')
      result = fgets(Linha, 100, vArqEnt);  // o 'fgets' lê até 99 caracteres ou até o '\n'
      if (result)  // Se foi possível ler
      //strtok(result,",")
      airline[i]->id = 
      i++;
  }
  fclose(arq);
for (c = getc(vArqEnt); c != EOF; c = getc(vArqEnt)){
if (!fscanf(vArqEnt,"%d;%s;%d",&vetor->id,vetor->airlineCode,&vetor->delay)){
printf("Erro ao Scanear o arquivo."); 
break;
}    

printf(&vetor->id,vetor->airlineCode,&vetor->delay);
s++;
if (s=2){
break;
}
      
      /*
      V = gera_vet_aleatorio(n);
      for(p=0;p<n;p++)
        printf("\n %d:%d", p, V[p]);
        break;
      */
}      
 return 1;
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
    
    AloVet(fp,vetorDinamico); 
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
    fclose(fp);
    return 0;
}
