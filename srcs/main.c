/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmelen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 19:21:46 by thmelen           #+#    #+#             */
/*   Updated: 2018/07/03 21:15:12 by thmelen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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


	// ///// FDF RESOLVER
  ft_init_resolver(&data);
	ft_map_resolver(&data);


	// EVENT
  mlx_hook(data.mlx_win, 2, 5, &ft_deal_key, &data);
  mlx_loop(data.mlx_ptr);
	return (EXIT_SUCCESS);
}
