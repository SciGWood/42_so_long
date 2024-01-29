/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdetourn <gdetourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:52:23 by gdetourn          #+#    #+#             */
/*   Updated: 2024/01/02 12:32:36 by gdetourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <X11/Xlib.h>
# include <X11/keysym.h>

# define IW 64
# define IH 64
# define ESC 65307
# define A 97
# define D 100
# define S 115
# define W 119
# define LEFT 'a'
# define RIGHT 'd'
# define DOWN 's'
# define UP 'w'

typedef struct s_pos
{
	int		x;
	int		y;
}					t_pos;

typedef struct s_img
{
	int		height;
	int		width;
	char	*player_r;
	char	*player_l;
	char	*player_ud;
	char	*exit_p_r;
	char	*exit_p_l;
	char	*exit_p_ud;
	char	*msq_0;
	char	*msq_1;
	char	*msq_2;
	char	*msq_3;
	char	*collect;
	char	*exit;
	char	*wall;
	char	*space;
	void	*img_player_r;
	void	*img_player_l;
	void	*img_player_ud;
	void	*img_exit_p_r;
	void	*img_exit_p_l;
	void	*img_exit_p_ud;
	void	*img_collect;
	void	*img_exit;
	void	*img_wall;
	void	*img_space;
	void	*img_msq_0;
	void	*img_msq_1;
	void	*img_msq_2;
	void	*img_msq_3;
}					t_img;

typedef struct s_cont
{
	int		player_p;
	int		exit_e;
	int		collect_c;
	int		total_moves;
}					t_cont;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	char	**map;
	char	**map_copy;
	int		size_x;
	int		size_y;
	int		col;
	int		line;
	int		clock;
	int		state_msq;
	t_cont	content;
	t_img	*img;
	t_pos	pos_p;
	t_pos	pos_m;
}					t_data;

/*error_exit.c*/
void	ft_move_long(t_data *data, t_pos *pos_p, int c);
void	ft_exit(t_data *data, int flag);
void	ft_free_map(char **tab);
void	ft_destroy_images(t_data *data);
void	ft_error(int flag, t_data *data);

/*game.c*/
void	ft_move(t_data *data, t_pos *pos_p, int c);
void	ft_move_right(t_data *data, t_pos *pos_p);
void	ft_move_left(t_data *data, t_pos *pos_p);
void	ft_move_up(t_data *data, t_pos *pos_p);
void	ft_move_down(t_data *data, t_pos *pos_p);

/*images.c*/
void	ft_print_image(t_data *data, void *img, t_pos pos);
void	ft_images_to_map(t_data *data);
void	ft_xpm_anim(t_data *data);
void	ft_xpm_to_image(t_data *data);
void	ft_set_images(t_data *data);

/*parsing.c*/
int		ft_init_for_path(t_data *data);
int		ft_check_map_content(t_data *data);
int		ft_check_map_wall(t_data *data);
int		ft_check_map_format(t_data *data);
void	ft_parse_map(t_data *data, char *argv[]);

/*so_long.c*/
void	ft_write_steps(t_data *data);
int		on_destroy(t_data *data);
int		on_keypress(int keysym, t_data *data);
int		ft_anim(t_data *data);

/*valid_path.c*/
int		ft_check_map_copy(char **tab, t_data *data);
int		ft_flood_fill_sl(char **map_copy, t_pos size, t_pos p);
int		ft_map_copy(t_data *data);
int		ft_valid_path(t_data *data);

#endif