/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdetourn <gdetourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 16:19:12 by gdetourn          #+#    #+#             */
/*   Updated: 2024/01/02 12:31:49 by gdetourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

void	ft_move(t_data *data, t_pos *pos_p, int c)
{
	if (data->map[pos_p->y][pos_p->x] == 'E')
		ft_print_image(data, data->img->img_exit, data->pos_p);
	else
		ft_print_image(data, data->img->img_space, data->pos_p);
	if (c == 'd')
	{
		ft_move_right(data, pos_p);
		if (data->map[pos_p->y][pos_p->x] == 'M')
			ft_exit(data, 'M');
	}
	else if (c == 'a')
	{
		ft_move_left(data, pos_p);
		if (data->map[pos_p->y][pos_p->x] == 'M')
			ft_exit(data, 'M');
	}
	else if (c == 'w' || c == 's')
		ft_move_long(data, pos_p, c);
}

void	ft_move_right(t_data *data, t_pos *pos_p)
{
	if (data->map[pos_p->y][pos_p->x + 1] == '1')
	{
		ft_print_image(data, data->img->img_player_r, data->pos_p);
		if (data->map[pos_p->y][pos_p->x] == 'E')
			ft_print_image(data, data->img->img_exit_p_r, data->pos_p);
	}
	else if (data->map[pos_p->y][pos_p->x + 1] != '1')
	{
		data->content.total_moves++;
		ft_printf("Steps to Exit: %d\n", data->content.total_moves);
		pos_p->x++;
		if (data->map[pos_p->y][pos_p->x] == 'C')
		{
			data->content.collect_c--;
			data->map[pos_p->y][pos_p->x] = '0';
		}
		if (data->map[pos_p->y][pos_p->x] == 'E')
		{
			ft_print_image(data, data->img->img_exit_p_r, data->pos_p);
			if (data->content.collect_c == 0)
				ft_exit(data, 'E');
		}
		else
			ft_print_image(data, data->img->img_player_r, data->pos_p);
	}
}

void	ft_move_left(t_data *data, t_pos *pos_p)
{
	if (data->map[pos_p->y][pos_p->x - 1] == '1')
	{
		ft_print_image(data, data->img->img_player_l, data->pos_p);
		if (data->map[pos_p->y][pos_p->x] == 'E')
			ft_print_image(data, data->img->img_exit_p_l, data->pos_p);
	}
	else if (data->map[pos_p->y][pos_p->x - 1] != '1')
	{
		data->content.total_moves++;
		ft_printf("Steps to Exit: %d\n", data->content.total_moves);
		pos_p->x--;
		if (data->map[pos_p->y][pos_p->x] == 'C')
		{
			data->content.collect_c--;
			data->map[pos_p->y][pos_p->x] = '0';
		}
		if (data->map[pos_p->y][pos_p->x] == 'E')
		{
			ft_print_image(data, data->img->img_exit_p_l, data->pos_p);
			if (data->content.collect_c == 0)
				ft_exit(data, 'E');
		}
		else
			ft_print_image(data, data->img->img_player_l, data->pos_p);
	}
}

void	ft_move_up(t_data *data, t_pos *pos_p)
{
	if (data->map[pos_p->y - 1][pos_p->x] == '1')
	{
		ft_print_image(data, data->img->img_player_ud, data->pos_p);
		if (data->map[pos_p->y][pos_p->x] == 'E')
			ft_print_image(data, data->img->img_exit_p_ud, data->pos_p);
	}
	else if (data->map[pos_p->y - 1][pos_p->x] != '1')
	{
		data->content.total_moves++;
		ft_printf("Steps to Exit: %d\n", data->content.total_moves);
		pos_p->y--;
		if (data->map[pos_p->y][pos_p->x] == 'C')
		{
			data->content.collect_c--;
			data->map[pos_p->y][pos_p->x] = '0';
		}
		if (data->map[pos_p->y][pos_p->x] == 'E')
		{
			ft_print_image(data, data->img->img_exit_p_ud, data->pos_p);
			if (data->content.collect_c == 0)
				ft_exit(data, 'E');
		}
		else
			ft_print_image(data, data->img->img_player_ud, data->pos_p);
	}
}

void	ft_move_down(t_data *data, t_pos *pos_p)
{
	if (data->map[pos_p->y + 1][pos_p->x] == '1')
	{
		ft_print_image(data, data->img->img_player_ud, data->pos_p);
		if (data->map[pos_p->y][pos_p->x] == 'E')
			ft_print_image(data, data->img->img_exit_p_ud, data->pos_p);
	}
	else if (data->map[pos_p->y + 1][pos_p->x] != '1')
	{
		data->content.total_moves++;
		ft_printf("Steps to Exit: %d\n", data->content.total_moves);
		pos_p->y++;
		if (data->map[pos_p->y][pos_p->x] == 'C')
		{
			data->content.collect_c--;
			data->map[pos_p->y][pos_p->x] = '0';
		}
		if (data->map[pos_p->y][pos_p->x] == 'E')
		{
			ft_print_image(data, data->img->img_exit_p_ud, data->pos_p);
			if (data->content.collect_c == 0)
				ft_exit(data, 'E');
		}
		else
			ft_print_image(data, data->img->img_player_ud, data->pos_p);
	}
}
