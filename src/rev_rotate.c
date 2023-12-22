/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 22:01:26 by brmoretti         #+#    #+#             */
/*   Updated: 2023/12/21 22:28:27 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate(t_list *stack)
{
	t_element	*tmp;

	if (stack->list_size > 1)
	{
		tmp = stack->last;
		stack->last = ft_lstsecondlast(stack);
		stack->last->next = NULL;
		stack->list_size--;
		ft_lstadd_front(stack, tmp);
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
