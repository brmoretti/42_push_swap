/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 23:23:45 by brmoretti         #+#    #+#             */
/*   Updated: 2023/12/30 12:32:42 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_if_ok(t_stacks *stacks)
{
	t_element	*el;

	if (stacks->b->size != 0)
		return (0);
	el = stacks->a->first;
	while (el->next)
	{
		if (el_int(el) > el_int(el->next))
			return (0);
		el = el->next;
	}
	return (1);
}

static void	algo_phase_one(t_stacks *stacks)
{
	t_element		*el;
	t_el_data		*min_moves;

	el = stacks->a->first;
	min_moves = NULL;
	while (el)
	{
		min_moves = n_moves(stacks, el, min_moves);
		if (min_moves->moves <= 1)
			break ;
		el = el->next;
	}
	move_a_to_b(stacks, min_moves);
}

static void	algo_phase_two(t_stacks *stacks)
{
	while (stacks->b->size > 0)
		stack_back_to_a(stacks, el_int(stacks->b->first));
	deliver_on_top_a(stacks, stacks->a_min);
}

void	algo(t_stacks *stacks)
{
	if (check_if_ok(stacks))
		return ;
	stack_rule_by_size(stacks);
	if (check_if_ok(stacks))
		return ;
	if (!stacks->b_sorted)
		algo_phase_one(stacks);
	else
	{
		a_properties(stacks);
		algo_phase_two(stacks);
	}
	algo(stacks);
}
