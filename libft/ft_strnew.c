/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 17:14:44 by vnguyen           #+#    #+#             */
/*   Updated: 2016/03/14 17:17:05 by vnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*tab;
	size_t	a;

	a = 0;
	tab = malloc(sizeof(char) * size + 1);
	if (tab != NULL)
	{
		while (a < size)
		{
			tab[a] = '\0';
			a++;
		}
		tab[a] = '\0';
		return (tab);
	}
	else
		return (NULL);
}
