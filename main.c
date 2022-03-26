/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseiv <eseiv@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 19:34:59 by eseiv             #+#    #+#             */
/*   Updated: 2022/03/21 20:58:24 by eseiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_swap *s)
{
	int	stack_a_save;

	stack_a_save = s->stack_a_size;
	if (s->stack_a_size <= 3)
	{
		while (!is_sorted(s->stack_a, s->stack_a_size))
			ft_sort_3_numbers(s);
	}
	else if (s->stack_a_size > 3 && s->stack_a_size < 50)
		ft_sort_medium_stack(s);
	else if (s->stack_a_size >= 50)
	{
		while (s->stack_a_quarter != 1)
		{
			ft_sort_big_stack_step_one(s);
			s->stack_a_quarter -= 1;
		}
		ft_sort_big_stack_step_two(s);
		while (s->stack_a_size + 1 < stack_a_save)
			ft_sort_big_stack_step_three(s);
		if (s->stack_a_size == stack_a_save - 1)
			ft_pa(s, 1);
	}
}

int	main(int ac, char **av)
{
	t_swap	s;
	char	*sep;
	char	**str;
	char	*tmp;

	sep = " ";
	tmp = ft_strjoin(ac, av, sep);
	str = ft_split(tmp, ' ');
	free(tmp);
	ft_assign(&s, ac, str);
	if (!ft_is_not_duplicate(s.stack_a, s.stack_a_size)
		|| !check_digit(ac, str)
		|| !ft_check_int_min_max(ac, str))
	{
		ft_print("Error\n");
		return (0);
	}
	if (s.stack_a_size == 1 || is_sorted(s.stack_a, s.stack_a_size))
		return (0);
	push_swap(&s);
	return (0);
}
