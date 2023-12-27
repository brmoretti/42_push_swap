/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 11:21:22 by brmoretti         #+#    #+#             */
/*   Updated: 2023/12/27 15:39:26 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned int	el_top_dist(t_element *top, t_element *el)
{
	unsigned int	dist;

	dist = 0;
	while (top && top != el)
	{
		dist++;
		top = top->next;
	}
	return (dist);
}

void	b_properties(t_stacks *stacks)
{
	t_element	*el;

	el = stacks->b->first;
	stacks->b_max = el;
	stacks->b_min = el;
	el = el->next;
	while (el)
	{
		if (el_int(el) > el_int(stacks->b_max))
			stacks->b_max = el;
		else if (el_int(el) < el_int(stacks->b_min))
			stacks->b_min = el;
		el = el->next;
	}
}

void	a_properties(t_stacks *stacks)
{
	t_element	*el;

	el = stacks->a->first;
	stacks->a_max = el;
	stacks->a_min = el;
	el = el->next;
	while (el)
	{
		if (el_int(el) > el_int(stacks->a_max))
			stacks->a_max = el;
		else if (el_int(el) < el_int(stacks->a_min))
			stacks->a_min = el;
		el = el->next;
	}
}
