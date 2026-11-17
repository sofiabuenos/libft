/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sobueno <sobueno@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 18:12:08 by sobueno           #+#    #+#             */
/*   Updated: 2026/11/07 19:08:03 by sobueno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countnum(long int n)
{
	int	count;

	count = 1;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		count ++;
		n *= -1;
	}
	while (n >= 10)
	{
		n /= 10;
		count ++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char		*nbr;
	int			len;
	long int	nb;

	nb = n;
	len = ft_countnum(n);
	nbr = ft_calloc(len + 1, sizeof (char));
	if (!nbr)
		return (NULL);
	if (nb == 0)
		nbr[0] = '0';
	if (nb < 0)
	{
		nb *= -1;
		nbr[0] = '-';
	}
	while (nb > 0)
	{
		nbr[--len] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (nbr);
}

//int	main(void)
//{
//	char	*nbr = ft_itoa(-10);
//	printf("%s", nbr);
//	free(nbr);
//}
