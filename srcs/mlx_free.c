/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmelen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 15:47:45 by thmelen           #+#    #+#             */
/*   Updated: 2018/07/03 21:15:54 by thmelen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	mlx_free_tabcontent(t_mlx *data)
{
	int i;

	i = 0;
	while (i < NB_LIGN)
	{
		free((data->tab_content)[i]);
		i++;
	}
	free(data->tab_content);
}
