/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdetourn <gdetourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 13:37:28 by gdetourn          #+#    #+#             */
/*   Updated: 2024/01/02 12:28:27 by gdetourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

int	ft_check_map_copy(char **tab, t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->line)
	{
		x = 0;
		while (x < data->col)
		{
			if (tab[y][x] != '1' && tab[y][x] != 'M' && tab[y][x] != 'X')
				ft_error(6, data);
			x++;
		}
		y++;
	}
	return (0);
}

int	ft_flood_fill_sl(char **map_copy, t_pos size, t_pos p)
{
	if (p.y < 0 || p.x < 0 || p.y >= size.y || p.x >= size.x)
		return (0);
	if (map_copy[p.y][p.x] == '1' || map_copy[p.y][p.x] == 'M'
		|| map_copy[p.y][p.x] == 'X')
		return (0);
	map_copy[p.y][p.x] = 'X';
	ft_flood_fill_sl(map_copy, size, (t_pos){p.x + 1, p.y});
	ft_flood_fill_sl(map_copy, size, (t_pos){p.x - 1, p.y});
	ft_flood_fill_sl(map_copy, size, (t_pos){p.x, p.y + 1});
	ft_flood_fill_sl(map_copy, size, (t_pos){p.x, p.y - 1});
	return (0);
}

int	ft_map_copy(t_data *data)
{
	int	x;
	int	y;

	data->map_copy = NULL;
	data->map_copy = ft_calloc(data->line + 1, sizeof(char *));
	if (!data->map_copy)
		return (1);
	y = 0;
	while (y < data->line)
	{
		data->map_copy[y] = ft_calloc(data->col + 1, sizeof(char));
		if (!data->map_copy[y])
			return (1);
		x = 0;
		while (x < data->col)
		{
			data->map_copy[y][x] = data->map[y][x];
			x++;
		}
		y++;
	}
	data->map_copy[y] = 0;
	return (0);
}

int	ft_valid_path(t_data *data)
{
	t_pos	size;
	t_pos	p;

	size.x = data->col;
	size.y = data->line;
	p = data->pos_p;
	ft_map_copy(data);
	ft_flood_fill_sl(data->map_copy, size, p);
	ft_check_map_copy(data->map_copy, data);
	return (0);
}

/* ft_printf("%c, ", data->map_copy[y][x]);
ft_printf("\n"); */