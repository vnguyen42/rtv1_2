/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multithreading.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 18:21:08 by vnguyen           #+#    #+#             */
/*   Updated: 2016/04/11 18:21:14 by vnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

int		gcd(int a, int b)
{
	int c;

	while (a != 0)
	{
		c = a;
		a = b % a;
		b = c;
	}
	return (b);
}

void	no_thread(t_thread *t)
{
	double x;
	double y;

	y = 0;
	while (y < t->tool->cam->y_res)
	{
		x = 0;
		while (x < t->tool->cam->x_res)
		{
			draw(t->tool, x, y);
			x += 1;
		}
		y += 1;
	}
	mlx_put_image_to_window(t->tool->mlx_ptr,
			t->tool->mlx_win, t->tool->mlx_img, 0, 0);
}

void	yes_thread(t_thread *thread)
{
	t_thread	*threads;
	int			thr_n;
	int			thread_runner;
	int			thread_size;

	thr_n = gcd((int)thread->tool->cam->x_res, (int)thread->tool->cam->y_res);
	if (!(threads = (t_thread *)malloc(sizeof(t_thread) * thr_n)))
		exit(0);
	thread_size = thread->tool->cam->y_res / thr_n;
	thread_runner = -1;
	while (++thread_runner < thr_n)
	{
		threads[thread_runner].tool = thread->tool;
		threads[thread_runner].thread_number = thread_runner;
		threads[thread_runner].thread_size = thread_size;
		pthread_create(&threads[thread_runner].pth, NULL, thread1,
				&threads[thread_runner]);
	}
	thread_runner = -1;
	while (++thread_runner < thr_n)
		pthread_join(threads[thread_runner].pth, NULL);
	mlx_put_image_to_window(thread->tool->mlx_ptr,
			thread->tool->mlx_win, thread->tool->mlx_img, 0, 0);
	free(threads);
}

void	*thread1(void *thread_data)
{
	double			limit_y;
	double			limit_z;
	double			x;
	t_thread		*thread;
	t_color			t;

	thread = (t_thread *)thread_data;
	limit_y = thread->thread_number * thread->thread_size;
	limit_z = limit_y + thread->thread_size;
	t.b = 55;
	t.g = 55;
	t.r = 55;
	while (limit_y < limit_z)
	{
		x = 0;
		while (x < thread->tool->cam->x_res)
		{
			draw(thread->tool, x, limit_y);
			x += 1;
		}
		limit_y++;
	}
	return (NULL);
}
