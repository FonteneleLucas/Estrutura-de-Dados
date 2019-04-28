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
#include <stdlib.h>
#include <iosfwd>

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

bool adicionarIndex(int value, int index, int vetor[], int size) {
    vetor[index] = value;
    return true;
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

int vOrdenado[100];

//retorna o indice do primeiro valor maior encontrado

int greatIndex(int value, int vetor[], int size) {
    int index = -1;
    for (int i = 0; i < size; i++) {
        if (vetor[i] >= value) {
            index = i;
            i = size;
        }
    }
    return index;
}

/**
 * Permuta o conteúdo de uma lista a partir de um indice(key) para uma posição acima: 
 **/
void upIndex(int key, int vetor[], int size) {
    if (vetor[size - 1] == 0) {
        //printf("Tem espaço\n");
        for (int i = size - 1; i > key; i--) {
            vOrdenado[i] = vetor[i - 1];
        }
        //        vOrdenado[key] = -50;
    } else {
        //printf("Nao tem espaço\n");
    }

}

/**
 * 
 * @param n
 * @param size
 */
int lastAdd = 0;

void vetorOrdenado(int n, int size) {



    if (vOrdenado[size - 1] == 0) {
        printf("Index: %d\n", greatIndex(n, vOrdenado, size));

        printf("LastAdd: %d\n", lastAdd);

        int index = greatIndex(n, vOrdenado, size);
        if (index == -1) {
            //adicionar(n, vOrdenado, size);
            adicionarIndex(n, lastAdd, vOrdenado, size);
            //            if (vOrdenado[index] == 0 && vOrdenado[index-1] == -50) {
            //                vOrdenado[index] = n;
            //            }
            printf("add normal\n");
            
            lastAdd += 1;

        }

        if (index >= 0) {



            printf(">=0\n");
            upIndex(index, vOrdenado, size);
            vOrdenado[index] = n;
            lastAdd += 1;
            //            if(vOrdenado[index] == -50){
            //                vOrdenado[index] = n;
            //            }
        }



    } else {
        printf("Não Pode add %d\n");
    }
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
    //    vOrdenado[0] = 20;
    //    vOrdenado[1] = 2;
    //    vetorOrdenado(8, 6);
    //    vetorOrdenado(-10, 10);
    //    //    vetorOrdenado(1, 3);
//        vetorOrdenado(1, 10);
//        vetorOrdenado(2, 10);
//        vetorOrdenado(3, 10);
//        vetorOrdenado(0, 10);
//        vetorOrdenado(0, 10);
//        vetorOrdenado(0, 10);
//        vetorOrdenado(0, 10);
    //    vetorOrdenado(8, 10);
    //    //
    //    vetorOrdenado(20, 10);
    //    vetorOrdenado(8, 10);
    //    vetorOrdenado(10, 3);
    //    vetorOrdenado(4, 2);

    //exibir(vOrdenado, 4);

    int i, n;
    time_t t;

    n = 100;

    /*  random number generator */
    srand((unsigned) time_t(&t));

    /* Print 5 random numbers from 0 to 49 */
    printf("RANDOM:\n");
    for (i = 0; i < n; i++) {
        int value = rand() % 2;
        printf("%d\n", value);

        vetorOrdenado(value, 100);
    }

    printf("----------------------\n");
    printf("ORDENADO:\n");
    exibir(vOrdenado, 100);


    return 0;
}

