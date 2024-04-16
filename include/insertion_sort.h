/*
 * Filename: insertion_sort.h
 * Created on: July  9, 2023
 * Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
 *
 * Implementation of the InsertionSort sorting algorithm
 *
 * Time complexity
 * Worst case:   O(n^2)
 * Average case: O(n^2)
 * Best case:    O(n)
 *
 * Space complexity: O(1), since it does not require extra space to sort
 **/

#ifndef INSERTION_SORT_H_
#define INSERTION_SORT_H_

#include <cstddef>
#include <cstdint>

#include "comparators.h"
#include "vector.h"

namespace sort
{
    /**
     * @brief Uses the InsertionSort algorithm to sort the vector
     * @param vector Vector to be sorted
     * @param comp Custom element comparator. If no custom comparator is provided,
     * the default comparator "less" will be used
     */
    template<typename typeT, typename Compare = decltype(comparators::less<typeT>)>
    inline void Insertion(Vector<typeT>& vector,
                          Compare        comp = comparators::less<typeT>)
    {
        typeT   key;
        int32_t j;

        for (std::size_t i = 1; i < vector.Size(); i++)
        {
            key = vector[i];
            j   = i - 1;

            while (j >= 0 and comp(key, vector[j]))
            {
                vector[j + 1] = vector[j];
                j--;
            }
            vector[j + 1] = key;
        }
    }

    /**
     * @brief Uses the InsertionSort algorithm to sort the array
     * @param array Array to be sorted
     * @param size Size of the interval to be sorted
     * @param comp Custom element comparator. If no custom comparator is provided,
     * the default comparator "less" will be used
     */
    template<typename typeT, typename Compare = decltype(comparators::less<typeT>)>
    inline void Insertion(typeT       array[],
                          std::size_t size,
                          Compare     comp = comparators::less<typeT>)
    {
        typeT   key;
        int32_t j;

        for (std::size_t i = 0; i < size; i++)
        {
            key = array[i];
            j   = i - 1;

            while (j >= 0 and comp(key, array[j]))
            {
                array[j + 1] = array[j];
                j--;
            }
            array[j + 1] = key;
        }
    }
} // namespace sort

#endif // INSERTION_SORT_H_
