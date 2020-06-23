/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 06:37:19 by aahizi-e          #+#    #+#             */
/*   Updated: 2019/10/03 08:12:19 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include "libft/libft.h"
# include <stdlib.h>
# include "minilibx_macos/mlx.h"
# include <pthread.h>

# define W 800
# define H 500
# define ESCAPE 256 * 256
# define THREAD 4
# define DEPTH 300
# define LINESIZE H / THREAD
# define SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

typedef	struct		s_complex
{
	float			r;
	float			i;
}					t_complex;

typedef struct		s_convert
{
	float			f;
	float			p;
	float			q;
	float			t;
}					t_convert;

typedef	struct		s_rgb
{
	float			red;
	float			grn;
	float			blu;
}					t_rgb;

typedef	struct		s_hsv
{
	float			hue;
	float			sat;
	float			val;
}					t_hsv;

typedef float		(*t_function_p)(void *, t_complex, t_complex);

typedef struct		s_fractal_cf
{
	t_complex		z;
	t_complex		c;
	float			unit;
	int				n_color;
	int				is_moving;
	float			iteration;
	t_complex		center;
	t_complex		mp;
	t_function_p	fun_fract;
	int				type;
}					t_fractal_cf;

typedef struct		s_img
{
	int				bpp;
	int				size_l;
	int				endian;
	char			*data_p;
	void			*img_p;
}					t_img;

typedef struct		s_thread_cf
{
	int				y_min;
	int				y_max;
	t_img			img;
	t_fractal_cf	fc;
}					t_thread_cf;

typedef struct		s_mlx
{
	t_fractal_cf	*fc;
	t_img			img;
	void			*win_p;
	void			*mlx_p;
}					t_mlx;

typedef struct		s_fractol
{
	int				num;
	char			*name;
	t_function_p	fun_fract;
}					t_fractol;

/*
**		main.c
*/

int					display_help(void);
void				mlx_connect(t_mlx *mlx);
void				set_fractal_conf(t_mlx *mlx, t_fractal_cf *fc, char *name);
int					thread_init(t_mlx *mlx);

/*
**		helper.c
*/

int					ft_mandelbrot_check(t_complex z, t_complex z_squared);
float				ft_reflection(t_complex dc, t_complex z, float reflection);
void				hsv2rgb(t_hsv hsv, t_rgb *rgb);
void				ft_color(t_fractal_cf *fc, t_thread_cf *tc, int x, int y);
void				*calculate(void *param);

/*
**		fractals.c
*/

void				calc_fpqt(t_hsv hsv, int i, t_convert *fpqt);
float				ft_mandelbrot(void *param, t_complex z, t_complex c);
float				ft_julia(void *param, t_complex z, t_complex c);
float				ft_julia2(void *param, t_complex z, t_complex c);
float				ft_julia3(void *param, t_complex z, t_complex c);
float				ft_julia4(void *param, t_complex z, t_complex c);
float				ft_burning_ship(void *param, t_complex z, t_complex c);
float				ft_mandel_map_effect(void *param, t_complex z, t_complex c);
float				ft_julia_map_effect(void *param, t_complex z, t_complex c);

/*
**		complex_calculator.c
*/

t_complex			complex_add(t_complex n1, t_complex n2);
t_complex			complex_sub(t_complex n1, t_complex n2);
t_complex			complex_mul(t_complex n1, t_complex n2);
t_complex			complex_div(t_complex n1, t_complex n2);
t_complex			complex_abs(t_complex n);

/*
**		hook_functions.c
*/

void				ft_get_func(int key, char *s, t_fractal_cf *fc);
int					mouse_press(int button, int x, int y, void *param);
int					key_press(int key, void *param);
int					mouse_move(int x, int y, void *param);

/*
**		globals.c
*/

static t_fractol	g_fractal_list[] = {
	{18, "Mandelbrot", &ft_mandelbrot},
	{19, "Julia", &ft_julia},
	{20, "Julia 2", &ft_julia2},
	{21, "Julia 3", &ft_julia3},
	{23, "Julia 4", &ft_julia4},
	{22, "Burning ship", &ft_burning_ship},
	{28, "Mandelbrot map effect", &ft_mandel_map_effect},
	{25, "Julia map effect", &ft_julia_map_effect}
};

static const int	g_palette[7][3] = {
	{0, 1, 2},
	{0, 2, 1},
	{1, 0, 2},
	{1, 2, 0},
	{2, 1, 0},
	{2, 0, 1},
};

#endif
