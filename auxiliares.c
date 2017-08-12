#include <stdio.h>
#include <stdlib.h>
#include "auxiliares.h"

int cmpfunc (const void *a, const void *b){
    par_impar *p1 = (par_impar *)a, *p2 = (par_impar *)b;
    return (p1->numero_colisoes > p2->numero_colisoes)? -1 : 1;//ordena em ordem decrescente
}

int compara_dinamico(const void *i, const void *j){
  par_impar *p1 = (par_impar *)i, *p2 = (par_impar *)j;
  return (p1->impar > p2->impar)? 1 : -1;//ordena em ordem crescente o lado impar da rua
}

void contaColisoes(int inicio, int numero_de_bares, par_impar vetor_pares_impar[]){
    int i, j, k;
    for(i = inicio; i < numero_de_bares; i++){
        vetor_pares_impar[i].numero_colisoes = 0;
    }
    for (j = inicio; j < numero_de_bares-1; j++){
        for (k = j+1; k < numero_de_bares; k++){
            if ((vetor_pares_impar[j].par > vetor_pares_impar[k].par && vetor_pares_impar[j].impar < vetor_pares_impar[k].impar) || (vetor_pares_impar[j].par < vetor_pares_impar[k].par && vetor_pares_impar[j].impar > vetor_pares_impar[k].impar)){
                vetor_pares_impar[j].numero_colisoes ++;
                vetor_pares_impar[k].numero_colisoes ++;
            }
        }
    }

    qsort(vetor_pares_impar, numero_de_bares, sizeof(par_impar), cmpfunc);
}
