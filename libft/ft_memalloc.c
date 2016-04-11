/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 17:11:49 by vnguyen           #+#    #+#             */
/*   Updated: 2016/03/14 17:16:17 by vnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	char	*tab;
	size_t	a;

	a = 0;
	tab = malloc(size);
	if (tab != NULL)
	{
		while (a < size)
		{
			tab[a] = '\0';
			a++;
		}
		return (tab);
	}
	return (NULL);
}
