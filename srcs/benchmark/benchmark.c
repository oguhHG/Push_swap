/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrandje <hgrandje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 15:23:20 by hgrandje          #+#    #+#             */
/*   Updated: 2026/01/21 15:23:27 by hgrandje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bench_init(t_bench *bench)
{
	bench->sa = 0;
	bench->sb = 0;
	bench->ss = 0;
	bench->pa = 0;
	bench->pb = 0;
	bench->ra = 0;
	bench->rb = 0;
	bench->rr = 0;
	bench->rra = 0;
	bench->rrb = 0;
	bench->rrr = 0;
	bench->total = 0;
}

char	*get_strategy_name(t_strategy strategy)
{
	if (strategy == STRATEGY_SIMPLE)
		return ("Simple");
	if (strategy == STRATEGY_MEDIUM)
		return ("Medium");
	if (strategy == STRATEGY_COMPLEX)
		return ("Complex");
	return ("Adaptive");
}

char	*get_strategy_complexity(t_strategy strategy)
{
	if (strategy == STRATEGY_SIMPLE)
		return ("O(n^2)");
	if (strategy == STRATEGY_MEDIUM)
		return ("O(n*sqrt(n))");
	if (strategy == STRATEGY_COMPLEX)
		return ("O(n*log(n))");
	return ("O(n*sqrt(n))");
}

static void	print_disorder(double disorder)
{
	int	integer_part;
	int	decimal_part;

	integer_part = (int)(disorder * 100);
	decimal_part = (int)((disorder * 10000)) % 100;
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_putnbr_fd(integer_part, 2);
	ft_putchar_fd('.', 2);
	if (decimal_part < 10)
		ft_putchar_fd('0', 2);
	ft_putnbr_fd(decimal_part, 2);
	ft_putstr_fd("%\n", 2);
}

static void	print_ops_detail(t_data *data)
{
	ft_putstr_fd("[bench] sa: ", 2);
	ft_putnbr_fd(data->bench.sa, 2);
	ft_putstr_fd("  sb: ", 2);
	ft_putnbr_fd(data->bench.sb, 2);
	ft_putstr_fd("  ss: ", 2);
	ft_putnbr_fd(data->bench.ss, 2);
	ft_putstr_fd("  pa: ", 2);
	ft_putnbr_fd(data->bench.pa, 2);
	ft_putstr_fd("  pb: ", 2);
	ft_putnbr_fd(data->bench.pb, 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("[bench] ra: ", 2);
	ft_putnbr_fd(data->bench.ra, 2);
	ft_putstr_fd("  rb: ", 2);
	ft_putnbr_fd(data->bench.rb, 2);
	ft_putstr_fd("  rr: ", 2);
	ft_putnbr_fd(data->bench.rr, 2);
	ft_putstr_fd("  rra: ", 2);
	ft_putnbr_fd(data->bench.rra, 2);
	ft_putstr_fd("  rrb: ", 2);
	ft_putnbr_fd(data->bench.rrb, 2);
	ft_putstr_fd("  rrr: ", 2);
	ft_putnbr_fd(data->bench.rrr, 2);
	ft_putstr_fd("\n", 2);
}

void	print_benchmark(t_data *data)
{
	print_disorder(data->disorder);
	ft_putstr_fd("[bench] strategy: ", 2);
	ft_putstr_fd(get_strategy_name(data->strategy), 2);
	ft_putstr_fd(" / ", 2);
	ft_putstr_fd(get_strategy_complexity(data->strategy), 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(data->bench.total, 2);
	ft_putstr_fd("\n", 2);
	print_ops_detail(data);
}