/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrandje <hgrandje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 09:09:47 by hgrandje          #+#    #+#             */
/*   Updated: 2026/01/21 09:53:59 by hgrandje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// Libère un nœud
void	node_free(t_node *node)
{
	if (node)
		free(node);
}

// Libère une stack et tous les nœuds en meme temps
void	stack_free(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	if (!stack)
		return ;
	current = stack->top;
	while (current)
	{
		next = current->next;
		node_free(current);
		current = next;
	}
	free(stack);
}

// Libère les deux stacks (fin de programme/cas d'erreur??)
void	free_both_stacks(t_stack *a, t_stack *b)
{
	if (a)
		stack_free(a);
	if (b)
		stack_free(b);
}
