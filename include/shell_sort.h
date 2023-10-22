/*
* Filename: shell_sort.h
* Created on: July  9, 2023
* Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
*
* Implementação do algoritmo de ordenação ShellSort
*
* Complexidade de tempo depende o intervalo escolhido, variando entre
* O(n^2) no pior caso e O(n) no melhor caso.
*
* Complexiade de espaço O(n)
*/

#ifndef SHELL_SORT_H_
#define SHELL_SORT_H_

#include <cmath>

#include "vector.h"

namespace sort
{
    /**
     * @brief Utiliza o algoritmo ShellSort para ordenar o vector
     *        O método de atualização utiliza-se do número de ouro e é dado pelo piso da equação h /= PHI
     * @param vector Vector que será ordenado
     * @param comp Comparador personalizado dos elementos. Se não for passado um comparador
     *        o comparador padrão less será utilizado
     */
    template<typename typeT, typename Compare = utils::less<typeT>>
    inline void Shell(Vector<typeT> &vector, Compare comp = utils::less<typeT>())
    {
        unsigned int h = 1;
        unsigned int j;
        unsigned int operacoes = 0;

        while (h < vector.Size() / std::numbers::phi)
            h = std::ceil(h * std::numbers::phi);

        while (h >= 1)
        {
            for (unsigned int i = h; i < vector.Size(); i++)
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
}

#endif // SHELL_SORT_H_
