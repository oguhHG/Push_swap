/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: colassin <colassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 10:19:25 by colassin          #+#    #+#             */
/*   Updated: 2026/01/21 11:00:23 by colassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	parse_string(char *str, t_stack *a)
{
	char	**split;
	int		i;

	split = ft_split(str, ' ');
	if (!split)
		return (0);
	i = 0;
	while (split[i])
	{
		if (!add_number(a, split[i]))
		{
			free_split(split);
			return (0);
		}
		i++;
	}
	free_split(split);
	return (1);
}

static int	parse_numbers(int ac, char **av, t_stack *a, int start)
{
	int	i;

	if (ac - start == 1 && !is_flag(av[start]))
		return (parse_string(av[start], a));
	i = start;
	while (i < ac)
	{
		if (!add_number(a, av[i]))
			return (0);
		i++;
	}
	return (1);
}

int	parse_args(int ac, char **av, t_stack *a, t_data *data)
{
	if (ac < 2)
		return (0);
	if (!parse_flags(ac, av, data))
		return (0);
	if (data->start_index >= ac)
		return (0);
	if (!parse_numbers(ac, av, a, data->start_index))
		return (0);
	if (a->size == 0)
		return (0);
	reverse_stack(a);
	return (1);
}
