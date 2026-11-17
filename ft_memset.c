/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sobueno <sobueno@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 16:12:44 by sobueno           #+#    #+#             */
/*   Updated: 2026/08/28 16:15:28 by sobueno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*s1;
	unsigned char	c1;

	s1 = (unsigned char *)s;
	c1 = (unsigned char)c;
	while (n--)
		*s1++ = c1;
	return (s);
}

/*int	main(void)
{
	int arr[5];
	ft_memset(arr, 0, sizeof(arr));
	for (int i = 0; i < 5; i++)
	    printf("%d ", arr[i]);
	return (0);
}*/
