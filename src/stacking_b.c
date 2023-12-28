/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacking_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 11:09:27 by brmoretti         #+#    #+#             */
/*   Updated: 2023/12/28 10:01:53 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static unsigned int	rb_moves_edge(t_stacks *stacks, int nb_to_push)
{
	t_element		*el;
	unsigned int	pos;

	el = stacks->b->first;
	pos = 0;
	while (el)
	{
		if (nb_to_push > el_int(stacks->b_max)
			&& (el == stacks->b_max))
			break ;
		if (nb_to_push < el_int(stacks->b_min)
			&& (el == stacks->b_min))
		{
			pos++;
			break ;
		}
		pos++;
		el = el->next;
	}
	return (pos);
}

static unsigned int	rb_moves(t_stacks *stacks, int nb_to_push)
{
	t_element		*el;
	t_element		*prev_el;
	unsigned int	pos;

	if (nb_to_push > el_int(stacks->b_max)
		|| nb_to_push < el_int(stacks->b_min))
		return (rb_moves_edge(stacks, nb_to_push));
	el = stacks->b->first;
	pos = 0;
	while (el)
	{
		prev_el = el->prev;
		if (!prev_el)
			prev_el = stacks->b->last;
		if (el == stacks->b_max)
			;
		else if (el_int(prev_el) > nb_to_push && el_int(el) < nb_to_push)
			break ;
		pos++;
		el = el->next;
	}
	return (pos);
}

static void	min_moves(t_el_data *data)
{
	unsigned int	moves;
	unsigned int	_moves;

	moves = data->rr + data->ra_net + data->rb_net;
	data->move_scheme = rr_ra_rb;
	_moves = ft_min(moves, data->rrr + data->rra_net + data->rrb_net);
	if (_moves < moves)
	{
		moves = _moves;
		data->move_scheme = rrr_rra_rrb;
	}
	_moves = ft_min(moves, data->ra + data->rrb);
	if (_moves < moves)
	{
		moves = _moves;
		data->move_scheme = ra_rrb;
	}
	_moves = ft_min(moves, data->rra + data->rb);
	if (_moves < moves)
	{
		moves = _moves;
		data->move_scheme = rra_rb;
	}
	data->moves = moves;
}

t_el_data	*n_moves(t_stacks *stacks, t_element *el_a,
	t_el_data *prev_min_moves)
{
	t_el_data		*data;

	data = ft_calloc(1, sizeof(t_el_data));
	data->el = el_a;
	data->ra = el_top_dist(stacks->a->first, el_a);
	data->rra = stacks->a->size - data->ra;
	data->rb = rb_moves(stacks, el_int(el_a));
	data->rrb = stacks->b->size - data->rb;
	data->rr = ft_min(data->ra, data->rb);
	data->rrr = ft_min(data->rra, data->rrb);
	data->ra_net = data->ra - data->rr;
	data->rb_net = data->rb - data->rr;
	data->rra_net = data->rra - data->rrr;
	data->rrb_net = data->rrb - data->rrr;
	min_moves(data);
	if (!prev_min_moves)
		return (data);
	if (prev_min_moves->moves <= data->moves)
	{
		free(data);
		return (prev_min_moves);
	}
	free(prev_min_moves);
	return (data);
}
