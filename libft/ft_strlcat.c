/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeftah- <smeftah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:48:59 by smeftah-          #+#    #+#             */
/*   Updated: 2022/10/22 09:39:37 by smeftah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	k;
	size_t	j;

	i = 0;
	if (!dest && size == 0)
		return (ft_strlen(src));
	j = ft_strlen((const char *)dest);
	k = ft_strlen((const char *)dest);
	if (size == 0 || k > size)
		return (ft_strlen(src) + size);
	while (src[i] && size - 1 > k)
		dest[k++] = src[i++];
	dest[k] = '\0';
	return (j + ft_strlen(src));
}
