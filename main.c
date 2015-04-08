/// Tomas Abril
/// Diego Wesley Braga
/// Daniel Silva Curi


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 13

char **nomes;
int fim = 0;
unsigned long long int trocas = 0;
unsigned long long int comparacoes = 0;

int check();
void troca(int i, int j);
void permuta(int i);
void lerArq();
void soLetra();

int main()
{
    int i = 0;

    criaMatriz();

    lerArq();

    check();

    permuta(0);

    printf("\nFIM\n %d nomes\n TROCAS:      %llu\n COMPARACOES: %llu \n", TAM,  trocas, comparacoes);

    return 0;
}

void criaMatriz()
{
    int i;

    nomes = (char**)malloc(TAM * sizeof(char*));

    for(i = 0; i < TAM; i++) {
        nomes[i] = (char*)malloc(80 * sizeof(char));
    }
}

void lerArq()
{
    char url[]="saida.txt";
    char leitor[80], palavra[80];
    int i, contador = 0;
    FILE *arq;
    arq = fopen(url, "r");

    while(!feof(arq) && contador < TAM) {
        if( fgets(palavra, 80, arq) != NULL ) {
            strcpy(nomes[contador], palavra);

            // printf("ola %s", nomes[contador]);

            contador++;
        }
    }
    puts("leu arquivo\n");

    fclose(arq);
}

int check()
{
    int i = 0;

    while(i < TAM-1) {
        comparacoes++;
        if(strcmp(nomes[i], nomes[i+1]) > 0) {
            return 1;
        }
        i++;
    }

    return 0;
}

void troca(int i, int j)
{
    char *aux;
    aux = nomes[i];
    nomes[i] = nomes[j];
    nomes[j] = aux;

    trocas++;
}

void permuta(int i)
{
    int j;
    int k = 0;
    if (i == TAM-1) {
        if(!check()) {
            fim = 1;
            while(k < TAM) {
                printf("%s", nomes[k]);
                k++;
            }
        }
    }


    else {
        for (j = i; j <= TAM-1; j++) {
            troca(i, j);
            permuta(i+1);
            if(fim) return;
            troca(i, j);
        }
    }
}

