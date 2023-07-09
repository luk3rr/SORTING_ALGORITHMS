/*
* Filename: counting_sort.h
* Created on: July  9, 2023
* Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
*
* Implementação do algoritmo de ordenação CountingSort
*
* Complexidade de tempo, onde k é o intervalo dos valores dos elementos
* Pior caso:   O(n + k)
* Caso médio:  O(n + k)
* Melhor caso: O(n + k)
*
* Complexidade de espaço O(n + k)
*/

#ifndef COUNTING_SORT_H_
#define COUNTING_SORT_H_

#include "vector.h"

namespace sort {
    /**
     * @brief Utiliza o algoritmo CountingSort para ordenar o vector
     * @param vector Vector que será ordenado
     */
    template<typename typeT>
    inline void Counting(Vector<typeT> &vector) {
        int max = vector[0];
        int min = vector[0];

        for (unsigned int i = 0; i < vector.Size(); i++) {
            if (vector[i] > max) max = vector[i];
            else if (vector[i] < min) min = vector[i];
        }

        unsigned int countSize = max - min + 1;
        int *countArray = new int[countSize](); // Cria um array preenchido com 0's

        // Calcula a frequência de cada valor
        for (unsigned int i = 0; i < countSize; i++)
            countArray[vector[i]]++;

        unsigned int index = 0;

        // Ordena o array
        for (int i = 0; i <= max; i++) {
            while (countArray[i] > 0) {
                vector[index++] = i;
                countArray[i]--;
            }
        }

        delete[] countArray;
    }
}

#endif // COUNTING_SORT_H_
