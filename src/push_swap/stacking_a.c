/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacking_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 17:38:09 by brmoretti         #+#    #+#             */
/*   Updated: 2023/12/28 20:59:07 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	deliver_on_top_a(t_stacks *stacks, t_element *el_to_deliver)
{
	unsigned int	top_dist;
	unsigned int	botton_dist;

	top_dist = el_top_dist(stacks->a->first, el_to_deliver);
	botton_dist = stacks->a->size - top_dist;
	if (top_dist <= botton_dist)
		while (top_dist--)
			ra(stacks);
	else
		while (botton_dist--)
			rra(stacks);
}

static void	find_and_deliver(t_stacks *stacks, int nb_to_push)
{
	t_element	*el;
	t_element	*next_el;

	el = stacks->a->first;
	next_el = el->next;
	while (el)
	{
		next_el = el->next;
		if (!next_el)
			next_el = stacks->a->first;
		if (el_int(el) < nb_to_push && el_int(next_el) > nb_to_push)
			break ;
		el = el->next;
	}
	deliver_on_top_a(stacks, next_el);
}

void	stack_back_to_a(t_stacks *stacks, int nb_to_push)
{
	if (nb_to_push > el_int(stacks->a_max))
	{
		deliver_on_top_a(stacks, stacks->a_min);
		stacks->a_max = stacks->b->first;
	}
	else if (nb_to_push < el_int(stacks->a_min))
	{
		deliver_on_top_a(stacks, stacks->a_min);
		stacks->a_min = stacks->b->first;
	}
	else
		find_and_deliver(stacks, nb_to_push);
	pa(stacks);
}