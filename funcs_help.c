/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:07:34 by sdavos            #+#    #+#             */
/*   Updated: 2022/05/27 15:07:37 by sdavos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_function(t_data *data)
{
	mlx_destroy_window(data->mlx, data->window);
	printf("EXIT THE GAME!");
	exit(0);
}

int	win_message(t_data *data)
{
	mlx_destroy_window(data->mlx, data->window);
	printf("You won!");
	exit(0);
}

void	error_message(char *message)
{
	ft_putstr_fd(message, 2);
	exit(1);
}

int	counter_for_map(char *s, char c)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (s && s[i])
		if (s[i++] == c)
			ret++;
	return (ret);
}
