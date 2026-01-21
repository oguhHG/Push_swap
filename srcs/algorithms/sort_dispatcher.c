/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_dispatcher.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrandje <hgrandje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 16:30:00 by hgrandje          #+#    #+#             */
/*   Updated: 2026/01/21 16:46:40 by hgrandje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Sort dispatcher - Routes to the appropriate algorithm
**
** --simple:  O(n²) selection sort (also handles small stacks)
** --medium:  O(n√n) chunk-based sort
** --complex: O(n log n) Turk algorithm (default for large stacks)
**
** Size <= 5: Uses algo_simple (optimized for tiny stacks)
*/

void	sort_stack(t_data *data)
{
	if (!data || !data->a || data->a->size <= 1)
		return ;
	if (is_sorted(data->a))
		return ;
	if (data->a->size <= 5)
	{
		algo_simple(data);
		return ;
	}
	if (data->strategy == STRATEGY_SIMPLE)
		algo_simple(data);
	else if (data->strategy == STRATEGY_MEDIUM)
		algo_medium(data);
	else
		algo_complex(data);
}
