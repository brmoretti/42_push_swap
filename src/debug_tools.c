/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 23:58:27 by brmoretti         #+#    #+#             */
/*   Updated: 2023/12/19 00:27:25 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_stack_numbers(void *content)
{
	ft_putnbr_fd(*(int *)content, 1);
	ft_putstr_fd("\n", 1);
}

void	debug_print_stack(t_list *stack)
{
	ft_lstiter(stack, put_stack_numbers);
}
