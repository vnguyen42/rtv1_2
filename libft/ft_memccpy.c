/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 17:11:53 by vnguyen           #+#    #+#             */
/*   Updated: 2016/03/14 17:16:18 by vnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*ss1;
	unsigned char	*ss2;

	if (dst != NULL && src != NULL)
	{
		ss1 = (unsigned char *)dst;
		ss2 = (unsigned char *)src;
		while (n > 0)
		{
			*ss1 = *ss2;
			if (*ss2 == (unsigned char)c)
				return ((void *)(ss1 + 1));
			ss1++;
			ss2++;
			n--;
		}
	}
	return (NULL);
}
