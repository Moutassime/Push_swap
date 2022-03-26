/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseiv <eseiv@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 19:56:39 by eseiv             #+#    #+#             */
/*   Updated: 2022/03/21 22:29:59 by eseiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_set_quarters(t_swap *s)
{
	if (s->stack_a_size < 100)
		s->stack_a_quarter = 2;
	else if (s->stack_a_size >= 100 && s->stack_a_size < 500)
		s->stack_a_quarter = 4;
	else if (s->stack_a_size >= 500)
		s->stack_a_quarter = 8;
}

void	ft_assign(t_swap *s, int ac, char **av)
{
	s->stack_a = ft_insert(ac, av);
	s->stack_a_size = ac - 1;
	s->stack_b_size = 0;
	s->stack_a_quarter = 0;
	ft_set_quarters(s);
}

int	ft_create_midpoints(t_swap *s)
{
	int	*temp_stack;
	int	counter;

	temp_stack = ft_copy_stack_elements(s);
	ft_sort_int_tab(temp_stack, s->stack_a_size);
	counter = s->stack_a_size / s->stack_a_quarter;
	s->stack_a_midpoint = temp_stack[s->stack_a_size];
	free(temp_stack);
	return (temp_stack[counter]);
}
