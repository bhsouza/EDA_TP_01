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

int AloVet(FILE *vArqEnt,airline vetor[],int QtdVet){
  int a=0,e=0,f=0,i=0,s=0,QtdAir=0;
  char c,strair[100];
  
  sub_airline *vetair;

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
    // contar quantas linhas aereas sao unicas
    for(e=0;e <= QtdVet;e++){
      vetor[e].contada = 0;
    }
      
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
    printf("\n%d",QtdAir);

    //x = (sub_airline*)malloc(QtdAir*sizeof(sub_airline));

      for(e=0;e < QtdVet;e++){
      printf("\n%d",vetor[e].contada);
    }
    /*
    for(g=0;g== q)
    // alocar memoria para nova struct com os dados finais
    vetair = (sub_airline*)malloc(QtdLinhas*sizeof(sub_airline));
    // Insert Sort para achar a média.
    if (s>=1){
      printf("\nTeste1");

      for (a=1;a<=QtdVet;a++) 
      { 
        next=vetor[a].airlineCode
        for (i=a-1; i<=QtdVet && (strcmp(next,vetor[i].airlineCode)==0);i--)
        {
          
        }
      }
      

      /* 
      for (a = 0;a<=QtdVet && VetEmp[1][a]==NULL; a++)
      {
        printf("\nTeste-1");
        VetEmp[1][a]=vetor[a].airlineCode;    
        for (i = 0;i<=QtdVet; i++) 
        {
          if (vetor[i].airlineCode==VetEmp[1][a]){
            VetEmp[3][a]++;   
            if (vetor[i].airlineCode==1)
            {
              VetEmp[2][a]++;
            }              
          }
        }
        printf("\nTeste-2");
        VetEmp[4][a]=VetEmp[2][a]/VetEmp[3][a];
        printf("\nMédia - %d",VetEmp[4][a]);
      }
      
    }
    */
  }
  else{
    return 0;
  }     
return 1;
}

int main(){
  //variaveis globais
  FILE *fp,*arquivosaida;
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
  }
  else
  {
    return 0;
  }
  return 1;
}
