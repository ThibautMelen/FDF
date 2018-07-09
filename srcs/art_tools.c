/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   art_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmelen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 14:57:45 by thmelen           #+#    #+#             */
/*   Updated: 2018/07/03 21:02:38 by thmelen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_winpaint_fill(t_mlx *data, int color)
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
