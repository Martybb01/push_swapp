/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_alog.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 20:24:56 by marboccu          #+#    #+#             */
/*   Updated: 2024/03/03 20:29:08 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
for each element in stack B:
	calculate index in stack A
	if index < stackA.size / 2:
		ra_moves = index
		rra_moves = stackA.size - index
	else:
		ra_moves = stackA.size - index
		rra_moves = index

	-Similar logic for rb and rrb in stack B
	if position_in_stackB < stackB.size / 2:
		rb_moves = position_in_stackB
		rrb_moves = stackB.size - position_in_stackB
	else:
		rb_moves = stackB.size - position_in_stackB
		rrb_moves = position_in_stackB

	total_moves = min(ra_moves + rb_moves, rra_moves + rrb_moves)
	-Store total_moves along with the move type decisions for this element

*/
