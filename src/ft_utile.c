/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 16:35:05 by vnguyen           #+#    #+#             */
/*   Updated: 2016/04/11 16:35:56 by vnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void		normalize_color(t_color *final_color)
{
	if (final_color->r < 0)
		final_color->r = 0;
	if (final_color->b < 0)
		final_color->b = 0;
	if (final_color->g < 0)
		final_color->g = 0;
	if (final_color->r > 255)
		final_color->r = 255;
	if (final_color->b > 255)
		final_color->b = 255;
	if (final_color->g > 255)
		final_color->g = 255;
}

void		verife(t_object *tmp, t_ray *ray, double *min)
{
	if (tmp->type == SPHERE)
		tmp->dist = intersection_sphere(tmp, ray, min);
	else if (tmp->type == CONE)
		tmp->dist = intersection_cone(tmp, ray, min);
	else if (tmp->type == PLAN)
		tmp->dist = intersection_plan(tmp, ray, min);
	else if (tmp->type == CYL)
		tmp->dist = intersection_cyl(tmp, ray, min);
}

double		calcule(t_ray *ray, t_object *cyl, double k)
{
	return (2 * (ray->d->x * (ray->o->x - cyl->o->x)
				+ (ray->d->y) * (ray->o->y
					- cyl->o->y) + ray->d->z * (ray->o->z - cyl->o->z))
			- (2 * (cyl->d->x * ray->d->x
					+ cyl->d->y * ray->d->y + cyl->d->z * ray->d->z)
				* (cyl->d->x * (ray->o->x - cyl->o->x) + cyl->d->y
					* (ray->o->y - cyl->o->y) + cyl->d->z * (ray->o->z - cyl->o->z)) / k));
}


t_object	*intersection(t_object *l_objects, t_ray *ray)
{
	double		min;
	t_object	*tmp;

	tmp = l_objects;
	min = 200000;
	while (tmp != NULL)
	{
		verife(tmp, ray, &min);
		tmp = tmp->next;
	}
	tmp = l_objects;
	if (min == 200000)
		return (NULL);
	while (tmp != NULL)
	{
		if (tmp->dist == min)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
