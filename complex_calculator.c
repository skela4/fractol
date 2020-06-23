/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_calculator.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 19:31:41 by aahizi-e          #+#    #+#             */
/*   Updated: 2019/10/02 07:22:06 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex			complex_add(t_complex n1, t_complex n2)
{
	return ((t_complex){n1.r + n2.r, n1.i + n2.i});
}

t_complex			complex_sub(t_complex n1, t_complex n2)
{
	return ((t_complex){n1.r - n2.r, n1.i - n2.i});
}

t_complex			complex_mul(t_complex n1, t_complex n2)
{
	return ((t_complex){(n1.r * n2.r) - (n1.i * n2.i),\
	n1.r * n2.i + n2.r * n1.i});
}

t_complex			complex_div(t_complex n1, t_complex n2)
{
	t_complex		nomi;
	t_complex		deno;

	nomi = complex_mul(n1, (t_complex){n2.r, -n2.i});
	deno = complex_mul(n2, (t_complex){n2.r, -n2.i});
	return ((t_complex){nomi.r / deno.r, nomi.i / deno.r});
}

t_complex			complex_abs(t_complex n)
{
	return ((t_complex){sqrt(n.r * n.r + n.i * n.i), 0.0f});
}
