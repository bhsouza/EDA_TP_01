#include <stdio.h>
#include <stdlib.h>

typedef struct Airline
{
  int id;
  char airlineCode[2];
  int delay;
};
  
int main()
{
    FILE *fp;
    int QtdLinhas = 0;
    char c;  
  

    fp = fopen("AirlinesDataSheet.csv", "r");
  
    if (fp == NULL)
    {
        printf("Nao foi possivel abrir o arquivo.");
        return 0;
    }
  
    for (c = getc(fp); c != EOF; c = getc(fp))
      if (c == '\n') 
        QtdLinhas++;

    fclose(fp);
    printf("O arquivo tem %d linhas\n ", QtdLinhas);
  
    return 0;
}