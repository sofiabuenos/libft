/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sobueno <sobueno@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 18:45:36 by sobueno           #+#    #+#             */
/*   Updated: 2026/11/07 19:11:16 by sobueno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	return (str);
}

//char teste(unsigned int i, char c)
//{
//	if (i % 2 == 0)
//		return (ft_toupper(c));
//	return (c);
//}
//int	main(void)
//{
//	char	*str;
//	str = ft_strmapi("hello", teste);
//	printf("%s", str);
//	free(str);
//}
