/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmelen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 06:07:26 by thmelen           #+#    #+#             */
/*   Updated: 2018/10/02 16:58:37 by thmelen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int		ft_len_lign(char *str)
{
	int i;
	int len_lign;

	i = 0;
	len_lign = 0;
	while (str[i])
	{
		if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
			len_lign++;
		i++;
	}
	return (len_lign);
}

static void		ft_parsing(t_mlx *data, int i, int j, int p)
{
	while (i < data->nb_lign)
	{
		if (!((data->tab_content)[i] = (int*)malloc(sizeof(int)
						* (data->len_lign))))
			ft_exit_program(MALLOC_ERROR);
		while (j < data->len_lign)
		{
			if ((data->content[p] >= '0' && data->content[p] <= '9')
			|| data->content[p] == '-')
			{
				data->tab_content[i][j] = ft_atoi(data->content + p);
				while (data->content[p] != ' ')
					p++;
				j++;
			}
			while (!(data->content[p] >= '0' && data->content[p] <= '9'))
				p++;
		}
		j = 0;
		i++;
	}
}

void			ft_parse_map(t_mlx *data)
{
	int i;
	int j;
	int p;

	i = 0;
	j = 0;
	p = 0;
	if (!(data->tab_content = (int**)malloc(sizeof(int*) * (data->nb_lign))))
		ft_exit_program(MALLOC_ERROR);
	ft_parsing(data, i, j, p);
	free(data->content);
}

void			ft_check_map(t_mlx *data)
{
	int i;

	i = 0;
	while (data->content[i])
	{
		if (ft_isprint(data->content[i]))
			i++;
		else
			ft_exit_program(CONTENT_ERROR);
	}
}

void			ft_read_map(char *path, t_mlx *data)
{
	char	*line;
	char	*tmp;
	int		fd;

	fd = ft_open_file(path);
	tmp = NULL;
	data->nb_lign = 0;
	data->content = ft_strnew('\0');
	while (ft_get_next_line(fd, &line) > 0)
	{
		tmp = data->content;
		if (!(data->content = ft_strjoin(tmp, line)))
			ft_exit_program(MALLOC_ERROR);
		free(tmp);
		tmp = data->content;
		if (!(data->content = ft_strjoin(tmp, " ")))
			ft_exit_program(MALLOC_ERROR);
		free(tmp);
		data->nb_lign++;
		data->len_lign = ft_len_lign(line);
		if (!ft_isprint(line[0]))
			ft_exit_program(CONTENT_ERROR);
		free(line);
	}
}
