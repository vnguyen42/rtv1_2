/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 17:14:10 by vnguyen           #+#    #+#             */
/*   Updated: 2016/03/14 17:16:55 by vnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t		len;
	size_t		c;
	char		*s;
	const char	*str;

	s = dst;
	str = src;
	c = n;
	while (c-- != 0 && *s != '\0')
		s++;
	len = s - dst;
	c = n - len;
	if (c == 0)
		return (len + ft_strlen(str));
	while (*str != '\0')
	{
		if (c != 1)
		{
			*s++ = *str;
			c--;
		}
		str++;
	}
	*s = '\0';
	return (len + (str - src));
}
