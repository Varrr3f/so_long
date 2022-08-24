/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:10:05 by sdavos            #+#    #+#             */
/*   Updated: 2022/05/27 15:10:07 by sdavos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# define TRUE 1
# define FALSE 0
# define BUFFER_SIZE 10
# define IMG_HEIGHT 32
# define IMG_LENGHT 32
# define UP 1
# define DOWN 2
# define LEFT 3
# define RIGHT 4
# define UP_KEY 13
# define DOWN_KEY 1
# define LEFT_KEY 0
# define RIGHT_KEY 2
# define ESC 53

typedef struct s_map
{
	char	**map;
	int		col;
	int		exit;
	int		collect;
}	t_map;

typedef struct s_imgs
{
	void	*player_left;
	void	*player_right;
	void	*player_up;
	void	*player_down;
	void	*collect;
	void	*exit;
	void	*background;
	void	*wall;
}	t_imgs;

typedef struct s_player
{
	int	pos_x;
	int	pos_y;
	int	collect;
}	t_player;

typedef struct s_data
{
	int			length;
	int			height;
	int			counter;
	int			moves;
	void		*mlx;
	void		*window;
	t_map		*map;
	t_imgs		*imgs;
	t_player	player;
}	t_data;

int		main(int argc, char **argv);
void	error_message(char *message);
void	map_info(char **argv, t_data *data);
int		lenght_count(int fd);
int		height_count(int fd, int map_lenght);
char	*skip_before_new_line(char *all_text);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_strchr_gnl(char *s, int c);
void	init(t_map *map, t_data *data);
void	init_help(t_data *data, int lenght, int height);
void	parse_input(t_data *data, char **argv);
void	check_content(t_data *data);
int		counter_for_map(char *s, char c);
void	check_border(t_data *data);
void	rendering_map(t_data *data);
void	rendering_map_help(t_data *data, int x, int y);
void	rendering_map_help_sec(t_data *data, int x, int y);
int		search_solution(int key_code, t_data *data);
int		find_player_position(t_data *data, char axis);
int		exit_function(t_data *data);
void	player_move_down(t_data *data);
void	player_move_down_help(t_data *data, int x, int y);
void	player_move_up(t_data *data);
void	player_move_up_help(t_data *data, int x, int y);
void	player_move_right(t_data *data);
void	player_move_right_help(t_data *data, int x, int y);
void	player_move_left(t_data *data);
void	player_move_left_help(t_data *data, int x, int y);
int		win_message(t_data *data);

#endif
