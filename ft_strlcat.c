/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiabuenos <sofiabuenos@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 15:40:17 by sofiabuenos       #+#    #+#             */
/*   Updated: 2026/10/26 15:33:13 by sofiabuenos      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char * restrict dst, const char * restrict src, size_t dstsize)
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