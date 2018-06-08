/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolver_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmelen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 14:47:02 by thmelen           #+#    #+#             */
/*   Updated: 2018/05/17 14:47:06 by thmelen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void ft_init_resolver(t_mlx	*data)
{
  //space
  data->p_space.x = PIXEL_SPACE / 2;
  data->p_space.y = PIXEL_SPACE / 2;

  //start
  data->p_start.x = START_X;
  data->p_start.y = START_Y;

  data->alti_scale = ALTITUDE_SCALE;
}

void ft_map_resolver(t_mlx	*data)
{
  //incrementation
  int i;
  int j;
  int p;

  p = 0;
  i = 0;
  j = 0;

  while(j < NB_LIGN)
  {
    while(i < LEN_LIGN)
    {
      // //altidude
      data->p_altitude.x = data->tab_content[j][i];
      data->p_altitude.y = data->tab_content[j][i];
      // ft_display_tab_content(data);

      //p1 position
      data->p1.x = data->p_start.x + (i * data->p_space.x) + (j * data->p_space.y) - (data->tab_content[j][i] * data->alti_scale);
      data->p1.x = data->p1.x / SQR_3;
      data->p1.y = data->p_start.y + (i * data->p_space.x) - (j * data->p_space.y);

      //SI ON EST PAS AU
      if ((i + 1) != LEN_LIGN)
      {
        data->p2.x = data->p_start.x + ((i + 1) * data->p_space.x) + (j * data->p_space.y) - (data->tab_content[j][i + 1] * data->alti_scale);
        data->p2.x = data->p2.x / SQR_3;
        data->p2.y = data->p_start.y + ((i + 1) * data->p_space.x) - (j * data->p_space.y);

        ft_draw_stroke(data->p1, data->p2, data);
      }
      if ((j + 1) != NB_LIGN)
      {

        data->p2.x = data->p_start.x + (i * data->p_space.x) + ((j + 1) * data->p_space.y) - (data->tab_content[j + 1][i] * data->alti_scale);
        data->p2.x = data->p2.x / SQR_3;
        data->p2.y = data->p_start.y + (i * data->p_space.x) - ((j + 1) * data->p_space.y);

        ft_draw_stroke(data->p1, data->p2, data);
      }

      i++;
      p++;
    }
    i = 0;
    j++;
  }

  //PUT 42 SUR WIN AVEC ESPACE

}
