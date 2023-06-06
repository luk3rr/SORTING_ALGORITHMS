/*
* Filename: sort_utils.h
* Created on: June  6, 2023
* Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
*/

#ifndef SORT_UTILS_H_
#define SORT_UTILS_H_

#include <type_traits>
#include <numbers>
#include <cmath>

class SortUtils {
    private:
        /**
        @brief Transforma o subarray em uma estrutura de dados do tipo heap
        @param subarray Subarray de inteiros
        @param position Posição do elemento do array que será ajustado
        @param size Tamanho do heap
        */
        static void MaxHeapify(int subarray[], unsigned int position, unsigned int size);

        /**
        @brief Constroí o heap inicial
        @param array Array que será transformado em um heap
        @param size Tamanho do array
        */
        static void BuildMaxHeap(int array[], unsigned int size);

        /**
        @brief Une os subarrays ordenados
        @param subarray Subarray de inteiros que será ordenado
        @param left, middle, right Índices do início, meio e fim do subarray
        */
        static void MergeSortedSubarrays(int subarray[], int left, int middle, int right);

        /**
        @brief Auxilia o algoritmo de MergeSort dividindo o array de forma recursiva
        @param subarray Subarray de inteiros que será ordenado
        @param left, right Índices de onde começa e termina o subarray
        */
        static void MergeSortHelper(int subarray[], int left, int right);

    public:
        /**
        @brief Utiliza o algoritmo HeapSort para ordenar o array
        @param array Array de inteiros que será ordenado
        @param size Tamanho do array que será ordenado
        */
        static void HeapSort(int array[], unsigned int size);

        /**
        @brief Utiliza o algoritmo ShellSort para ordenar o array
        @param array Array de inteiros que será ordenado
        @param size Tamanho do array que será ordenado
        */
        static void ShellSort(int array[], unsigned int size);

        /**
        @brief Utiliza o algoritmo MergeSort para ordenar o array
        @param array Array de inteiros que será ordenado
        @param size Tamanho do array que será ordenado
        */
        static void MergeSort(int array[], unsigned int size);

        /**
        @brief Utiliza o algoritmo InsertionSort para ordenar o array
        @param array Array de inteiros que será ordenado
        @param size Tamanho do array que será ordenado
        */
        static void InsertionSort(int array[], unsigned int size);

        /**
        @brief Utiliza o algoritmo CountingSort para ordenar o array
        @param array Array de inteiros que será ordenado
        @param size Tamanho do array que será ordenado
        */
        static void CountingSort(int array[], unsigned int size);

        /**
        @brief Utiliza o algoritmo BucketSort para ordenar o array
        @param array Array de inteiros que será ordenado
        @param size Tamanho do array que será ordenado
        */
        static void BucketSort(int array[], unsigned int size);
};

#endif // SORT_UTILS_H_
