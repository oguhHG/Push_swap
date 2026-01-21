/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrandje <hgrandje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 10:14:07 by colassin          #+#    #+#             */
/*   Updated: 2026/01/21 11:33:07 by colassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	execute_sort(t_stack *a, t_stack *b, int strategy)
{
	if (strategy == STRAT_SIMPLE)
		simple_sort(a, b);
	else if (strategy == STRAT_MEDIUM)
		simple_sort(a, b);
	else if (strategy == STRAT_COMPLEX)
		simple_sort(a, b);
	else
		simple_sort(a, b);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	t_data	data;

	if (ac < 2)
		return (0);
	a = stack_init();
	b = stack_init();
	if (!a || !b)
		error_free_exit(a, b);
	if (!parse_args(ac, av, a, &data))
		error_free_exit(a, b);
	if (!stack_is_sorted(a))
		execute_sort(a, b, data.strategy);
	free_both_stacks(a, b);
	return (0);
}
