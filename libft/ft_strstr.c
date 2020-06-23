/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 08:08:46 by aahizi-e          #+#    #+#             */
/*   Updated: 2019/01/17 16:32:59 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	n_size;

	n_size = ft_strlen(needle);
	if (!n_size)
		return ((char *)haystack);
	while (*haystack)
		if (ft_memcmp(haystack++, needle, n_size) == 0)
			return ((char *)haystack - 1);
	return (NULL);
}
