/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_big_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseiv <eseiv@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 19:56:49 by eseiv             #+#    #+#             */
/*   Updated: 2022/03/21 22:17:38 by eseiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_big_stack_step_one(t_swap *s)
{
	int	i;
	int	mid_point_holder;

	i = 0;
	mid_point_holder = ft_create_midpoints(s);
	while (i < s->stack_a_size)
	{
		if (s->stack_a[i] < mid_point_holder)
		{
			ft_send_number_to_top_stack_a(s, s->stack_a[i], i);
			i = 0;
		}
		i++;
	}
}

void	ft_sort_big_stack_step_two(t_swap *s)
{
	int	i;
	int	min;

	i = 0;
	min = 0;
	while (s->stack_a_size >= 1 && s->stack_a[i])
	{
		min = ft_min(s->stack_a, s->stack_a_size);
		if (s->stack_a[0] == min)
		{
			ft_pb(s, 1);
			i++;
		}
		else if (s->stack_a[i] != min)
			i++;
		else if (s->stack_a[i] == min)
		{
			ft_send_number_to_top_stack_a(s, min, i);
			i = 0;
		}
	}
}

void	ft_sort_big_stack_step_three(t_swap *s)
{
	int	i;
	int	max;

	i = 0;
	max = 0;
	while (s->stack_b_size >= 1 && i < s->stack_b_size)
	{
		max = ft_max(s->stack_b, s->stack_b_size);
		if (s->stack_b[0] == max)
		{
			ft_pa(s, 1);
			i++;
		}
		else if (s->stack_b[i] != max)
			i++;
		else if (s->stack_b[i] == max)
		{
			ft_send_number_to_top_stack_b(s, max, i);
			i = 0;
		}
	}
}
