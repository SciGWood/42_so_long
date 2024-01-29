/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdetourn <gdetourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:55:08 by gdetourn          #+#    #+#             */
/*   Updated: 2024/01/02 13:33:26 by gdetourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

void	ft_move_long(t_data *data, t_pos *pos_p, int c)
{
	if (c == 'w')
	{
		ft_move_up(data, pos_p);
		if (data->map[pos_p->y][pos_p->x] == 'M')
			ft_exit(data, 'M');
	}
	else if (c == 's')
	{
		ft_move_down(data, pos_p);
		if (data->map[pos_p->y][pos_p->x] == 'M')
			ft_exit(data, 'M');
	}
}

void	ft_exit(t_data *data, int flag)
{
	if (flag == 'O')
		ft_printf("Don't want to play anymore?\n");
	if (flag == 'E')
		ft_printf("You found the Exit :D Well Done!!!\n");
	if (flag == 'M')
		ft_printf("Dangerous Mosquito -> You lose :'( Try again!!\n");
	on_destroy(data);
}

void	ft_free_map(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	ft_destroy_images(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img->img_player_r);
	mlx_destroy_image(data->mlx, data->img->img_player_l);
	mlx_destroy_image(data->mlx, data->img->img_player_ud);
	mlx_destroy_image(data->mlx, data->img->img_exit_p_r);
	mlx_destroy_image(data->mlx, data->img->img_exit_p_l);
	mlx_destroy_image(data->mlx, data->img->img_exit_p_ud);
	mlx_destroy_image(data->mlx, data->img->img_collect);
	mlx_destroy_image(data->mlx, data->img->img_exit);
	mlx_destroy_image(data->mlx, data->img->img_wall);
	mlx_destroy_image(data->mlx, data->img->img_space);
	mlx_destroy_image(data->mlx, data->img->img_msq_0);
	mlx_destroy_image(data->mlx, data->img->img_msq_1);
	mlx_destroy_image(data->mlx, data->img->img_msq_2);
	mlx_destroy_image(data->mlx, data->img->img_msq_3);
	free(data->img);
}

void	ft_error(int flag, t_data *data)
{
	if (flag == 1)
		ft_printf("Error\nfail to open file (file has to be .ber)\n");
	else
	{
		ft_free_map(data->map);
		if (flag == 3)
			ft_printf("Error\nmap must be a rectangle\n");
		if (flag == 4)
			ft_printf("Error\nline or column must be closed by a wall\n");
		if (flag == 5)
			ft_printf("Error\nmap is not valid\n");
		if (flag == 6 || flag == 7 || flag == 8)
		{
			ft_free_map(data->map_copy);
			if (flag == 6)
				ft_printf("Error\nNo valid path in this map\n");
			if (flag == 7)
				ft_printf("Error\nAt least 1 item to collect required\n");
			if (flag == 8)
				ft_printf("Error\nOnly 1 player and 1 exit required\n");
		}
	}
	exit(1);
}
