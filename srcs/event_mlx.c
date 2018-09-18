/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmelen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 15:08:25 by thmelen           #+#    #+#             */
/*   Updated: 2018/09/18 21:21:58 by thmelen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		ft_event_downup(int key, t_mlx *data)
{
	if (key == KEY_DOWN)
	{
		data->p_start.x += 10;
		ft_winpaint_fill(data, COLOR_BLACK);
		ft_map_resolver(data);
	}
	else if (key == KEY_UP)
	{
		data->p_start.x -= 10;
		ft_winpaint_fill(data, COLOR_BLACK);
		ft_map_resolver(data);
	}
}

static void		ft_event_rightleft(int key, t_mlx *data)
{
	if (key == KEY_RIGHT)
	{
		data->p_start.y += 10;
		ft_winpaint_fill(data, COLOR_BLACK);
		ft_map_resolver(data);
	}
	else if (key == KEY_LEFT)
	{
		data->p_start.y -= 10;
		ft_winpaint_fill(data, COLOR_BLACK);
		ft_map_resolver(data);
	}
}

static void		ft_event_plusmoins(int key, t_mlx *data)
{
	if (key == KEY_PLUS)
	{
		data->p_space.x += 2;
		data->p_space.y += 2;
		ft_winpaint_fill(data, COLOR_BLACK);
		ft_map_resolver(data);
	}
	else if (key == KEY_MOINS)
	{
		data->p_space.x -= 2;
		data->p_space.y -= 2;
		ft_winpaint_fill(data, COLOR_BLACK);
		ft_map_resolver(data);
	}
}

static void		ft_event_plusmoins2(int key, t_mlx *data)
{
	if (key == KEY_PLUS_2)
	{
		data->alti_scale += 5;
		ft_winpaint_fill(data, COLOR_BLACK);
		ft_map_resolver(data);
	}
	else if (key == KEY_MOINS_2)
	{
		data->alti_scale -= 5;
		ft_winpaint_fill(data, COLOR_BLACK);
		ft_map_resolver(data);
	}
}

int				ft_deal_key(int key, t_mlx *data)
{
	if (key == KEY_ESC)
		exit(1);
	ft_event_downup(key, data);
	ft_event_rightleft(key, data);
	ft_event_plusmoins(key, data);
	ft_event_plusmoins2(key, data);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
	data->img.img_ptr, 0, 0);
	return (EXIT_SUCCESS);
}
