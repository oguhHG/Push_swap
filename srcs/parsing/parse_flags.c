/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrandje <hgrandje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 14:00:00 by hgrandje          #+#    #+#             */
/*   Updated: 2026/01/21 14:00:00 by hgrandje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	is_flag(char *str)
{
	if (str[0] == '-' && str[1] == '-')
		return (1);
	return (0);
}

static int	get_strategy(char *str)
{
	if (ft_strncmp(str, "--simple", 9) == 0)
		return (STRAT_SIMPLE);
	else if (ft_strncmp(str, "--medium", 9) == 0)
		return (STRAT_MEDIUM);
	else if (ft_strncmp(str, "--complex", 10) == 0)
		return (STRAT_COMPLEX);
	else if (ft_strncmp(str, "--adaptive", 11) == 0)
		return (STRAT_ADAPTIVE);
	return (-1);
}

int	parse_flags(int ac, char **av, t_data *data)
{
	int	i;
	int	strat;

	i = 1;
	data->strategy = STRAT_ADAPTIVE;
	data->start_index = 1;
	while (i < ac && is_flag(av[i]))
	{
		strat = get_strategy(av[i]);
		if (strat == -1)
			return (0);
		data->strategy = strat;
		data->start_index = i + 1;
		i++;
	}
	return (1);
}
