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

template<typename typeT>
class SortUtils {
    private:
        /**
        @brief Transforma o subarray em uma estrutura de dados do tipo heap
        @param subarray Subarray que será transformado em um heap
        @param position Posição do elemento do array que será ajustado
        @param size Tamanho do heap
        */
        static void MaxHeapify(typeT subarray[], unsigned int position, unsigned int size);

        /**
        @brief Constroí o heap inicial
        @param array Array que será transformado em um heap
        @param size Tamanho do array
        */
        static void BuildMaxHeap(typeT array[], unsigned int size);

        /**
        @brief Une os subarrays ordenados
        @param subarray Subarray que será ordenado
        @param left, middle, right Índices do início, meio e fim do subarray
        */
        static void MergeSortedSubarrays(typeT subarray[], int left, int middle, int right);

        /**
        @brief Auxilia o algoritmo de MergeSort dividindo o array de forma recursiva
        @param subarray Subarray que será ordenado
        @param left, right Índices de onde começa e termina o subarray
        */
        static void MergeSortHelper(typeT subarray[], int left, int right);

    public:
        /**
        @brief Utiliza o algoritmo HeapSort para ordenar o array
        @param array Array que será ordenado
        @param size Tamanho do array que será ordenado
        */
        static void HeapSort(typeT array[], unsigned int size);

        /**
        @brief Utiliza o algoritmo ShellSort para ordenar o array
        @param array Array que será ordenado
        @param size Tamanho do array que será ordenado
        */
        static void ShellSort(typeT array[], unsigned int size);

        /**
        @brief Utiliza o algoritmo MergeSort para ordenar o array
        @param array Array que será ordenado
        @param size Tamanho do array que será ordenado
        */
        static void MergeSort(typeT array[], unsigned int size);

        /**
        @brief Utiliza o algoritmo InsertionSort para ordenar o array
        @param array Array que será ordenado
        @param size Tamanho do array que será ordenado
        */
        static void InsertionSort(typeT array[], unsigned int size);

        /**
        @brief Utiliza o algoritmo CountingSort para ordenar o array
        @param array Array que será ordenado
        @param size Tamanho do array que será ordenado
        */
        static void CountingSort(typeT array[], unsigned int size);

        /**
        @brief Utiliza o algoritmo BucketSort para ordenar o array
        @param array Array que será ordenado
        @param size Tamanho do array que será ordenado
        */
        static void BucketSort(typeT array[], unsigned int size);
};

// ----------------------------------------------------- HEAPSORT -------------------------------------------------------

template<typename typeT>
void SortUtils<typeT>::MaxHeapify(typeT subarray[], unsigned int position, unsigned int size) {
    unsigned int largest = position;
    unsigned int left = 2 * position + 1;
    unsigned int right = 2 * position + 2;

    if (left < size and subarray[left] > subarray[largest])
        largest = left;

    if (right < size and subarray[right] > subarray[largest])
        largest = right;

    if (largest != position) {
        std::swap(subarray[position], subarray[largest]);
        SortUtils<typeT>::MaxHeapify(subarray, largest, size);
    }
}

template<typename typeT>
void SortUtils<typeT>::BuildMaxHeap(typeT array[], unsigned int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        SortUtils<typeT>::MaxHeapify(array, i, size);
    }
}

template<typename typeT>
void SortUtils<typeT>::HeapSort(typeT array[], unsigned int size) {
    SortUtils<typeT>::BuildMaxHeap(array, size);

    for (int i = size - 1; i > 0; i--) {
        std::swap(array[0], array[i]);
        SortUtils<typeT>::MaxHeapify(array, 0, i);
    }
}

// ----------------------------------------------------- SHELLSORT ------------------------------------------------------

template<typename typeT>
void SortUtils<typeT>::ShellSort(typeT array[], unsigned int size) {
    unsigned int h = 1;
    unsigned int j;
    unsigned int operacoes = 0;

    while (h < size / std::numbers::phi) {
        h = std::ceil(h * std::numbers::phi);
    }

    while (h >= 1) {
        for (unsigned int i = h; i < size; i++) {
            j = i;
            while (j >= h and array[j - h] > array[j]) {
                operacoes++;
                std::swap(array[j], array[j - h]);
                j -= h;
            }
        }
        h = std::floor(h / std::numbers::phi);
    }
}

