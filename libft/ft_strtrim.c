/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeftah- <smeftah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 21:19:15 by smeftah-          #+#    #+#             */
/*   Updated: 2022/10/27 12:09:53 by smeftah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check(char const *s, char const c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (-1);
}

static size_t	partone(char const *str, char const *s)
{
	size_t	i;

	i = 0;
	while (str[i] && check(s, str[i]) != -1)
		i++;
	return (i);
}

static size_t	partf(char const *str, char const *s)
{
	size_t	i;

	i = ft_strlen(str) - 1;
	while (i >= 0 && check(s, str[i]) != -1)
		i--;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		k;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	i = partone(s1, set);
	k = partf(s1, set);
	str = ft_substr(s1, i, (k - i) + 1);
	return (str);
}
