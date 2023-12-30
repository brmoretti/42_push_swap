/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 18:06:45 by brmoretti         #+#    #+#             */
/*   Updated: 2023/12/29 21:20:48 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_stacks *stacks)
{
	swap(stacks->b);
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_stacks *stacks)
{
	swap(stacks->a);
	swap(stacks->b);
	ft_putstr_fd("ss\n", 1);
}
