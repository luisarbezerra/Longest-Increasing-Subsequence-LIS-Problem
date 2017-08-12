#include <stdio.h>
#include <stdlib.h>
#include "forcabruta.h"
#include "guloso.h"
#include "dinamico.h"
#include "auxiliares.h"

int main(){
    char algoritmo;
    scanf("%c", &algoritmo); //le o tipo de algoritmo a ser usado: guloso, programa��o din�mica ou for�a bruta.

    int numero_de_bares;
    scanf("%d", &numero_de_bares);

    if (algoritmo == 'g'){
        guloso(numero_de_bares);
    } else if (algoritmo == 'd'){
        dinamico(numero_de_bares);
    } else if (algoritmo == 'b'){
        forcaBruta(numero_de_bares);
    }
    return 0;
}
