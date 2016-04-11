/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 16:15:06 by vnguyen           #+#    #+#             */
/*   Updated: 2016/04/11 16:15:09 by vnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void		pixel_put_to_image(t_tool *t, int x, int y, t_color *color)
{
	t->image->data[x * t->image->bpp / 8 +
		y * t->image->size_line] = (unsigned char)color->b;
	t->image->data[x * t->image->bpp / 8 + 1 +
		y * t->image->size_line] = (unsigned char)color->g;
	t->image->data[x * t->image->bpp / 8 + 2 +
		y * t->image->size_line] = (unsigned char)color->r;
}

t_ray		*get_ray(t_tool *t, double x, double y)
{
	t_ray	*ray;
	t_pos	*b;

	ray = malloc(sizeof(t_ray));
	ray->o = malloc(sizeof(t_pos));
	b = malloc(sizeof(t_pos));
	ray->o->x = t->cam->pos->x;
	ray->o->y = t->cam->pos->y;
	ray->o->z = t->cam->pos->z;
	b->x = t->cam->upleft->x + t->cam->r_vect->x *
		t->cam->indent * x - t->cam->h_vect->x * t->cam->indent * y;
	b->y = t->cam->upleft->y + t->cam->r_vect->y *
		t->cam->indent * x - t->cam->h_vect->y * t->cam->indent * y;
	b->z = t->cam->upleft->z + t->cam->r_vect->z *
		t->cam->indent * x - t->cam->h_vect->z * t->cam->indent * y;
	ray->d = vectorsub(b, ray->o);
	vectornorm(ray->d);
	free(b);
	return (ray);
}

void		draw(t_tool *t, double x, double y)
{
	t_ray	*ray;
	double	x0;
	double	y0;
	t_color	*final_color;

	final_color = new_color();
	x0 = x;
	while (x0 <= x + 0.5)
	{
		y0 = y;
		while (y0 <= y + 0.5)
		{
			ray = get_ray(t, x0, y0);
			add_color(final_color, draw_suite(ray, t));
			y0 += 0.5;
		}
		x0 += 0.5;
	}
	div_color(final_color, 4);
	normalize_color(final_color);
	pixel_put_to_image(t, x, y, final_color);
}

void		ft_init(t_draw_suite *val)
{
	val->reflectray = malloc(sizeof(t_pos));
	val->final_color = malloc(sizeof(t_color));
	val->final_color = new_color();
	val->lightray = malloc(sizeof(t_ray));
	val->impact = malloc(sizeof(t_ray));
	val->kdiff = 0;
	val->kspec = 0;
	val->final_color->r = 0;
	val->final_color->g = 0;
	val->final_color->b = 0;
}

t_color		*draw_suite(t_ray *ray, t_tool *t)
{
	t_draw_suite *val;

	val = malloc(sizeof(t_draw_suite));
	ft_init(val);
	if ((val->curobject = intersection(t->l_objects, ray)))
	{
		ft_impact(val, ray, t);
	}
	return (val->final_color);
}
