/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrandje <hgrandje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 15:12:19 by hgrandje          #+#    #+#             */
/*   Updated: 2026/01/21 15:55:27 by hgrandje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_numbers(int argc)
{
	return (argc - 1);
}

static int	*create_array(char **argv, int argc, int *size)
{
	int		*arr;
	int		i;
	long	num;

	*size = count_numbers(argc);
	arr = malloc(sizeof(int) * (*size));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < *size)
	{
		num = ft_atol(argv[i + 1]);
		if (num > INT_MAX || num < INT_MIN)
		{
			free(arr);
			return (NULL);
		}
		arr[i] = (int)num;
		i++;
	}
	return (arr);
}

static int	fill_stack(t_data *data, int *arr, int size)
{
	int		i;
	t_node	*node;

	i = size - 1;
	while (i >= 0)
	{
		node = node_new(arr[i]);
		if (!node)
			return (0);
		stack_push(data->a, node);
		i--;
	}
	return (1);
}

int	parse_args(t_data *data, int argc, char **argv)
{
	int	*arr;
	int	size;

	if (!validate_input(argv, argc))
		return (0);
	arr = create_array(argv, argc, &size);
	if (!arr)
		return (0);
	if (has_duplicates(arr, size))
	{
		free(arr);
		return (0);
	}
	data->a = stack_init();
	data->b = stack_init();
	if (!data->a || !data->b)
	{
		free(arr);
		return (0);
	}
	if (!fill_stack(data, arr, size))
	{
		free(arr);
		return (0);
	}
	free(arr);
	index_stack(data->a);
	return (1);
}