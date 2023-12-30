/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rule_by_size.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 12:06:10 by brmoretti         #+#    #+#             */
/*   Updated: 2023/12/30 12:34:04 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stack_of_two(t_stacks *stacks)
{
	if (el_int(stacks->a->first) > el_int(stacks->a->last))
		sa(stacks);
}

static void	stack_of_three(t_stacks *stacks)
{
	int	first;
	int	second;
	int	third;

	first = el_int(stacks->a->first);
	second = el_int(stacks->a->first->next);
	third = el_int(stacks->a->last);
	if (first < second && second < third)
		;
	else if (first < third && second > third)
	{
		rra(stacks);
		sa(stacks);
	}
	else if (first < third && second < first)
		sa(stacks);
	else if (first < second && third < first)
		rra(stacks);
	else if (first > third && second < third)
		ra(stacks);
	else if (first > second && second > third)
	{
		sa(stacks);
		rra(stacks);
	}
}

void	stack_rule_by_size(t_stacks *stacks)
{
	if (stacks->a->size == 1)
		return ;
	if (stacks->a->size == 2)
	{
		stack_of_two(stacks);
		stacks->b_sorted = 1;
	}
	else if (stacks->a->size == 3)
	{
		stack_of_three(stacks);
		stacks->b_sorted = 1;
	}
	if (!stacks->b_sorted)
	{
		while (stacks->a->size > 3 && stacks->b->size < 2)
			pb(stacks);
		b_properties(stacks);
		if (stacks->a->size == 3)
			stack_rule_by_size(stacks);
	}
}
