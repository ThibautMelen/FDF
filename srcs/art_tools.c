/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   art_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmelen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 14:57:45 by thmelen           #+#    #+#             */
/*   Updated: 2018/06/06 14:57:47 by thmelen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

//Paint Part
void ft_winpaint_fill(t_mlx *data, int color)
{
	int i_h;
	int i_w;

	i_h = 0;
	i_w = 0;
	while (i_h < WIN_Y)
	{
		while (i_w < WIN_X)
		{
			data->img.tab_img[i_h * WIN_X + i_w] = color;
			i_w++;
		}
		i_h++;
		i_w = 0;
	}
}
void ft_winpaint_sqr(t_mlx *data, int size, int x, int y, int color)
{
	int i_h;
	int i_w;
	int stop_x;
	int stop_y;

	i_h = 0;
	i_w = 0;
	stop_x = 0;
	stop_y = 0;
	while (i_h < WIN_Y)
	{
		while (i_w < WIN_X)
		{
			if (i_h >= x && i_w >= y && stop_x <= size && stop_y <= size)
			{
				data->img.tab_img[i_h * WIN_X + i_w] = color;
				stop_x++;
			}
			i_w++;
		}
		i_h++;
		if (i_h >= x && i_w >= y)
			stop_y++;
		stop_x = 0;
		i_w = 0;
	}
}
