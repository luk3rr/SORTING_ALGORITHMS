/*
* Filename: selection_sort.h
* Created on: July  9, 2023
* Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
*
* Implementação do algoritmo de ordenação SelectionSort
*
* Complexidade de tempo
* Pior caso:   O(n^2)
* Caso médio:  O(n^2)
* Melhor caso: O(n^2)
*
* Complexiade de espaço O(n)
*/

#ifndef SELECTION_SORT_H_
#define SELECTION_SORT_H_

#include "vector.h"

namespace sort {
    /**
     * @brief Utiliza o algoritmo SelectionSort para ordenar o vector
     * @param vector Vector que será ordenado
     */
    template <typename typeT>
    inline void Selection(Vector<typeT> &vector) {
        unsigned int min;

        for (unsigned int i = 0; i < vector.Size() - 1; i++) {
            min = i;

            for (unsigned int j = i + 1; j < vector.Size(); j++) {
                if (vector[j] < vector[min])
                    min = j;
            }

            if (i != min)
                vector.Swap(min, i);
        }
    }
}

#endif // SELECTION_SORT_H_
