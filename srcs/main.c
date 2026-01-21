/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrandje <hgrandje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 15:33:16 by hgrandje          #+#    #+#             */
/*   Updated: 2026/01/21 15:33:18 by hgrandje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_data(t_data *data)
{
	data->a = NULL;
	data->b = NULL;
	data->strategy = STRATEGY_ADAPTIVE;
	data->bench_mode = 0;
	data->disorder = 0.0;
	bench_init(&data->bench);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2)
		return (0);
	init_data(&data);
	if (!parse_flags(&data, &argc, &argv))
		error_exit(&data);
	if (argc < 2)
		return (0);
	if (!parse_args(&data, argc, argv))
		error_exit(&data);
	data.disorder = compute_disorder(data.a);
	if (!is_sorted(data.a))
		sort_stack(&data);
	if (data.bench_mode)
		print_benchmark(&data);
	data_free(&data);
	return (0);
}