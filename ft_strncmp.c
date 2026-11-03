/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiabuenos <sofiabuenos@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 16:24:57 by sofiabuenos       #+#    #+#             */
/*   Updated: 2026/10/12 16:33:27 by sofiabuenos      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n <= 0)
		return (0);
	while (i < n - 1 && s1[i] == s2[i] && (s1[i] != '\0' || s2[i] != '\0'))
		i++;
	if ((unsigned char)s1[i] - (unsigned char)s2[i] == 0)
		return (0);
	else if ((unsigned char)s1[i] - (unsigned char)s2[i] > 0)
		return (1);
	else
		return (-1);
}

//int main(void)
//{
//    printf("%d\n", strncmp("hello", "hello", 5));
//    printf("%d\n", ft_strncmp("hello", "hello", 5));
//    return (0);
//}
