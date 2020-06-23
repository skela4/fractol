/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 08:08:46 by aahizi-e          #+#    #+#             */
/*   Updated: 2019/01/17 16:27:40 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	n;

	if ((n = ft_strlen(src)) >= len)
		return (ft_memcpy(dst, src, len));
	ft_bzero(dst + n, len - n);
	return (ft_memcpy(dst, src, n));
}
