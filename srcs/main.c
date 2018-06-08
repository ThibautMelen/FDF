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


//Evenement Clavier
int ft_deal_key(int key, t_mlx *data)
{
  ft_putstr("X\n");
  ft_putnbr(key);

  // UP / DOWN
  if(key == KEY_DOWN)
  {
    data->p_start.x += 10;
    ft_winpaint_fill(data, COLOR_BLACK);
    ft_map_resolver(data);
  }
	else if(key == KEY_UP)
  {
	   data->p_start.x -= 10;
     ft_winpaint_fill(data, COLOR_BLACK);
     ft_map_resolver(data);
  }

  // LEFT / RIGHT
  if(key == KEY_RIGHT)
  {
    data->p_start.y += 10;
    ft_winpaint_fill(data, COLOR_BLACK);
    ft_map_resolver(data);
  }
	else if(key == KEY_LEFT)
  {
	   data->p_start.y -= 10;
     ft_winpaint_fill(data, COLOR_BLACK);
     ft_map_resolver(data);
  }

  // + / -
  if(key == KEY_PLUS)
  {
    data->p_space.x += 2;
    data->p_space.y += 2;
    ft_winpaint_fill(data, COLOR_BLACK);
    ft_map_resolver(data);
  }
  else if(key == KEY_MOINS)
  {
    data->p_space.x -= 2;
    data->p_space.y -= 2;
     ft_winpaint_fill(data, COLOR_BLACK);
     ft_map_resolver(data);
  }

  // + / - 2
  if(key == KEY_PLUS_2)
  {
    data->alti_scale += 5;
    ft_winpaint_fill(data, COLOR_BLACK);
    ft_map_resolver(data);
  }
  else if(key == KEY_MOINS_2)
  {
    data->alti_scale -= 5;
     ft_winpaint_fill(data, COLOR_BLACK);
     ft_map_resolver(data);
  }

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
	ft_mlx_start(&data, argv[1]);

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

  ft_init_resolver(&data);

	ft_map_resolver(&data);


	//Affichage de l'image dans la fenetre
	mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, data.img.tab_img, 0, 0);
	// EVENT
	//Evenement clavier
  mlx_hook(data.mlx_win, 2, 5, &ft_deal_key, &data);
  mlx_loop(data.mlx_ptr);

	return (EXIT_SUCCESS);
}
