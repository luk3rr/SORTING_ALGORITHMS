/*
 * Filename: selection_sort.h
 * Created on: July  9, 2023
 * Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
 *
 * Implementation of the SelectionSort algorithm
 *
 * Time complexity:
 * Worst case:   O(n^2)
 * Average case: O(n^2)
 * Best case:    O(n^2)
 *
 * Space complexity: O(1), since it does not require extra space to sort
 */

#ifndef SELECTION_SORT_H_
#define SELECTION_SORT_H_

#include "vector.h"
#include <cstddef>

namespace sort
{
    /**
     * @brief Uses the SelectionSort algorithm to sort the vector
     * @param vector Vector to be sorted
     * @param comp Custom element comparator. If no custom comparator is provided,
     * the default comparator "less" will be used.
     */
    template<typename typeT, typename Compare = utils::less<typeT>>
    inline void Selection(Vector<typeT>& vector, Compare comp = utils::less<typeT>())
    {
        std::size_t min;

        for (std::size_t i = 0; i < vector.Size() - 1; i++)
        {
            min = i;

            for (std::size_t j = i + 1; j < vector.Size(); j++)
            {
                if (comp(vector[j], vector[min]))
                    min = j;
            }

            if (i != min)
                vector.Swap(min, i);
        }
    }
} // namespace sort

#endif // SELECTION_SORT_H_
