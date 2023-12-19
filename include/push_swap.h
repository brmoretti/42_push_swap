/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 12:44:20 by brmoretti         #+#    #+#             */
/*   Updated: 2023/12/19 00:27:39 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

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

//DEBUG TOOLS
void	debug_print_stack(t_list *stack);

#endif