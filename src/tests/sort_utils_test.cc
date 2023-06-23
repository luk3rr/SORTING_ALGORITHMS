/*
* Filename: sort_utils_test.cc
* Created on: June  6, 2023
* Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
*/

#include <ctime>
#include <cstdlib>
#include <random>
#include <type_traits>

#include "doctest.h"
#include "sort_utils.h"
#include "vector.h"

#define ARRAY_MAX_LENGHT_TEST 10000
#define ARRAY_MIN_LENGHT_TEST 100

TEST_CASE("BubbleSort") {
    std::srand(std::time(nullptr));

    int arrayRandomLength = (std::rand() % (ARRAY_MAX_LENGHT_TEST - ARRAY_MIN_LENGHT_TEST + 1) + ARRAY_MIN_LENGHT_TEST);

    int *checkArray = new int[arrayRandomLength]; // Array de verificação
    Vector<int> vector; // Vetor que será ordenado

    int randomPosition;

    // Preenche os arrays com uma sequencia de números
    for (int i = 0; i < arrayRandomLength; i++) {
        vector.PushBack(i);
        checkArray[i] = i;
    }

    // Embaralha os números do array que será ordenado
    for (int i = arrayRandomLength - 1; i > 0; i--) {
        randomPosition = std::rand() % (i + 1);
        vector.Swap(i, randomPosition);
    }

    SortUtils<int>::BubbleSort(vector);
    bool correct = true;

    // Verificação se a ordenação foi bem sucedida
    for (int i = 0; i < arrayRandomLength; i++) {
        if (vector[i] != checkArray[i]) {
            correct = false;
            break;
        }
    }

    delete[] checkArray;

    CHECK(correct);
}

TEST_CASE("SelectionSort") {
    std::srand(std::time(nullptr));

    int arrayRandomLength = (std::rand() % (ARRAY_MAX_LENGHT_TEST - ARRAY_MIN_LENGHT_TEST + 1) + ARRAY_MIN_LENGHT_TEST);

    int *checkArray = new int[arrayRandomLength]; // Array de verificação
    Vector<int> vector; // Vetor que será ordenado

    int randomPosition;

    // Preenche os arrays com uma sequencia de números
    for (int i = 0; i < arrayRandomLength; i++) {
        vector.PushBack(i);
        checkArray[i] = i;
    }

    // Embaralha os números do array que será ordenado
    for (int i = arrayRandomLength - 1; i > 0; i--) {
        randomPosition = std::rand() % (i + 1);
        vector.Swap(i, randomPosition);
    }

    SortUtils<int>::SelectionSort(vector);
    bool correct = true;

    // Verificação se a ordenação foi bem sucedida
    for (int i = 0; i < arrayRandomLength; i++) {
        if (vector[i] != checkArray[i]) {
            correct = false;
            break;
        }
    }

    delete[] checkArray;

    CHECK(correct);
}

TEST_CASE("HeapSort") {
    std::srand(std::time(nullptr));

    int arrayRandomLength = (std::rand() % (ARRAY_MAX_LENGHT_TEST - ARRAY_MIN_LENGHT_TEST + 1) + ARRAY_MIN_LENGHT_TEST);

    int *checkArray = new int[arrayRandomLength]; // Array de verificação
    Vector<int> vector; // Vetor que será ordenado

    int randomPosition;

    // Preenche os arrays com uma sequencia de números
    for (int i = 0; i < arrayRandomLength; i++) {
        vector.PushBack(i);
        checkArray[i] = i;
    }

    // Embaralha os números do array que será ordenado
    for (int i = arrayRandomLength - 1; i > 0; i--) {
        randomPosition = std::rand() % (i + 1);
        vector.Swap(i, randomPosition);
    }

    SortUtils<int>::HeapSort(vector);
    bool correct = true;

    // Verificação se a ordenação foi bem sucedida
    for (int i = 0; i < arrayRandomLength; i++) {
        if (vector[i] != checkArray[i]) {
            correct = false;
            break;
        }
    }

    delete[] checkArray;

    CHECK(correct);
}

TEST_CASE("ShellSort") {
    std::srand(std::time(nullptr));

    int arrayRandomLength = (std::rand() % (ARRAY_MAX_LENGHT_TEST - ARRAY_MIN_LENGHT_TEST + 1) + ARRAY_MIN_LENGHT_TEST);

    int *checkArray = new int[arrayRandomLength]; // Array de verificação
    Vector<int> vector; // Vetor que será ordenado

    int randomPosition;

    // Preenche os arrays com uma sequencia de números
    for (int i = 0; i < arrayRandomLength; i++) {
        vector.PushBack(i);
        checkArray[i] = i;
    }

    // Embaralha os números do array que será ordenado
    for (int i = arrayRandomLength - 1; i > 0; i--) {
        randomPosition = std::rand() % (i + 1);
        vector.Swap(i, randomPosition);
    }

    SortUtils<int>::ShellSort(vector);
    bool correct = true;

    // Verificação se a ordenação foi bem sucedida
    for (int i = 0; i < arrayRandomLength; i++) {
        if (vector[i] != checkArray[i]) {
            correct = false;
            break;
        }
    }

    delete[] checkArray;

    CHECK(correct);
}

