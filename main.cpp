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

void inverter(int vetor[], int result[], int size) { //inverter L1 - > L2
    for (int i = size - 1; i >= 0; i--) {
        adicionar(vetor[i], result, size);

    }
}

void inverterL(int vetor[], int size) { //Inverter L1
    int aux[size];
    int j = size - 1;
    for (int i = 0; i < size; i++) {
        aux[j] = vetor[i];
        j--;
    }

    for (int i = 0; i < size; i++) {
        L[i] = aux[i];
    }

}

void vetorOrdenado(int n, int size) {
    int vetor[size];
}

int main(int argc, char** argv) {
    adicionar(1, L, size);
    adicionar(2, L, size);
    adicionar(3, L, size);
    adicionar(4, L, size);
    adicionar(5, L, size);


    //inverter(L, L2, size);
    //    inverterL(L, size);
    //    exibir(L, size);
    //exibir(L2, size);


    return 0;
}

