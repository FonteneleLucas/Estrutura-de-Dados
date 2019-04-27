/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: lucas
 *
 * Created on April 27, 2019, 7:04 PM
 */

#include <cstdlib>
#include <stdio.h>

using namespace std;

/*
 * 
 */
int L[5];
int L2[8];
int size = 5;

bool adicionar(int value, int vetor[], int size) {
    for (int i = 0; i < size; i++) {
        if (vetor[i] == 0) {
            vetor[i] = value;
            return true;
        }
    }
    return false;
}

bool contains(int value, int vetor[], int size) {
    for (int i = 0; i < size; i++) {
        if (vetor[i] == value) {
            return true;
        }
    }
    return false;
}

bool adicionarSR(int value, int vetor[], int size) {
    for (int i = 0; i < size; i++) {
        if (!contains(value, vetor, size)) {
            adicionar(value, vetor, size);
            return true;
        }
    }
    return false;

}

void exibir(int vetor[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d\n", vetor[i]);
    }
    printf("--------------------\n");
}

bool copiarLista(int from[], int to[], int tipo) {
    if (tipo == 1) { //Copiar com repetição
        for (int i = 0; i < size; i++) {
            adicionar(from[i], to, size);
        }
        return true;
    } else if (tipo == 2) { //Copiar sem repetição (SR)
        for (int i = 0; i < size; i++) {
            adicionarSR(from[i], to, size);
        }
        return true;
    } else {
        return false;
    }
    return false;
}

int main(int argc, char** argv) {
    adicionar(12, L, size);
    adicionar(12, L, size);
    adicionar(13, L, size);
    adicionar(12, L, size);
    adicionar(13, L, size);



    //adicionar(10, L2, size);
    //    printf("stts> %d\n", adicionarSR(L[0], L2, size));
    //    printf("stts> %d\n", adicionarSR(L[1], L2, size));
    //    printf("stts> %d\n", adicionarSR(L[2], L2, size));
    //    printf("stts> %d\n", adicionarSR(L[3], L2, size));
    //    printf("stts> %d\n", adicionarSR(L[4], L2, size));

    //    adicionar(10, L2, size);

    //printf("Contains: %d\n", contains(10, L2, size));

    printf("stts> %d\n", copiarLista(L, L2, 2));
    

    exibir(L, size);
    exibir(L2, size);


    return 0;
}

