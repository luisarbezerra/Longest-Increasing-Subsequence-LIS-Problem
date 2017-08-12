#include <stdio.h>
#include <stdlib.h>
#include "dinamico.h"
#include "auxiliares.h"

int max(int i, int j){//acha o maximo
    return ((i > j) ? i : j);
}

void LIS(par_impar vetor_pares_impar[], int numero_de_bares){//longest increasing subsequence
    int i, j;
    int maximo_sem_colidir = 0;
    int *aux = calloc(numero_de_bares, sizeof(int));
    for(i = 0; i < numero_de_bares;i++){
        aux[i] = 1;
    }
    for(i = 1; i < numero_de_bares; i++){//acha a subsequencia de forma incremental
        for(j = 0; j < i; j++){
            if(vetor_pares_impar[i].par > vetor_pares_impar[j].par){//aplica a LIS no outro lado da rua, assim achamos uma combinacao sem colisoes
                aux[i] = max(aux[i], aux[j]+1);//compara a maior subsequence já em i com a de j +1 elemento;
                maximo_sem_colidir = max(maximo_sem_colidir, aux[i]);//salva o máximo encontrado, no final, é nossa resposta
            }
        }
    }

    printf("%d\n", maximo_sem_colidir);
    free(aux);
}

void dinamico(int numero_de_bares){
    int i, a, b;
    par_impar *vetor_pares_impar = calloc(numero_de_bares, sizeof(par_impar));

    for (i = 0; i < numero_de_bares; i++){
        scanf("%d %d", &a, &b); //lendo as linhas.
        if(a % 2 == 0){
          vetor_pares_impar[i].par = a;
          vetor_pares_impar[i].impar = b;
        } else {
          vetor_pares_impar[i].par = b;
          vetor_pares_impar[i].impar = a;
        }
      }
      qsort(vetor_pares_impar, numero_de_bares, sizeof(par_impar), compara_dinamico);//ordena o lado impar da rua
      LIS(vetor_pares_impar, numero_de_bares);
      free(vetor_pares_impar);
}
