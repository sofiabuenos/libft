/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sobueno <sobueno@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 19:13:01 by sobueno           #+#    #+#             */
/*   Updated: 2026/11/07 19:29:08 by sobueno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

/*void	teste(unsigned int i, char *c)
{
	if (i % 2 == 0)
		*c = ft_toupper(*c);
}*/

//int	main(void)
//{
//	char str[] = "hello";
//	ft_striteri(str, teste);
//	printf("%s", str);
//}
