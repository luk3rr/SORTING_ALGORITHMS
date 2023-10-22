/*
* Filename: bubble_sort.h
* Created on: July  9, 2023
* Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
*
* Implementação do algoritmo de ordenação BubbleSort
*
* Complexidade de tempo
* Pior caso:   O(n^2)
* Caso médio:  O(n^2)
* Melhor caso: O(n)
*
* Complexidade de espaço O(n)
*/

#ifndef BUBBLE_SORT_H_
#define BUBBLE_SORT_H_

#include "vector.h"
#include "utils.h"

namespace sort {
    /**
     * @brief Utiliza o algoritmo BubbleSort para ordenar o vector
     * @param vector Vector que será ordenado
     */
    template<typename typeT>
    inline void Bubble(Vector<typeT> &vector) {
        bool swapped;

        for (unsigned int i = 0; i < vector.Size() - 1; i++) {
            swapped = false;

            for (unsigned int j = 0; j < vector.Size() - i - 1; j++) {
                if (vector[j] > vector[j + 1]) {
                    vector.Swap(j + 1, j);
                    swapped = true;
                }
            }
            if (not swapped) break;
        }
    }
}

#endif // BUBBLE_SORT_H_
