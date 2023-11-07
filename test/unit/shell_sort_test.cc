/*
 * Filename: shell_sort_test.cc
 * Created on: July  9, 2023
 * Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
 */

#include <cstdlib>
#include <ctime>
#include <random>
#include <type_traits>

#include "doctest.h"
#include "shell_sort.h"
#include "vector.h"

#define ARRAY_MAX_LENGHT_TEST 10000
#define ARRAY_MIN_LENGHT_TEST 100

TEST_CASE("ShellSort")
{
    std::srand(std::time(nullptr));

    std::size_t arrayRandomLength =
        (std::rand() % (ARRAY_MAX_LENGHT_TEST - ARRAY_MIN_LENGHT_TEST + 1) +
         ARRAY_MIN_LENGHT_TEST);

    std::size_t* checkArray =
        new std::size_t[arrayRandomLength]; // Array de verificação
    Vector<std::size_t> vector;             // Vetor que será ordenado

    std::size_t randomPosition;

    // Preenche os arrays com uma sequencia de números
    for (std::size_t i = 0; i < arrayRandomLength; i++)
    {
        vector.PushBack(i);
        checkArray[i] = i;
    }

    // Embaralha os números do array que será ordenado
    for (std::size_t i = arrayRandomLength - 1; i > 0; i--)
    {
        randomPosition = std::rand() % (i + 1);
        vector.Swap(i, randomPosition);
    }

    sort::Shell(vector);
    bool correct = true;

    // Verificação se a ordenação foi bem sucedida
    for (std::size_t i = 0; i < arrayRandomLength; i++)
    {
        if (vector[i] != checkArray[i])
        {
            correct = false;
            break;
        }
    }

    delete[] checkArray;

    CHECK(correct);
}
