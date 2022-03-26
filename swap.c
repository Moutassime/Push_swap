/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseiv <eseiv@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 19:35:36 by eseiv             #+#    #+#             */
/*   Updated: 2022/03/19 23:59:05 by eseiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_sa(t_swap *s, int flag)
{
	ft_swap(&s->stack_a[0], &s->stack_a[1]);
	if (flag == 1)
		ft_print("sa\n");
}

void	ft_sb(t_swap *s, int flag)
{
	ft_swap(&s->stack_b[0], &s->stack_b[1]);
	if (flag == 1)
		ft_print("sb\n");
}

void	ft_ss(t_swap *s, int flag)
{
	ft_sa(s, flag);
	ft_sb(s, flag);
	ft_print("ss\n");
}
