/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sobueno <sobueno@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 15:24:35 by sobueno           #+#    #+#             */
/*   Updated: 2026/09/14 15:40:42 by sobueno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (d < s)
		return (ft_memcpy(dest, src, n));
	if (d > s)
		while (n--)
			d[n] = s[n];
	return (dest);
}

/*takes memory overflow into consideration so if d > s it does a back-to-front
copy to avoid data destruction*/
