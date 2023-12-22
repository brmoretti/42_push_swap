/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 18:41:24 by brmoretti         #+#    #+#             */
/*   Updated: 2023/12/21 22:27:44 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_list *from, t_list *to)
{
	t_element	*el_from;

	if (from->list_size >= 1)
	{
		from->list_size--;
		el_from = from->first;
		from->first = el_from->next;
		if (from->last == el_from)
			from->last = NULL;
		ft_lstadd_front(to, el_from);
	}
}

void	pa(t_stacks *stacks)
{
	push(stacks->b, stacks->a);
}

void	pb(t_stacks *stacks)
{
	push(stacks->a, stacks->b);
}
