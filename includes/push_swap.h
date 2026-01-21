/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrandje <hgrandje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 15:02:12 by hgrandje          #+#    #+#             */
/*   Updated: 2026/01/21 16:46:40 by hgrandje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

/*
** ============================================================================
** STRUCTURES
** ============================================================================
*/

typedef struct s_node
{
	int				value;
	int				index;
	int				cost;
	int				above_median_a;
	int				above_median_b;
	struct s_node	*target;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		size;
}	t_stack;

typedef enum e_strategy
{
	STRATEGY_ADAPTIVE,
	STRATEGY_SIMPLE,
	STRATEGY_MEDIUM,
	STRATEGY_COMPLEX
}	t_strategy;

typedef struct s_bench
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	total;
}	t_bench;

typedef struct s_data
{
	t_stack		*a;
	t_stack		*b;
	t_strategy	strategy;
	int			bench_mode;
	t_bench		bench;
	double		disorder;
}	t_data;

/*
** ============================================================================
** PARSING
** ============================================================================
*/

int			parse_args(t_data *data, int argc, char **argv);
int			parse_flags(t_data *data, int *argc, char ***argv);
int			validate_input(char **argv, int argc);
int			is_valid_number(char *str);
int			has_duplicates(int *arr, int size);
long		ft_atol(const char *str);

/*
** ============================================================================
** STACK OPERATIONS
** ============================================================================
*/

t_stack		*stack_init(void);
t_node		*node_new(int value);
void		stack_push(t_stack *stack, t_node *node);
t_node		*stack_pop(t_stack *stack);
void		stack_free(t_stack *stack);
void		data_free(t_data *data);
int			stack_is_empty(t_stack *stack);
t_node		*stack_peek(t_stack *stack);

/*
** ============================================================================
** PUSH_SWAP OPERATIONS
** ============================================================================
*/

void		op_sa(t_data *data, int print);
void		op_sb(t_data *data, int print);
void		op_ss(t_data *data, int print);
void		op_pa(t_data *data, int print);
void		op_pb(t_data *data, int print);
void		op_ra(t_data *data, int print);
void		op_rb(t_data *data, int print);
void		op_rr(t_data *data, int print);
void		op_rra(t_data *data, int print);
void		op_rrb(t_data *data, int print);
void		op_rrr(t_data *data, int print);

/*
** ============================================================================
** SORTING ALGORITHMS
** ============================================================================
*/

void		sort_stack(t_data *data);
void		algo_simple(t_data *data);
void		algo_medium(t_data *data);
void		algo_complex(t_data *data);

/*
** ============================================================================
** SIMPLE SORT UTILS
** ============================================================================
*/

int			get_min_pos(t_stack *stack);
void		push_min_to_b(t_data *data);
void		push_all_back(t_data *data);
void		rotate_min_to_top(t_data *data);
int			stack_is_sorted(t_stack *stack);

/*
** ============================================================================
** MEDIUM SORT UTILS
** ============================================================================
*/

int			get_max_pos_b(t_stack *stack);

/*
** ============================================================================
** TURK SORT UTILS
** ============================================================================
*/

void		assign_index(t_stack *stack);
int			get_node_position(t_stack *stack, t_node *node);
t_node		*get_max_node(t_stack *stack);
t_node		*get_min_node(t_stack *stack);
void		init_nodes(t_data *data);
void		init_nodes_b(t_data *data);
t_node		*get_cheapest(t_stack *a);
void		move_cheapest_to_b(t_data *data);
void		move_to_a(t_data *data);

/*
** ============================================================================
** DISORDER CALCULATION
** ============================================================================
*/

double		compute_disorder(t_stack *stack);

/*
** ============================================================================
** UTILS
** ============================================================================
*/

int			is_sorted(t_stack *stack);
int			get_min(t_stack *stack);
int			get_max(t_stack *stack);
int			get_min_index(t_stack *stack);
int			get_position(t_stack *stack, int index);
void		index_stack(t_stack *stack);
void		error_exit(t_data *data);

/*
** ============================================================================
** BENCHMARK
** ============================================================================
*/

void		print_benchmark(t_data *data);
void		bench_init(t_bench *bench);
char		*get_strategy_name(t_strategy strategy);
char		*get_strategy_complexity(t_strategy strategy);

#endif