/// Daniel Silva Curi
/// Diego Wesley Braga
/// Tomas Abril

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 12 // número de nomes a ordenar

char **nomes;
int fim = 0;
unsigned long long int trocas = 0;
unsigned long long int comparacoes = 0;

int check();
void troca(int i, int j);
void permuta(int i);
void lerArq();
void soLetra();
void criaMatriz();

int main()
{
    criaMatriz();
    lerArq();
    check();
    permuta(0);

    printf("\nFIM \n %d Nomes \n TROCAS:      %llu \n COMPARACOES: %llu \n", TAM,  trocas, comparacoes);

    return 0;
}


/// Aloca uma matriz de caracteres
void criaMatriz()
{
    int i;

    nomes = (char**)malloc(TAM * sizeof(char*));

    for(i = 0; i < TAM; i++) {
        nomes[i] = (char*)malloc(80 * sizeof(char));
    }
}

/// Le o arquivo com os nomes
void lerArq()
{
    char url[]="saida.txt";
    char palavra[80];
    int contador = 0;
    FILE *arq;
    arq = fopen(url, "r");

    while(!feof(arq) && contador < TAM) {
        if( fgets(palavra, 80, arq) != NULL ) {
            strcpy(nomes[contador], palavra);
            contador++;
        }
    }
    puts("Arquivo lido. Ordenando...\n");

    fclose(arq);
}

/// Checa se um nome deverá vir antes de seu predecessor
int check()
{
    int i = 0;

    while(i < TAM-1) {
        comparacoes++;
        if(strcmp(nomes[i], nomes[i+1]) > 0) { // caso o nome seguinte seja
            return 1;                          // menor que o atual, retorna 1
        }
        i++;
    }

    return 0;
}

/// Troca dois nomes de posição (ponteiros)
void troca(int i, int j)
{
    char *aux;
    aux = nomes[i];
    nomes[i] = nomes[j];
    nomes[j] = aux;

    trocas++;
}

/// Permuta os nomes
void permuta(int i)
{
    int j;
    int k = 0;

    if (i == TAM-1) {
        if(!check()) {          // caso esteja ordenado
            fim = 1;            // termine
            while(k < TAM) {
                printf("%s", nomes[k]); // e imprima os nomes
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
