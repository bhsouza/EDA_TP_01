#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Airline
{
    int id;
    char airlineCode[2];
    int delay;
};

int word2vec(FILE *vArqEnt)
{
   int  nValFor,valor1,valor3,valor6,valor7,valor8,valor9=0;
   char buff,valor2,valor4,valor5="";

   /*
    while(!feof(pArqTeste)){
        if (!fscanf(pArqTeste,"%d", &n))
            break;
        V = gera_vet_aleatorio(n);
        for(p=0;p<n;p++)
            printf("\n %d:%d", p, V[p]);
    break;
        printf("\n %d", n);
    }
   */

   while(!feof(vArqEnt))
   {
      if (!fscanf(vArqEnt,"%s;%s;%s;%s;%s;%s;%s;%s;%s",valor1,valor2,valor3,valor4,valor5,valor6,valor7,valor8,valor9))
         break;
      //Printf para chegar os valores
      printf(valor1,valor2,valor3,valor4,valor5,valor6,valor7,valor8,valor9);
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
   char vTxtRec;
   FILE *fp = fopen("C:/Users/joaoe/Documents/Airlines.csv","r");
   if (fp != NULL)
   {
      if (!word2vec(fp))
      {
         printf("Erro na abertura da database");
         exit(0);
      } 
   }
   else
   {
      printf("Erro de leitura da database");
      exit(0);
   }
   fclose(fp);
}