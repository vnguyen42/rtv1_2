/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 16:25:28 by vnguyen           #+#    #+#             */
/*   Updated: 2016/04/11 16:27:14 by vnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

t_pos		*rotation(t_pos *axe, t_pos *vect)
{
	t_pos	*rota_matrice;

	rota_matrice = malloc(sizeof(t_pos));
	rota_matrice->x = -vect->x + 2 * vect->x * pow(axe->x, 2) + 2 *
		vect->y * axe->x * axe->y + 2 * vect->z * axe->x * axe->z;
	rota_matrice->y = -vect->y + 2 * vect->x * axe->x * axe->y + 2 *
		vect->y * pow(axe->y, 2) + vect->z * 2 * axe->y * axe->z;
	rota_matrice->z = -vect->z + 2 * vect->x * axe->x * axe->z + 2 *
		vect->y * axe->y * axe->z + 2 * vect->z * pow(axe->z, 2);
	vectornorm(rota_matrice);
	return (rota_matrice);
}

double		intersection_plan(t_object *plan, t_ray *ray, double *min)
{
	double	a;
	double	b;

	a = plan->d->x * ray->d->x + plan->d->y * ray->d->y + plan->d->z *
		ray->d->z;
	b = plan->d->x * ray->o->x + plan->d->y * ray->o->y + plan->d->z *
		ray->o->z + plan->h;
	if (-b / a > E)
	{
		if (-b / a < *min)
			*min = -b / a;
		return (-b / a);
	}
	return (0);
}

double		intersection_sphere(t_object *sphere, t_ray *ray, double *min)
{
	t_equation	param;
	t_pos		*dist;

	dist = vectorsub(ray->o, sphere->o);
	param.a = vectordot(ray->d, ray->d);
	param.b = 2 * vectordot(ray->d, dist);
	param.c = vectordot(dist, dist) - (sphere->rad * sphere->rad);
	param.discr = param.b * param.b - 4 * param.a * param.c;
	if (param.discr < E)
		return (0);
	param.t0 = (-param.b + sqrtf(param.discr)) / (2 * param.a);
	param.t1 = (-param.b - sqrtf(param.discr)) / (2 * param.a);
	if (fabs(param.t0) > fabs(param.t1))
		param.t0 = param.t1;
	if (param.t0 < 0)
		return (0);
	else if (param.t0 < *min)
		*min = param.t0;
	return (param.t0);
}

double		intersection_cone(t_object *cone, t_ray *ray, double *min)
{
	double		k;
	t_equation	param;

	k = pow(cone->rad / cone->h, 2);
	param.a = pow(ray->d->x, 2) + pow(ray->d->z, 2) - pow(ray->d->y, 2) * k;
	param.b = 2 * (ray->d->x * (ray->o->x - cone->o->x) + ray->d->z *
			(ray->o->z - cone->o->z) - ray->d->y * (ray->o->y - cone->o->y) * k);
	param.c = pow((ray->o->x - cone->o->x), 2) +
		pow((ray->o->z - cone->o->z), 2)
		- pow((ray->o->y - cone->o->y), 2) * k;
	param.discr = param.b * param.b - 4 * param.a * param.c;
	if (param.discr < E)
		return (0);
	param.t0 = (-param.b + sqrtf(param.discr)) / (2 * param.a);
	param.t1 = (-param.b - sqrtf(param.discr)) / (2 * param.a);
	if (fabs(param.t0) > fabs(param.t1))
		param.t0 = param.t1;
	if (param.t0 < 0)
		return (0);
	else if (param.t0 < *min)
		*min = param.t0;
	return (param.t0);
}

double		intersection_cyl(t_object *cyl, t_ray *ray, double *min)
{
	t_equation	param;
	double		k;

	k = pow(cyl->d->x, 2) + pow(cyl->d->y, 2) + pow(cyl->d->z, 2);
	param.a = vectordot(ray->d, ray->d) - (pow(cyl->d->x * ray->d->x
				+ cyl->d->y * ray->d->y + cyl->d->z * ray->d->z, 2) / k);
	param.b = calcule(ray, cyl, k);
	param.c = (ray->o->x - cyl->o->x) * (ray->o->x - cyl->o->x) +
		(ray->o->y - cyl->o->y) * (ray->o->y - cyl->o->y) + (ray->o->z - cyl->o->z)
		* (ray->o->z - cyl->o->z) - (cyl->rad * cyl->rad) - (pow(cyl->d->x *
					(ray->o->x - cyl->o->x) + cyl->d->y * (ray->o->y - cyl->o->y) + cyl->d->z
					* (ray->o->z - cyl->o->z), 2) / k);
	param.discr = param.b * param.b - 4 * param.a * param.c;
	if (param.discr < E)
		return (0);
	param.t0 = (-param.b + sqrtf(param.discr)) / (2 * param.a);
	param.t1 = (-param.b - sqrtf(param.discr)) / (2 * param.a);
	if (fabs(param.t0) > fabs(param.t1))
		param.t0 = param.t1;
	if (param.t0 < 0)
		return (0);
	else if (param.t0 < *min)
		*min = param.t0;
	return (param.t0);
}
