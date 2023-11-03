/*
 * Filename: quick_sort_test.cc
 * Created on: October 23, 2023
 * Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
 */

#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <random>
#include <type_traits>

#include "doctest.h"
#include "quick_sort.h"
#include "vector.h"

#define ARRAY_MAX_LENGHT_TEST 10000
#define ARRAY_MIN_LENGHT_TEST 100

TEST_CASE("QuickSort")
{
    std::srand(std::time(nullptr));

    std::size_t arrayRandomLength =
        (std::rand() % (ARRAY_MAX_LENGHT_TEST - ARRAY_MIN_LENGHT_TEST + 1) +
         ARRAY_MIN_LENGHT_TEST);

    std::size_t* checkArray = new std::size_t[arrayRandomLength]; // Verification array
    Vector<std::size_t> vector; // The array that will be sorted

    std::size_t randomPosition;

    // Filling the arrays with a sequence of numbers
    for (std::size_t i = 0; i < arrayRandomLength; i++)
    {
        vector.PushBack(i);
        checkArray[i] = i;
    }

    // Shuffling the numbers in the array to be sorted
    for (std::size_t i = arrayRandomLength - 1; i > 0; i--)
    {
        randomPosition = std::rand() % (i + 1);
        vector.Swap(i, randomPosition);
    }

    sort::Quick(vector);
    bool correct = true;

    // Checking if the sorting was successful
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
