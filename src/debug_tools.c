/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 23:58:27 by brmoretti         #+#    #+#             */
/*   Updated: 2023/12/21 22:31:30 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	greater_stack(t_stacks *stacks)
{
	if (stacks->a->list_size > stacks->b->list_size)
		return (stacks->a->list_size);
	else
		return (stacks->b->list_size);
}

static void	debug_print_stacks_helper(t_stacks *stacks,
		t_element *el_a, t_element *el_b)
{
	int		i;

	i = greater_stack(stacks);
	while (i--)
	{
		if (i < (int)stacks->a->list_size && i < (int)stacks->b->list_size)
		{
			ft_printf("%4d | %-4d\n", *(int *)el_a->content,
				*(int *)el_b->content);
			el_a = el_a->next;
			el_b = el_b->next;
		}
		else if (i < (int)stacks->a->list_size)
		{
			ft_printf("%4d |\n", *(int *)el_a->content);
			el_a = el_a->next;
		}
		else if (i < (int)stacks->b->list_size)
		{
			ft_printf("     | %-4d\n", *(int *)el_b->content);
			el_b = el_b->next;
		}
	}
}

void	debug_print_stacks(t_stacks *stacks)
{
	t_element	*el_a;
	t_element	*el_b;

	el_a = stacks->a->first;
	el_b = stacks->b->first;
	debug_print_stacks_helper(stacks, el_a, el_b);
	ft_printf("   a | b   \n\n");
}

void	debug_print_stats(t_stacks *stacks)
{
	int	first;
	int	last;
	int	n_elements;

	first = *(int *)stacks->a->first->content;
	last = *(int *)stacks->a->last->content;
	n_elements = (int)stacks->a->list_size;
	ft_printf("Stack a:\n");
	ft_printf("First: %-5dLast: %-5dN_Elements: %-5d\n\n",
		first, last, n_elements);
	first = *(int *)stacks->b->first->content;
	last = *(int *)stacks->b->last->content;
	n_elements = (int)stacks->b->list_size;
	ft_printf("Stack b:\n");
	ft_printf("First: %-5dLast: %-5dN_Elements: %-5d\n\n",
		first, last, n_elements);
}