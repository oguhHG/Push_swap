/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrandje <hgrandje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 12:00:00 by hgrandje          #+#    #+#             */
/*   Updated: 2026/01/21 11:29:22 by hgrandje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	add_number(t_stack *stack, char *str)
{
	int	value;

	if (!is_valid_number(str))
		return (0);
	if (!check_overflow(str))
		return (0);
	value = ft_atoi(str);
	if (has_duplicates(stack, value))
		return (0);
	if (!stack_push(stack, value))
		return (0);
	return (1);
}

static int	*extract_values(t_stack *stack)
{
	int		*arr;
	int		i;
	t_node	*current;

	arr = malloc(sizeof(int) * stack->size);
	if (!arr)
		return (NULL);
	current = stack->top;
	i = 0;
	while (current)
	{
		arr[i++] = current->value;
		current = current->next;
	}
	return (arr);
}

static void	clear_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	while (stack->top)
	{
		current = stack->top;
		next = current->next;
		free(current);
		stack->top = next;
	}
	stack->size = 0;
}

void	reverse_stack(t_stack *stack)
{
	int		*arr;
	int		size;
	int		i;

	if (!stack || stack->size < 2)
		return ;
	size = stack->size;
	arr = extract_values(stack);
	if (!arr)
		return ;
	clear_stack(stack);
	i = 0;
	while (i < size)
		stack_push(stack, arr[i++]);
	free(arr);
}
