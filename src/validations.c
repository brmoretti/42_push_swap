/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 18:40:49 by brmoretti         #+#    #+#             */
/*   Updated: 2023/12/23 00:52:30 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int check_int_limits(char *nptr)
{
	long long	i;

	if (ft_strlen(nptr) > 11)
		return (0);
	i = ft_atoll(nptr);
	if (i > INT_MAX || i < INT_MIN)
		return (0);
	return (1);
}

void	args_validation(int argc, char **argv)
{
	int		i;
	char	*str;

	if (argc < 2)
		errors(insufficient_args);
	i = 0;
	while (argv[++i])
	{
		str = argv[i];
		if (check_int_limits(str) == 0)
			errors(integer_overflow);
		if (!ft_strisinteger(str))
			errors(not_digit);
	}
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