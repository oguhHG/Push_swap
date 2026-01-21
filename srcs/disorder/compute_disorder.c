/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_disorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: colassin <colassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 17:10:26 by colassin          #+#    #+#             */
/*   Updated: 2026/01/20 17:10:40 by colassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	count_inversions(t_stack *stack)
{
	t_node	*i;
	t_node	*j;
	int		mistakes;

	mistakes = 0;
	i = stack->top;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->value > j->value)
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	return (mistakes);
}

static int	count_total_pairs(int size)
{
	return ((size * (size - 1)) / 2);
}

double	compute_disorder(t_stack *stack)
{
	int	mistakes;
	int	total_pairs;

	if (!stack || stack->size < 2)
		return (0.0);
	mistakes = count_inversions(stack);
	total_pairs = count_total_pairs(stack->size);
	if (total_pairs == 0)
		return (0.0);
	return ((double)mistakes / (double)total_pairs);
}
