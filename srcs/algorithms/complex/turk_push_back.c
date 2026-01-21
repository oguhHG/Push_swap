/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_push_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrandje <hgrandje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 14:00:00 by hgrandje          #+#    #+#             */
/*   Updated: 2026/01/21 15:55:27 by hgrandje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*find_target_in_a(t_stack *a, t_node *node_b)
{
	t_node	*current;
	t_node	*target;
	int		best_diff;

	current = a->top;
	target = NULL;
	best_diff = -1;
	while (current)
	{
		if (current->index > node_b->index)
		{
			if (best_diff == -1 || (current->index - node_b->index) < best_diff)
			{
				best_diff = current->index - node_b->index;
				target = current;
			}
		}
		current = current->next;
	}
	if (!target)
		target = get_min_node(a);
	return (target);
}

void	init_nodes_b(t_data *data)
{
	t_node	*target;

	target = find_target_in_a(data->a, data->b->top);
	data->b->top->target = target;
}

static void	rotate_a_to_target(t_data *data, t_node *target)
{
	int	pos;

	pos = get_node_position(data->a, target);
	if (pos <= data->a->size / 2)
	{
		while (data->a->top != target)
			op_ra(data, 1);
	}
	else
	{
		while (data->a->top != target)
			op_rra(data, 1);
	}
}

void	move_to_a(t_data *data)
{
	rotate_a_to_target(data, data->b->top->target);
	op_pa(data, 1);
}
