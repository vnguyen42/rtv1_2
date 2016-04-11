/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 16:43:03 by vnguyen           #+#    #+#             */
/*   Updated: 2016/04/11 16:43:06 by vnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atof(char *str)
{
	int		sign;
	double	i;
	double	value;

	i = 1;
	sign = 0;
	value = 0;
	while (ft_isblank(*str))
		str++;
	*str == '-' ? sign = 1 : 0;
	*str == '-' || *str == '+' ? str++ : 0;
	while ('0' <= *str && *str <= '9')
		value = value * 10 + (*str++ - '0');
	if (*str == '.' && (str++))
		while ('0' <= *str && *str <= '9')
			value += (*str++ - '0') / (i *= 10);
	return (sign == 1 && value > 0 ? -value : value);

