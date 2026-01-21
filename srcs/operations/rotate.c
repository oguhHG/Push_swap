/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrandje <hgrandje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 15:21:26 by hgrandje          #+#    #+#             */
/*   Updated: 2026/01/21 15:21:33 by hgrandje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack *stack)
{
	t_node	*first;

	if (!stack || stack->size < 2)
		return ;
	first = stack->top;
	stack->top = first->next;
	stack->top->prev = NULL;
	first->next = NULL;
	first->prev = stack->bottom;
	stack->bottom->next = first;
	stack->bottom = first;
}

void	op_ra(t_data *data, int print)
{
	rotate(data->a);
	if (print)
		write(1, "ra\n", 3);
	data->bench.ra++;
	data->bench.total++;
}

void	op_rb(t_data *data, int print)
{
	rotate(data->b);
	if (print)
		write(1, "rb\n", 3);
	data->bench.rb++;
	data->bench.total++;
}

void	op_rr(t_data *data, int print)
{
	rotate(data->a);
	rotate(data->b);
	if (print)
		write(1, "rr\n", 3);
	data->bench.rr++;
	data->bench.total++;
}