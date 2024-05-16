/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-oirg <zel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 08:26:58 by zel-oirg          #+#    #+#             */
/*   Updated: 2024/05/16 18:43:53 by zel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

t_complex	add_complex(t_complex a, t_complex b)
{
	t_complex	sum;

	sum.x = a.x + b.x;
	sum.y = a.y + b.y;
	return (sum);
}

double	abs_val(double x)
{
	if (x < 0)
		x = -x;
	return (x);
}

t_complex	square_complex(t_complex z)
{
	t_complex	res;

	res.x = z.x * z.x - z.y * z.y;
	res.y = 2 * abs_val(z.x) * abs_val(z.y);
	return (res);
}

double	mod(t_complex z)
{
	double	mod;

	mod = z.x * z.x + z.y * z.y;
	return (mod);
}
