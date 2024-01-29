/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:03:57 by marboccu          #+#    #+#             */
/*   Updated: 2024/01/28 22:19:43 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "libft_super/libft.h"
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

typedef struct s_stack
{
	int value;
	int curr_pos;
	int final_idx;
	int push_price;
	bool cheapest;
	bool above_mid;
	struct s_stack *next;
	struct s_stack *prev;
} t_stack;

void ft_free_matrix(char **matrix);
int ft_syntax_error(char *str);
int ft_duplicate_error(t_stack *stack, int num);
void ft_error(void);

t_stack *ft_find_last_node(t_stack *head);
void ft_add_new_node(t_stack **stack, int num);
void print_stack(t_stack *stackm, char *str);
t_stack *ft_stacklast(t_stack *lst);

t_stack *checker_input(int ac, char **av);
int check_if_sorted(t_stack *stack_a);

void nodes_swap(t_stack *stack, char *str);
void nodes_double_swap(t_stack *stack_a, t_stack *stack_b);

void nodes_rotate(t_stack **stack, char *str);
void nodes_double_rotate(t_stack **stack_a, t_stack **stack_b);

void nodes_reverse_rotate(t_stack **stack, char *str);
void nodes_double_reverse_rotate(t_stack **stack_a, t_stack **stack_b);

void node_push(t_stack **stack_src, t_stack **stack_dst, char *str);

#endif
