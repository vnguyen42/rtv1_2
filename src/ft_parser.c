/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 17:00:54 by vnguyen           #+#    #+#             */
/*   Updated: 2016/04/11 17:01:07 by vnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void	parse_camera(t_tool *tools, int fd)
{
	char	**split;
	char	*line;

	tools->cam = malloc(sizeof(t_cam));
	init_camera(tools);
	while (get_next_line(fd, &line) > 0 && ft_strcmp(line, "}"))
	{
		split = ft_strsplit(line, ' ');
		if (ft_strstr(line, "pos:"))
			tools->cam->pos = fill_pos(split);
		else if (ft_strstr(line, "res:"))
		{
			if (ft_tablen(split) != 3)
				ft_error(7);
			if (str_digit(split[1]) || str_digit(split[2]))
				ft_error(2);
			if (ft_atoi(split[1]) < 0 || ft_atoi(split[2]) < 0)
				ft_error(8);
			tools->cam->x_res = ft_atoi(split[1]);
			tools->cam->y_res = ft_atoi(split[2]);
		}
		else if (ft_strcmp(line, "{"))
			ft_error(1);
	}
}

void	parse_object(t_tool *tools, int fd)
{
	t_object	*object;
	char		*line;
	char		**split;

	object = malloc(sizeof(*object));
	init_object(object);
	while (get_next_line(fd, &line) != 0 && ft_strcmp(line, "}"))
	{
		split = ft_strsplit(line, ' ');
		if (ft_strstr(line, "type:"))
			object->type = object_type(split);
		else if (ft_strstr(line, "pos:"))
			object->o = fill_pos(split);
		else if (ft_strstr(line, "dir:"))
			object->d = fill_pos(split);
		else if (ft_strstr(line, "rayon:"))
		{
			if (ft_tablen(split) != 2 || str_digit(split[1]))
				ft_error(9);
			object->rad = ft_atof(split[1]);
		}
		else
			parse_object_suite(object, &line, split);
	}
	add_object(&tools->l_objects, object);
}

void	parse_object_suite(t_object *object, char **line, char **split)
{
	if (ft_strstr(*line, "color:"))
		object->color = fill_color(split);
	else if (ft_strstr(*line, "h:"))
	{
		if (ft_tablen(split) != 2)
			ft_error(7);
		if (str_digit(split[1]))
			ft_error(2);
		object->h = ft_atof(split[1]);
	}
	else if (ft_strstr(*line, "shiny:"))
	{
		if (ft_tablen(split) != 2)
			ft_error(7);
		if (str_digit(split[1]))
			ft_error(2);
		object->shiny = ft_atof(split[1]);
	}
	else if (ft_strcmp(*line, "{"))
		ft_error(4);
}

void	parse_light(t_tool *tools, int fd)
{
	char	**split;
	char	*line;
	t_light	*light;

	light = malloc(sizeof(*light));
	init_light(light);
	while (get_next_line(fd, &line) > 0 && !ft_strstr(line, "}"))
	{
		split = ft_strsplit(line, ' ');
		if (ft_strstr(line, "pos:"))
			light->o = fill_pos(split);
		else if (ft_strstr(line, "color:"))
			light->color = fill_color(split);
		else if (ft_strstr(line, "dist:"))
		{
			if (ft_tablen(split) != 2)
				ft_error(7);
			if (str_digit(split[1]))
				ft_error(2);
			light->dist = ft_atof(split[1]);
		}
		else if (ft_strcmp(line, "{"))
			ft_error(3);
	}
	add_light(&tools->l_lights, light);
}

t_tool	*parser(int fd)
{
	t_tool	*tools;
	char	*line;
	int		c;

	c = 0;
	tools = malloc(sizeof(*tools));
	tools->l_objects = NULL;
	tools->l_lights = NULL;
	while (get_next_line(fd, &line) != 0)
	{
		if (!ft_strcmp(line, "camera"))
		{
			c++;
			parse_camera(tools, fd);
		}
		else if (!ft_strcmp(line, "light"))
			parse_light(tools, fd);
		else if (!ft_strcmp(line, "object"))
			parse_object(tools, fd);
	}
	if (c != 1)
		ft_error(6);
	return (tools);
}
