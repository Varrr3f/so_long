/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_move_help.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:52:25 by sdavos            #+#    #+#             */
/*   Updated: 2022/05/27 15:52:30 by sdavos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_move_down_help(t_data *data, int x, int y)
{
	if (data->map->map[y][x] == 'C')
	{
		data->map->map[y][x] = '0';
		data->player.collect += 1;
	}
	mlx_put_image_to_window(data->mlx, data->window,
		data->imgs->player_down, x * 32, (y + 1) * 32);
	if (data->map->map[y + 1][x] == 'E'
		&& data->map->collect == data->player.collect)
		win_message(data);
	else if (data->map->map[y][x] == 'E')
		mlx_put_image_to_window(data->mlx, data->window,
			data->imgs->exit, x * 32, y * 32);
	else
		mlx_put_image_to_window(data->mlx, data->window,
			data->imgs->background, x * 32, y * 32);
	data->player.pos_y = data->player.pos_y + 1;
}

void	player_move_right_help(t_data *data, int x, int y)
{
	if (data->map->map[y][x] == 'C')
	{
		data->map->map[y][x] = '0';
		data->player.collect += 1;
	}
	mlx_put_image_to_window(data->mlx, data->window,
		data->imgs->player_right, (x + 1) * 32, y * 32);
	if (data->map->map[y][x + 1] == 'E'
		&& data->map->collect == data->player.collect)
		win_message(data);
	else if (data->map->map[y][x] == 'E')
		mlx_put_image_to_window(data->mlx, data->window,
			data->imgs->exit, x * 32, y * 32);
	else
		mlx_put_image_to_window(data->mlx, data->window,
			data->imgs->background, x * 32, y * 32);
	data->player.pos_x = data->player.pos_x + 1;
}

void	player_move_up_help(t_data *data, int x, int y)
{
	if (data->map->map[y][x] == 'C')
	{
		data->map->map[y][x] = '0';
		data->player.collect += 1;
	}
	mlx_put_image_to_window(data->mlx, data->window,
		data->imgs->player_up, x * 32, (y - 1) * 32);
	if (data->map->map[y - 1][x] == 'E'
		&& data->player.collect == data->map->collect)
		win_message(data);
	else if (data->map->map[y][x] == 'E')
		mlx_put_image_to_window(data->mlx, data->window,
			data->imgs->exit, x * 32, y * 32);
	else
		mlx_put_image_to_window(data->mlx, data->window,
			data->imgs->background, x * 32, y * 32);
	data->player.pos_y = data->player.pos_y - 1;
}

void	player_move_left_help(t_data *data, int x, int y)
{
	if (data->map->map[y][x] == 'C')
	{
		data->map->map[y][x] = '0';
		data->player.collect += 1;
	}
	mlx_put_image_to_window(data->mlx, data->window,
		data->imgs->player_left, (x - 1) * 32, y * 32);
	if (data->map->map[y][x - 1] == 'E'
		&& data->player.collect == data->map->collect)
		win_message(data);
	else if (data->map->map[y][x] == 'E')
		mlx_put_image_to_window(data->mlx, data->window,
			data->imgs->exit, x * 32, y * 32);
	else
		mlx_put_image_to_window(data->mlx, data->window,
			data->imgs->background, x * 32, y * 32);
	data->player.pos_x = data->player.pos_x - 1;
}
