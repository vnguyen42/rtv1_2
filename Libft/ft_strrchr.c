/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 17:14:54 by vnguyen           #+#    #+#             */
/*   Updated: 2016/03/14 17:17:07 by vnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int a;

	a = ft_strlen((char *)s);
	while (a != 0 && s[a] != (char)c)
		a--;
	if (s[a] == (char)c)
		return ((char *)&s[a]);
	return (NULL);
}
