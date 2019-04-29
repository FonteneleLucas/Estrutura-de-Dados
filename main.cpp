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
int L2[5];
int L3[10];
int size = 5;
int lastIndex = 0;

/**
 * Adiciona o valor passado na primeira possição que for encontrado "0"
 * @param value
 * @param vetor
 * @param size
 * @return 
 */
bool adicionar(int value, int vetor[], int size) {
    for (int i = 0; i < size; i++) {
        if (vetor[0] == 0) {
            vetor[lastIndex] = value;
            i = size;
        }else{
            vetor[lastIndex] = value;
            i = size;
        }

        lastIndex++;
    }
    return false;
}

/**
 * Adiciona o valor passado na posição escolhida
 * @param value
 * @param index
 * @param vetor
 * @param size
 * @return 
 */
bool adicionarIndex(int value, int index, int vetor[], int size) {
    vetor[index] = value;
    return true;
}

bool verificaCrescente(int vetor[], int size) {
    for (int i = 0; i < size - 1; i++) {
        if ((vetor[i + 1] - vetor[i]) <= 0) {
            return false;
        }

    }

    return true;
}

bool verificaDecrescente(int vetor[], int size) {
    for (int i = 0; i < size - 1; i++) {
        if ((vetor[i + 1] - vetor[i]) >= 0) {
            return false;
        }
    }
    return true;
}

bool verificaOrdenada(int vetor[], int size) {
    if (verificaCrescente(vetor, size) == true || verificaDecrescente(vetor, size) == true) {
        return true;
    }
    return false;
}

/**
 * retorna o índice do item buscado exista na lista passada
 * @param value
 * @param vetor
 * @param size
 * @return 
 */
int contains(int value, int vetor[], int size) {
    for (int i = 0; i < size; i++) {
        if (vetor[i] == value) {
            return i;
        }
    }
    return -1;
}

/**
 * Adiciona valor na lista sem que haja repetição de valores
 * @param value
 * @param vetor
 * @param size
 * @return 
 */
bool adicionarSR(int value, int vetor[], int size) {
    for (int i = 0; i < size; i++) {
        if (contains(value, vetor, size) == -1) {
            adicionar(value, vetor, size);
            return true;
        }
    }
    return false;

}

/**
 * Exibe a lista passada
 * @param vetor
 * @param size
 */
void exibir(int vetor[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d\n", vetor[i]);
    }
    printf("--------------------\n");
}

/**
 * Faz uma cópia da lista passa considerando o tipo
 * 1 - copiar com repetição
 * 2 - copiar sem repetição
 * @param from
 * @param to
 * @param tipo
 * @return 
 */
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

/**
 * retorna o indice do primeiro valor maior ou igual encontrado
 * @param value
 * @param vetor
 * @param size
 * @return 
 */
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
 * @param key
 * @param vetor
 * @param size
 */
bool upIndex(int key, int vetor[], int size) {
    if (vetor[size - 1] == 0) {
        //printf("Tem espaço\n");
        for (int i = size - 1; i > key; i--) {
            vetor[i] = vetor[i - 1];
        }
        return true;
    }
    return false;

}

bool downIndex(int key, int vetor[], int size) {
    int cont = 0;
    for (int i = key; i < size - 1; i++) {
        //vetor[i] = vetor[i + 1];
        adicionarIndex(vetor[i + 1], i, L, 5);
        adicionar(0, vetor, 5);
        //        cont = i;
    }
    //    adicionarIndex(vetor[cont], 0, L, 5);
    return true;


}

/**
 * Insere vetor passado com parâmetro com ordenação crescente
 * @param n
 * @param vetor
 * @param size
 * @return boolean
 */
int lastAdd = 0;

bool vetorOrdenado(int n, int vetor[], int size) {
    if (vetor[size - 1] == 0) {

        int index = greatIndex(n, vetor, size);
        if (index == -1) {
            adicionarIndex(n, lastAdd, vetor, size);
            lastAdd += 1;
        }

        if (index >= 0) {
            //printf(">=0\n");
            upIndex(index, vetor, size);
            vetor[index] = n;
            lastAdd += 1;
        }
        return true;
    } else {
        return false;
    }
}

/**
 * Gera lista ordenada a partir de duas listas passadas
 * @param vetor1
 * @param size1
 * @param vetor2
 * @param size2
 * @param resultVetor
 * @param resultSize
 * @return boolean
 */
bool intercalarL1L2(int vetor1[], int size1, int vetor2[], int size2, int resultVetor[], int resultSize) {
    if (size1 + size2 == resultSize) {
        int aux[resultSize];
        int cont = 0;
        for (int i = 0; i < size1; i++) {
            aux[i] = vetor1[i];
            cont = i;
        }

        for (int i = 0; i < size2; i++) {
            aux[++cont] = vetor2[i];
        }

        for (int i = 0; i < 10; i++) {
            vetorOrdenado(aux[i], resultVetor, resultSize);
        }
        return true;
    }
    return false;

}

/**
 * Exclui todas ocorrências do valor passado na lista
 * @param value
 * @param vetor
 * @param size
 * @return 
 */
bool excluir(int value, int vetor[], int size) {
    int cont = 0;
    if (vetor[0] != 0) {
        for (int i = 0; i < size; i++) {
            if (value == vetor[i]) {
                cont++;
            }
        }

        for (int i = 1; i <= cont; i++) {
            int index = contains(value, vetor, size);
            downIndex(index, L, size);
            adicionarIndex(0, size - 1, vetor, size);
        }
        return true;
    }
    return false;
}

int L4[100];

int main(int argc, char** argv) {
    adicionar(1, L, size);
    adicionar(20, L, size);
    adicionar(3, L, size);
    adicionar(4, L, size);
    adicionar(5, L, size);
    //    adicionar(5, L, size);
    //    adicionarIndex(1, 0, L, 5);
    //    adicionarIndex(10, 1, L, 5);
    //    adicionarIndex(20, 2, L, 5);
    //    adicionarIndex(30, 3, L, 5);
    //    adicionarIndex(40, 4, L, 5);

    exibir(L, 5);

    int i, n;
    time_t t;

    n = 100;

    /*  random number generator */
    srand((unsigned) time_t(&t));

    /* Print 5 random numbers from 0 to 49 */
    printf("RANDOM:\n");
    for (i = 0; i < n; i++) {
        int value = rand() % 50;
        //        printf("%d\n", value);

        vetorOrdenado(value, L4, 100);
    }

    printf("----------------------\n");
    printf("ORDENADO:\n");
    //exibir(L4, 100);

    printf("Crescente: %d\n", verificaCrescente(L, 5));
    printf("Decrescente: %d\n", verificaDecrescente(L, 5));
    printf("Verificar Ordenada: %d\n", verificaOrdenada(L, 5));
    //    adicionar(-8, L2, size);
    //    adicionar(2, L2, size);
    //    adicionar(3, L2, size);
    //    adicionar(1, L2, size);
    //    adicionar(90, L2, size);

    //    printf("Stts: %d\n", excluir(10, L, 5));
    //    printf("Stts: %d\n", excluir(7, L, 5));
    //    printf("Stts: %d\n", excluir(4, L, 5));
    //    printf("Stts: %d\n", excluir(9, L, 5));

    //    printf("value: %d\n", intercalarL1L2(L, 5, L2, 5, L3, 10));
    //    exibir(L3, 10);
    //    exibir(L2,5);
    //    exibir(L, 5);
    //    inverter(L, L2, size);
    //    inverterL(L, size);
    //    exibir(vOrdenado, 4);

    return 0;
}

