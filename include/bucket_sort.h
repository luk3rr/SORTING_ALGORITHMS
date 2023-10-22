/*
* Filename: bucket_sort.h
* Created on: July  9, 2023
* Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
*
* Implementação do algoritmo de ordenação BucketSort
*
* Complexidade de tempo, onde k é o número de baldes
* Pior caso:   O(n^2)
* Caso médio:  O(n + k)
* Melhor caso: O(n + k)
*
* Complexidade de espaço O(n + k)
*/

#ifndef BUCKET_SORT_H_
#define BUCKET_SORT_H_

#include "vector.h"
#include "insertion_sort.h"

namespace sort
{
    /**
     * @brief Utiliza o algoritmo BucketSort para ordenar o vector
     * @param vector Vector que será ordenado
     * @param comp Comparador personalizado dos elementos. Se não for passado um comparador
     *        o comparador padrão less será utilizado
     */
    template<typename typeT, typename Compare = utils::less<typeT>>
    inline void Bucket(Vector<typeT> &vector, Compare comp = utils::less<typeT>())
    {
        const unsigned int numBuckets = 10;
        typeT buckets[numBuckets][vector.Size()];
        int *bucketSizes = new int[numBuckets](); // Cria um array preenchido com 0's

        int max = vector[0];
        for (unsigned int i = 1; i < vector.Size(); i++)
            if (comp(max, vector[i]))
                max = vector[i];

        // Faz a distribuição das chaves nos baldes
        unsigned int index;
        for (unsigned int i = 0; i < vector.Size(); i++)
        {
            index = numBuckets * vector[i] / (max + 1);
            buckets[index][bucketSizes[index]] = vector[i];
            bucketSizes[index]++;
        }

        // Ordena os elementos em cada balde
        for (unsigned int i = 0; i < numBuckets; i++)
            Insertion(buckets[i], bucketSizes[i]);

        // Junta os trem que foram ordenados
        index = 0;
        for (unsigned int i = 0; i < numBuckets; i++)
        {
            for (int j = 0; j < bucketSizes[i]; j++)
                vector[index++] = buckets[i][j];
        }

        delete[] bucketSizes;
    }
}

#endif // BUCKET_SORT_H_
