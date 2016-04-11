/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 17:11:57 by vnguyen           #+#    #+#             */
/*   Updated: 2016/03/14 17:16:19 by vnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		*ss;
	size_t				a;
	unsigned char		stop;

	a = 0;
	stop = (unsigned char)c;
	ss = (unsigned char*)s;
	while (n--)
	{
		if (ss[a] == stop)
			return (ss + a);
		a++;
	}
	return (NULL);
}
