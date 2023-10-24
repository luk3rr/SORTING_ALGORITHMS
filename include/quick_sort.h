/*
* Filename: quick_sort.h
* Created on: October 23, 2023
* Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
*/

#ifndef QUICK_SORT_H_
#define QUICK_SORT_H_

#include "vector.h"
#include <cstddef>

namespace sort
{
    // Private methods
    namespace
    {
        /**
         * @brief Partitions a subarray of sorted vectors
         * @param vector Vector to be partitioned
         * @param low Index of the subarray's start
         * @param high Index of the subarray's end
         * @param comp Custom element comparator. If not provided, the default 'less' comparator will be used.
         * @return The index of the pivot after partitioning
         */
        template<typename typeT, typename Compare = utils::less<typeT>>
        inline std::size_t Partition(Vector<typeT> &vector, const std::size_t &low, const std::size_t &high, Compare comp = utils::less<typeT>())
        {
            typeT pivot = vector[high];
            std::size_t i = low;
            for (std::size_t j = low; j < high; j++)
            {
                if (comp(vector[j], pivot))
                {
                    vector.Swap(i, j);
                    i++;
                }
            }

            vector.Swap(i, high);
            return i;
        }

        /**
         * @brief Uses the Quick Sort algorithm to sort the vector
         * @param vector Vector to be sorted
         * @param low Index of the subarray's start
         * @param high Index of the subarray's end
         * @param comp Custom element comparator. If not provided, the default 'less' comparator will be used.
         */
        template<typename typeT, typename Compare = utils::less<typeT>>
        inline void Quick(Vector<typeT> &vector, const std::size_t &low, const std::size_t &high, Compare comp = utils::less<typeT>())
        {
            if (low < high)
            {
                std::size_t pivot = Partition(vector, low, high, comp);

                if (pivot > 0) // if pivot = 0 -> pivot - 1 == shit
                    Quick(vector, low, pivot - 1, comp);

                Quick(vector, pivot + 1, high, comp);
            }
        }

    } // Private methods

    /**
     * @brief Uses the Quick Sort algorithm to sort the vector
     * @param vector Vector to be sorted
     * @param comp Custom element comparator. If not provided, the default 'less' comparator will be used.
     */
    template<typename typeT, typename Compare = utils::less<typeT>>
    inline void Quick(Vector<typeT> &vector, Compare comp = utils::less<typeT>())
    {
        Quick(vector, 0, vector.Size() - 1, comp);
    }
}

#endif // QUICK_SORT_H_