// ----------------------------------------------------- MERGESORT ------------------------------------------------------

template<typename typeT>
void SortUtils<typeT>::MergeSortedSubarrays(typeT subarray[], int left, int middle, int right) {
    unsigned int firstHalf = middle - left + 1;
    unsigned int secondHalf = right - middle;

    int leftArray[firstHalf];
    int rightArray[secondHalf];

    for (unsigned int i = 0; i < firstHalf; i++)
        leftArray[i] = subarray[left + i];

    for (unsigned int j = 0; j < secondHalf; j++)
        rightArray[j] = subarray[middle + 1 + j];

    unsigned int i, j, k;
    i = j = 0;
    k = left;

    while (i < firstHalf and j < secondHalf) {
        if (leftArray[i] <= rightArray[j]) {
            subarray[k] = leftArray[i];
            i++;
        }
        else {
            subarray[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < firstHalf) {
        subarray[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < secondHalf) {
        subarray[k] = rightArray[j];
        j++;
        k++;
    }
}

template<typename typeT>
void SortUtils<typeT>::MergeSortHelper(typeT subarray[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2; // Evita overflow para valores de left e right grandes
        SortUtils<typeT>::MergeSortHelper(subarray, left, middle);
        SortUtils<typeT>::MergeSortHelper(subarray, middle + 1, right);
        SortUtils<typeT>::MergeSortedSubarrays(subarray, left, middle, right);
    }
}

template<typename typeT>
void SortUtils<typeT>::MergeSort(typeT array[], unsigned int size) {
    SortUtils<typeT>::MergeSortHelper(array, 0, size - 1);
}

// -------------------------------------------------- INSERTIONSORT -----------------------------------------------------

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
void SortUtils<typeT>::CountingSort(typeT array[], unsigned int size) {
    int max = array[0];
    int min = array[0];

    for (unsigned int i = 0; i < size; i++) {
        if (array[i] > max)
            max = array[i];

        else if (array[i] < min)
            min = array[i];
    }

    unsigned int countSize = max - min + 1;
    int *countArray = new int[countSize](); // Cria um array preenchido com 0's

    // Calcula a frequência de cada valor
    for (unsigned int i = 0; i < countSize; i++) {
        countArray[array[i]]++;
    }

    unsigned int index = 0;

    // Ordena o array
    for (int i = 0; i <= max; i++) {
        while (countArray[i] > 0) {
            array[index] = i;
            index++;
            countArray[i]--;
        }
    }

    delete[] countArray;
}

// -------------------------------------------------- BUCKETSORT --------------------------------------------------------

template<typename typeT>
void SortUtils<typeT>::BucketSort(typeT array[], unsigned int size) {
    const unsigned int numBuckets = 10;
    typeT buckets[numBuckets][size];
    int *bucketSizes = new int[numBuckets](); // Cria um array preenchido com 0's

    int max = array[0];
    for (unsigned int i = 1; i < size; i++) {
        if (array[i] > max)
            max = array[i];
    }

    // Faz a distribuição das chaves nos baldes
    unsigned int index;
    for (unsigned int i = 0; i < size; i++) {
        index = numBuckets * array[i] / (max + 1);
        buckets[index][bucketSizes[index]] = array[i];
        bucketSizes[index]++;
    }

    // Ordena os elementos em cada balde
    for (unsigned int i = 0; i < numBuckets; i++)
        SortUtils<typeT>::InsertionSort(buckets[i], bucketSizes[i]);

    // Junta os trem que foram ordenados
    index = 0;
    for (unsigned int i = 0; i < numBuckets; i++) {
        for (int j = 0; j < bucketSizes[i]; j++) {
            array[index++] = buckets[i][j];
        }
    }

    delete[] bucketSizes;
}

#endif // SORT_UTILS_H_
