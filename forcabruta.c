#include <stdio.h>
#include <stdlib.h>
#include "forcabruta.h"
#include "auxiliares.h"

int recursaoCombinacao(par_impar vetor_pares_impar[], par_impar combinacao[], int inicio_vetor_pares, int fim_vetor_pares, int indice, int numero_subgrupo){
    int j, k, nao_opcao = 0;
    if (indice == numero_subgrupo){ //se está feita a combinação toda no vetor combinacao
        for (j = 0; j < numero_subgrupo-1; j++){
           if(nao_opcao == 0){
                for (k=j+1; k < numero_subgrupo; k++){
    //                printf("    COMPARANDO %d-%d COM %d-%d\n", combinacao[j].par, combinacao[j].impar,combinacao[k].par, combinacao[k].impar);
                    if ((combinacao[j].par > combinacao[k].par && combinacao[j].impar < combinacao[k].impar) || (combinacao[j].par < combinacao[k].par && combinacao[j].impar > combinacao[k].impar)){
                        nao_opcao = 1;
      //                  printf("-->BATEU!\n");
                       break;
                       break;
                    }
                }
            }
        }
  //      printf("\n");

        if (nao_opcao == 1){
            return 0;
        } else {
          return numero_subgrupo;
        }
    }

    int i, linhas, max = 1;
    //substitui o index com todos os elementos possiveis. A condição "fim_vetor_pares-i+1 >= numero_subgrupo - indice" confirma que incluir um elemento no indice vai fazer a combinacao com os outros elementos nas posições restantes.
    for (i = inicio_vetor_pares; i <= fim_vetor_pares && fim_vetor_pares-i+1 >= numero_subgrupo - indice; i++){
        combinacao[indice].par = vetor_pares_impar[i].par;
        combinacao[indice].impar = vetor_pares_impar[i].impar;
        linhas = recursaoCombinacao(vetor_pares_impar, combinacao, i+1, fim_vetor_pares, indice+1, numero_subgrupo);
        if(linhas > max){
          max = linhas;
          break;
        }
        //funcao de conferir se tem combinacoes
    }
    return max;
}

void forcaBruta(int numero_de_bares){
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

        //printf("i = %d\n",i );
        //printf("leu %d %d\n", vetor_pares_impar[i].par, vetor_pares_impar[i].impar);
    }

    int numero_subgrupo, max_linhas_subgrupo = 0, max_linhas = 1;
    for (numero_subgrupo = 2; numero_subgrupo <= numero_de_bares; numero_subgrupo++){
        par_impar combinacao[numero_subgrupo];
        max_linhas_subgrupo = recursaoCombinacao(vetor_pares_impar, combinacao, 0, numero_de_bares - 1 , 0, numero_subgrupo);
  //      printf("max_linhas_subgrupo: %d\n", max_linhas_subgrupo);
        if (max_linhas_subgrupo > max_linhas){
            max_linhas = max_linhas_subgrupo;
        }
    }
    printf("%d\n", max_linhas);
    free(vetor_pares_impar);
}
