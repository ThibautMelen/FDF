/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_stroke.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmelen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 18:47:47 by thmelen           #+#    #+#             */
/*   Updated: 2018/07/03 21:14:10 by thmelen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static	void	ft_draw_stroke_up(t_point p1, t_point p2, t_mlx *data)
{
	int x;
	int y;

	y = p1.y;
	while (y < p2.y)
	{
		x = p1.x + (p2.x - p1.x) * (y - p1.y) / (p2.y - p1.y);
		if (x >= 0 && x < WIN_X && y >= 0 && y < WIN_X)
			data->img.tab_img[x * WIN_X + y] = data->color;
		y++;
	}
}

static	void	ft_draw_stroke_down(t_point p1, t_point p2, t_mlx *data)
{
	int x;
	int y;

	x = p1.x;
	while (x <= p2.x)
	{
		y = p1.y + (p2.y - p1.y) * (x - p1.x) / (p2.x - p1.x);
		if (x >= 0 && x < WIN_X && y >= 0 && y < WIN_X)
			data->img.tab_img[x * WIN_X + y] = data->color;
		x++;
	}
}

void			ft_draw_stroke(t_point p1, t_point p2, t_mlx *data)
{
	int x;
	int y;

	x = ft_abs(p1.x - p2.x);
	y = ft_abs(p1.y - p2.y);
	if (x > y)
	{
		if (p1.x <= p2.x)
			ft_draw_stroke_down(p1, p2, data);
		else
			ft_draw_stroke_down(p2, p1, data);
	}
	else
	{
		if (p1.y < p2.y)
			ft_draw_stroke_up(p1, p2, data);
		else
			ft_draw_stroke_up(p2, p1, data);
	}
}
