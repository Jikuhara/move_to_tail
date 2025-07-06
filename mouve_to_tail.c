/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouve_to_tail.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 14:37:08 by kei2003730        #+#    #+#             */
/*   Updated: 2025/07/06 14:56:08 by kei2003730       ###   ########.fr       */
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

void move_to_tail(int nums[], int size, int i)
{
    while (i < size - 1)
    {
        swap(&nums[i], &nums[i + 1]);
        i++;
    }
}

int move_zero_to_tail(int nums[], int size)
{
    int i = 0;
    int count = 0;
    while (i < size)
    {
        if (nums[i] == 0)
        {
            move_to_tail(nums, size, i);
            count++;
        }
        i++;
    }
    return (count);
}

int main(void)
{
    int nums[] = {0, 3, 1, 0};
    int size = 4;
    move_zero_to_tail(nums, size);
    for (int i = 0; i < size; i++)
    {
        printf("nums[%i] = %i\n", i, nums[i]);
    }
    return (0);
}