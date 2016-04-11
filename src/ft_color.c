/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 16:13:44 by vnguyen           #+#    #+#             */
/*   Updated: 2016/04/11 16:14:51 by vnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void	init_color(t_tool *t, t_color *objcolor, t_color *final_color)
{
	final_color->r = objcolor->r * t->lumamb;
	final_color->g = objcolor->g * t->lumamb;
	final_color->b = objcolor->b * t->lumamb;
}

void	update_color(double k, t_color *lightco, t_color *f_c, t_color *objcol)
{
	f_c->r += (lightco->r + 3 * objcol->r) / 4 * k;
	f_c->g += (lightco->g + 3 * objcol->g) / 4 * k;
	f_c->b += (lightco->b + 3 * objcol->b) / 4 * k;
}

void	add_color(t_color *color1, t_color *color2)
{
	color1->r += color2->r;
	color1->g += color2->g;
	color1->b += color2->b;
}

void	div_color(t_color *color, float n)
{
	color->r /= n;
	color->g /= n;
	color->b /= n;
}

t_color	*new_color(void)
{
	t_color *color;

	color = malloc(sizeof(t_color));
	color->r = 0;
	color->g = 0;
	color->b = 0;
	return (color);
}
