/// Tomas Abril
/// Diego W. Braga
/// Daniel Silva Curi


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 14
char nomes[TAM][80];
int fim = 0;
int trocas = 0;
int comparacoes = 0;

int check();
void troca(int i, int j);
void permuta(int i);
void lerArq();
void soLetra();

int main()
{
    int i = 0;
    lerArq();
    soLetra();
    check();
    permuta(0);
    printf("\nFIM\n TROCAS:      %d\n COMPARACOES: %d \n", trocas, comparacoes);

    return 0;
}

void soLetra()
{
    int i=0, j=0;

    for(i=0; i<TAM; i++){
        for(j=0; j<80; j++){
            if(isalpha(nomes[i][j]) == 0 && nomes[i][j] != '\0' && nomes[i][j] != '\n')        //se nao e alfabetico
            {
                nomes[i][j] = ' ';
            }
        }
    }
}

void lerArq()
{
    char url[]="saida.txt";

    char leitor[80], palavra[80];

    int i, contador = 0;

    FILE *arq;

    arq = fopen(url, "r");


    while(!feof(arq) && contador < TAM)
    {
        if( fgets(palavra, 80, arq) != NULL )
        {
         //   puts(palavra);
            strcpy(nomes[contador ++], palavra);
        }
    }
    puts("leu arquivo\n");

    fclose(arq);
}

int check()
{
    int i = 0;

    while(i < TAM-1)
    {
        comparacoes++;
        if(strcmp(nomes[i], nomes[i+1]) > 0)
        {
            //printf("Desordenado\n");
            return 1;
        }
        i++;
    }

    return 0;
}

void troca(int i, int j)
{
    char aux[80];
    strcpy(aux, nomes[i]);
    strcpy(nomes[i], nomes[j]);
    strcpy(nomes[j], aux);

    trocas++;
}

void permuta(int i)
{
    int j;
    int k = 0;
    if (i == TAM-1)
    {
        if(!check())
        {
            fim = 1;
            while(k < TAM)
            {
                printf("%s", nomes[k]);
                k++;
            }
        }
    }


    else
    {
        for (j = i; j <= TAM-1; j++)
       {
          troca(i, j);
          permuta(i+1);
          if(fim) return;
          troca(i, j);
       }
    }
}

