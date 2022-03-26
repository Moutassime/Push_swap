/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseiv <eseiv@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 19:36:00 by eseiv             #+#    #+#             */
/*   Updated: 2022/03/19 19:42:49 by eseiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static size_t	taille_tab(const char *s, char c)
{
	size_t	cnt;

	cnt = 0;
	while (*s && s++)
	{
		while (*s != c && *s)
			s++;
		cnt++;
		while (*s == c && *s)
			s++;
	}
	return (cnt);
}

static int	remp_tab(char const *s, char c, char **tab)
{
	size_t	i;
	size_t	len;

	i = 0;
	while (*s)
	{
		len = 0;
		while (*s != c && *s && ++s)
			len++;
		tab[i] = malloc(len + 1);
		if (!tab[i])
		{
			while (i)
				free(tab[--i]);
			free(tab);
			return (1);
		}
		ft_strlcpy(tab[i++], s - len, len + 1);
		while (*s == c && *s)
			s++;
	}
	tab[i] = 0;
	return (0);
}

char	**ft_split(const char *s, char c)
{
	char	**tab;

	if (!s)
		return (NULL);
	while (*s == c && *s)
		s++;
	tab = (char **)malloc(sizeof(char *) * (taille_tab(s, c) + 1));
	if (!tab)
		return (NULL);
	if (remp_tab(s, c, tab))
		return (NULL);
	return (tab);
}
