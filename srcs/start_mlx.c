/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmelen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 06:07:39 by thmelen           #+#    #+#             */
/*   Updated: 2018/05/11 06:07:44 by thmelen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void ft_mlx_start(t_mlx	*data)
{
  if ((data->mlx_ptr = mlx_init()) == NULL)
    ft_exit_program(INIT_ERROR);
	//Creation fenetre
  if ((data->mlx_win = mlx_new_window(data->mlx_ptr, WIN_X, WIN_Y, "FDF")) == NULL)
    ft_exit_program(INIT_ERROR);
	//Creation img
	if ((data->img.img_ptr = mlx_new_image(data->mlx_ptr, WIN_X, WIN_Y)) == NULL)
		ft_exit_program(INIT_ERROR);
	//Convertion img char* to int
	if ((data->img.tab_img = (int *)mlx_get_data_addr(data->img.img_ptr, &data->img.bpp, &data->img.size_l, &data->img.endian)) == NULL)
		ft_exit_program(INIT_ERROR);
}
