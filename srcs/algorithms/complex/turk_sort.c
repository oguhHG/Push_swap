/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrandje <hgrandje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 14:00:00 by hgrandje          #+#    #+#             */
/*   Updated: 2026/01/21 15:55:27 by hgrandje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_all_to_b(t_data *data)
{
	int	pushed;

	pushed = 0;
	while (data->a->size > 3 && pushed < 2)
	{
		op_pb(data, 1);
		pushed++;
	}
	while (data->a->size > 3)
	{
		init_nodes(data);
		move_cheapest_to_b(data);
	}
}

static void	push_all_to_a(t_data *data)
{
	while (data->b->size > 0)
	{
		init_nodes_b(data);
		move_to_a(data);
	}
}

static void	final_rotate(t_data *data)
{
	int	min_pos;

	min_pos = get_min_pos(data->a);
	if (min_pos <= data->a->size / 2)
	{
		while (min_pos-- > 0)
			op_ra(data, 1);
	}
	else
	{
		while (min_pos++ < data->a->size)
			op_rra(data, 1);
	}
}

static void	turk_sort_three(t_data *data)
{
	int	first;
	int	second;
	int	third;

	first = data->a->top->index;
	second = data->a->top->next->index;
	third = data->a->top->next->next->index;
	if (first > second && second < third && first < third)
		op_sa(data, 1);
	else if (first > second && second > third)
	{
		op_sa(data, 1);
		op_rra(data, 1);
	}
	else if (first > second && second < third && first > third)
		op_ra(data, 1);
	else if (first < second && second > third && first < third)
	{
		op_sa(data, 1);
		op_ra(data, 1);
	}
	else if (first < second && second > third && first > third)
		op_rra(data, 1);
}

void	algo_complex(t_data *data)
{
	if (!data || !data->a || data->a->size < 2)
		return ;
	if (is_sorted(data->a))
		return ;
	assign_index(data->a);
	if (data->a->size == 2)
	{
		if (data->a->top->index > data->a->top->next->index)
			op_sa(data, 1);
		return ;
	}
	if (data->a->size == 3)
	{
		turk_sort_three(data);
		return ;
	}
	push_all_to_b(data);
	turk_sort_three(data);
	push_all_to_a(data);
	final_rotate(data);
}
