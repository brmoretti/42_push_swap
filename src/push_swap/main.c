/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 12:29:41 by brmoretti         #+#    #+#             */
/*   Updated: 2023/12/30 11:25:33 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clear_stacks(t_stacks *stacks, int error)
{
	ft_lstclear(stacks->a, free);
	ft_lstclear(stacks->b, free);
	if (error)
		errors(error);
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
			clear_stacks(stacks, malloc_error);
		*nb = ft_atoi(tab[i++]);
		el = ft_lstnewelement((void *)nb);
		if (!el)
			clear_stacks(stacks, malloc_error);
		ft_lstadd_back(stacks->a, el);
	}
	clear_tab(tab);
}

int	main(int argc, char **argv)
{
	char		**tab;
	t_stacks	stacks;

	tab = args_validation(argc, argv);
	ft_bzero(&stacks, sizeof(t_stacks));
	stacks.a = ft_calloc(1, sizeof(t_list));
	stacks.b = ft_calloc(1, sizeof(t_list));
	if (!stacks.a || !stacks.b)
		clear_stacks(&stacks, malloc_error);
	stack_a_fill(tab, &stacks);
	find_duplicates(&stacks);
	algo(&stacks);
	clear_stacks(&stacks, not_error);
	return (0);
}
