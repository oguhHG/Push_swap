/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrandje <hgrandje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 16:40:00 by hgrandje          #+#    #+#             */
/*   Updated: 2026/01/21 16:46:40 by hgrandje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** O(n√n) - Chunk-based Sorting Algorithm
**
** Strategy:
** 1. Assign indices to all elements (0 to n-1)
** 2. Divide elements into √n chunks based on index ranges
** 3. Push elements to B chunk by chunk, rotating to find closest
** 4. Push back to A by always bringing the maximum to top
**
** Time Complexity: O(n√n) operations
** - For each of n elements, we search within a chunk of size √n
*/

static int	get_chunk_count(int size)
{
	if (size <= 100)
		return (5);
	return (11);
}

static int	find_closest_in_chunk(t_data *data, int min_idx, int max_idx)
{
	t_node	*current;
	int		pos;
	int		closest_top;
	int		closest_bottom;

	closest_top = -1;
	closest_bottom = -1;
	pos = 0;
	current = data->a->top;
	while (current)
	{
		if (current->index >= min_idx && current->index <= max_idx)
		{
			if (closest_top == -1)
				closest_top = pos;
			closest_bottom = pos;
		}
		pos++;
		current = current->next;
	}
	if (closest_top == -1)
		return (-1);
	if (closest_top <= data->a->size - closest_bottom - 1)
		return (closest_top);
	return (-(data->a->size - closest_bottom));
}

static void	push_chunk_to_b(t_data *data, int min_idx, int max_idx)
{
	int	pos;
	int	mid_idx;

	mid_idx = (min_idx + max_idx) / 2;
	while (1)
	{
		pos = find_closest_in_chunk(data, min_idx, max_idx);
		if (pos == -1)
			break ;
		if (pos >= 0)
		{
			while (pos-- > 0)
				op_ra(data, 1);
		}
		else
		{
			pos = -pos;
			while (pos-- > 0)
				op_rra(data, 1);
		}
		op_pb(data, 1);
		if (data->b->size > 1 && data->b->top->index < mid_idx)
			op_rb(data, 1);
	}
}

static void	push_back_to_a(t_data *data)
{
	int	max_pos;
	int	size;

	while (data->b->size > 0)
	{
		max_pos = get_max_pos_b(data->b);
		size = data->b->size;
		if (max_pos <= size / 2)
		{
			while (max_pos-- > 0)
				op_rb(data, 1);
		}
		else
		{
			while (max_pos++ < size)
				op_rrb(data, 1);
		}
		op_pa(data, 1);
	}
}

void	algo_medium(t_data *data)
{
	int	chunk_count;
	int	chunk_size;
	int	i;

	if (!data || !data->a || data->a->size <= 1)
		return ;
	if (is_sorted(data->a))
		return ;
	if (data->a->size <= 5)
	{
		algo_simple(data);
		return ;
	}
	assign_index(data->a);
	chunk_count = get_chunk_count(data->a->size);
	chunk_size = (data->a->size + chunk_count - 1) / chunk_count;
	i = 0;
	while (i < chunk_count)
	{
		push_chunk_to_b(data, i * chunk_size,
			((i + 1) * chunk_size) - 1);
		i++;
	}
	push_back_to_a(data);
}
