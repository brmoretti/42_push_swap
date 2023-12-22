/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 18:06:45 by brmoretti         #+#    #+#             */
/*   Updated: 2023/12/21 22:27:24 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_list *stack)
{
	t_element	*el_first;
	t_element	*el_second;

	if (stack->list_size >= 2)
	{
		el_first = stack->first;
		el_second = el_first->next;
		el_first->next = el_second->next;
		el_second->next = el_first;
		stack->first = el_second;
		if (stack->last == el_second)
			stack->last = el_first;
	}
}

void	sa(t_stacks *stacks)
{
	swap(stacks->a);
}

void	sb(t_stacks *stacks)
{
	swap(stacks->b);
}

void	ss(t_stacks *stacks)
{
	swap(stacks->a);
	swap(stacks->b);
}
