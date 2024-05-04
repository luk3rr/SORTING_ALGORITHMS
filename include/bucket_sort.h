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

#include <cstddef>

#include "comparators.h"
#include "insertion_sort.h"
#include "vector.h"

namespace sort
{
    /**
     * @brief Uses the BucketSort algorithm to sort the vector
     * @param vector The vector to be sorted
     * @param comp Custom comparator for elements. If not provided, the default 'less'
     * comparator will be used
     */
    template<typename typeT, typename Compare = decltype(comparators::Less<typeT>)>
    inline void Bucket(Vector<typeT>& vector,
                       std::size_t    numBuckets = 10,
                       Compare        comp       = comparators::Less<typeT>)
    {
        Vector<std::size_t>   bucketSizes(numBuckets, 0);
        Vector<Vector<typeT>> buckets(numBuckets);

        std::hash<typeT> hasher;
        std::size_t      index;

        std::size_t max = hasher(vector[0]);
        std::size_t aux;

        // Find the largest hash to normalize the values
        for (std::size_t i = 1; i < vector.Size(); i++)
        {
            aux = hasher(vector[i]);
            if (max < aux)
            {
                max = aux;
            }
        }

        // Insert elements in the buckets
        for (std::size_t i = 0; i < vector.Size(); i++)
        {
            index = numBuckets * hasher(vector[i]) / (max + 1);
            buckets[index].PushBack(vector[i]);
            bucketSizes[index]++;
        }

        // Sort each bucket
        for (std::size_t i = 0; i < numBuckets; i++)
        {
            Insertion(buckets[i], comp);
        }

        // Merge the buckets
        index = 0;
        for (std::size_t i = 0; i < numBuckets; i++)
        {
            for (std::size_t j = 0; j < bucketSizes[i]; j++)
            {
                vector[index++] = buckets[i][j];
            }
        }
    }
} // namespace sort

#endif // BUCKET_SORT_H_
