/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 22:49:31 by marboccu          #+#    #+#             */
/*   Updated: 2024/01/18 23:05:43 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int ft_lis(t_list *stack)
// {
// 	int lis[ft_lstsize(stack)];
// 	int i;
// 	int j;
// 	int max;

// 	i = 0;
// 	while (stack)
// 	{
// 		lis[i] = 1;
// 		i++;
// 		stack = stack->next;
// 	}
// 	i = 1;
// 	while (stack)
// 	{
// 		j = 0;
// 		while (j < i)
// 		{
// 			if (stack->value > stack->next->value && lis[i] < lis[j] + 1)
// 				lis[i] = lis[j] + 1;
// 			j++;
// 		}
// 		i++;
// 		stack = stack->next;
// 	}
// 	max = 0;
// 	i = 0;
// 	while (i < ft_lstsize(stack))
// 	{
// 		if (max < lis[i])
// 			max = lis[i];
// 		i++;
// 	}
// 	return (max);
// }

int length_of_lis(int nums[], int n)
{
	int lis[n];
	int i;
	int low;
	int high;
	int mid;
	int lis_size;

	lis_size = 1;
	lis[0] = nums[0];

	i = 1;
	printf("ciao");
	while (i < n)
	{
		if (nums[i] > lis[lis_size - 1])
		{
			lis[lis_size++] = nums[i];
		}
		else
		{
			low = 0;
			high = lis_size - 1;
			while (low <= high)
			{
				mid = (low + high) / 2;
				if (lis[mid] >= nums[i])
					high = mid - 1;
				else
					low = mid + 1;
			}
		}
		i++;
		lis[low] = nums[i];
	}
	return (lis_size);
}

int main()
{
	printf("ciao");
	int nums[] = {2, 5, 3, 7, 11, 8, 10, 13, 6};
	int n = sizeof(nums) / sizeof(nums[0]);
	printf("Length of LIS is %d\n", length_of_lis(nums, n));
	return (0);
}
