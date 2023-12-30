/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 16:32:12 by brmoretti         #+#    #+#             */
/*   Updated: 2023/12/28 12:35:30 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	el_int(t_element *el)
{
	return (*(int *)el->content);
}

unsigned int	ft_max(unsigned int a, unsigned int b)
{
	if (a > b)
		return (a);
	return (b);
}

unsigned int	ft_min(unsigned int a, unsigned int b)
{
	if (a < b)
		return (a);
	return (b);
}

char	**clear_tab(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
		free (tab[i++]);
	free (tab);
	return (NULL);
}