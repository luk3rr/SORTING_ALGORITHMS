/*
* Filename: insertion_sort.h
* Created on: July  9, 2023
* Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
*
* Implementação do algoritmo de ordenação InsertionSort
*
* Complexidade de tempo
* Pior caso:   O(n^2)
* Caso médio:  O(n^2)
* Melhor caso: O(n)
*
* Complexidade de espaço O(n)
*/

#ifndef INSERTION_SORT_H_
#define INSERTION_SORT_H_

#include "vector.h"

namespace sort
{
    /**
     * @brief Utiliza o algoritmo InsertionSort para ordenar o vector
     * @param vector Vector que será ordenado
     * @param comp Comparador personalizado dos elementos. Se não for passado um comparador
     *        o comparador padrão less será utilizado
     */
    template<typename typeT, typename Compare = utils::less<typeT>>
    inline void Insertion(Vector<typeT> &vector, Compare comp = utils::less<typeT>())
    {
        int key, j;

        for (unsigned int i = 1; i < vector.Size(); i++)
        {
            key = vector[i];
            j = i - 1;

            while (j >= 0 and comp(key, vector[j]))
            {
                vector[j + 1] = vector[j];
                j--;
            }
            vector[j + 1] = key;
        }
    }

    /**
     * @brief Utiliza o algoritmo InsertionSort para ordenar o array
     * @param array Array que será ordenado
     * @param size Tamanho do intervalo que deve ser ordenado
     * @param comp Comparador personalizado dos elementos. Se não for passado um comparador
     *        o comparador padrão less será utilizado
     */
    template<typename typeT, typename Compare = utils::less<typeT>>
    inline void Insertion(typeT array[], unsigned int size, Compare comp = utils::less<typeT>())
    {
        int key, j;

        for (unsigned int i = 0; i < size; i++)
        {
            key = array[i];
            j = i - 1;

            while (j >= 0 and comp(key, array[j]))
            {
                array[j + 1] = array[j];
                j--;
            }
            array[j + 1] = key;
        }
    }
}

#endif // INSERTION_SORT_H_
