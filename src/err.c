/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 12:43:36 by brmoretti         #+#    #+#             */
/*   Updated: 2023/12/19 00:27:16 by brmoretti        ###   ########.fr       */
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
	exit(EXIT_FAILURE);
}
