/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:03:57 by marboccu          #+#    #+#             */
/*   Updated: 2024/03/21 16:50:28 by marboccu         ###   ########.fr       */
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

typedef struct s_sequence
{
	int				start_idx;
	int				final_idx;
}					t_sequence;
typedef struct s_stack
{
	int				value;
	int				final_idx;
	int				is_half_up;
	int				push_to_b_price;
	int				cheapest_node;
	struct s_stack	*best_node;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

// ------------ UTILS ------------

void				ft_free_stack(t_stack *stack);
void				ft_free_matrix(char **matrix);
void				mega_free(t_stack *stack_a, char **str);
int					ft_syntax_error(char *str);
int					ft_duplicate_error(t_stack *stack, int num);
int					ft_sign_error(char *str);
void				ft_error(void);
int					ft_min(int a, int b);
int					ft_max(int a, int b);

// -------------------------------

// ------------ STACK ------------

t_stack				*ft_find_last_node(t_stack *head);
void				ft_add_new_node(t_stack **stack, int num);
void				print_stack(t_stack *stackm, char *str);
t_stack				*ft_stacklast(t_stack *lst);
int					ft_stack_size(t_stack *stack);
int					stack_max_value(t_stack *stack);
int					stack_min_value(t_stack *stack);
t_stack				*ft_find_min_node(t_stack **head);
int					check_index(t_stack *stack, int value);

// -------------------------------

// ------------ CHECKER ------------

t_stack				*checker_input(int ac, char **av);
int					check_if_sorted(t_stack *stack_a);

// -------------------------------

// ------------ MOVES ------------

void				nodes_swap(t_stack *stack, char *str);
void				nodes_double_swap(t_stack *stack_a, t_stack *stack_b);
void				swap_and_rotate(t_stack **stack);
void				swap_and_reverse_rotate(t_stack **stack);

void				nodes_rotate(t_stack **stack, char *str);
void				nodes_double_rotate(t_stack **stack_a, t_stack **stack_b);
void				stack_rotate_togheter(t_stack **stack_a, t_stack **stack_b,
						t_stack *cheapest_node);

void				nodes_reverse_rotate(t_stack **stack, char *str);
void				nodes_double_reverse_rotate(t_stack **stack_a,
						t_stack **stack_b);
void				stack_rev_rotate_togheter(t_stack **stack_a,
						t_stack **stack_b, t_stack *cheapest_node);

void				node_push(t_stack **stack_src, t_stack **stack_dst,
						char *str);

// -------------------------------

// ------------ SORT ------------

void				routing(t_stack **stack_a, t_stack **stack_b);
void				sort_three(t_stack **stack_a);
void				sort_small(t_stack **stack_a, t_stack **stack_b, int len);
int					is_closer_to_top(t_stack *stack, int x, int len);

void				quick_sort(int *array, int low, int high);
void				map_values(t_stack **stack_a);

void				radix_sort(t_stack **stack_a, t_stack **stack_b);
void				my_algo_sort(t_stack **stack_a, t_stack **stack_b);
void				sort_big(t_stack **stack_a, t_stack **stack_b);
void				big_sort(t_stack **stack_a, t_stack **stack_b);

void				assign_index(t_stack *stack);
void				post_optimization(t_stack **stack_a, t_stack **stack_b);

// -------------------------------

#endif
