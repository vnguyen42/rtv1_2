/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 17:14:41 by vnguyen           #+#    #+#             */
/*   Updated: 2016/03/14 17:17:04 by vnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t a;
	size_t b;

	a = 0;
	b = 0;
	if (s1 != NULL && s2 != NULL)
	{
		while (a < n)
		{
			if (s1[a] == s2[b])
				b++;
			a++;
		}
		if (a == b)
			return (1);
	}
	return (0);
}
