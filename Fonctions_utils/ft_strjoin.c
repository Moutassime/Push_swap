/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseiv <eseiv@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 19:35:56 by eseiv             #+#    #+#             */
/*   Updated: 2022/03/19 20:37:30 by eseiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ft_strlen(char	*str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

static char	*ft_strcpy(char	*dest, char	*src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		*dest = src [i];
		dest++;
		i++;
	}
	return (dest);
}

static int	ft_full_len(int size, char **strs, int sep_len)
{
	int	i;
	int	len;

	len = sep_len * -1;
	i = 0;
	while (i < size)
	{
		len += ft_strlen(strs[i]) + sep_len;
		i++;
	}
	return (len);
}

char	*ft_strjoin(int size, char	**strs, char	*sep)
{
	int		i;
	int		len;
	char	*rtn;

	len = ft_full_len(size, strs, ft_strlen(sep));
	rtn = (char *)malloc(sizeof(char) * (len + 1));
	if (rtn == NULL)
		return (NULL);
	else
	{
		i = -1;
		while (++i < size)
		{
			rtn = ft_strcpy(rtn, strs[i]);
			if (i < size - 1)
				rtn = ft_strcpy(rtn, sep);
		}
	}
	*rtn = 0;
	return (rtn - len);
}
