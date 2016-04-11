/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 17:15:05 by vnguyen           #+#    #+#             */
/*   Updated: 2016/03/14 17:17:10 by vnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*tab;
	size_t		a;

	a = 0;
	tab = malloc(sizeof(char) * len + 1);
	if (tab != NULL && s != NULL)
	{
		while (a < len)
		{
			tab[a] = s[start];
			a++;
			start++;
		}
	}
	else
		return (NULL);
	tab[a] = '\0';
	return (char*)(tab);
}
