/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouve_to_tail.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 14:37:08 by kei2003730        #+#    #+#             */
/*   Updated: 2025/07/06 14:54:25 by kei2003730       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = *a;
}

void move_to_tail(int tab[], int size, int i)
{
    while (i < size - 1)
    {
        swap(&tab[i], &tab[i + 1]);
        i++;
    }
}

void move_zero_to_tail(int tab[], int size)
{
    int i = 0;
    while (i < size)
    {
        if (tab[i] == 0)
        {
            move_to_tail(tab, size, i);
        }
        i++;
    }
}

int main(void)
{
    int tab[] = {0, 3, 1, 0};
    int size = 4;
    move_zero_to_tail(tab, size);
    for (int i = 0; i < size; i++)
    {
        printf("tab[%i] = %i\n", i, tab[i]);
    }
    return (0);
}