TEST_CASE("MergeSort") {
    std::srand(std::time(nullptr));

    int arrayRandomLength = (std::rand() % (ARRAY_MAX_LENGHT_TEST - ARRAY_MIN_LENGHT_TEST + 1) + ARRAY_MIN_LENGHT_TEST);

    int *checkArray = new int[arrayRandomLength]; // Array de verificação
    Vector<int> vector; // Vetor que será ordenado

    int randomPosition;

    // Preenche os arrays com uma sequencia de números
    for (int i = 0; i < arrayRandomLength; i++) {
        vector.PushBack(i);
        checkArray[i] = i;
    }

    // Embaralha os números do array que será ordenado
    for (int i = arrayRandomLength - 1; i > 0; i--) {
        randomPosition = std::rand() % (i + 1);
        vector.Swap(i, randomPosition);
    }

    SortUtils<int>::MergeSort(vector);
    bool correct = true;

    // Verificação se a ordenação foi bem sucedida
    for (int i = 0; i < arrayRandomLength; i++) {
        if (vector[i] != checkArray[i]) {
            correct = false;
            break;
        }
    }

    delete[] checkArray;

    CHECK(correct);
}


TEST_CASE("InsertionSort") {
    std::srand(std::time(nullptr));

    int arrayRandomLength = (std::rand() % (ARRAY_MAX_LENGHT_TEST - ARRAY_MIN_LENGHT_TEST + 1) + ARRAY_MIN_LENGHT_TEST);

    int *checkArray = new int[arrayRandomLength]; // Array de verificação
    Vector<int> vector; // Vetor que será ordenado

    int randomPosition;

    // Preenche os arrays com uma sequencia de números
    for (int i = 0; i < arrayRandomLength; i++) {
        vector.PushBack(i);
        checkArray[i] = i;
    }

    // Embaralha os números do array que será ordenado
    for (int i = arrayRandomLength - 1; i > 0; i--) {
        randomPosition = std::rand() % (i + 1);
        vector.Swap(i, randomPosition);
    }

    SortUtils<int>::InsertionSort(vector);
    bool correct = true;

    // Verificação se a ordenação foi bem sucedida
    for (int i = 0; i < arrayRandomLength; i++) {
        if (vector[i] != checkArray[i]) {
            correct = false;
            break;
        }
    }

    delete[] checkArray;

    CHECK(correct);
}

TEST_CASE("CountingSort") {
    std::srand(std::time(nullptr));

    int arrayRandomLength = (std::rand() % (ARRAY_MAX_LENGHT_TEST - ARRAY_MIN_LENGHT_TEST + 1) + ARRAY_MIN_LENGHT_TEST);

    int *checkArray = new int[arrayRandomLength]; // Array de verificação
    Vector<int> vector; // Vetor que será ordenado

    int randomPosition;

    // Preenche os arrays com uma sequencia de números
    for (int i = 0; i < arrayRandomLength; i++) {
        vector.PushBack(i);
        checkArray[i] = i;
    }

    // Embaralha os números do array que será ordenado
    for (int i = arrayRandomLength - 1; i > 0; i--) {
        randomPosition = std::rand() % (i + 1);
        vector.Swap(i, randomPosition);
    }

    SortUtils<int>::CountingSort(vector);
    bool correct = true;

    // Verificação se a ordenação foi bem sucedida
    for (int i = 0; i < arrayRandomLength; i++) {
        if (vector[i] != checkArray[i]) {
            correct = false;
            break;
        }
    }

    delete[] checkArray;

    CHECK(correct);
}

TEST_CASE("BucketSort") {
    std::srand(std::time(nullptr));

    int arrayRandomLength = (std::rand() % (ARRAY_MAX_LENGHT_TEST - ARRAY_MIN_LENGHT_TEST + 1) + ARRAY_MIN_LENGHT_TEST);

    int *checkArray = new int[arrayRandomLength]; // Array de verificação
    Vector<int> vector; // Vetor que será ordenado

    int randomPosition;

    // Preenche os arrays com uma sequencia de números
    for (int i = 0; i < arrayRandomLength; i++) {
        vector.PushBack(i);
        checkArray[i] = i;
    }

    // Embaralha os números do array que será ordenado
    for (int i = arrayRandomLength - 1; i > 0; i--) {
        randomPosition = std::rand() % (i + 1);
        vector.Swap(i, randomPosition);
    }

    SortUtils<int>::BucketSort(vector);
    bool correct = true;

    // Verificação se a ordenação foi bem sucedida
    for (int i = 0; i < arrayRandomLength; i++) {
        if (vector[i] != checkArray[i]) {
            correct = false;
            break;
        }
    }

    delete[] checkArray;

    CHECK(correct);
}
