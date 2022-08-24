/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:08:10 by sdavos            #+#    #+#             */
/*   Updated: 2022/05/27 15:08:12 by sdavos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	search_solution(int key_code, t_data *data)
{
	if (key_code == ESC)
		exit_function(data);
	else if (key_code == UP_KEY)
		player_move_up(data);
	else if (key_code == DOWN_KEY)
		player_move_down(data);
	else if (key_code == RIGHT_KEY)
		player_move_right(data);
	else if (key_code == LEFT_KEY)
		player_move_left(data);
	return (0);
}

void	player_move_down(t_data *data)
{
	int	x;
	int	y;

	x = data->player.pos_x;
	y = data->player.pos_y;
	if (data->map->map[y + 1][x] != '1')
	{
		data->moves++;
		player_move_down_help(data, x, y);
		ft_putnbr_fd(data->moves, 1);
		write(1, "\n", 1);
	}
	else
		mlx_put_image_to_window(data->mlx, data->window,
			data->imgs->player_down, x * 32, y * 32);
}

void	player_move_up(t_data *data)
{
	int	x;
	int	y;

	x = data->player.pos_x;
	y = data->player.pos_y;
	if (data->map->map[y - 1][x] != '1')
	{
		data->moves++;
		player_move_up_help(data, x, y);
		ft_putnbr_fd(data->moves, 1);
		write(1, "\n", 1);
	}
	else
		mlx_put_image_to_window(data->mlx, data->window,
			data->imgs->player_up, x * 32, y * 32);
}

void	player_move_right(t_data *data)
{
	int	x;
	int	y;

	x = data->player.pos_x;
	y = data->player.pos_y;
	if (data->map->map[y][x + 1] != '1')
	{
		data->moves++;
		player_move_right_help(data, x, y);
		ft_putnbr_fd(data->moves, 1);
		write(1, "\n", 1);
	}
	else
		mlx_put_image_to_window(data->mlx, data->window,
			data->imgs->player_right, x * 32, y * 32);
}

void	player_move_left(t_data *data)
{
	int	x;
	int	y;

	x = data->player.pos_x;
	y = data->player.pos_y;
	if (data->map->map[y][x - 1] != '1')
	{
		data->moves++;
		player_move_left_help(data, x, y);
		ft_putnbr_fd(data->moves, 1);
		write(1, "\n", 1);
	}
	else
		mlx_put_image_to_window(data->mlx, data->window,
			data->imgs->player_left, x * 32, y * 32);
}
