#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct airline{
  int  id;
  char airlineCode[3];
  int  delay;
  int  contada;
}airline;

typedef struct sub_airline{
  char   airlineCode[3];
  int    quant_delay;
  int    total;
  float  media;
}sub_airline;

int ValArq(FILE *fp){
  if (fp == NULL){
      printf("Nao foi possivel abrir o arquivo.");
      return 0;
    }
  return 1;
}

void InsertSort(sub_airline VetAir[],int QtdAir)
{
  int e=0,f=0;
  sub_airline VetSub;
  for (e=1; e < QtdAir; e++) {
    VetSub = VetAir[e];
    for (f=e; (f>0) && (VetSub.media < VetAir[f-1].media);f--)
      {
        VetAir[f] = VetAir[f-1];
      }
    VetAir[f]= VetSub;
  }
}

int AloVet(FILE *vArqEnt,airline vetor[],int QtdVet){
  int e=0,f=0,g=0,s=0,QtdAir=0,ValTot=0,ValDel=0;
  char c,ProVet[3];
  sub_airline *vetair,VetSub;
  FILE *arquivosaida;
  vArqEnt = fopen("AirlinesDataSetTeste.csv", "r");
  if (ValArq(vArqEnt))
  {
    //Percorre o Arquivo
    while (!feof(vArqEnt)){
      //Pular o Cabeçalho
      if (s==0){
        for (c = getc(vArqEnt); c != EOF; c = getc(vArqEnt))
          if (c == '\n') 
            break;
      }
      //Preencher o vetor com os dados da DataBase.
      if (!fscanf(vArqEnt,"%d,%[^,],%d",&vetor[s].id,vetor[s].airlineCode, &vetor[s].delay)){
        printf("Erro ao Scanear o arquivo."); 
        break;
      }   
      //printf para acompanhar
      printf("\n%d,%s,%d", vetor[s].id,vetor[s].airlineCode,vetor[s].delay);
      s++;
    }
    fclose(vArqEnt);
    //Definir os vetores para contar como 0 para trabalho no For abaixo. 
    for(e=0;e <= QtdVet;e++){
      vetor[e].contada = 0;
    }
    //Contar quantas linhas aereas sao unicas e definir 1 para unica no contada e 0 para repetida
    for (e = 0; e < QtdVet; e++){
      if (vetor[e].contada == 1){
        vetor[e].contada = 0;
        continue;    
      }
      else{
        for(f=0;f < QtdVet;f++){  
          if(strcmp(vetor[e].airlineCode,vetor[f].airlineCode) == 0){
            if(vetor[f].contada == 0){
              vetor[f].contada = 1;
            }
          }
        }
        QtdAir++;        
      }
    }
    //printf para acompanhar a quantidade de empresas. 
    printf("\n%d Empresas",QtdAir);
    //printf para acompanhar as empresas contadas. 
    for(e=0;e < QtdVet;e++){
      printf("\n%d",vetor[e].contada);
    }
    //alocar memoria para nova struct com os dados finais.
    vetair = (sub_airline*)malloc(QtdAir*sizeof(sub_airline));
    if (vetair == NULL){
		  printf("Alocação mal sucedida!");
		  exit(1);
      return 0;
	  }
    else
    {
      //achar a média e preencher no struct secundário.
      for (e = 0; e < QtdVet; e++){
        if (vetor[e].contada==1)
        {
          ValTot=0;
          ValDel=0;
          for(f=0;f < QtdVet;f++){
            if(strcmp(vetor[e].airlineCode,vetor[f].airlineCode) == 0)
            {
              if (vetor[f].delay==1)
              {
                ValDel++;
              }
              ValTot++;
            }
          }
          sprintf(vetair[g].airlineCode,"%s",vetor[e].airlineCode);
          vetair[g].quant_delay=ValDel;
          vetair[g].total=ValTot;
          vetair[g].media=(float)ValDel/ValTot;
          g++;
        }
      }
      //Liberar o vetor primário pois não será mais usado
      free(vetor);
      //Insert Sort para Ordenar struct secundário por média.
      InsertSort(vetair,QtdAir);

      //Printf para Acompanhamento do Struct secundário
      for (g = 0; g < QtdAir; g++)
      {
        printf("\nTeste Struct (%s,%d,%d,%f)",vetair[g].airlineCode,vetair[g].quant_delay,vetair[g].total,vetair[g].media); 
      }
      //Cria Arquivo de Saida
      arquivosaida = fopen("AirlinesSaida.csv","w+");
      if (arquivosaida == NULL){
        printf("Erro na criação do arquivo de saida!");
          exit(1);
          return 0;
      }
      else{
        fprintf(arquivosaida,"Airline,Media\n");
        for(e=0; e<QtdAir; e++){
          fprintf(arquivosaida, "%s,%f\n", vetair[e].airlineCode, vetair[e].media);
        }
    
        fclose(arquivosaida);
      }
      free(vetair);
    }  
  }
  else{
    return 0;
  }     
return 1;
}


int main(){
  //variaveis globais
  FILE *fp;
  int QtdLinhas = 0;
  char c;  
  airline *vetorDinamico;
  //abre o arquivo e conta as linhas para alocar um vetor na memoria
  fp = fopen("AirlinesDataSetTeste.csv", "r");
  if (ValArq(fp)){
    for (c = getc(fp); c != EOF; c = getc(fp))
      if (c == '\n')
        QtdLinhas++;
      fclose(fp); 
    //printf de acompanhamento
    printf("O arquivo tem %d linhas\n ", QtdLinhas);
    //alocaçao dinamica na memoria
    vetorDinamico = (airline*)malloc(QtdLinhas*sizeof(airline));
    //printf(*vetorDinamico);
    if (vetorDinamico == NULL){
		  printf("Alocação mal sucedida!");
		  exit(1);
      return 0;
	  }
	  else{
      AloVet(fp,vetorDinamico,QtdLinhas); 
    }
  }
  else
  {
    return 0;
  }
  return 1;
}
