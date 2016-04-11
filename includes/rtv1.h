/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 16:00:11 by vnguyen           #+#    #+#             */
/*   Updated: 2016/04/11 17:55:49 by vnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
#define RTV1_H
# include "mlx.h"
# include <math.h>
# include <fcntl.h>
# include <pthread.h>
# include <semaphore.h>
# include "libft.h"
# define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
# define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))
# define SPHERE 0
# define CYL 1
# define CONE 2
# define PLAN 3
# define E -0.000001

typedef struct	s_equation
{
	double	a;
	double	b;
	double	c;
	double discr;
	double t1;
	double t0;
}				t_equation;

typedef struct	s_color
{
	double r;
	double g;
	double b;
}				t_color;

typedef struct	s_pos
{
	double x;
	double y;
	double z;
}				t_pos;

typedef struct	s_object
{
	int				type;
	double			dist;
	t_color			*color;
	t_pos			*o;
	t_pos			*d;
	double			rad;
	double			h;
	double			shiny;
	int				mirror;
	struct s_object	*next;
}					t_object;

typedef struct	s_ray
{
	t_pos	*o;
	t_pos	*d;
}			t_ray;

typedef	struct	s_light
{
	t_pos	*o;
	t_color	*color;
	double dist;
	struct s_light *next;
}			t_light;

typedef struct s_cam
{
	t_pos *pos;
	t_pos *h_vect;
	t_pos *r_vect;
	t_pos *vect;
	double			dist;
	double			w;
	double			h;
	t_pos			*upleft;
	double			x_res;
	double			y_res;
	double			indent;
}					t_cam;

typedef struct		s_image
{
	int				endian;
	int				size_line;
	int				bpp;
	char			*data;
}					t_image;

typedef struct		s_tool
{
	void			*mlx_ptr;
	void			*mlx_win;
	void			*mlx_img;
	t_object		*l_objects;
	t_light			*l_lights;
	t_image			*image;
	t_cam			*cam;
	double			lumamb;
}					t_tool;

typedef struct		s_thread
{
	pthread_t		pth;
	t_tool			*tool;
	int				thread_size;
	int				thread_number;
	int				x;
	int				y;
	int				z;
	int				yes;
}					t_thread;

typedef struct		s_draw_suite
{
	t_object		*curobject;
	t_object		*curobject2;
	t_color			*final_color;
	t_ray			*lightray;
	t_ray			*impact;
	t_light			*curlight;
	t_pos			*reflectray;
	t_pos			*invlight;
	double			kdiff;
	double			kspec;
}					t_draw_suite;

t_object			*intersection(t_object *l_objects, t_ray *ray);
double				intersection_plan(t_object *plan, t_ray *ray, double *coef);
double				intersection_sphere(t_object *sphere,
		t_ray *ray, double *coef);
double				intersection_cone(t_object *cone, t_ray *ray, double *coef);
double				intersection_cyl(t_object *cyl, t_ray *ray, double *coef);
void				pixel_put_to_image(t_tool *t, int x, int y, t_color *color);
t_color				*draw_suite(t_ray *ray, t_tool *t);
t_ray				*get_ray(t_tool *t, double x, double y);
void				draw(t_tool *t, double x, double y);
void				find_normal(t_ray *impact, t_object *object);
void				vectornorm(t_pos *v);
t_pos				*vectorsub(t_pos *v1, t_pos *v2);
double				vectordot(t_pos *v1, t_pos *v2);
t_pos				*vectorscale(double c, t_pos *v);
t_pos				*vectoradd(t_pos *v1, t_pos *v2);
t_pos				*vectorcopy(t_pos *v1);
t_pos				*vectornew(double x, double y, double z);
t_pos				*rotation(t_pos *axe, t_pos *vect);
t_tool				*parser(int fd);
void				parse_light(t_tool *tools, int fd);
void				parse_object(t_tool *tools, int fd);
void				parse_camera(t_tool *tools, int fd);
void				parse_object_suite(t_object *object,
		char **line, char **split);
void				add_object(t_object **l_objects, t_object *new);
void				add_light(t_light **l_lights, t_light *new);
int					object_type(char **split);
t_pos				*fill_pos(char **split);
t_color				*fill_color(char **split);
t_color				*new_color();
void				init_color(t_tool *t, t_color *objcolor,
		t_color *final_color);
void				update_color(double k, t_color *lightcolor,
		t_color *final_color, t_color *objcolor);
void				normalize_color(t_color *final_color);
void				add_color(t_color *color1, t_color *color2);
void				div_color(t_color *color, float n);
void				ft_error(int i);
void				init_camera(t_tool *tools);
void				init_light(t_light *light);
void				init_object(t_object *object);
void				no_thread(t_thread *t);
void				yes_thread(t_thread *t);
void				*thread1(void *thread_data);
int					touch_rotate(int keycode, t_thread *t);
void				run_through(t_thread *thread);
double				calcule(t_ray *ray, t_object *cyl, double k);
void				verife(t_object *tmp, t_ray *ray, double *min);
void				ft_impact(t_draw_suite *val, t_ray *ray, t_tool *t);

#endif

