/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 21:29:47 by brmoretti         #+#    #+#             */
/*   Updated: 2023/12/21 22:28:12 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_list *stack)
{
	t_element	*tmp;

	if (stack->list_size > 1)
	{
		tmp = stack->first;
		stack->first = tmp->next;
		stack->list_size--;
		ft_lstadd_back(stack, tmp);
	}
}

void	ra(t_stacks *stacks)
{
	rotate(stacks->a);
}

void	rb(t_stacks *stacks)
{
	rotate(stacks->b);
}

void	rr(t_stacks *stacks)
{
	rotate(stacks->a);
	rotate(stacks->b);
}
