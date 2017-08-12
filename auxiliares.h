#ifndef _AUXILIARES
#define _AUXILIARES

typedef struct par_impar{
    int par;
    int impar;
    int numero_colisoes;
    //lista
}par_impar;

int cmpfunc (const void *a, const void *b);//pro guloso

int compara_dinamico(const void *i, const void *j);//pro dinamico

void contaColisoes(int inicio, int numero_de_bares, par_impar vetor_pares_impar[]);

#endif // _AUXILIARES
