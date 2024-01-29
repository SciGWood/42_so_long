/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdetourn <gdetourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:08:38 by gdetourn          #+#    #+#             */
/*   Updated: 2024/01/02 15:30:21 by gdetourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

int	ft_init_for_path(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->line)
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'P')
			{
				data->pos_p.y = y;
				data->pos_p.x = x;
			}
			if (data->map[y][x] == 'M')
			{
				data->pos_m.y = y;
				data->pos_m.x = x;
			}
			x++;
		}
		y++;
	}
	ft_valid_path(data);
	return (0);
}

/* checker pathway dfs or flood_fill*/
int	ft_check_map_content(t_data *data)
{
	int	x;
	int	i;

	i = 0;
	while (i < data->line)
	{
		x = 0;
		while (data->map[i][x])
		{
			if (data->map[i][x] == 'P')
				data->content.player_p++;
			if (data->map[i][x] == 'E')
				data->content.exit_e++;
			if (data->map[i][x] == 'C')
				data->content.collect_c++;
			if (data->map[i][x] != 'P' && data->map[i][x] != 'E'
				&& data->map[i][x] != 'C' && data->map[i][x] != '1'
				&& data->map[i][x] != '0' && data->map[i][x] != 'M')
				ft_error(5, data);
			x++;
		}
		i++;
	}
	ft_init_for_path(data);
	return (0);
}

int	ft_check_map_wall(t_data *data)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (data->map[0][x] && data->map[data->line - 1] != NULL)
	{
		if (data->map[data->line - 1][x] != '1')
			ft_error(4, data);
		if (data->map[0][x] != '1')
			ft_error(4, data);
		x++;
	}
	while (data->map[y] != NULL && data->map[y][data->col - 1])
	{
		if (data->map[y][data->col - 1] != '1')
			ft_error(4, data);
		if (data->map[y][0] != '1')
			ft_error(4, data);
		y++;
	}
	ft_check_map_content(data);
	return (0);
}

int	ft_check_map_format(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	data->col = 0;
	data->line = 0;
	while (data->map[y][data->col])
		data->col++;
	while (data->map[data->line] != NULL)
		data->line++;
	while (data->map[y] != NULL)
	{
		while (data->map[y][x])
			x++;
		if (x != data->col || data->line == data->col)
			ft_error(3, data);
		x = 0;
		y++;
	}
	ft_check_map_wall(data);
	return (0);
}

void	ft_parse_map(t_data *data, char *argv[])
{
	char	*stash;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_error(1, data);
	if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == NULL)
		ft_error(1, data);
	stash = NULL;
	if (!stash)
		stash = ft_calloc(1, sizeof(char));
	stash = ft_read_text_sl(fd, stash);
	data->map = ft_split(stash, '\n');
	close(fd);
	free(stash);
	data->content.player_p = 0;
	data->content.collect_c = 0;
	data->content.exit_e = 0;
	data->content.total_moves = 0;
	ft_check_map_format(data);
	if (data->content.collect_c < 1)
		ft_error(7, data);
	if (data->content.player_p != 1 || data->content.exit_e != 1)
		ft_error(8, data);
}
