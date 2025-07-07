/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouve_to_tail.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 14:37:08 by kei2003730        #+#    #+#             */
/*   Updated: 2025/07/06 16:36:31 by kei2003730       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

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

void test_move_to_zero_tail(int nums[], int size)
{
    int rtv = move_zero_to_tail(nums, size);
    for (int i = 0; i < size; i++)
    {
        printf("nums[%i] = %i\n", i, nums[i]);
    }
    printf("Return value = %i\n", rtv);
}

int main(void)
{
    test_move_to_zero_tail((int[]){0, 3, 1, 0}, 4);
    test_move_to_zero_tail((int[]){0}, 1);
    // test_move_to_zero_tail((int[]){}, 0);
    test_move_to_zero_tail((int[]){1, 0}, 2);
    int nums_10k[10000];
    memset(nums_10k, 0, sizeof(int) * 10000);
    test_move_to_zero_tail(nums_10k, 10000);
    int size = 100000;
    int nums_size[size];
    memset(nums_size, 0, sizeof(int) * size);
    test_move_to_zero_tail(nums_size, size);
    return (0);
}