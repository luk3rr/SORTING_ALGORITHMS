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

namespace sort
{
    // Private methods
    namespace
    {
        /**
         * @brief Transforma o subvector em uma estrutura de dados do tipo heap
         * @param subvector Subvector que será transformado em um heap
         * @param position Posição do elemento do array que será ajustado
         * @param heapSize Tamanho do heap
         * @param comp Comparador personalizado dos elementos. Se não for passado um comparador
         *        o comparador padrão less será utilizado
         */
        template<typename typeT, typename Compare = utils::less<typeT>>
        inline void MaxHeapify(Vector<typeT> &subvector, unsigned int position, unsigned int heapSize, Compare comp = utils::less<typeT>())
        {
            unsigned int largest = position;
            unsigned int left = 2 * position + 1;
            unsigned int right = 2 * position + 2;

            if (left < heapSize and comp(subvector[largest], subvector[left]))
                largest = left;

            if (right < heapSize and comp(subvector[largest], subvector[right]))
                largest = right;

            if (largest != position)
            {
                subvector.Swap(position, largest);
                MaxHeapify(subvector, largest, heapSize);
            }
        }

        /**
         * @brief Constroí o heap inicial
         * @param array Array que será transformado em um heap
         * @param heapSize Tamanho do heap
         * @param comp Comparador personalizado dos elementos. Se não for passado um comparador
         *        o comparador padrão less será utilizado
         */
        template<typename typeT, typename Compare = utils::less<typeT>>
        inline void BuildMaxHeap(Vector<typeT> &vector, unsigned int heapSize, Compare comp = utils::less<typeT>())
        {
            for (int i = heapSize / 2 - 1; i >= 0; i--)
                MaxHeapify(vector, i, heapSize, comp);
        }

    } // Private methods

    /**
     * @brief Utiliza o algoritmo HeapSort para ordenar o vector
     * @param vector Vector que será ordenado
     * @param comp Comparador personalizado dos elementos. Se não for passado um comparador
     *        o comparador padrão less será utilizado
     */
    template<typename typeT, typename Compare = utils::less<typeT>>
    inline void Heap(Vector<typeT> &vector, Compare comp = utils::less<typeT>())
    {
        BuildMaxHeap(vector, vector.Size(), comp);

        for (int i = vector.Size() - 1; i > 0; i--)
        {
            vector.Swap(0, i);
            MaxHeapify(vector, 0, i, comp);
        }
    }
}

#endif // HEAP_SORT_H_
