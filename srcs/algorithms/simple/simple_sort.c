/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrandje <hgrandje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 11:40:04 by colassin          #+#    #+#             */
/*   Updated: 2026/01/21 16:46:40 by hgrandje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** O(n²) - Selection Sort Algorithm
** Also handles small stacks (2-5 elements) optimally
*/

static void	simple_sort_two(t_data *data)
{
	if (data->a->top->index > data->a->top->next->index)
		op_sa(data, 1);
}

static void	simple_sort_three(t_data *data)
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

static void	simple_sort_large(t_data *data)
{
	while (data->a->size > 3)
		push_min_to_b(data);
	simple_sort_three(data);
	push_all_back(data);
}

void	algo_simple(t_data *data)
{
	if (!data || !data->a || data->a->size < 2)
		return ;
	if (is_sorted(data->a))
		return ;
	assign_index(data->a);
	if (data->a->size == 2)
		simple_sort_two(data);
	else if (data->a->size == 3)
		simple_sort_three(data);
	else
		simple_sort_large(data);
}
