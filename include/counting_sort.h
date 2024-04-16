/*
 * Filename: counting_sort.h
 * Created on: July  9, 2023
 * Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
 *
 * Implementation of the CountingSort algorithm
 *
 * Time complexity, where k is the range of element values
 * Worst case:   O(n + k)
 * Average case: O(n + k)
 * Best case:    O(n + k)
 *
 * Space complexity: O(n + k)
 */

#ifndef COUNTING_SORT_H_
#define COUNTING_SORT_H_

#include <cstddef>
#include <type_traits>

#include "vector.h"

namespace sort
{
    /**
     * @brief Uses the CountingSort algorithm to sort the vector
     * @param vector The vector to be sorted
     * @param comp Custom comparator for elements. If not provided, the default 'less'
     * comparator will be used
     *
     * NOTE: This function is enabled only if typeT is a integer value
     */
    template<typename typeT>
    typename std::enable_if<std::is_integral<typeT>::value>::type
    Counting(Vector<typeT>& vector)
    {
        typeT max = vector[0];
        typeT min = vector[0];

        for (std::size_t i = 0; i < vector.Size(); i++)
        {
            if (max < vector[i])
                max = vector[i];

            else if (vector[i] < min)
                min = vector[i];
        }

        std::size_t countSize = max - min + 1;

        std::size_t* countArray = new std::size_t[countSize]();

        // Calculates the frequency of each value
        for (std::size_t i = 0; i < countSize; i++)
            countArray[vector[i]]++;

        std::size_t index = 0;

        // Sort the array
        for (std::size_t i = 0; i <= max; i++)
        {
            while (countArray[i] > 0)
            {
                vector[index++] = i;
                countArray[i]--;
            }
        }

        delete[] countArray;
    }
} // namespace sort

#endif // COUNTING_SORT_H_
