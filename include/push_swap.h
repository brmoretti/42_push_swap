/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 12:44:20 by brmoretti         #+#    #+#             */
/*   Updated: 2023/12/21 22:28:59 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/include/ft_printf.h"

enum	e_errors
{
	not_error,
	insufficient_args,
	not_digit,
	malloc_error
};

typedef struct s_stacks
{
	t_list	*a;
	t_list	*b;
}	t_stacks;

void	errors(int error_code);
void	sa(t_stacks *stacks);
void	sb(t_stacks *stacks);
void	ss(t_stacks *stacks);
void	pa(t_stacks *stacks);
void	pb(t_stacks *stacks);
void	ra(t_stacks *stacks);
void	rb(t_stacks *stacks);
void	rr(t_stacks *stacks);
void	rra(t_stacks *stacks);
void	rrb(t_stacks *stacks);
void	rrr(t_stacks *stacks);

//DEBUG TOOLS
void	debug_print_stacks(t_stacks *stacks);
void	debug_print_stats(t_stacks *stacks);

#endif