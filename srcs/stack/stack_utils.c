/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrandje <hgrandje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 09:25:43 by hgrandje          #+#    #+#             */
/*   Updated: 2026/01/21 10:05:48 by hgrandje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	stack_is_empty(t_stack *stack)
{
	if (!stack)
		return (1);
	return (stack->top == NULL); // int fonction on peut renvoyer null ?
}

// recup de la taille d'une stack
int	stack_size(t_stack *stack)
{
	if (!stack)
		return (0);
	return (stack->size);
}

// recup du min dans une des stack
int	stack_get_min(t_stack *stack)
{
	t_node	*current;
	int		min;

	if (!stack || stack_is_empty(stack))
		return (0);
	current = stack->top;
	min = current->value;
	while (current)
	{
		if (current->value < min)
			min = current->value;
		current = current->next;
	}
	return (min);
}

// Recup du max dans une des stack
int	stack_get_max(t_stack *stack)
{
	t_node	*current;
	int		max;

	if (!stack || stack_is_empty(stack))
		return (0);
	current = stack->top;
	max = current->value;
	while (current)
	{
		if (current->value>  max)
			max = current->value;
		current = current->next;
	}
	return (max);
}

// je sais pas si il faut une autre fonction
// la stack est trier ?
int	stack_is_sorted(t_stack *stack)
{
	t_node	*current;

	if (!stack || stack_is_empty(stack))
		return (1);
	current = stack->top;
	while (current->next)
	{
		if (current->value > current->next->value) // vraiment pas sur de ça
			return (0);
		current = current->next;
	}
	return (1);
}
