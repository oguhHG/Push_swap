/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrandje <hgrandje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 15:13:00 by hgrandje          #+#    #+#             */
/*   Updated: 2026/01/21 15:13:15 by hgrandje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_strategy_flag(char *str)
{
	if (!str)
		return (0);
	if (ft_strncmp(str, "--simple", 9) == 0)
		return (1);
	if (ft_strncmp(str, "--medium", 9) == 0)
		return (1);
	if (ft_strncmp(str, "--complex", 10) == 0)
		return (1);
	if (ft_strncmp(str, "--adaptive", 11) == 0)
		return (1);
	if (ft_strncmp(str, "--bench", 8) == 0)
		return (1);
	return (0);
}

static void	set_strategy(t_data *data, char *flag)
{
	if (ft_strncmp(flag, "--simple", 9) == 0)
		data->strategy = STRATEGY_SIMPLE;
	else if (ft_strncmp(flag, "--medium", 9) == 0)
		data->strategy = STRATEGY_MEDIUM;
	else if (ft_strncmp(flag, "--complex", 10) == 0)
		data->strategy = STRATEGY_COMPLEX;
	else if (ft_strncmp(flag, "--adaptive", 11) == 0)
		data->strategy = STRATEGY_ADAPTIVE;
	else if (ft_strncmp(flag, "--bench", 8) == 0)
		data->bench_mode = 1;
}

int	parse_flags(t_data *data, int *argc, char ***argv)
{
	int	i;
	int	flags_count;

	flags_count = 0;
	i = 1;
	while (i < *argc && is_strategy_flag((*argv)[i]))
	{
		set_strategy(data, (*argv)[i]);
		flags_count++;
		i++;
	}
	*argc -= flags_count;
	*argv += flags_count;
	return (1);
}