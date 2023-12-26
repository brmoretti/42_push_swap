/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 12:43:36 by brmoretti         #+#    #+#             */
/*   Updated: 2023/12/22 19:22:22 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	errors(int error_code)
{
	if (error_code == insufficient_args)
		ft_putstr_fd("Insufficient args.\n"
			"Usage: ./push_swap <int> <int> ... <int>\n", 2);
	else if (error_code == not_digit)
		ft_putstr_fd("Only integers allowed as arguments.\n", 2);
	else if (error_code == integer_overflow)
		ft_putstr_fd("Integer overflow.\n", 2);
	else if (error_code == malloc_error)
		ft_putstr_fd("Malloc error.\n", 2);
	else if (error_code == duplicated_value)
		ft_putstr_fd("Duplicated value.\n", 2);
	else
		ft_putstr_fd("Error.\n", 2);
	exit(EXIT_FAILURE);
}
