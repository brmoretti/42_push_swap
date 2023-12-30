/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 21:29:47 by brmoretti         #+#    #+#             */
/*   Updated: 2023/12/29 21:21:47 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	rotate(t_list *stack)
{
	t_element	*el;

	if (stack->size > 1)
	{
		el = ft_lstpop(stack, 0);
		ft_lstadd_back(stack, el);
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
