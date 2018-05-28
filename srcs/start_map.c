/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmelen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 06:07:26 by thmelen           #+#    #+#             */
/*   Updated: 2018/05/11 06:07:31 by thmelen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/fdf.h"

//TO SUPP
void ft_display_tab_content(t_mlx	*data)
{
  int p;
  int i;
  int j;
  i = 0;
  j = 0;
  p = 0;
  while(i < data->nb_lign)
  {
    while (j < data->len_lign)
    {
      ft_putnbr(data->tab_content[p]);
      ft_putstr(" ");
      p++;
      j++;
    }
    ft_putchar('\n');
    j = 0;
    i++;
  }
}
//

static int ft_len_lign(char *str)
{
  int i;
  int len_lign;


  i = 0;
  len_lign = 0;
  while(str[i])
  {
    if(str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
      len_lign++;
    i++;
  }
  return (len_lign);
}

void ft_parse_map(t_mlx	*data)
{
  int i;
  int j;

  i = 0;
  j = 0;
  if(!(data->tab_content = malloc(sizeof(int) * (data->len_lign * data->nb_lign))))
    ft_exit_program(MALLOC_ERROR);
  while(data->content[i])
  {
    if(data->content[i] >= '0' && data->content[i] <= '9')
    {
      data->tab_content[j] = ft_atoi(data->content + i);
      while(data->content[i] >= '0' && data->content[i] <= '9')
        i++;
      j++;
    }
    i++;
  }
  //TO SUPP
  ft_display_tab_content(data);
}

void ft_check_map(t_mlx	*data)
{
  int i;

	i = 0;
	while (data->content[i])
	{
		if ((data->content[i] >= '0' && data->content[i] <= '9') || \
    data->content[i] == '-' || (data->content[i] >= 0 && \
    data->content[i] <= 32) || data->content[i] == 127)
			i++;
		else
			ft_exit_program(CONTENT_ERROR);
	}
  // if ((data->len_lign *  data->nb_lign) <= 1)
  //   ft_exit_program(CONTENT_ERROR);
}

void ft_read_map(char *path, t_mlx	*data)
{
  char *line;
  char *tmp;
  int fd = ft_open_file(path);

  tmp = NULL;
  data->nb_lign = 0;
  data->content = ft_strnew('\0');
  while(ft_get_next_line(fd, &line) > 0)
  {
		tmp = data->content;
		if (!(data->content = ft_strjoin(tmp, line)))
			ft_exit_program(MALLOC_ERROR);
    tmp = data->content;
    if (!(data->content = ft_strjoin(tmp, " ")))
      ft_exit_program(MALLOC_ERROR);
		free(tmp);
    data->nb_lign++;
  }
  data->len_lign = ft_len_lign(line);
}
