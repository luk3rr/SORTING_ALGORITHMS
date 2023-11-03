/*
 * Filename: shell_sort.h
 * Created on: July  9, 2023
 * Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
 *
 * Implementation of the ShellSort algorithm
 *
 * Time complexity depends on the chosen gap sequence, ranging from
 * O(n^2) in the worst case to O(n) in the best case.
 *
 * Space complexity: O(1), since it does not require extra space to sort
 */

#ifndef SHELL_SORT_H_
#define SHELL_SORT_H_

#include <cmath>
#include <cstddef>

#include "vector.h"

namespace sort
{
    /**
     * @brief Uses the ShellSort algorithm to sort the vector
     *        The update method uses the golden ratio and is given by the floor of the
     *        equation h /= PHI
     * @param vector Vector to be sorted
     * @param comp Custom element comparator. If no custom comparator is provided,
     * the default comparator "less" will be used
     */
    template<typename typeT, typename Compare = utils::less<typeT>>
    inline void Shell(Vector<typeT>& vector, Compare comp = utils::less<typeT>())
    {
        std::size_t h = 1;
        std::size_t j;
        std::size_t operacoes = 0;

        while (h < vector.Size() / std::numbers::phi)
            h = std::ceil(h * std::numbers::phi);

        while (h >= 1)
        {
            for (std::size_t i = h; i < vector.Size(); i++)
            {
                j = i;

                while (j >= h and comp(vector[j], vector[j - h]))
                {
                    operacoes++;
                    vector.Swap(j, j - h);
                    j -= h;
                }
            }

            h = std::floor(h / std::numbers::phi);
        }
    }
} // namespace sort

#endif // SHELL_SORT_H_
