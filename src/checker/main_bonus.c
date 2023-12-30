/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 10:01:13 by brmoretti         #+#    #+#             */
/*   Updated: 2023/12/29 21:18:58 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	clear_heap(t_stacks *stacks, t_list *instructions, int error)
{
	if (instructions)
		ft_lstclear(instructions, free);
	ft_lstclear(stacks->a, free);
	ft_lstclear(stacks->b, free);
	if (error)
		errors(error);
}

static void	check_if_ok(t_stacks *stacks)
{
	t_element	*el;
	
	if (stacks->b->size != 0)
	{
		ft_putstr_fd("KO\n", 1);
		return ;
	}
	el = stacks->a->first;
	while (el->next)
	{
		if (el_int(el) > el_int(el->next))
		{
			ft_putstr_fd("KO\n", 1);
			return ;
		}
		el = el->next;
	}
	ft_putstr_fd("OK\n", 1);
}

static void	stack_a_fill(char **tab, t_stacks *stacks)
{
	t_element	*el;
	int			*nb;
	int			i;

	i = 0;
	while (tab[i])
	{
		nb = malloc(sizeof(int));
		if (!nb)
			clear_heap(stacks, NULL, malloc_error);
		*nb = ft_atoi(tab[i++]);
		el = ft_lstnewelement((void *)nb);
		if (!el)
			clear_heap(stacks, NULL, malloc_error);
		ft_lstadd_back(stacks->a, el);
	}
	clear_tab(tab);
}

int	main(int argc, char **argv)
{
	char		**tab;
	t_stacks	stacks;
	t_list		*instructions;

	tab = args_validation(argc, argv);
	ft_bzero(&stacks, sizeof(t_stacks));
	stacks.a = ft_calloc(1, sizeof(t_list));
	stacks.b = ft_calloc(1, sizeof(t_list));
	if (!stacks.a || !stacks.b)
		clear_heap(&stacks, NULL, malloc_error);
	stack_a_fill(tab, &stacks);
	find_duplicates(&stacks);
	instructions = get_instructions(&stacks);
	instructions_execution(&stacks, instructions);
	check_if_ok(&stacks);
	clear_heap(&stacks, instructions, not_error);
	return (0);
}