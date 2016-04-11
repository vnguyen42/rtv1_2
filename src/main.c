/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 16:29:23 by vnguyen           #+#    #+#             */
/*   Updated: 2016/04/11 16:29:45 by vnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void	init_param(t_tool *t)
{
	t->mlx_ptr = mlx_init();
	t->lumamb = 0.2;
	t->cam->indent = 0.001;
	t->cam->dist = 1;
	t->cam->w = t->cam->x_res * t->cam->indent;
	t->cam->h = t->cam->y_res * t->cam->indent;
	t->mlx_win = mlx_new_window(t->mlx_ptr, t->cam->x_res,
			t->cam->y_res, "RTv1");
	t->mlx_img = mlx_new_image(t->mlx_ptr, t->cam->x_res, t->cam->y_res);
	t->image = malloc(sizeof(t_image));
	t->image->data = mlx_get_data_addr(t->mlx_img, &t->image->bpp,
			&t->image->size_line, &t->image->endian);
	t->cam->vect = vectornew(0, 0, 1);
	t->cam->h_vect = vectornew(0, 1, 0);
	t->cam->r_vect = vectornew(1, 0, 0);
	t->cam->upleft = malloc(sizeof(t_pos));
	t->cam->upleft->x = t->cam->pos->x + t->cam->vect->x * t->cam->dist +
		t->cam->h_vect->x * (t->cam->h / 2) - t->cam->r_vect->x * (t->cam->w / 2);
	t->cam->upleft->y = t->cam->pos->y + t->cam->vect->y * t->cam->dist +
		t->cam->h_vect->y * (t->cam->h / 2) - t->cam->r_vect->y * (t->cam->w / 2);
	t->cam->upleft->z = t->cam->pos->z + t->cam->vect->z * t->cam->dist +
		t->cam->h_vect->z * (t->cam->h / 2) - t->cam->r_vect->z * (t->cam->w / 2);
}

void	run_through(t_thread *thread)
{
	if (thread->yes == 0)
		no_thread(thread);
	if (thread->yes == 1)
		yes_thread(thread);
}

int		main(int argc, char **argv)
{
	t_thread	*thread;
	int			fd;

	thread = malloc(sizeof(t_thread));
	if (argc != 2)
	{
		ft_putendl("Bad number of arguments");
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putendl("Error, file can't be open");
		return (1);
	}
	thread->x = 0;
	thread->y = 0;
	thread->z = 0;
	thread->yes = 0;
	thread->tool = parser(fd);
	init_param(thread->tool);
	run_through(thread);
	mlx_key_hook(thread->tool->mlx_win, touch_rotate, thread);
	mlx_loop(thread->tool->mlx_ptr);
	return (0);
}
