/*
* Filename: sort_utils.cc
* Created on: June  6, 2023
* Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
*/

#include "sort_utils.h"

// ----------------------------------------------------- HEAPSORT -------------------------------------------------------

void SortUtils::MaxHeapify(int subarray[], unsigned int position, unsigned int size) {
    unsigned int largest = position;
    unsigned int left = 2 * position + 1;
    unsigned int right = 2 * position + 2;

    if (left < size and subarray[left] > subarray[largest])
        largest = left;

    if (right < size and subarray[right] > subarray[largest])
        largest = right;

    if (largest != position) {
        std::swap(subarray[position], subarray[largest]);
        SortUtils::MaxHeapify(subarray, largest, size);
    }
}

void SortUtils::BuildMaxHeap(int array[], unsigned int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        SortUtils::MaxHeapify(array, i, size);
    }
}

void SortUtils::HeapSort(int array[], unsigned int size) {
    SortUtils::BuildMaxHeap(array, size);

    for (int i = size - 1; i > 0; i--) {
        std::swap(array[0], array[i]);
        SortUtils::MaxHeapify(array, 0, i);
    }
}

// ----------------------------------------------------- SHELLSORT ------------------------------------------------------

void SortUtils::ShellSort(int array[], unsigned int size) {
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

void SortUtils::MergeSortedSubarrays(int subarray[], int left, int middle, int right) {
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

void SortUtils::MergeSortHelper(int subarray[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2; // Evita overflow para valores de left e right grandes
        SortUtils::MergeSortHelper(subarray, left, middle);
        SortUtils::MergeSortHelper(subarray, middle + 1, right);
        SortUtils::MergeSortedSubarrays(subarray, left, middle, right);
    }
}

void SortUtils::MergeSort(int array[], unsigned int size) {
    SortUtils::MergeSortHelper(array, 0, size - 1);
}

// -------------------------------------------------- INSERTIONSORT -----------------------------------------------------

void SortUtils::InsertionSort(int array[], unsigned int size) {
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

void SortUtils::CountingSort(int array[], unsigned int size) {
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

void SortUtils::BucketSort(int array[], unsigned int size) {
    const unsigned int numBuckets = 10;
    int buckets[numBuckets][size];
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
        SortUtils::InsertionSort(buckets[i], bucketSizes[i]);

    // Junta os trem que foram ordenados
    index = 0;
    for (unsigned int i = 0; i < numBuckets; i++) {
        for (int j = 0; j < bucketSizes[i]; j++) {
            array[index++] = buckets[i][j];
        }
    }

    delete[] bucketSizes;
}
