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

#include "vector.h"

template<typename typeT>
class SortUtils {
    private:
        /**
        @brief Transforma o subvector em uma estrutura de dados do tipo heap
        @param subvector Subvector que será transformado em um heap
        @param position Posição do elemento do array que será ajustado
        @param heapSize Tamanho do heap
        */
        static void MaxHeapify(Vector<typeT> &subvector, unsigned int position, unsigned int heapSize);

        /**
        @brief Constroí o heap inicial
        @param array Array que será transformado em um heap
        @param heapSize Tamanho do heap
        */
        static void BuildMaxHeap(Vector<typeT> &vector, unsigned int heapSize);

        /**
        @brief Une os vetores ordenados
        @param subvector Subvector que será ordenado
        @param left, middle, right Índices do início, meio e fim do subarray
        */
        static void MergeSortedSubarrays(Vector<typeT> &subvector, int left, int middle, int right);

        /**
        @brief Auxilia o algoritmo de MergeSort dividindo o vector de forma recursiva
        @param subvector Subvector que será ordenado
        @param left, right Índices de onde começa e termina o subarray
        */
        static void MergeSortHelper(Vector<typeT> &subvector, int left, int right);

    public:
        /**
        @brief Utiliza o algoritmo HeapSort para ordenar o vector
        @param vector Vector que será ordenado
        */
        static void HeapSort(Vector<typeT> &vector);

        /**
        @brief Utiliza o algoritmo ShellSort para ordenar o vector
        @param vector Vector que será ordenado
        */
        static void ShellSort(Vector<typeT> &vector);

        /**
        @brief Utiliza o algoritmo MergeSort para ordenar o vector
        @param vector Vector que será ordenado
        */
        static void MergeSort(Vector<typeT> &vector);

        /**
        @brief Utiliza o algoritmo InsertionSort para ordenar o vector
        @param vector Vector que será ordenado
        */
        static void InsertionSort(Vector<typeT> &vector);

        /**
        @brief Utiliza o algoritmo InsertionSort para ordenar o array
        @param array Array que será ordenado
        @param size Tamanho do intervalo que deve ser ordenado
        */
        static void InsertionSort(typeT array[], unsigned int size);

        /**
        @brief Utiliza o algoritmo CountingSort para ordenar o vector
        @param vector Vector que será ordenado
        */
        static void CountingSort(Vector<typeT> &vector);

        /**
        @brief Utiliza o algoritmo BucketSort para ordenar o vector
        @param vector Vector que será ordenado
        */
        static void BucketSort(Vector<typeT> &vector);
};

// ----------------------------------------------------- HEAPSORT -------------------------------------------------------

template<typename typeT>
void SortUtils<typeT>::MaxHeapify(Vector<typeT> &subvector, unsigned int position, unsigned int size) {
    unsigned int largest = position;
    unsigned int left = 2 * position + 1;
    unsigned int right = 2 * position + 2;

    if (left < size and subvector[left] > subvector[largest])
        largest = left;

    if (right < size and subvector[right] > subvector[largest])
        largest = right;

    if (largest != position) {
        std::swap(subvector[position], subvector[largest]);
        SortUtils<typeT>::MaxHeapify(subvector, largest, size);
    }
}

template<typename typeT>
void SortUtils<typeT>::BuildMaxHeap(Vector<typeT> &vector, unsigned int heapSize) {
    for (int i = heapSize / 2 - 1; i >= 0; i--) {
        SortUtils<typeT>::MaxHeapify(vector, i, heapSize);
    }
}

template<typename typeT>
void SortUtils<typeT>::HeapSort(Vector<typeT> &vector) {
    SortUtils<typeT>::BuildMaxHeap(vector, vector.Size());

    for (int i = vector.Size() - 1; i > 0; i--) {
        std::swap(vector[0], vector[i]);
        SortUtils<typeT>::MaxHeapify(vector, 0, i);
    }
}

// ----------------------------------------------------- SHELLSORT ------------------------------------------------------

template<typename typeT>
void SortUtils<typeT>::ShellSort(Vector<typeT> &vector) {
    unsigned int h = 1;
    unsigned int j;
    unsigned int operacoes = 0;

    while (h < vector.Size() / std::numbers::phi) {
        h = std::ceil(h * std::numbers::phi);
    }

    while (h >= 1) {
        for (unsigned int i = h; i < vector.Size(); i++) {
            j = i;
            while (j >= h and vector[j - h] > vector[j]) {
                operacoes++;
                std::swap(vector[j], vector[j - h]);
                j -= h;
            }
        }
        h = std::floor(h / std::numbers::phi);
    }
}

