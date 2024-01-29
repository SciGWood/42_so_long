/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdetourn <gdetourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:23:59 by gdetourn          #+#    #+#             */
/*   Updated: 2024/01/02 12:20:21 by gdetourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

void	ft_print_image(t_data *data, void *img, t_pos pos)
{
	mlx_put_image_to_window(data->mlx, data->win, img, pos.x * IW, pos.y * IH);
}

void	ft_images_to_map(t_data *data)
{
	t_pos	pos;

	pos.y = 0;
	while (data->map[pos.y])
	{
		pos.x = 0;
		while (data->map[pos.y][pos.x])
		{
			if (data->map[pos.y][pos.x] == 'P')
				ft_print_image(data, data->img->img_player_r, pos);
			if (data->map[pos.y][pos.x] == 'E')
				ft_print_image(data, data->img->img_exit, pos);
			if (data->map[pos.y][pos.x] == 'C')
				ft_print_image(data, data->img->img_collect, pos);
			if (data->map[pos.y][pos.x] == '1')
				ft_print_image(data, data->img->img_wall, pos);
			if (data->map[pos.y][pos.x] == '0')
				ft_print_image(data, data->img->img_space, pos);
			if (data->map[pos.y][pos.x] == 'M')
				ft_print_image(data, data->img->img_msq_0, pos);
			pos.x++;
		}
		pos.y++;
	}
}

void	ft_xpm_anim(t_data *data)
{
	data->img->img_msq_1 = mlx_xpm_file_to_image(data->mlx, data->img->msq_1,
			&(data->img->width), &(data->img->height));
	data->img->img_msq_2 = mlx_xpm_file_to_image(data->mlx, data->img->msq_2,
			&(data->img->width), &(data->img->height));
	data->img->img_msq_3 = mlx_xpm_file_to_image(data->mlx, data->img->msq_3,
			&(data->img->width), &(data->img->height));
}

void	ft_xpm_to_image(t_data *data)
{
	data->img->img_player_r = mlx_xpm_file_to_image(data->mlx,
			data->img->player_r, &(data->img->width), &(data->img->height));
	data->img->img_player_l = mlx_xpm_file_to_image(data->mlx,
			data->img->player_l, &(data->img->width), &(data->img->height));
	data->img->img_player_ud = mlx_xpm_file_to_image(data->mlx,
			data->img->player_ud, &(data->img->width), &(data->img->height));
	data->img->img_exit_p_r = mlx_xpm_file_to_image(data->mlx,
			data->img->exit_p_r, &(data->img->width), &(data->img->height));
	data->img->img_exit_p_l = mlx_xpm_file_to_image(data->mlx,
			data->img->exit_p_l, &(data->img->width), &(data->img->height));
	data->img->img_exit_p_ud = mlx_xpm_file_to_image(data->mlx,
			data->img->exit_p_ud, &(data->img->width), &(data->img->height));
	data->img->img_collect = mlx_xpm_file_to_image(data->mlx,
			data->img->collect, &(data->img->width), &(data->img->height));
	data->img->img_exit = mlx_xpm_file_to_image(data->mlx, data->img->exit,
			&(data->img->width), &(data->img->height));
	data->img->img_wall = mlx_xpm_file_to_image(data->mlx, data->img->wall,
			&(data->img->width), &(data->img->height));
	data->img->img_space = mlx_xpm_file_to_image(data->mlx, data->img->space,
			&(data->img->width), &(data->img->height));
	data->img->img_msq_0 = mlx_xpm_file_to_image(data->mlx, data->img->msq_0,
			&(data->img->width), &(data->img->height));
	ft_xpm_anim(data);
}

void	ft_set_images(t_data *data)
{
	t_img	*img;

	img = calloc(1, sizeof(t_img));
	if (!img)
		exit(1);
	data->img = img;
	data->img->height = 64;
	data->img->width = 64;
	data->img->player_r = "./assets/Player_R.xpm";
	data->img->player_l = "./assets/Player_L.xpm";
	data->img->player_ud = "./assets/Player_UD.xpm";
	data->img->exit_p_r = "./assets/Exit_Rayman_r.xpm";
	data->img->exit_p_l = "./assets/Exit_Rayman_l.xpm";
	data->img->exit_p_ud = "./assets/Exit_Rayman_UD.xpm";
	data->img->collect = "./assets/Collec.xpm";
	data->img->exit = "./assets/Exit.xpm";
	data->img->wall = "./assets/Wall.xpm";
	data->img->space = "./assets/Space.xpm";
	data->img->msq_0 = "./assets/Mosquito.xpm";
	data->img->msq_1 = "./assets/Mosquito_1.xpm";
	data->img->msq_2 = "./assets/Mosquito_2.xpm";
	data->img->msq_3 = "./assets/Mosquito_3.xpm";
	data->size_x = data->col * data->img->width;
	data->size_y = data->line * data->img->height;
}
