/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sobueno <sobueno@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 17:00:02 by sobueno           #+#    #+#             */
/*   Updated: 2026/11/13 17:04:29 by sobueno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	total_size;

	if (size != 0 && count > SIZE_MAX / size)
		return (NULL);
	total_size = count * size;
	ptr = (void *)malloc(total_size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, total_size);
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
