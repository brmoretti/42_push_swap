/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 12:43:36 by brmoretti         #+#    #+#             */
/*   Updated: 2023/12/29 12:20:36 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	errors(int error_code)
{
	if (error_code == not_digit)
		ft_putstr_fd("Error\n", 2);
	else if (error_code == integer_overflow)
		ft_putstr_fd("Error\n", 2);
	else if (error_code == malloc_error)
		ft_putstr_fd("Error\n", 2);
	else if (error_code == duplicated_value)
		ft_putstr_fd("Error\n", 2);
	else
		ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}
