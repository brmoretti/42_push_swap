/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 23:23:45 by brmoretti         #+#    #+#             */
/*   Updated: 2023/12/26 20:23:55 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	el_int(t_element *el)
{
	return (*(int *)el->content);
}

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

unsigned int	rb_moves(t_stacks *stacks, int nb_to_push)
{
	t_element		*el;
	t_element		*prev_el;
	unsigned int	pos;

	if (nb_to_push > el_int(stacks->b_max)
		|| nb_to_push < el_int(stacks->b_min))
		return (ft_min(el_top_dist(stacks->b->first, stacks->b_max),
			el_top_dist(stacks->b->first, stacks->b_min)));
	el = stacks->b->first;
	pos = 0;
	while (el)
	{
		prev_el = el->prev;
		if (!prev_el)
			prev_el = stacks->b->last;
		if (el_int(prev_el) > nb_to_push && el_int(el) < nb_to_push)
			break ;
		pos++;
		el = el->next;
	}
	return (pos);
}

void	min_moves(t_el_data *data)
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

t_el_data	*n_moves(t_stacks *stacks, t_element *el_a, t_el_data *prev_min_moves)
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

void	move_a_to_b(t_stacks *stacks, t_el_data *data)
{
	if (data->move_scheme == rr_ra_rb)
	{
		while (data->rr--)
			rr(stacks);
		while (data->ra_net--)
			ra(stacks);
		while (data->rb_net--)
			rb(stacks);
	}
	else if (data->move_scheme == rrr_rra_rrb)
	{
		while (data->rrr--)
			rrr(stacks);
		while (data->rra_net--)
			ra(stacks);
		while (data->rrb_net--)
			rb(stacks);
	}
	else if (data->move_scheme == ra_rrb)
	{
		while (data->ra--)
			ra(stacks);
		while (data->rrb--)
			rb(stacks);
	}
	else if (data->move_scheme == rra_rb)
	{
		while (data->rra--)
			ra(stacks);
		while (data->rb--)
			rb(stacks);
	}
	pb(stacks);
	free (data);
}

void	algo(t_stacks *stacks)
{
	t_element		*el;
	t_el_data		*min_moves;
	
	if (stacks->b->size < 2)
	{
		pb(stacks);
		pb(stacks);
	}
	debug_print_stacks(stacks);
	b_properties(stacks);
	el = stacks->a->first;
	min_moves = NULL;
	while (el)
	{
		min_moves = n_moves(stacks, el, min_moves);
		el = el->next;
	}
	ft_printf("chose: %i\n", el_int(min_moves->el));
	move_a_to_b(stacks, min_moves);
}