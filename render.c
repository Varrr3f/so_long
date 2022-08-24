/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:08:20 by sdavos            #+#    #+#             */
/*   Updated: 2022/05/27 15:08:21 by sdavos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	rendering_map_help_sec(t_data *data, int x, int y)
{
	if (data->map->map[y][x] == 'E')
	{
		mlx_put_image_to_window(data->mlx, data->window,
			data->imgs->exit, x * 32, y * 32);
	}
	else
	{
		mlx_put_image_to_window(data->mlx, data->window,
			data->imgs->background, x * 32, y * 32);
	}
}

void	rendering_map_help(t_data *data, int x, int y)
{
	if (data->map->map[y][x] == 'P')
	{
		mlx_put_image_to_window(data->mlx, data->window,
			data->imgs->player_down, x * 32, y * 32);
			data->player.pos_x = x;
			data->player.pos_y = y;
	}
	else if (data->map->map[y][x] == 'C')
	{
		mlx_put_image_to_window(data->mlx, data->window,
			data->imgs->collect, x * 32, y * 32);
	}
	else if (data->map->map[y][x] == '1')
	{
		mlx_put_image_to_window(data->mlx, data->window,
			data->imgs->wall, x * 32, y * 32);
	}
	else
		rendering_map_help_sec(data, x, y);
}

void	rendering_map(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->length)
		{
			rendering_map_help(data, x, y);
			x++;
		}
		y++;
	}
	mlx_hook(data->window, 17, 1L << 2, exit_function, data);
	mlx_key_hook(data->window, search_solution, data);
}
