/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 18:41:24 by brmoretti         #+#    #+#             */
/*   Updated: 2023/12/22 16:10:24 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_list *from, t_list *to)
{
	t_element	*el_from;

	if (from->size >= 1)
	{
		el_from = ft_lstpop(from, 0);
		ft_lstadd_front(to, el_from);
	}
}

void	pa(t_stacks *stacks)
{
	push(stacks->b, stacks->a);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_stacks *stacks)
{
	push(stacks->a, stacks->b);
	ft_putstr_fd("pb\n", 1);
}
