/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:03:57 by marboccu          #+#    #+#             */
/*   Updated: 2024/03/25 14:50:27 by marboccu         ###   ########.fr       */
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
	int				final_idx;
	int				is_half_up;
	int				push_to_b_price;
	int				cheapest_node;
	struct s_stack	*best_node;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

int					main(int ac, char **av);

// ------------ UTILS ------------

void				ft_free_stack(t_stack *stack);
void				ft_free_matrix(char **matrix);
void				mega_free(t_stack *stack_a, char **str);
void				ft_error_free_str(char *str);
int					ft_syntax_error(char *str);
int					ft_duplicate_error(t_stack *stack, int num);
int					ft_sign_error(char *str);
void				ft_error(void);

// -------------------------------

// ------------ STACK ------------

t_stack				*ft_find_last_node(t_stack *head);
void				ft_add_new_node(t_stack **stack, int num);
int					ft_stack_size(t_stack *stack);
int					stack_min_value(t_stack *stack);
t_stack				*ft_find_min_node(t_stack **head);

// -------------------------------

// ------------ CHECKER ------------

t_stack				*checker_input(int ac, char **av);
int					check_if_sorted(t_stack *stack_a);
int					check_index(t_stack *stack, int value);

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

void				map_values(t_stack **stack_a);

void				big_sort(t_stack **stack_a, t_stack **stack_b);
void				assign_index(t_stack *stack);
void				find_best_biggest_smallest(t_stack *stack_a,
						t_stack *stack_b);
void				calc_push_price(t_stack *stack_a, t_stack *stack_b);
void				set_cheapest_push(t_stack *stack_b);
void				post_rotation(t_stack **stack, t_stack *cheapest_node,
						char stack_name);
void				final_rotation(t_stack **stack_a, int index, int middle);

// -------------------------------

#endif
