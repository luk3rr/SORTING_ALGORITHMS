/*
 * Filename: bucket_sort.h
 * Created on: July  9, 2023
 * Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
 *
 * Implementation of the BucketSort algorithm
 *
 * Time complexity, where k is the number of buckets:
 * Worst case:   O(n^2)
 * Average case: O(n + k)
 * Best case:    O(n + k)
 *
 * Space complexity: O(n + k)
 */

#ifndef BUCKET_SORT_H_
#define BUCKET_SORT_H_

#include "insertion_sort.h"
#include "vector.h"
#include <cstddef>

namespace sort
{
    /**
     * @brief Uses the BucketSort algorithm to sort the vector
     * @param vector The vector to be sorted
     * @param comp Custom comparator for elements. If not provided, the default 'less'
     * comparator will be used
     */
    template<typename typeT, typename Compare = utils::less<typeT>>
    inline void Bucket(Vector<typeT>& vector, Compare comp = utils::less<typeT>())
    {
        const std::size_t numBuckets = 10;

        typeT buckets[numBuckets][vector.Size()];

        // Creates an array filled with 0's
        std::size_t* bucketSizes = new std::size_t[numBuckets]();

        typeT max = vector[0];
        for (std::size_t i = 1; i < vector.Size(); i++)
            if (comp(max, vector[i]))
                max = vector[i];

        // Distributes the keys into the buckets
        std::size_t index;
        for (std::size_t i = 0; i < vector.Size(); i++)
        {
            index = numBuckets * vector[i] / (max + 1);

            buckets[index][bucketSizes[index]] = vector[i];
            bucketSizes[index]++;
        }

        // Sorts the elements in each bucket. In this case, we use the insertion sort
        // algorithm
        for (std::size_t i = 0; i < numBuckets; i++)
            Insertion(buckets[i], bucketSizes[i]);

        // Merges the sorted items together
        index = 0;
        for (std::size_t i = 0; i < numBuckets; i++)
        {
            for (std::size_t j = 0; j < bucketSizes[i]; j++)
                vector[index++] = buckets[i][j];
        }

        delete[] bucketSizes;
    }
} // namespace sort

#endif // BUCKET_SORT_H_
