/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmelen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 19:21:46 by thmelen           #+#    #+#             */
/*   Updated: 2018/05/11 06:08:14 by thmelen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// alias data="man /usr/share/man/man3/data.1"
// alias mlx_new_window="man /usr/share/man/man3/mlx_new_window.1"
// alias mlx_pixel_put="man /usr/share/man/man3/mlx_pixel_put.1"
// alias mlx_new_image="man /usr/share/man/man3/mlx_new_image.1"
// alias mlx_loop="man /usr/share/man/man3/mlx_loop.1"


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


//Evenement Clavier
int ft_deal_key(int key, t_mlx *data)
{
  ft_putstr("X\n");
  ft_putnbr(key);
  if(key == KEY_DOWN)
    ft_winpaint_fill(data, COLOR_DRAGON_SKIN);
	if(key == KEY_UP)
	   ft_winpaint_fill(data, COLOR_BLUE_JUST);
	if(key == KEY_RIGHT)
		ft_winpaint_sqr(data, /*ft_atoi((data->av)[1])*/50, 70, 80, COLOR_RED_AMOUR);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img.img_ptr, 0, 0);
  return (EXIT_SUCCESS);
}

//Main
int	main(int argc, char **argv)
{
	t_mlx	data;

	//Check Arg
	if (argc != 2)
		ft_show_usage(argv[0]);

	///// MLX INIT
	// Mlx init
	ft_mlx_start(&data);
	mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, data.img.tab_img, 0, 0);


	// ///// READ CONTENT
	//mets la map dans content sans les '\n' (echange contre espace)
	//compte le nb de lignes >> data->nb_lign;
	//compte la len content >> data->len_content;
	ft_read_map(argv[1], &data);
	//check pas des caracteres demandes
	//check content_len <= 2
	// ft_check_map(&data);
	//parse la map en int >> data.tab_content
	ft_parse_map(&data);

	///
	// ///// FDF RESOLVER
	ft_map_resolver(&data);


	//Affichage de l'image dans la fenetre
	mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, data.img.tab_img, 0, 0);
	//EVENT
	//Evenement clavier
  mlx_hook(data.mlx_win, 2, 5, &ft_deal_key, &data);
  mlx_loop(data.mlx_ptr);

	return (EXIT_SUCCESS);
}
