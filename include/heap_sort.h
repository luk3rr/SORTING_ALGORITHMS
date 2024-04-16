/*
 * Filename: heap_sort.h
 * Created on: July  9, 2023
 * Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
 *
 * Implementation of the HeapSort algorithm
 *
 * Time complexity
 * Worst case:   O(n log n)
 * Average case: O(n log n)
 * Best case:    O(n log n)
 *
 * Space complexity: O(1), since it does not require extra space to sort
 **/

#ifndef HEAP_SORT_H_
#define HEAP_SORT_H_

#include <cstddef>
#include <cstdint>

#include "comparators.h"
#include "vector.h"

namespace sort
{
    // Private methods
    namespace
    {
        /**
         * @brief Transforms the subvector into a heap data structure
         * @param subvector Subvector to be transformed into a heap
         * @param position Position of the array element to be adjusted
         * @param heapSize Heap size
         * @param comp Custom element comparator. If no custom comparator is provided,
         * the default comparator "less" will be used
         */
        template<typename typeT, typename Compare = decltype(comparators::less<typeT>)>
        inline void MaxHeapify(Vector<typeT>& subvector,
                               std::size_t    position,
                               std::size_t    heapSize,
                               Compare        comp = comparators::less<typeT>)
        {
            std::size_t largest = position;
            std::size_t left    = 2 * position + 1;
            std::size_t right   = 2 * position + 2;

            if (left < heapSize and comp(subvector[largest], subvector[left]))
                largest = left;

            if (right < heapSize and comp(subvector[largest], subvector[right]))
                largest = right;

            if (largest != position)
            {
                subvector.Swap(position, largest);
                MaxHeapify(subvector, largest, heapSize);
            }
        }

        /**
         * @brief Builds the initial heap
         * @param array Array to be transformed into a heap
         * @param heapSize Heap size
         * @param comp Custom element comparator. If no custom comparator is provided,
         * the default comparator "less" will be used
         */
        template<typename typeT, typename Compare = decltype(comparators::less<typeT>)>
        inline void BuildMaxHeap(Vector<typeT>& vector,
                                 std::size_t    heapSize,
                                 Compare        comp = comparators::less<typeT>)
        {
            // This loop stops when i = -1
            for (int32_t i = heapSize / 2 - 1; i >= 0; i--)
                MaxHeapify(vector, i, heapSize, comp);
        }

    } // namespace

    /**
     * @brief Uses the HeapSort algorithm to sort the vector
     * @param vector Vector to be sorted
     * @param comp Custom element comparator. If no custom comparator is provided,
     * the default comparator "less" will be used
     */
    template<typename typeT, typename Compare = decltype(comparators::less<typeT>)>
    inline void Heap(Vector<typeT>& vector, Compare comp = comparators::less<typeT>)
    {
        BuildMaxHeap(vector, vector.Size(), comp);

        for (std::size_t i = vector.Size() - 1; i > 0; i--)
        {
            vector.Swap(0, i);
            MaxHeapify(vector, 0, i, comp);
        }
    }
} // namespace sort

#endif // HEAP_SORT_H_
