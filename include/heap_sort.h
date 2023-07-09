/*
* Filename: heap_sort.h
* Created on: July  9, 2023
* Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
*
* Implementação do algoritmo de ordenação HeapSort
*
* Complexidade de tempo
* Pior caso:   O(n log n)
* Caso médio:  O(n log n)
* Melhor caso: O(n log n)
*
* Complexidade de espaço O(n)
*/

#ifndef HEAP_SORT_H_
#define HEAP_SORT_H_

#include "vector.h"

namespace sort {
    // Private methods
    namespace {
        /**
         * @brief Transforma o subvector em uma estrutura de dados do tipo heap
         * @param subvector Subvector que será transformado em um heap
         * @param position Posição do elemento do array que será ajustado
         * @param heapSize Tamanho do heap
         */
        template<typename typeT>
        inline void MaxHeapify(Vector<typeT> &subvector, unsigned int position, unsigned int heapSize) {
            unsigned int largest = position;
            unsigned int left = 2 * position + 1;
            unsigned int right = 2 * position + 2;

            if (left < heapSize and subvector[left] > subvector[largest])
                largest = left;

            if (right < heapSize and subvector[right] > subvector[largest])
                largest = right;

            if (largest != position) {
                subvector.Swap(position, largest);
                MaxHeapify(subvector, largest, heapSize);
            }
        }

        /**
         * @brief Constroí o heap inicial
         * @param array Array que será transformado em um heap
         * @param heapSize Tamanho do heap
         */
        template<typename typeT>
        inline void BuildMaxHeap(Vector<typeT> &vector, unsigned int heapSize) {
            for (int i = heapSize / 2 - 1; i >= 0; i--)
                MaxHeapify(vector, i, heapSize);
        }

    } // Private methods

    /**
     * @brief Utiliza o algoritmo HeapSort para ordenar o vector
     * @param vector Vector que será ordenado
     */
    template<typename typeT>
    inline void Heap(Vector<typeT> &vector) {
        BuildMaxHeap(vector, vector.Size());

        for (int i = vector.Size() - 1; i > 0; i--) {
            vector.Swap(0, i);
            MaxHeapify(vector, 0, i);
        }
    }
}

#endif // HEAP_SORT_H_
