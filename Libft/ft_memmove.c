/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 17:12:26 by vnguyen           #+#    #+#             */
/*   Updated: 2016/03/14 17:16:33 by vnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*s;

	if (dst == '\0' || src == '\0')
		return (NULL);
	s = (unsigned char*)malloc(sizeof(*s) * len);
	if (s == NULL)
		return (dst);
	ft_memcpy(s, src, len);
	ft_memcpy(dst, s, len);
	free(s);
	return (dst);
}
