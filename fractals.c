/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 19:31:41 by aahizi-e          #+#    #+#             */
/*   Updated: 2019/10/03 07:21:35 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

float				ft_mandelbrot(void *param, t_complex z, t_complex c)
{
	float			i;
	t_complex		zsq;

	(void)param;
	i = 0.0f;
	zsq = (t_complex){z.r * z.r, z.i * z.i};
	if (ft_mandelbrot_check(z, zsq))
		return (DEPTH);
	while (zsq.r + zsq.i <= ESCAPE && i < DEPTH)
	{
		z.i = z.r * z.i;
		z.i += z.i;
		z.i += c.i;
		z.r = zsq.r - zsq.i + c.r;
		zsq = (t_complex){z.r * z.r, z.i * z.i};
		i += 1.0f;
	}
	if (i == DEPTH)
		return (DEPTH);
	return (i - log2(log2(zsq.r + zsq.i)) + 4.0f);
}

float				ft_julia(void *param, t_complex z, t_complex c)
{
	float			i;
	t_complex		zsq;
	t_fractal_cf	*fc;

	i = 0.0f;
	fc = (t_fractal_cf *)param;
	zsq = (t_complex){z.r * z.r, z.i * z.i};
	while (zsq.r + zsq.i <= ESCAPE && i < DEPTH)
	{
		z.i = z.r * z.i;
		z.i += z.i;
		z.i += fc->mp.i;
		z.r = zsq.r - zsq.i + fc->mp.r;
		zsq = (t_complex){z.r * z.r, z.i * z.i};
		i += 1.0f;
	}
	if (i == DEPTH)
		return (DEPTH);
	return (i - log2(log2(zsq.r + zsq.i)) + 4.0f);
}

float				ft_julia2(void *param, t_complex z, t_complex c)
{
	float			i;
	t_complex		zsq;
	t_complex		tmp;
	t_fractal_cf	*fc;
	float			zz;

	i = 1.0f;
	fc = (t_fractal_cf *)param;
	zsq = (t_complex){z.r * z.r, z.i * z.i};
	while (zsq.r + zsq.i <= ESCAPE && i < DEPTH)
	{
		zz = (zsq.r + zsq.i);
		tmp.r = zsq.r - zsq.i + fc->mp.r * z.r / zz + fc->mp.i * z.i / zz;
		tmp.i = 2 * z.r * z.i - fc->mp.r * z.i / zz + fc->mp.i * z.r / zz;
		z = tmp;
		zsq = (t_complex){z.r * z.r, z.i * z.i};
		i += 1.0f;
	}
	if (i == DEPTH)
		return (DEPTH);
	return (i - log2(log2(zsq.r + zsq.i)) + 4.0f);
}

float				ft_julia3(void *param, t_complex z, t_complex c)
{
	float			i;
	t_complex		zsq;
	t_complex		tmp;
	t_fractal_cf	*fc;
	float			zz;

	i = -1.0f;
	fc = (t_fractal_cf *)param;
	zsq = (t_complex){z.r * z.r, z.i * z.i};
	while (zsq.r + zsq.i <= ESCAPE && ++i < DEPTH)
	{
		zz = (zsq.r + zsq.i);
		z.i = z.r * z.i - fc->mp.r * z.i / zz + fc->mp.i * z.r / zz;
		z.i += z.i;
		z.r = zsq.r - zsq.i + fc->mp.r * z.r / zz + fc->mp.i * z.i / zz;
		zsq = (t_complex){z.r * z.r, z.i * z.i};
	}
	if (i == DEPTH)
		return (DEPTH);
	return (i - log2(log2(zsq.r + zsq.i)) + 4.0f);
}

float				ft_julia4(void *param, t_complex z, t_complex c)
{
	float			i;
	t_complex		zsq;
	t_complex		tmp;
	t_fractal_cf	*fc;
	float			zz;

	i = -1.0f;
	fc = (t_fractal_cf *)param;
	zsq = (t_complex){z.r * z.r, z.i * z.i};
	while (zsq.r + zsq.i <= ESCAPE && ++i < DEPTH)
	{
		zz = (pow((z.r * z.r - z.i * z.i), 2) - 4 * z.r * z.r * z.i * z.i) * 10;
		tmp.r = z.r * z.r - z.i * z.i + fc->mp.r * (z.r * z.r - z.i * z.i) /\
		zz + fc->mp.i * 2 * z.r * z.i / zz;
		tmp.i = 2 * z.r * z.i - fc->mp.r * 2 * z.r * z.i /\
		zz + fc->mp.i * (z.r * z.r - z.i * z.i) / zz;
		z = tmp;
		zsq = (t_complex){z.r * z.r, z.i * z.i};
		i++;
	}
	if (i == DEPTH)
		return (DEPTH);
	return (i - log2(log2(zsq.r + zsq.i)) + 4.0f);
}
