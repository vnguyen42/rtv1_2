/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 17:13:50 by vnguyen           #+#    #+#             */
/*   Updated: 2016/03/14 17:16:46 by vnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *mot)
{
	int		a;
	int		j;
	char	*copie;

	if (mot == NULL)
		return (NULL);
	a = ft_strlen(mot);
	copie = (char*)malloc(sizeof(char) * a + 1);
	if (copie == NULL)
		return (NULL);
	j = 0;
	while (j < a)
	{
		copie[j] = mot[j];
		j++;
	}
	copie[j] = '\0';
	return (copie);
}
