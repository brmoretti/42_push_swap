/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 10:01:35 by brmoretti         #+#    #+#             */
/*   Updated: 2023/12/29 21:10:58 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "../../ft_printf/include/ft_printf.h"
# include <limits.h>

enum	e_errors
{
	not_error,
	not_digit,
	integer_overflow,
	malloc_error,
	duplicated_value,
	empty_string,
	invalid_instruction,
	empty_stack,
	less_than_two_elements
};

enum	e_instruction
{
	not_instruction,
	i_sa,
	i_sb,
	i_ss,
	i_pa,
	i_pb,
	i_ra,
	i_rb,
	i_rr,
	i_rra,
	i_rrb,
	i_rrr
};

typedef struct s_stacks
{
	t_list		*a;
	t_list		*b;
}	t_stacks;

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

char	**args_validation(int argc, char **argv);
void	find_duplicates(t_stacks *stacks);
void	errors(int error_code);
char	**clear_tab(char **tab);
void	clear_heap(t_stacks *stacks, t_list *instructions, int error);
t_list	*get_instructions(t_stacks *stacks);
void	instructions_execution(t_stacks *stacks, t_list *instructions);
int		el_int(t_element *el);

#endif