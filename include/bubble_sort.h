/*
 * Filename: bubble_sort.h
 * Created on: July  9, 2023
 * Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
 *
 * Implementation of the BubbleSort algorithm
 *
 * Time complexity
 * Worst case:   O(n^2)
 * Average case: O(n^2)
 * Best case:    O(n)
 *
 * Space complexity: O(1), since it does not require extra space to sort
 */

#ifndef BUBBLE_SORT_H_
#define BUBBLE_SORT_H_

#include "utils.h"
#include "vector.h"
#include <cstddef>

namespace sort
{
    /**
     * @brief Uses the BubbleSort algorithm to sort the vector
     * @param vector The vector to be sorted
     * @param comp Custom comparator for elements. If not provided, the default 'less'
     * comparator will be used
     */
    template<typename typeT, typename Compare = utils::less<typeT>>
    inline void Bubble(Vector<typeT>& vector, Compare comp = utils::less<typeT>())
    {
        bool swapped;

        for (std::size_t i = 0; i < vector.Size() - 1; i++)
        {
            swapped = false;

            for (std::size_t j = 0; j < vector.Size() - i - 1; j++)
            {
                if (comp(vector[j + 1], vector[j]))
                {
                    vector.Swap(j + 1, j);
                    swapped = true;
                }
            }

            if (not swapped)
                break;
        }
    }
} // namespace sort

#endif // BUBBLE_SORT_H_
