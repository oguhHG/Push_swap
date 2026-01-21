/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_disorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrandje <hgrandje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 15:22:44 by hgrandje          #+#    #+#             */
/*   Updated: 2026/01/21 15:22:51 by hgrandje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Computes the disorder metric as defined in the subject:
** disorder = mistakes / total_pairs
** where mistakes is the count of pairs (i,j) with i < j but a[i] > a[j]
** (inversions count)
**
** disorder = 0 means fully sorted
** disorder = 1 means reverse sorted (maximum disorder)
*/

double	compute_disorder(t_stack *stack)
{
	t_node	*i_node;
	t_node	*j_node;
	long	mistakes;
	long	total_pairs;

	if (!stack || stack->size < 2)
		return (0.0);
	mistakes = 0;
	total_pairs = 0;
	i_node = stack->top;
	while (i_node && i_node->next)
	{
		j_node = i_node->next;
		while (j_node)
		{
			total_pairs++;
			if (i_node->value > j_node->value)
				mistakes++;
			j_node = j_node->next;
		}
		i_node = i_node->next;
	}
	if (total_pairs == 0)
		return (0.0);
	return ((double)mistakes / (double)total_pairs);
}