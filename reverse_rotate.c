/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseiv <eseiv@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 19:35:29 by eseiv             #+#    #+#             */
/*   Updated: 2022/03/19 23:59:34 by eseiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(int *tab, int size)
{
	int	i;
	int	swap;

	i = size - 1;
	while (i > 0)
	{
		swap = tab[i];
		tab[i] = tab[i - 1];
		tab[i - 1] = swap;
		i--;
	}
}

void	ft_rra(t_swap *s, int flag)
{
	reverse_rotate(s->stack_a, s->stack_a_size);
	if (flag == 1)
		ft_print("rra\n");
}

void	ft_rrb(t_swap *s, int flag)
{
	reverse_rotate(s->stack_b, s->stack_b_size);
	if (flag == 1)
		ft_print("rrb\n");
}

void	ft_rrr(t_swap *s)
{
	reverse_rotate(s->stack_a, s->stack_a_size);
	reverse_rotate(s->stack_b, s->stack_b_size);
	ft_print("rrr\n");
}
