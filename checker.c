/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseiv <eseiv@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 20:13:37 by eseiv             #+#    #+#             */
/*   Updated: 2022/03/20 22:40:04 by eseiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./get_next_line/get_next_line.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	ft_handle_instructions(t_swap *s, char *instructions)
{
	if (ft_strcmp(instructions, "pa\n") == 0)
		ft_pa(s, 0);
	else if (ft_strcmp(instructions, "pb\n") == 0)
		ft_pb(s, 0);
	else if (ft_strcmp(instructions, "sa\n") == 0)
		ft_sa(s, 0);
	else if (ft_strcmp(instructions, "sb\n") == 0)
		ft_sb(s, 0);
	else if (ft_strcmp(instructions, "ra\n") == 0)
		ft_ra(s, 0);
	else if (ft_strcmp(instructions, "rb\n") == 0)
		ft_rb(s, 0);
	else if (ft_strcmp(instructions, "rra\n") == 0)
		ft_rra(s, 0);
	else if (ft_strcmp(instructions, "rrb\n") == 0)
		ft_rrb(s, 0);
	else if (ft_strcmp(instructions, "rr\n") == 0)
		ft_rr(s);
	else if (ft_strcmp(instructions, "rrr\n") == 0)
		ft_rrr(s);
	else
		return (0);
	return (1);
}

int	ft_check_instructions(t_swap *s, int fd)
{
	char	*instructions;

	instructions = get_next_line(fd);
	while (instructions)
	{
		if (!instructions)
		{
			ft_print("Error\n");
			return (0);
		}
		if (!ft_handle_instructions(s, instructions))
		{
			ft_print("Error\n");
			return (0);
		}
		free(instructions);
		instructions = get_next_line(fd);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_swap	s;

	if (ac > 1)
	{
		s.stack_a = ft_insert(ac, av);
		s.stack_a_size = ac - 1;
		s.stack_b_size = 0;
		if (!ft_is_not_duplicate(s.stack_a, s.stack_a_size)
			|| !check_digit(ac, av)
			|| !ft_check_int_min_max(ac, av))
		{
			ft_print("Error\n");
			return (0);
		}
		if (!ft_check_instructions(&s, 0))
			return (0);
		if (is_sorted(s.stack_a, s.stack_a_size))
			ft_print("OK\n");
		else
			ft_print("KO\n");
	}
	return (0);
}
