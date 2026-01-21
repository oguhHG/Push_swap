/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrandje <hgrandje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 16:40:00 by hgrandje          #+#    #+#             */
/*   Updated: 2026/01/21 16:46:40 by hgrandje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_pos_b(t_stack *stack)
{
	t_node	*current;
	int		max_idx;
	int		max_pos;
	int		pos;

	if (!stack || !stack->top)
		return (0);
	current = stack->top;
	max_idx = current->index;
	max_pos = 0;
	pos = 0;
	while (current)
	{
		if (current->index > max_idx)
		{
			max_idx = current->index;
			max_pos = pos;
		}
		pos++;
		current = current->next;
	}
	return (max_pos);
}
