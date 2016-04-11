/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 17:15:02 by vnguyen           #+#    #+#             */
/*   Updated: 2016/03/14 17:17:09 by vnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int i;
	int j;
	int c;

	i = 0;
	c = 0;
	if (s2[0] == '\0')
		return (char*)(s1);
	while (s1[i])
	{
		j = i;
		c = 0;
		while (s1[j] == s2[c])
		{
			j++;
			c++;
			if (s2[c] == '\0')
				return (char*)(&s1[i]);
		}
		i++;
	}
	return (NULL);
}
