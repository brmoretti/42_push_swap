/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 22:01:26 by brmoretti         #+#    #+#             */
/*   Updated: 2023/12/22 16:14:13 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate(t_list *stack)
{
	t_element	*el;

	if (stack->size > 1)
	{
		el = ft_lstpop(stack, -1);
		ft_lstadd_front(stack, el);
	}
}

void	rra(t_stacks *stacks)
{
	rev_rotate(stacks->a);
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stacks *stacks)
{
	rev_rotate(stacks->b);
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stacks *stacks)
{
	rev_rotate(stacks->a);
	rev_rotate(stacks->b);
	ft_putstr_fd("rrr\n", 1);
}
