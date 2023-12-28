/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 18:40:49 by brmoretti         #+#    #+#             */
/*   Updated: 2023/12/28 12:49:46 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_int_limits(char *nptr)
{
	long long	i;

	if (ft_strlen(nptr) > 11)
		return (0);
	i = ft_atoll(nptr);
	if (i > INT_MAX || i < INT_MIN)
		return (0);
	return (1);
}

static char	**create_args_tab(int argc, char **argv)
{
	char	**tab;
	int		i;

	if (argc == 2)
		tab = ft_split(argv[1], ' ');
	else
	{
		tab = ft_calloc(argc, sizeof(char *));
		if (!tab)
			errors(malloc_error);
		i = 0;
		while (++i < argc)
		{
			tab[i - 1] = ft_strdup(argv[i]);
			if (!tab[i - 1])
				clear_tab(tab);
		}
	}
	if (!tab)
		errors(malloc_error);
	return (tab);
}


char	**args_validation(int argc, char **argv)
{
	int		i;
	char	**tab;

	if (argc < 2)
		exit(EXIT_SUCCESS);
	else
		tab = create_args_tab(argc, argv);
	i = 0;
	while (tab[i])
	{
		if (check_int_limits(tab[i]) == 0)
		{
			clear_tab(tab);
			errors(integer_overflow);
		}
		if (!ft_strisinteger(tab[i++]))
		{
			clear_tab(tab);
			errors(not_digit);
		}
	}
	return (tab);
}

void	find_duplicates(t_stacks *stacks)
{
	t_element	*el;
	t_element	*el2;
	t_list		*stack_a;

	stack_a = stacks->a;
	el = stack_a->first;
	while (el)
	{
		el2 = el->next;
		while (el2)
		{
			if (*(int *)el->content == *(int *)el2->content)
				clear_stacks(stacks, duplicated_value);
			el2 = el2->next;
		}
		el = el->next;
	}
}
