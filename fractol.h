/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-oirg <zel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 08:26:49 by zel-oirg          #+#    #+#             */
/*   Updated: 2024/05/15 20:09:46 by zel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>

# define SIZE  0

typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_image;

typedef struct s_fractol
{
	void		*mlx;
	void		*mlx_win;
	char		*name;
	t_image		image;
	t_complex	trans;
	t_complex	julia;
	double		zoom;
	int			precision;
	int			color;
}	t_fractol;

int			ft_strcmp(char *s1, char *s2);
t_complex	square_complex(t_complex z, char *name_fract);
double		ft_atod(char *s);
t_complex	add_complex(t_complex a, t_complex b);
void		fract_centring(t_fractol *fract);
int			color(int iter, t_fractol *fract);
void		my_mlx_pixel_put(t_image *data, int x, int y, int color);
int			clean_fract(t_fractol *fract);
double		mod(t_complex z);
void		rendring(t_fractol *fract);
int			key_pres(int button, t_fractol *fract);
char		*ft_strdup(const char *s1);
int			mouse_handling(int button, int x, int y, t_fractol *fract);
void		init_fract(t_fractol *fract, char *name);
int			chec_julia(char *nb1);
void		ft_strput(char *s);

#endif