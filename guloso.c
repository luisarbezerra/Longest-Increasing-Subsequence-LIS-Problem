#include <stdio.h>
#include <stdlib.h>
#include "guloso.h"
#include "auxiliares.h"

void guloso(int numero_de_bares) {
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

        contaColisoes(0, numero_de_bares, vetor_pares_impar); //0 e minha referencia para que a funcao decorra para a situacao "Guloso"
        int fim = numero_de_bares;//
        while (vetor_pares_impar[numero_de_bares - fim].numero_colisoes != 0){
            fim--;
            contaColisoes((numero_de_bares - fim), numero_de_bares, vetor_pares_impar);
        }
        printf("%d\n", fim);//bares que sobraram
        free(vetor_pares_impar);
}
