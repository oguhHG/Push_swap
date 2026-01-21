/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: colassin <colassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 10:37:55 by colassin          #+#    #+#             */
/*   Updated: 2026/01/21 10:39:54 by colassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	print_error(void)
{
	write(2, "Error\n", 6);
}

void	error_exit(void)
{
	print_error();
	exit(1);
}

void	error_free_exit(t_stack *a, t_stack *b)
{
	free_both_stacks(a, b);
	error_exit();
}
