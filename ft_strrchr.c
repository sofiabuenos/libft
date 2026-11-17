/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sobueno <sobueno@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 15:51:28 by sobueno           #+#    #+#             */
/*   Updated: 2026/10/12 15:56:36 by sobueno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*temp;

	i = 0;
	temp = NULL;
	while (s[i] != '\0')
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			temp = (char *)&s[i];
		i++;
	}
	if (temp != NULL)
		return (temp);
	if ((unsigned char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

//int	main(void)
//{
//	printf("%s\n", strrchr("hello", 'l'));
//	printf("%s\n", ft_strrchr("hello", 'l'));
//	return (0);
//}
