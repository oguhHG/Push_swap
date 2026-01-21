/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrandje <hgrandje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 15:22:07 by hgrandje          #+#    #+#             */
/*   Updated: 2026/01/21 15:22:13 by hgrandje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack *stack)
{
	t_node	*last;

	if (!stack || stack->size < 2)
		return ;
	last = stack->bottom;
	stack->bottom = last->prev;
	stack->bottom->next = NULL;
	last->prev = NULL;
	last->next = stack->top;
	stack->top->prev = last;
	stack->top = last;
}

void	op_rra(t_data *data, int print)
{
	reverse_rotate(data->a);
	if (print)
		write(1, "rra\n", 4);
	data->bench.rra++;
	data->bench.total++;
}

void	op_rrb(t_data *data, int print)
{
	reverse_rotate(data->b);
	if (print)
		write(1, "rrb\n", 4);
	data->bench.rrb++;
	data->bench.total++;
}

void	op_rrr(t_data *data, int print)
{
	reverse_rotate(data->a);
	reverse_rotate(data->b);
	if (print)
		write(1, "rrr\n", 4);
	data->bench.rrr++;
	data->bench.total++;
}