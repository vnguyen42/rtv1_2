/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_touch_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 17:58:21 by vnguyen           #+#    #+#             */
/*   Updated: 2016/04/11 17:59:33 by vnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void	string_mlx(t_thread *t)
{
	mlx_string_put(t->tool->mlx_ptr, t->tool->mlx_win,
			0, 0, 0x00CC6600, "Coordonnees cam :");
	mlx_string_put(t->tool->mlx_ptr, t->tool->mlx_win,
			0, 17, 0x00CC6600, "x =");
	mlx_string_put(t->tool->mlx_ptr, t->tool->mlx_win, 40,
			17, 0x00CC6600, ft_itof(t->x));
	mlx_string_put(t->tool->mlx_ptr, t->tool->mlx_win, 0,
			34, 0x00CC6600, "y =");
	mlx_string_put(t->tool->mlx_ptr, t->tool->mlx_win, 40,
			34, 0x00CC6600, ft_itof(t->y));
	mlx_string_put(t->tool->mlx_ptr, t->tool->mlx_win, 0,
			51, 0x00CC6600, "z =");
	mlx_string_put(t->tool->mlx_ptr, t->tool->mlx_win, 40,
			51, 0x00CC6600, ft_itoa(t->z));
}

void	thread_on_or_off(int keycode, t_thread *t)
{
	if (keycode == 49)
	{
		if (t->yes == 0)
			t->yes = 1;
		else
			t->yes = 0;
		run_through(t);
	}
}

void	touch_rotate_suite(int keycode, t_thread *t)
{
	if (keycode == 126)
	{
		t->y--;
		t->tool->cam->pos->y -= 0.1;
	}
	if (keycode == 125)
	{
		t->y++;
		t->tool->cam->pos->y += 0.1;
		run_through(t);
	}
	if (keycode == 123)
	{
		t->x++;
		t->tool->cam->pos->x += 0.1;
		run_through(t);
	}
	if (keycode == 124)
	{
		t->x--;
		t->tool->cam->pos->x -= 0.1;
		run_through(t);
	}
}

int		touch_rotate(int keycode, t_thread *t)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 78 && t->z > 0)
	{
		t->z--;
		t->tool->cam->pos->z -= 1;
		run_through(t);
	}
	if (keycode == 69)
	{
		t->z++;
		t->tool->cam->pos->z += 1;
		run_through(t);
	}
	thread_on_or_off(keycode, t);
	touch_rotate_suite(keycode, t);
	string_mlx(t);
	return (0);
}
