/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeftah- <smeftah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 17:36:37 by smeftah-          #+#    #+#             */
/*   Updated: 2022/10/27 16:41:55 by smeftah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	calcul(const char *s, char c)
{
	int	k;
	int	i;

	k = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			k++;
		i++;
	}
	return (k);
}

static char	*remp(const char *s, char c, int *i)
{
	char	*str;
	int		j;
	int		r;

	j = 0;
	while (s[(*i)] == c)
		(*i)++;
	while (s[(*i)] && s[(*i)] != c)
	{
		j++;
		(*i)++;
	}
	r = (*i) - j;
	str = ft_substr(s, r, j);
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	if (!s)
		return (NULL);
	j = calcul(s, c);
	str = (char **)malloc(sizeof(char *) * (j + 1));
	if (!str)
		return (NULL);
	while (k < j)
	{
		str[k] = remp(s, c, &i);
		if (str[k++])
			continue ;
		while (--k >= 0)
			free(str[k]);
		free(str);
		return (NULL);
	}
	str[k] = NULL;
	return (str);
}
