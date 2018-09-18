/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmelen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 06:07:39 by thmelen           #+#    #+#             */
/*   Updated: 2018/09/18 21:23:14 by thmelen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static char		*path_name(char *path)
{
	int i;
	int len_start;
	int len_end;

	i = 0;
	len_end = 0;
	len_start = 0;
	while (path[i])
	{
		if (path[i] == '.' && path[i + 1] == 'f' &&
				path[i + 2] == 'd' && path[i + 3] == 'f')
		{
			len_end = i;
			while (ft_isprint(i) && i != '/')
				i--;
			if (ft_isprint(i) == FALSE || i == '/')
				len_start = i;
			return (ft_strsub(path, len_start + 2, (len_end - len_start - 2)));
		}
		i++;
	}
	return (path);
}

void			ft_mlx_start(t_mlx *data, char *path)
{
	if ((data->mlx_ptr = mlx_init()) == NULL)
		ft_exit_program(INIT_ERROR);
	if ((data->mlx_win = mlx_new_window(data->mlx_ptr, WIN_X, WIN_Y,
					path_name(path))) == NULL)
		ft_exit_program(INIT_ERROR);
	if ((data->img.img_ptr = mlx_new_image(data->mlx_ptr, WIN_X,
					WIN_Y)) == NULL)
		ft_exit_program(INIT_ERROR);
	if ((data->img.tab_img = (int *)mlx_get_data_addr(data->img.img_ptr,
					&data->img.bpp, &data->img.size_l, &data->img.endian))
			== NULL)
		ft_exit_program(INIT_ERROR);
}
