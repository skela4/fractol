/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 08:51:03 by aahizi-e          #+#    #+#             */
/*   Updated: 2019/01/17 16:50:37 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_nb_convert(long nb, int count, char *s)
{
	while (nb)
	{
		*(s + --count) = nb % 10 + '0';
		nb = nb / 10;
	}
	if (count--)
		*(s + count) = '-';
	return (s);
}

char			*ft_itoa(int n)
{
	int		count;
	char	*s;
	long	nb;

	nb = n;
	count = ft_nbrlen(nb);
	if (nb < 0 && (nb = nb * -1))
		count++;
	if (!(s = ft_strnew(count)))
		return (NULL);
	else if (nb == 0)
		return (ft_strdup("0"));
	return (ft_nb_convert(nb, count, s));
}
