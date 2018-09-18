/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmelen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 19:21:46 by thmelen           #+#    #+#             */
/*   Updated: 2018/09/18 18:25:44 by thmelen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	t_mlx	data;

	if (argc != 2)
		ft_show_usage(argv[0]);
	ft_mlx_start(&data, argv[1]);
	ft_read_map(argv[1], &data);
	ft_parse_map(&data);
	ft_init_resolver(&data);
	ft_map_resolver(&data);
	mlx_hook(data.mlx_win, 2, 5, &ft_deal_key, &data);
	mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, data.img.img_ptr, 0, 0);
	mlx_loop(data.mlx_ptr);
	return (EXIT_SUCCESS);
}
