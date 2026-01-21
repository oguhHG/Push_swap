/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrandje <hgrandje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 15:21:09 by hgrandje          #+#    #+#             */
/*   Updated: 2026/01/21 15:21:14 by hgrandje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack *stack)
{
	int	tmp_value;
	int	tmp_index;

	if (!stack || stack->size < 2)
		return ;
	tmp_value = stack->top->value;
	tmp_index = stack->top->index;
	stack->top->value = stack->top->next->value;
	stack->top->index = stack->top->next->index;
	stack->top->next->value = tmp_value;
	stack->top->next->index = tmp_index;
}

void	op_sa(t_data *data, int print)
{
	swap(data->a);
	if (print)
		write(1, "sa\n", 3);
	data->bench.sa++;
	data->bench.total++;
}

void	op_sb(t_data *data, int print)
{
	swap(data->b);
	if (print)
		write(1, "sb\n", 3);
	data->bench.sb++;
	data->bench.total++;
}

void	op_ss(t_data *data, int print)
{
	swap(data->a);
	swap(data->b);
	if (print)
		write(1, "ss\n", 3);
	data->bench.ss++;
	data->bench.total++;
}