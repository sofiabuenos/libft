/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiabuenos <sofiabuenos@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 17:00:02 by sofiabuenos       #+#    #+#             */
/*   Updated: 2026/10/26 17:20:31 by sofiabuenos      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(size * count);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}

/*int	main(void)
{
	int i = 0;
	int *arr = ft_calloc(15, sizeof(int));
	while(i < 15)
	{
		printf("%d, ", arr[i]);
		i++;
	}
	i = 0;
	while (i < 15)
	{
		arr[i] = i + 1;
		i++;
	}
	i = 0;
	while(i < 15)
	{
		printf("%d, ", arr[i]);
		i++;
	}
}*/