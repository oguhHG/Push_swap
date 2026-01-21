/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrandje <hgrandje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 14:00:00 by hgrandje          #+#    #+#             */
/*   Updated: 2026/01/21 15:55:27 by hgrandje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*find_target_in_b(t_stack *b, t_node *node_a)
{
	t_node	*current;
	t_node	*target;
	int		best_diff;

	current = b->top;
	target = NULL;
	best_diff = -1;
	while (current)
	{
		if (current->index < node_a->index)
		{
			if (best_diff == -1 || (node_a->index - current->index) < best_diff)
			{
				best_diff = node_a->index - current->index;
				target = current;
			}
		}
		current = current->next;
	}
	if (!target)
		target = get_max_node(b);
	return (target);
}

static int	calc_cost(int pos_a, int pos_b, int size_a, int size_b)
{
	int	cost_a;
	int	cost_b;

	if (pos_a <= size_a / 2)
		cost_a = pos_a;
	else
		cost_a = size_a - pos_a;
	if (pos_b <= size_b / 2)
		cost_b = pos_b;
	else
		cost_b = size_b - pos_b;
	if ((pos_a <= size_a / 2) == (pos_b <= size_b / 2))
	{
		if (cost_a > cost_b)
			return (cost_a);
		return (cost_b);
	}
	return (cost_a + cost_b);
}

static void	set_cost(t_data *data, t_node *node)
{
	int	pos_a;
	int	pos_b;

	pos_a = get_node_position(data->a, node);
	node->target = find_target_in_b(data->b, node);
	pos_b = get_node_position(data->b, node->target);
	node->cost = calc_cost(pos_a, pos_b, data->a->size, data->b->size);
	node->above_median_a = (pos_a <= data->a->size / 2);
	node->above_median_b = (pos_b <= data->b->size / 2);
}

void	init_nodes(t_data *data)
{
	t_node	*current;

	current = data->a->top;
	while (current)
	{
		set_cost(data, current);
		current = current->next;
	}
}

t_node	*get_cheapest(t_stack *a)
{
	t_node	*current;
	t_node	*cheapest;

	current = a->top;
	cheapest = current;
	while (current)
	{
		if (current->cost < cheapest->cost)
			cheapest = current;
		current = current->next;
	}
	return (cheapest);
}
