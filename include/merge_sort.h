/*
* Filename: merge_sort.h
* Created on: July  9, 2023
* Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
*
* Implementação do algoritmo de ordenação MergeSort
*
* Complexidade de tempo
* Pior caso:   O(n log n)
* Caso médio:  O(n log n)
* Melhor caso: O(n log n)
*
* Complexidade de espaço O(n)
*/

#ifndef MERGE_SORT_H_
#define MERGE_SORT_H_

#include "vector.h"

namespace sort
{
    // Private methods
    namespace
    {
        /**
         * @brief Une os vetores ordenados
         * @param subvector Subvector que será ordenado
         * @param left, middle, right Índices do início, meio e fim do subarray
         * @param comp Comparador personalizado dos elementos. Se não for passado um comparador
         *        o comparador padrão less será utilizado
         */
        template<typename typeT, typename Compare = utils::less<typeT>>
        inline void MergeSortedSubarrays(Vector<typeT> &subvector, int left, int middle, int right, Compare comp = utils::less<typeT>())
        {
            unsigned int firstHalf = middle - left + 1;
            unsigned int secondHalf = right - middle;

            int leftArray[firstHalf];
            int rightArray[secondHalf];

            for (unsigned int i = 0; i < firstHalf; i++)
                leftArray[i] = subvector[left + i];

            for (unsigned int j = 0; j < secondHalf; j++)
                rightArray[j] = subvector[middle + 1 + j];

            unsigned int i, j, k;
            i = j = 0;
            k = left;

            while (i < firstHalf and j < secondHalf)
            {
                if (comp(leftArray[i], rightArray[j])) // TODO: verificar funcionalidade, <= antes
                    subvector[k++] = leftArray[i++];

                else
                    subvector[k++] = rightArray[j++];
            }

            while (i < firstHalf)
                subvector[k++] = leftArray[i++];

            while (j < secondHalf)
                subvector[k++] = rightArray[j++];
        }

        /**
         * @brief Auxilia o algoritmo de MergeSort dividindo o vector de forma recursiva
         * @param subvector Subvector que será ordenado
         * @param left, right Índices de onde começa e termina o subarray
         * @param comp Comparador personalizado dos elementos. Se não for passado um comparador
         *        o comparador padrão less será utilizado
         */
        template<typename typeT, typename Compare = utils::less<typeT>>
        inline void MergeSortHelper(Vector<typeT> &subvector, int left, int right, Compare comp = utils::less<typeT>())
        {
            if (left < right)
            {
                int middle = left + (right - left) / 2; // Evita overflow para valores de left e right grandes
                MergeSortHelper(subvector, left, middle, comp);
                MergeSortHelper(subvector, middle + 1, right, comp);
                MergeSortedSubarrays(subvector, left, middle, right, comp);
            }
        }
    } // Private methods

    /**
     * @brief Utiliza o algoritmo MergeSort para ordenar o vector
     * @param vector Vector que será ordenado
     * @param comp Comparador personalizado dos elementos. Se não for passado um comparador
     *        o comparador padrão less será utilizado
     */
    template<typename typeT, typename Compare = utils::less<typeT>>
    inline void Merge(Vector<typeT> &vector, Compare comp = utils::less<typeT>())
    {
        MergeSortHelper(vector, 0, vector.Size() - 1, comp);
    }
}

#endif // MERGE_SORT_H_
