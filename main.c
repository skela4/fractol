/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 19:31:41 by aahizi-e          #+#    #+#             */
/*   Updated: 2019/10/02 08:37:58 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int					display_help(void)
{
	int				i;

	i = 0;
	ft_putstr("Usage: ./fractol ");
	while (i < SIZE(g_fractal_list))
	{
		ft_putstr(g_fractal_list[i].name);
		if (i + 1 < SIZE(g_fractal_list))
			ft_putstr(" | ");
		else
			ft_putchar('\n');
		i += 1;
	}
	exit(EXIT_FAILURE);
}

void				mlx_connect(t_mlx *mlx)
{
	mlx->mlx_p = mlx_init();
	mlx->win_p = mlx_new_window(mlx->mlx_p, W, H, "fractol");
	mlx->img.img_p = mlx_new_image(mlx->mlx_p, W, H);
	mlx->img.data_p = mlx_get_data_addr(\
	mlx->img.img_p, &mlx->img.bpp, &mlx->img.size_l, &mlx->img.endian);
}

void				set_fractal_conf(t_mlx *mlx, t_fractal_cf *fc, char *name)
{
	fc->type = 0;
	fc->fun_fract = NULL;
	ft_get_func(0, name, fc);
	if (!fc->fun_fract)
		display_help();
	fc->c = (t_complex){0.0f, 0.0f};
	fc->z = (t_complex){0.0f, 0.0f};
	fc->center.r = W / 2;
	fc->center.i = H / 2;
	fc->n_color = 0;
	fc->is_moving = 1;
	fc->unit = (W < H) ? W : H;
	mlx->fc = fc;
}

int					thread_init(t_mlx *mlx)
{
	int				i;
	pthread_t		threads[THREAD];
	t_thread_cf		tcs[THREAD];

	i = 0;
	while (i < THREAD)
	{
		tcs[i].y_min = i * LINESIZE;
		tcs[i].y_max = (i + 1) * LINESIZE;
		tcs[i].img = mlx->img;
		tcs[i].fc = *(mlx->fc);
		pthread_create(&(threads[i]), NULL, calculate, &(tcs[i]));
		i += 1;
	}
	pthread_join(threads[0], NULL);
	pthread_join(threads[1], NULL);
	pthread_join(threads[2], NULL);
	pthread_join(threads[3], NULL);
	return (0);
}

int					main(int argc, char **argv)
{
	t_mlx			mlx;
	t_fractal_cf	fc;

	if (argc != 2)
		display_help();
	set_fractal_conf(&mlx, &fc, argv[1]);
	mlx_connect(&mlx);
	thread_init(&mlx);
	mlx_put_image_to_window(mlx.mlx_p, mlx.win_p, mlx.img.img_p, 0, 0);
	mlx_hook(mlx.win_p, 2, 0, &key_press, (void*)(&mlx));
	mlx_hook(mlx.win_p, 4, 0, &mouse_press, (void *)&mlx);
	mlx_hook(mlx.win_p, 6, 0, &mouse_move, (void*)(&mlx));
	mlx_loop(mlx.mlx_p);
	return (0);
}
