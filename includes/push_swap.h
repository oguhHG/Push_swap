/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: colassin <colassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 16:52:40 by hgrandje          #+#    #+#             */
/*   Updated: 2026/01/21 11:10:38 by colassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

// Strategies de tri
# define STRAT_ADAPTIVE	0
# define STRAT_SIMPLE	1
# define STRAT_MEDIUM	2
# define STRAT_COMPLEX	3

// Structure pour les noeuds
typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	int				size;
	t_node			*top;
}					t_stack;

typedef struct s_data
{
	t_stack			*a;
	t_stack			*b;
	int				strategy;
	int				start_index;
}					t_data;

// stack_init.c
t_stack				*stack_init(void);
t_node				*node_create(int value);
int					stack_push(t_stack *stack, int value);

// stack_free.c
void				stack_free(t_stack *stack);
void				node_free(t_node *node);
void				free_both_stacks(t_stack *a, t_stack *b);

// stack_utils.c
int					stack_is_empty(t_stack *stack);
int					stack_size(t_stack *stack);
int					stack_get_min(t_stack *stack);
int					stack_get_max(t_stack *stack);
int					stack_is_sorted(t_stack *stack);

// error_handler.c
void				print_error(void);
void				error_exit(void);
void				error_free_exit(t_stack *a, t_stack *b);

// validate_input.c
int					is_valid_number(char *str);
int					check_overflow(char *str);
int					has_duplicates(t_stack *stack, int value);

// parse_utils.c
void				free_split(char **split);
int					add_number(t_stack *stack, char *str);
void				reverse_stack(t_stack *stack);

// parse_flags.c
int					is_flag(char *str);
int					parse_flags(int ac, char **av, t_data *data);

// parse_args.c
int					parse_args(int ac, char **av, t_stack *a, t_data *data);

// swap.c
void				sa(t_stack *a);
void				sb(t_stack *b);
void				ss(t_stack *a, t_stack *b);

// push.c
void				pa(t_stack *a, t_stack *b);
void				pb(t_stack *a, t_stack *b);

// rotate.c
void				ra(t_stack *a);
void				rb(t_stack *b);
void				rr(t_stack *a, t_stack *b);

// reverse_rotate.c
void				rra(t_stack *a);
void				rrb(t_stack *b);
void				rrr(t_stack *a, t_stack *b);

// compute_disorder.c
double				compute_disorder(t_stack *stack);

// simple_sort_utils.c
int					get_min_pos(t_stack *stack);
void				push_min_to_b(t_stack *a, t_stack *b);
void				push_all_back(t_stack *a, t_stack *b);
void				rotate_min_to_top(t_stack *a);

// simple_sort.c
void				simple_sort(t_stack *a, t_stack *b);

#endif