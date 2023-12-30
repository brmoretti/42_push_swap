/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 18:06:45 by brmoretti         #+#    #+#             */
/*   Updated: 2023/12/29 21:21:17 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	swap(t_list *stack)
{
	t_element	*el;

	if (stack->size > 1)
	{
		el = ft_lstpop(stack, 1);
		ft_lstadd_front(stack, el);
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
