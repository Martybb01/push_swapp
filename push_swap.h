/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:03:57 by marboccu          #+#    #+#             */
/*   Updated: 2024/02/15 12:01:19 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft_super/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				pivot;
	int				curr_pos;
	int				final_idx;
	int				push_price;
	bool			cheapest;
	bool			above_mid;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

// ------------ UTILS ------------

void				ft_free_matrix(char **matrix);
int					ft_syntax_error(char *str);
int					ft_duplicate_error(t_stack *stack, int num);
void				ft_sign_error(char *str);
void				ft_error(void);

// -------------------------------

// ------------ STACK ------------

t_stack				*ft_find_last_node(t_stack *head);
void				ft_add_new_node(t_stack **stack, int num);
void				print_stack(t_stack *stackm, char *str);
t_stack				*ft_stacklast(t_stack *lst);
int					ft_stack_size(t_stack *stack);
t_stack				*stack_max_value(t_stack *stack);
t_stack				*stack_min_value(t_stack *stack);
t_stack				*stack_top_value(t_stack *stack);

// -------------------------------

// ------------ CHECKER ------------

t_stack				*checker_input(int ac, char **av);
int					check_if_sorted(t_stack *stack_a);

// -------------------------------

// ------------ MOVES ------------

void				nodes_swap(t_stack *stack, char *str);
void				nodes_double_swap(t_stack *stack_a, t_stack *stack_b);

void				nodes_rotate(t_stack **stack, char *str);
void				nodes_double_rotate(t_stack **stack_a, t_stack **stack_b);

void				nodes_reverse_rotate(t_stack **stack, char *str);
void				nodes_double_reverse_rotate(t_stack **stack_a,
						t_stack **stack_b);

void				node_push(t_stack **stack_src, t_stack **stack_dst,
						char *str);

// -------------------------------

// ------------ SORT ------------

void				routing(t_stack **stack_a, t_stack **stack_b);
void				sort_three(t_stack **stack_a);
void				sort_small(t_stack **stack_a, t_stack **stack_b, int len);

int					is_closer_to_top(t_stack *stack, int x, int len);
int					is_on_top(t_stack *stack, int x);
void				quick_sort(int *array, int low, int high);
void				quicksort_stack(t_stack **stack_a, int low, int high);

void				radix_sort(t_stack **stack_a, t_stack **stack_b);
void				mergeSort(int arr[], int l, int r);

// -------------------------------

#endif