// ----------------------------------------------------- MERGESORT ------------------------------------------------------

template<typename typeT>
void SortUtils<typeT>::MergeSortedSubarrays(Vector<typeT> &subvector, int left, int middle, int right) {
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

    while (i < firstHalf and j < secondHalf) {
        if (leftArray[i] <= rightArray[j]) {
            subvector[k] = leftArray[i];
            i++;
        }
        else {
            subvector[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < firstHalf) {
        subvector[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < secondHalf) {
        subvector[k] = rightArray[j];
        j++;
        k++;
    }
}

template<typename typeT>
void SortUtils<typeT>::MergeSortHelper(Vector<typeT> &subvector, int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2; // Evita overflow para valores de left e right grandes
        SortUtils<typeT>::MergeSortHelper(subvector, left, middle);
        SortUtils<typeT>::MergeSortHelper(subvector, middle + 1, right);
        SortUtils<typeT>::MergeSortedSubarrays(subvector, left, middle, right);
    }
}

template<typename typeT>
void SortUtils<typeT>::MergeSort(Vector<typeT> &vector) {
    SortUtils<typeT>::MergeSortHelper(vector, 0, vector.Size() - 1);
}

// -------------------------------------------------- INSERTIONSORT -----------------------------------------------------

template<typename typeT>
void SortUtils<typeT>::InsertionSort(Vector<typeT> &vector) {
    int key, j;

    for (unsigned int i = 0; i < vector.Size(); i++) {
        key = vector[i];
        j = i - 1;

        while (j >= 0 and key < vector[j]) {
            vector[j + 1] = vector[j];
            j--;
        }
        vector[j + 1] = key;
    }
}

template<typename typeT>
void SortUtils<typeT>::InsertionSort(typeT array[], unsigned int size) {
    int key, j;

    for (unsigned int i = 0; i < size; i++) {
        key = array[i];
        j = i - 1;

        while (j >= 0 and key < array[j]) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

// -------------------------------------------------- COUNTINGSORT ------------------------------------------------------

template<typename typeT>
void SortUtils<typeT>::CountingSort(Vector<typeT> &vector) {
    int max = vector[0];
    int min = vector[0];

    for (unsigned int i = 0; i < vector.Size(); i++) {
        if (vector[i] > max)
            max = vector[i];

        else if (vector[i] < min)
            min = vector[i];
    }

    unsigned int countSize = max - min + 1;
    int *countArray = new int[countSize](); // Cria um array preenchido com 0's

    // Calcula a frequência de cada valor
    for (unsigned int i = 0; i < countSize; i++) {
        countArray[vector[i]]++;
    }

    unsigned int index = 0;

    // Ordena o array
    for (int i = 0; i <= max; i++) {
        while (countArray[i] > 0) {
            vector[index] = i;
            index++;
            countArray[i]--;
        }
    }

    delete[] countArray;
}

// -------------------------------------------------- BUCKETSORT --------------------------------------------------------

template<typename typeT>
void SortUtils<typeT>::BucketSort(Vector<typeT> &vector) {
    const unsigned int numBuckets = 10;
    typeT buckets[numBuckets][vector.Size()];
    int *bucketSizes = new int[numBuckets](); // Cria um array preenchido com 0's

    int max = vector[0];
    for (unsigned int i = 1; i < vector.Size(); i++) {
        if (vector[i] > max)
            max = vector[i];
    }

    // Faz a distribuição das chaves nos baldes
    unsigned int index;
    for (unsigned int i = 0; i < vector.Size(); i++) {
        index = numBuckets * vector[i] / (max + 1);
        buckets[index][bucketSizes[index]] = vector[i];
        bucketSizes[index]++;
    }

    // Ordena os elementos em cada balde
    for (unsigned int i = 0; i < numBuckets; i++)
        SortUtils<typeT>::InsertionSort(buckets[i], bucketSizes[i]);

    // Junta os trem que foram ordenados
    index = 0;
    for (unsigned int i = 0; i < numBuckets; i++) {
        for (int j = 0; j < bucketSizes[i]; j++) {
            vector[index++] = buckets[i][j];
        }
    }

    delete[] bucketSizes;
}

#endif // SORT_UTILS_H_
