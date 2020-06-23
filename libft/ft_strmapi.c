/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 22:16:40 by cwu               #+#    #+#             */
/*   Updated: 2019/01/17 16:46:15 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	n;
	char	*p;

	if (!s)
		return (NULL);
	n = ft_strlen(s);
	if (!f || !(p = ft_strnew(n)))
		return (NULL);
	while (n--)
		*(p + n) = f(n, *(char *)(s + n));
	return (p);
}
