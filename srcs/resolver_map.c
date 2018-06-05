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

//Isomer Part
int ft_creat_iso(t_mlx *data)
{
  (void)data;
	return (EXIT_SUCCESS);
}

void ft_map_resolver(t_mlx	*data)
{
  //space
  data->p_space.x = PIXEL_SPACE;
  data->p_space.y = PIXEL_SPACE;

  //start
  data->p_start.x = 0;
  data->p_start.y = 0;






  //PUT 42 SUR WIN AVEC ESPACE




}

// void ft_map_resolver(t_mlx	*data)
// {
//   int i_x;
//   int i_y;
//   int cnt_point;
//
//   i_x = PIXEL_SPACE_START;
//   i_y = PIXEL_SPACE_START;
//   cnt_point = 0;
//   while(i_x < WIN_Y)
//   {
//     while (i_y < WIN_X)
//     {
//         //X Y
//         printf("%d %d %d %d\n", i_x, i_y, NB_POINT, LEN_LIGN);
//         if ((i_x - PIXEL_SPACE_START) % PIXEL_SPACE == 0 && cnt_point < NB_POINT)
//         {
//           if ((i_y - PIXEL_SPACE_START) % PIXEL_SPACE == 0)
//           {
//             if(data->tab_content[cnt_point] == 0)
//             {
//               data->img.tab_img[i_x * WIN_X + i_y] = COLOR_FFF;
//             }
//             else
//               data->img.tab_img[i_x * WIN_X + i_y] = COLOR_RED;
//
//             cnt_point++;
//           }
//         }
//       i_y++;
//     }
//     i_y = PIXEL_SPACE_START;
//     i_x++;
//   }
// }
