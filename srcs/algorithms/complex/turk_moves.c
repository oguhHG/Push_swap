/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrandje <hgrandje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 14:00:00 by hgrandje          #+#    #+#             */
/*   Updated: 2026/01/21 15:55:27 by hgrandje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_both_up(t_data *data, t_node *cheapest)
{
	while (data->a->top != cheapest && data->b->top != cheapest->target)
		op_rr(data, 1);
	while (data->a->top != cheapest)
		op_ra(data, 1);
	while (data->b->top != cheapest->target)
		op_rb(data, 1);
}

static void	rotate_both_down(t_data *data, t_node *cheapest)
{
	while (data->a->top != cheapest && data->b->top != cheapest->target)
		op_rrr(data, 1);
	while (data->a->top != cheapest)
		op_rra(data, 1);
	while (data->b->top != cheapest->target)
		op_rrb(data, 1);
}

static void	rotate_opposite(t_data *data, t_node *cheapest)
{
	if (cheapest->above_median_a)
	{
		while (data->a->top != cheapest)
			op_ra(data, 1);
		while (data->b->top != cheapest->target)
			op_rrb(data, 1);
	}
	else
	{
		while (data->a->top != cheapest)
			op_rra(data, 1);
		while (data->b->top != cheapest->target)
			op_rb(data, 1);
	}
}

void	move_cheapest_to_b(t_data *data)
{
	t_node	*cheapest;

	cheapest = get_cheapest(data->a);
	if (cheapest->above_median_a && cheapest->above_median_b)
		rotate_both_up(data, cheapest);
	else if (!cheapest->above_median_a && !cheapest->above_median_b)
		rotate_both_down(data, cheapest);
	else
		rotate_opposite(data, cheapest);
	op_pb(data, 1);
}
