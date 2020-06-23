/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 07:22:47 by aahizi-e          #+#    #+#             */
/*   Updated: 2019/10/02 08:08:53 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				calc_fpqt(t_hsv hsv, int i, t_convert *fpqt)
{
	fpqt->f = hsv.hue - i;
	fpqt->p = hsv.val * (1 - hsv.sat);
	fpqt->q = hsv.val * (1 - (hsv.sat * fpqt->f));
	fpqt->t = hsv.val * (1 - (hsv.sat * (1 - fpqt->f)));
}

float				ft_burning_ship(void *param, t_complex z, t_complex c)
{
	float			i;
	t_complex		zsq;

	(void)param;
	i = 0.0f;
	zsq = (t_complex){z.r * z.r, z.i * z.i};
	while (zsq.r + zsq.i <= ESCAPE && i < DEPTH)
	{
		z.i = z.r * z.i;
		z.i += z.i;
		z.i = fabs(z.i);
		z.i += -c.i;
		z.r = zsq.r - zsq.i + c.r;
		z.r = fabs(z.r);
		zsq = (t_complex){z.r * z.r, z.i * z.i};
		i += 1.0f;
	}
	if (i == DEPTH)
		return (DEPTH);
	return (i - log2(log2(zsq.r + zsq.i)) + 4.0f);
}

float				ft_mandel_map_effect(void *param, t_complex z, t_complex c)
{
	int				i;
	float			reflection;
	t_complex		zsq;
	t_complex		dc;

	(void)param;
	i = -1.0f;
	dc = (t_complex){0.0f, 0.0f};
	reflection = FP_ZERO;
	zsq = (t_complex){z.r * z.r, z.i * z.i};
	if (ft_mandelbrot_check(z, zsq))
		return (FP_ZERO);
	while (zsq.r + zsq.i <= ESCAPE && ++i < DEPTH)
	{
		dc = complex_mul(dc, (t_complex){2.0f, 0.0f});
		dc = complex_add(complex_mul(dc, z), (t_complex){1.0f, 0.0f});
		z.i = z.r * z.i;
		z.i += z.i;
		z.i += c.i;
		z.r = zsq.r - zsq.i + c.r;
		zsq = (t_complex){z.r * z.r, z.i * z.i};
	}
	if (zsq.r + zsq.i > ESCAPE)
		reflection = ft_reflection(dc, z, reflection);
	return (reflection);
}

float				ft_julia_map_effect(void *param, t_complex z, t_complex c)
{
	int				i;
	float			reflection;
	t_complex		zsq;
	t_complex		dc;

	i = -1;
	dc = (t_complex){0.0f, 0.0f};
	reflection = FP_ZERO;
	zsq = (t_complex){z.r * z.r, z.i * z.i};
	while (zsq.r + zsq.i <= ESCAPE && ++i < DEPTH)
	{
		dc = complex_mul(dc, (t_complex){2.0f, 0.0f});
		dc = complex_add(complex_mul(dc, z), (t_complex){1.0f, 0.0f});
		z.i = z.r * z.i;
		z.i += z.i;
		z.i += ((t_fractal_cf *)param)->mp.i;
		z.r = zsq.r - zsq.i + ((t_fractal_cf *)param)->mp.r;
		zsq = (t_complex){z.r * z.r, z.i * z.i};
	}
	if (zsq.r + zsq.i > ESCAPE)
		reflection = ft_reflection(dc, z, reflection);
	return (reflection);
}
