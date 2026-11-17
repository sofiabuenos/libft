/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sobueno <sobueno@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 15:40:17 by sobueno           #+#    #+#             */
/*   Updated: 2026/11/04 12:56:16 by sobueno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	strl[2];

	strl[0] = ft_strlen(src);
	strl[1] = ft_strlen(dst);
	i = strl[1];
	if (dstsize != 0)
	{
		j = 0;
		while (i < dstsize - 1 && src[j] != '\0')
		{
			dst[i] = src[j];
			i++;
			j++;
		}
		dst[i] = '\0';
	}
	if (dstsize <= strl[1])
		return (dstsize + strl[0]);
	else
		return (strl[0] + strl[1]);
}
