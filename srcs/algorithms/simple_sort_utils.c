/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrandje <hgrandje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 13:00:00 by hgrandje          #+#    #+#             */
/*   Updated: 2026/01/21 13:04:39 by hgrandje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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

void	push_min_to_b(t_stack *a, t_stack *b)
{
	int	min_pos;
	int	size;

	min_pos = get_min_pos(a);
	size = a->size;
	if (min_pos <= size / 2)
	{
		while (min_pos > 0)
		{
			ra(a);
			min_pos--;
		}
	}
	else
	{
		while (min_pos < size)
		{
			rra(a);
			min_pos++;
		}
	}
	pb(a, b);
}

void	push_all_back(t_stack *a, t_stack *b)
{
	while (b->size > 0)
		pa(a, b);
}

void	rotate_min_to_top(t_stack *a)
{
	int	min_pos;
	int	size;

	min_pos = get_min_pos(a);
	size = a->size;
	if (min_pos <= size / 2)
	{
		while (min_pos > 0)
		{
			ra(a);
			min_pos--;
		}
	}
	else
	{
		while (min_pos < size)
		{
			rra(a);
			min_pos++;
		}
	}
}
