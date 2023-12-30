/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:16:51 by brmoretti         #+#    #+#             */
/*   Updated: 2023/12/30 15:06:41 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	get_instruction(char *line)
{
	if (!ft_strncmp(line, "sa\n", 4))
		return (i_sa);
	else if (!ft_strncmp(line, "sb\n", 4))
		return (i_sb);
	else if (!ft_strncmp(line, "ss\n", 4))
		return (i_ss);
	else if (!ft_strncmp(line, "pa\n", 4))
		return (i_pa);
	else if (!ft_strncmp(line, "pb\n", 4))
		return (i_pb);
	else if (!ft_strncmp(line, "ra\n", 4))
		return (i_ra);
	else if (!ft_strncmp(line, "rb\n", 4))
		return (i_rb);
	else if (!ft_strncmp(line, "rr\n", 4))
		return (i_rr);
	else if (!ft_strncmp(line, "rra\n", 5))
		return (i_rra);
	else if (!ft_strncmp(line, "rrb\n", 5))
		return (i_rrb);
	else if (!ft_strncmp(line, "rrr\n", 5))
		return (i_rrr);
	else
		return (not_instruction);
}

static void	instructions_fill(t_stacks *stacks, t_list *instructions)
{
	t_element	*el;
	int			*instruction;
	char		*line;

	line = get_next_line(0);
	while (line)
	{
		instruction = malloc(sizeof(int));
		if (!instruction)
			clear_heap(stacks, instructions, malloc_error);
		*instruction = get_instruction(line);
		free (line);
		if (*instruction == not_instruction)
		{
			free (instruction);
			clear_heap(stacks, instructions, invalid_instruction);
		}
		el = ft_lstnewelement(instruction);
		if (!el)
			clear_heap(stacks, instructions, malloc_error);
		ft_lstadd_back(instructions, el);
		line = get_next_line(0);
	}
}

t_list	*get_instructions(t_stacks *stacks)
{
	t_list	*instructions;

	instructions = ft_calloc(1, sizeof(t_list));
	if (!instructions)
		clear_heap(stacks, NULL, malloc_error);
	instructions_fill(stacks, instructions);
	return (instructions);
}

static void	execute(t_stacks *stacks, int instruction)
{
	if (instruction == i_sa)
		sa(stacks);
	else if (instruction == i_sb)
		sb(stacks);
	else if (instruction == i_ss)
		ss(stacks);
	else if (instruction == i_pa)
		pa(stacks);
	else if (instruction == i_pb)
		pb(stacks);
	else if (instruction == i_ra)
		ra(stacks);
	else if (instruction == i_rb)
		rb(stacks);
	else if (instruction == i_rr)
		rr(stacks);
	else if (instruction == i_rra)
		rra(stacks);
	else if (instruction == i_rrb)
		rrb(stacks);
	else if (instruction == i_rrr)
		rrr(stacks);
}

void	instructions_execution(t_stacks *stacks, t_list *instructions)
{
	t_element	*el;
	int			instruction;

	el = instructions->first;
	while (el)
	{
		instruction = el_int(el);
		execute(stacks, instruction);
		el = el->next;
	}
}
