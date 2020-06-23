/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 19:31:41 by aahizi-e          #+#    #+#             */
/*   Updated: 2019/10/02 08:28:54 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int			exit_program(t_mlx *mlxp)
{
	(void)mlxp;
	exit(EXIT_SUCCESS);
}

int					mouse_press(int button, int x, int y, void *param)
{
	t_mlx			*mlxp;

	mlxp = (t_mlx *)param;
	if (button == 5)
	{
		mlxp->fc->center.r = (mlxp->fc->center.r - x) *\
							(mlxp->fc->unit * 1.1) / mlxp->fc->unit + x;
		mlxp->fc->center.i = (mlxp->fc->center.i - y) *\
							(mlxp->fc->unit * 1.1) / mlxp->fc->unit + y;
		mlxp->fc->unit *= 1.1;
	}
	else if (button == 4 && mlxp->fc->unit > 1.0f)
	{
		mlxp->fc->center.r = (mlxp->fc->center.r - x) *\
							(mlxp->fc->unit / 1.1) / mlxp->fc->unit + x;
		mlxp->fc->center.i = (mlxp->fc->center.i - y) *\
							(mlxp->fc->unit / 1.1) / mlxp->fc->unit + y;
		mlxp->fc->unit /= 1.1;
	}
	thread_init(mlxp);
	mlx_put_image_to_window(mlxp->mlx_p, mlxp->win_p, mlxp->img.img_p, 0, 0);
	return (0);
}

void				ft_get_func(int key, char *s, t_fractal_cf *fc)
{
	int				i;

	i = -1;
	if ((key >= 18 && key <= 23) || key == 25 || key == 26 || key == 28 || s)
	{
		if (s && ft_strstr(s, "map"))
			fc->type = 1;
		else
			fc->type = 0;
		while (++i < SIZE(g_fractal_list))
		{
			if (s && !ft_strcmp(g_fractal_list[i].name, s))
				fc->fun_fract = g_fractal_list[i].fun_fract;
			if (key == g_fractal_list[i].num)
			{
				fc->fun_fract = g_fractal_list[i].fun_fract;
				if (ft_strstr(g_fractal_list[i].name, "map"))
					fc->type = 1;
				else
					fc->type = 0;
			}
		}
	}
}

int					key_press(int key, void *param)
{
	t_mlx			*mlxp;

	mlxp = (t_mlx*)param;
	ft_get_func(key, NULL, mlxp->fc);
	if (!mlxp->fc->fun_fract)
		display_help();
	if (key == 46)
		mlxp->fc->is_moving = !mlxp->fc->is_moving;
	if (key == 49)
		mlxp->fc->n_color += 1;
	if (key == 53)
		exit_program(mlxp);
	if (key == 125 || key == 126)
		(mlxp->fc->center).i += (key == 125 ? 10 : -10);
	else if (key == 123 || key == 124)
		(mlxp->fc->center).r += (key == 124 ? 10 : -10);
	thread_init(mlxp);
	mlx_put_image_to_window(mlxp->mlx_p, mlxp->win_p, mlxp->img.img_p, 0, 0);
	return (0);
}

int					mouse_move(int x, int y, void *param)
{
	t_mlx			*mlxp;
	float			angle;

	mlxp = (t_mlx*)param;
	if (mlxp->fc->is_moving && x >= 0 && x <= W && y >= 0 && y < H)
	{
		mlxp->fc->mp.r = 4 * (x - mlxp->fc->center.r) / mlxp->fc->unit;
		mlxp->fc->mp.i = -4 * (y - mlxp->fc->center.i) / mlxp->fc->unit;
	}
	thread_init(mlxp);
	mlx_put_image_to_window(mlxp->mlx_p, mlxp->win_p, mlxp->img.img_p, 0, 0);
	return (0);
}
