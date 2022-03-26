/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_tests.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseiv <eseiv@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 19:56:42 by eseiv             #+#    #+#             */
/*   Updated: 2022/03/19 20:34:56 by eseiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_not_duplicate(int *stack, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (stack[i] == stack[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!((str[i] >= '0' && str[i] <= '9' ) || (str[i] == '-')))
			return (0);
		i++;
	}
	return (1);
}

int	check_digit(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!is_digit(av[i]))
			return (0);
		i++;
	}
	return (1);
}

long	ft_atol(char *str)
{
	int		i;
	long	num;
	int		sign;

	i = 0;
	num = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + str[i] - '0';
		i++;
	}
	return (num * sign);
}

int	ft_check_int_min_max(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_atol(av[i]) > 2147483647 || ft_atol(av[i]) < -2147483648)
			return (0);
		i++;
	}
	return (1);
}
