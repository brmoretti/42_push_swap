/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 21:29:47 by brmoretti         #+#    #+#             */
/*   Updated: 2023/12/30 15:39:37 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_list *stack)
{
	t_element	*el;

	if (stack->size > 1)
	{
		el = ft_lstpop(stack, 0);
		ft_lstadd_back(stack, el);
	}
}

void	ra(t_stacks *stacks)
{
	rotate(stacks->a);
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_stacks *stacks)
{
	rotate(stacks->b);
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_stacks *stacks)
{
	rotate(stacks->a);
	rotate(stacks->b);
	ft_putstr_fd("rr\n", 1);
}
