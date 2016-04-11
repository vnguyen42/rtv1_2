/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 17:12:30 by vnguyen           #+#    #+#             */
/*   Updated: 2016/03/14 17:17:24 by vnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t				a;
	unsigned	char	*tab;

	a = 0;
	tab = (unsigned char *)b;
	while (a < len)
	{
		tab[a] = (unsigned char)c;
		a++;
	}
	return (tab);
}
