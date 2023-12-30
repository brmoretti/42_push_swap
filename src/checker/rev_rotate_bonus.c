/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 22:01:26 by brmoretti         #+#    #+#             */
/*   Updated: 2023/12/29 21:21:56 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
}

void	rrb(t_stacks *stacks)
{
	rev_rotate(stacks->b);
}

void	rrr(t_stacks *stacks)
{
	rev_rotate(stacks->a);
	rev_rotate(stacks->b);
}
