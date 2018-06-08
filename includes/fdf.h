/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmelen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 19:24:27 by thmelen           #+#    #+#             */
/*   Updated: 2018/05/06 19:24:31 by thmelen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/includes/libft.h"
# include <mlx.h>

//A SUPP
#include <stdio.h>
# include <math.h>

#define COLOR_FFF 0xffffff
#define COLOR_BLACK 0x000000
#define COLOR_RED 0xff0000
#define COLOR_GREEN 0x00ff00
#define COLOR_BLUE 0x0000ff
#define COLOR_JADE_DUST 0x00d2d3
#define COLOR_DRAGON_SKIN 0xff9f43
#define COLOR_RED_AMOUR 0xee5253
#define COLOR_BLUE_JUST 0x54a0ff
#define COLOR_DRAGON_SKIN 0xff9f43

#define WIN_XY 1000
#define WIN_X WIN_XY
#define WIN_Y WIN_XY
#define WIN_NBPIXEL (WIN_X * WIN_Y)

#define KEY_UP 126
#define KEY_DOWN 125
#define KEY_LEFT 123
#define KEY_RIGHT 124
#define KEY_PLUS 69
#define KEY_MOINS 78
#define KEY_PLUS_2 24
#define KEY_MOINS_2 27

#define NB_LIGN (data->nb_lign)
#define LEN_LIGN (data->len_lign)
#define NB_POINT (data->nb_lign * data->len_lign)

#define SQR_3 1.73205080757


#define START_X WIN_X / 2
#define START_Y WIN_Y / 2
#define PIXEL_SPACE 55
#define PIXEL_SPACE_START (PIXEL_SPACE / 2)
#define ALTITUDE_SCALE 10




//MLX STUFF
typedef struct	s_mlximg
{
	//id img
	void		*img_ptr;
	//tableau int img
	int			*tab_img;
  //nombre de Bit par pixel, size_line (taille de la ligne), et endian.
	int			bpp;
	int			size_l;
	int			endian;
}				t_mlximg;

//T POINT
typedef struct s_point
{
	double x;
	double y;
}	t_point;

//MLX BASE
typedef struct	s_mlx
{
  //base
	void		*mlx_ptr;
	void		*mlx_win;

	//TAB IMAGE
	t_mlximg		img;

	//POINT
	t_point p1;
	t_point p2;

	//SPACE POINT
	t_point p_space;

	//STAR POINT
	t_point p_start;

	//STAR ALTITUDE
	t_point p_altitude;

	//scale
	int alti_scale;

  //content option
  char *content;
	int **tab_content;

	//content spef
  int nb_lign;
  int len_lign;




	//A SUPP
	// char **av;
}				t_mlx;



void ft_read_map(char *path, t_mlx	*data);
void ft_check_map(t_mlx	*data);
void ft_parse_map(t_mlx	*datma);
void ft_mlx_start(t_mlx	*data, char *path);
void ft_map_resolver(t_mlx	*data);
void ft_init_resolver(t_mlx	*data);
void ft_draw_stroke(t_point p1, t_point p2, t_mlx *data);
void ft_display_tab_content(t_mlx	*data);

void ft_winpaint_fill(t_mlx *data, int color);
void ft_winpaint_sqr(t_mlx *data, int size, int x, int y, int color);

#endif
