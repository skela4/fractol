/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 19:31:41 by aahizi-e          #+#    #+#             */
/*   Updated: 2019/10/03 08:15:07 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int					ft_mandelbrot_check(t_complex z, t_complex zz)
{
	float			q;
	float			tmp;
	float			tmp2;

	tmp = z.r - 0.25f;
	q = tmp * tmp + zz.i;
	q *= (q + tmp);
	tmp2 = z.r + 1.0f;
	return (q < 0.25 * zz.i || tmp2 * tmp2 + zz.i < 0.0625f);
}

float				ft_reflection(t_complex dc, t_complex z, float rflct)
{
	t_complex		u;

	u = complex_div(z, dc);
	u = complex_div(u, complex_abs(u));
	rflct = (u.i * 0.707107f) + 1.5f;
	rflct = complex_div((t_complex){rflct, 0.0f}, (t_complex){2.5f, 0.0f}).r;
	rflct = (rflct < 0.0f) ? 0.0f : rflct;
	return (rflct);
}

void				hsv2rgb(t_hsv hsv, t_rgb *rgb)
{
	t_convert		fpqt;
	int				i;

	hsv.hue = 6 * (hsv.hue - floor(hsv.hue));
	i = floor(hsv.hue);
	calc_fpqt(hsv, i, &fpqt);
	if (i == 0)
		*rgb = (t_rgb){hsv.val, fpqt.t, fpqt.p};
	else if (i == 1)
		*rgb = (t_rgb){fpqt.q, hsv.val, fpqt.p};
	else if (i == 2)
		*rgb = (t_rgb){fpqt.p, hsv.val, fpqt.t};
	else if (i == 3)
		*rgb = (t_rgb){fpqt.p, fpqt.q, hsv.val};
	else if (i == 4)
		*rgb = (t_rgb){fpqt.t, fpqt.p, hsv.val};
	else
		*rgb = (t_rgb){hsv.val, fpqt.p, fpqt.q};
	*rgb = (t_rgb){rgb->red * 255, rgb->grn * 255, rgb->blu * 255};
}

void				ft_color(t_fractal_cf *fc, t_thread_cf *tc, int x, int y)
{
	double			iteration;
	int				pos;
	t_hsv			hsv;
	t_rgb			rgb;

	hsv.hue = 0.0f;
	hsv.sat = 0.7f;
	hsv.val = 1.0f;
	pos = 4 * (y * W + x);
	iteration = fc->fun_fract(fc, fc->c, fc->c);
	if (!fc->type && iteration != DEPTH)
		hsv.hue = iteration / 64.0f;
	else if (fc->type && iteration != FP_ZERO)
		hsv.hue = iteration / 8.0f;
	else
		hsv.val = 0.0f;
	if (hsv.val != 0.0)
		hsv2rgb(hsv, &rgb);
	else
		rgb = (t_rgb){hsv.val, hsv.val, hsv.val};
	tc->img.data_p[g_palette[fc->n_color % 6][0] + pos] = rgb.blu;
	tc->img.data_p[g_palette[fc->n_color % 6][1] + pos] = rgb.grn;
	tc->img.data_p[g_palette[fc->n_color % 6][2] + pos] = rgb.red;
}

void				*calculate(void *param)
{
	int				y;
	int				x;
	t_thread_cf		*tc;

	tc = (t_thread_cf *)param;
	y = tc->y_min;
	while (y < tc->y_max)
	{
		x = 0;
		while (x < W)
		{
			tc->fc.c.r = 4 * (x - tc->fc.center.r) / tc->fc.unit;
			tc->fc.c.i = -4 * (y - tc->fc.center.i) / tc->fc.unit;
			ft_color(&(tc->fc), tc, x, y);
			x += 1;
		}
		y += 1;
	}
	return (NULL);
}
