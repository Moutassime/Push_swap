/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseiv <eseiv@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 19:35:43 by eseiv             #+#    #+#             */
/*   Updated: 2022/03/20 22:36:26 by eseiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_min(int *tab, int len)
{
	int	i;
	int	max;

	i = 0;
	max = tab[i];
	while (i < len)
	{
		if (max > tab[i])
			max = tab[i];
		i++;
	}
	return (max);
}

int	ft_max(int *tab, int len)
{
	int	i;
	int	max;

	i = 0;
	max = tab[i];
	while (i < len)
	{
		if (max < tab[i])
			max = tab[i];
		i++;
	}
	return (max);
}

void	ft_print(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}
