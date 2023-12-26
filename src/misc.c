/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 16:32:12 by brmoretti         #+#    #+#             */
/*   Updated: 2023/12/26 16:37:39 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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