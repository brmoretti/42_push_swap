/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 12:44:20 by brmoretti         #+#    #+#             */
/*   Updated: 2023/12/29 17:11:51 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../../ft_printf/include/ft_printf.h"
# include <limits.h>

enum	e_errors
{
	not_error,
	not_digit,
	integer_overflow,
	malloc_error,
	duplicated_value,
	empty_string
};

enum	e_move_scheme
{
	rr_ra_rb,
	rrr_rra_rrb,
	ra_rrb,
	rra_rb
};

typedef struct s_stacks
{
	t_list		*a;
	t_list		*b;
	t_element	*a_max;
	t_element	*a_min;
	t_element	*b_max;
	t_element	*b_min;
	int			b_sorted;
}	t_stacks;

typedef struct s_el_data
{
	t_element		*el;
	unsigned int	ra;
	unsigned int	rra;
	unsigned int	rb;
	unsigned int	rrb;
	unsigned int	rr;
	unsigned int	rrr;
	unsigned int	ra_net;
	unsigned int	rb_net;
	unsigned int	rra_net;
	unsigned int	rrb_net;
	unsigned int	moves;
	int				move_scheme;
}	t_el_data;

void			sa(t_stacks *stacks);
void			sb(t_stacks *stacks);
void			ss(t_stacks *stacks);
void			pa(t_stacks *stacks);
void			pb(t_stacks *stacks);
void			ra(t_stacks *stacks);
void			rb(t_stacks *stacks);
void			rr(t_stacks *stacks);
void			rra(t_stacks *stacks);
void			rrb(t_stacks *stacks);
void			rrr(t_stacks *stacks);

void			errors(int error_code);
char			**args_validation(int argc, char **argv);
void			find_duplicates(t_stacks *stacks);
void			clear_stacks(t_stacks *stacks, int error);

void			algo(t_stacks *stacks);
void			move_a_to_b(t_stacks *stacks, t_el_data *data);
t_el_data		*n_moves(t_stacks *stacks, t_element *el_a,
					t_el_data *prev_min_moves);
unsigned int	el_top_dist(t_element *top, t_element *el);
void			a_properties(t_stacks *stacks);
void			b_properties(t_stacks *stacks);
void			stack_rule_by_size(t_stacks *stacks);
void			stack_back_to_a(t_stacks *stacks, int nb_to_push);
void			deliver_on_top_a(t_stacks *stacks, t_element *el_to_deliver);
int				el_int(t_element *el);
unsigned int	ft_max(unsigned int a, unsigned int b);
unsigned int	ft_min(unsigned int a, unsigned int b);
char			**clear_tab(char **tab);

//DEBUG TOOLS
void			debug_print_stacks(t_stacks *stacks);
void			debug_print_stats(t_stacks *stacks);

#endif