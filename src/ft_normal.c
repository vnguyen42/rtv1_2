/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 16:30:12 by vnguyen           #+#    #+#             */
/*   Updated: 2016/04/11 16:34:32 by vnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

double		ft_normale2(t_ray *impact, t_object *object)
{
	return (2 * (impact->o->y - object->o->y) - (2 * object->d->y
				* (object->d->x * (impact->o->x - object->o->x) + object->d->z
					* (impact->o->z - object->o->z) + object->d->y
					* (impact->o->y - object->o->y))) / (pow(object->d->z, 2) +
				pow(object->d->y, 2) + pow(object->d->x, 2)));
}

double		ft_normale(t_ray *impact, t_impact *object)
{
	return (2 * (impact->->x - object->o->x) - (2 * object->d->x *
				(object->d->x * (impact->o->x - object->o->x) + object->d->z *
				 (impact->o->z - object->o->z) + object->d->y * (impact->o->y
					 - object->o->y))) / (pow(object->d->z, 2)
				 + pow(object->d->y, 2) + pow(object->d->x, 2)));
}

void		find_normal(t_ray *impact, t_object *object)
{
	if (object->type == SPHERE)
		impact->d = vectorsub(impact->o, object->o);
	else if (object->type == PLAN)
		impact->d = vectorcopy(object->d);
	else if (object->type == CONE)
	{
		impact->d = malloc(sizeof(t_pos));
		impact->d->x = impact->o->x - object->o->x;
		impact->d->y = 0;
		impact->d->z = impact->o->z - object->o->z;
	}
	else if (object->type == CYL)
	{
		impact->d = malloc(sizeof(t_pos));
		impact->d->x = ft_normale(impact, object);
		impact->d->y = ft_normale2(impact, object);
		impact->d->z = 2 * (impact->o->z - object->o->z) - (2 * object->d->z
		* (object->d->x * (impact->o->x - object->o->x) + object->d->z
		* (impact->o->z - object->o->z) + object->d->y * (impact->o->y
		- object->o->y))) / (pow(object->d->z, 2) + pow(object->d->y, 2)
		+ pow(object->d->x, 2));
	}
}
