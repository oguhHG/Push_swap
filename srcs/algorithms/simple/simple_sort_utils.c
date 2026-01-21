/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrandje <hgrandje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 13:00:00 by hgrandje          #+#    #+#             */
/*   Updated: 2026/01/21 15:55:27 by hgrandje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min_pos(t_stack *stack)
{
	t_node	*current;
	int		min;
	int		min_pos;
	int		pos;

	if (!stack || !stack->top)
		return (0);
	current = stack->top;
	min = current->value;
	min_pos = 0;
	pos = 0;
	while (current)
	{
		if (current->value < min)
		{
			min = current->value;
			min_pos = pos;
		}
		pos++;
		current = current->next;
	}
	return (min_pos);
}

void	push_min_to_b(t_data *data)
{
	int	min_pos;
	int	size;

	min_pos = get_min_pos(data->a);
	size = data->a->size;
	if (min_pos <= size / 2)
	{
		while (min_pos > 0)
		{
			op_ra(data, 1);
			min_pos--;
		}
	}
	else
	{
		while (min_pos < size)
		{
			op_rra(data, 1);
			min_pos++;
		}
	}
	op_pb(data, 1);
}

void	push_all_back(t_data *data)
{
	while (data->b->size > 0)
		op_pa(data, 1);
}

void	rotate_min_to_top(t_data *data)
{
	int	min_pos;
	int	size;

	min_pos = get_min_pos(data->a);
	size = data->a->size;
	if (min_pos <= size / 2)
	{
		while (min_pos > 0)
		{
			op_ra(data, 1);
			min_pos--;
		}
	}
	else
	{
		while (min_pos < size)
		{
			op_rra(data, 1);
			min_pos++;
		}
	}
}

int	stack_is_sorted(t_stack *stack)
{
	t_node	*current;

	if (!stack || !stack->top || stack->size <= 1)
		return (1);
	current = stack->top;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}
