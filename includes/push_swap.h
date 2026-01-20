/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: colassin <colassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 16:52:40 by hgrandje          #+#    #+#             */
/*   Updated: 2026/01/20 17:05:44 by colassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* # include "libft/libft.h" */
# include <stdarg.h>
# include <unistd.h>

typedef struct s_stack
{
	int *array;   // Les valeurs
	int size;     // Taille actuelle
	int capacity; // Capacité max
}			t_stack;

typedef struct s_data
{
	t_stack	*a;
	t_stack	*b;
	int total_ops;   // Compteur d'opérations
	double disorder; // Métrique de désordre
	char *strategy;  // Nom de la stratégie utilisée
	int bench_mode;  // Flag pour --bench
}			t_data;

typedef struct s_flags
{
}			t_flags;

int			ft_printf(const char *format, ...);

#endif