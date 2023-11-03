/*
 * Filename: merge_sort.h
 * Created on: July  9, 2023
 * Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
 *
 * Implementation of the MergeSort sorting algorithm
 *
 * Time complexity:
 * Worst case:   O(n log n)
 * Average case: O(n log n)
 * Best case:    O(n log n)
 *
 * Space complexity: O(n), linear space due to temporary storage of divided and merged
 * portions
 */

#ifndef MERGE_SORT_H_
#define MERGE_SORT_H_

#include "vector.h"
#include <cstddef>

namespace sort
{
    // Private methods
    namespace
    {
        /**
         * @brief Merges the sorted subvectors
         * @param subvector Subvector to be merged
         * @param left, middle, right Indices of the start, middle, and end of the
         * subarray
         * @param comp Custom element comparator. If no custom comparator is provided,
         * the default comparator "less" will be used
         */
        template<typename typeT, typename Compare = utils::less<typeT>>
        inline void MergeSortedSubarrays(Vector<typeT>& subvector,
                                         std::size_t    left,
                                         std::size_t    middle,
                                         std::size_t    right,
                                         Compare        comp = utils::less<typeT>())
        {
            std::size_t firstHalf  = middle - left + 1;
            std::size_t secondHalf = right - middle;

            typeT leftArray[firstHalf];
            typeT rightArray[secondHalf];

            for (std::size_t i = 0; i < firstHalf; i++)
                leftArray[i] = subvector[left + i];

            for (std::size_t j = 0; j < secondHalf; j++)
                rightArray[j] = subvector[middle + 1 + j];

            std::size_t i, j, k;
            i = j = 0;
            k     = left;

            while (i < firstHalf and j < secondHalf)
            {
                if (comp(leftArray[i], rightArray[j]))
                    subvector[k++] = leftArray[i++];

                else
                    subvector[k++] = rightArray[j++];
            }

            while (i < firstHalf)
                subvector[k++] = leftArray[i++];

            while (j < secondHalf)
                subvector[k++] = rightArray[j++];
        }

        /**
         * @brief Assists the MergeSort algorithm by recursively dividing the vector
         * @param subvector Subvector to be sorted
         * @param left, right Indices of where the subarray starts and ends
         * @param comp Custom element comparator. If no custom comparator is provided,
         * the default comparator "less" will be used
         */
        template<typename typeT, typename Compare = utils::less<typeT>>
        inline void MergeSortHelper(Vector<typeT>& subvector,
                                    std::size_t    left,
                                    std::size_t    right,
                                    Compare        comp = utils::less<typeT>())
        {
            if (left < right)
            {
                // Avoids overflow for large left and right values
                std::size_t middle = left + (right - left) / 2;

                MergeSortHelper(subvector, left, middle, comp);
                MergeSortHelper(subvector, middle + 1, right, comp);
                MergeSortedSubarrays(subvector, left, middle, right, comp);
            }
        }
    } // namespace

    /**
     * @brief Uses the MergeSort algorithm to sort the vector
     * @param vector Vector to be sorted
     * @param comp Custom element comparator. If no custom comparator is provided,
     * the default comparator "less" will be used
     */
    template<typename typeT, typename Compare = utils::less<typeT>>
    inline void Merge(Vector<typeT>& vector, Compare comp = utils::less<typeT>())
    {
        MergeSortHelper(vector, 0, vector.Size() - 1, comp);
    }
} // namespace sort

#endif // MERGE_SORT_H_
