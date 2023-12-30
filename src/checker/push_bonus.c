/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 18:41:24 by brmoretti         #+#    #+#             */
/*   Updated: 2023/12/29 21:22:11 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
}

void	pb(t_stacks *stacks)
{
	push(stacks->a, stacks->b);
}
