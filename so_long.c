/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdetourn <gdetourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:50:29 by gdetourn          #+#    #+#             */
/*   Updated: 2024/01/02 15:34:46 by gdetourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

/*should return an int but exit(0) is required to quit the program properly*/
int	on_destroy(t_data *data)
{
	ft_destroy_images(data);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	ft_free_map(data->map);
	ft_free_map(data->map_copy);
	free(data->mlx);
	exit(0);
	return (0);
}

void	ft_write_steps(t_data *data)
{
	char	*str;

	mlx_put_image_to_window(data->mlx, data->win, data->img->img_wall,
		1 * IW, 0 * IH);
	str = ft_itoa(data->content.total_moves);
	mlx_string_put(data->mlx, data->win, 20, 20, 0xffffff, "Steps:");
	mlx_string_put(data->mlx, data->win, 80, 20, 0x000000, str);
	free(str);
}

	/* ft_printf("Pressed key: %d\n", keysym); */
int	on_keypress(int keysym, t_data *data)
{
	if (keysym == ESC)
		ft_exit(data, 'O');
	else if (keysym == A || keysym == 65361)
		ft_move(data, &(data->pos_p), LEFT);
	else if (keysym == D || keysym == 65363)
		ft_move(data, &(data->pos_p), RIGHT);
	else if (keysym == S || keysym == 65364)
		ft_move(data, &(data->pos_p), DOWN);
	else if (keysym == W || keysym == 65362)
		ft_move(data, &(data->pos_p), UP);
	ft_write_steps(data);
	return (0);
}

int	ft_anim(t_data *data)
{
	data->clock++;
	if (data->clock == 2024)
		data->clock = 0;
	if (data->clock == 2023)
	{
		if (data->state_msq == 0)
			ft_print_image(data, data->img->img_msq_0, data->pos_m);
		if (data->state_msq == 1)
			ft_print_image(data, data->img->img_msq_1, data->pos_m);
		if (data->state_msq == 2)
			ft_print_image(data, data->img->img_msq_2, data->pos_m);
		if (data->state_msq == 3)
			ft_print_image(data, data->img->img_msq_3, data->pos_m);
		if (data->state_msq < 4)
			data->state_msq++;
		else
			data->state_msq = 0;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc != 2)
	{
		ft_printf("Error\nThis program needs an argument of type .ber\n");
		exit(0);
	}
	ft_parse_map(&data, argv);
	ft_set_images(&data);
	data.mlx = mlx_init();
	if (!data.mlx)
		return (1);
	data.win = mlx_new_window(data.mlx, data.size_x, data.size_y, "so_long");
	if (!data.win)
		return (free(data.mlx), 1);
	ft_xpm_to_image(&data);
	ft_images_to_map(&data);
	mlx_hook(data.win, KeyRelease, KeyReleaseMask, &on_keypress, &data);
	data.clock = 0;
	data.state_msq = 0;
	mlx_loop_hook(data.mlx, ft_anim, &data);
	mlx_hook(data.win, 17, 0, &on_destroy, &data);
	mlx_loop(data.mlx);
	return (0);
}

/* 	mlx_hook(data.win, DestroyNotify, StructureNotifyMask, &on_destroy,
		&data); */