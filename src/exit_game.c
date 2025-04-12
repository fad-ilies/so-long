/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifadhli <ifadhli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 00:27:47 by ifadhli           #+#    #+#             */
/*   Updated: 2025/04/13 00:31:54 by ifadhli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_game(t_data *data)
{/*
	if (data->map)
		free_map(data->map);
	if (data->map_copy)
		free(data->map_copy);
	if (data->mlx && data->win)
		mlx_destroy_window(data->mlx, data->win);
	// if (data->mlx)
	// 	mlx_destroy_display(data->mlx);
	// free(data->win);
	// free(data->mlx);
	*/

	if (data->map)
		free_map(data->map);
	if (data->map_copy)
		free_map(data->map_copy);
	if (data->floor)
		mlx_destroy_image(data->mlx, data->floor);
	if (data->play)
		mlx_destroy_image(data->mlx, data->play);
	if (data->wall)
		mlx_destroy_image(data->mlx, data->wall);
	if (data->collect)
		mlx_destroy_image(data->mlx, data->collect);
	if (data->exit)
		mlx_destroy_image(data->mlx, data->exit);
	if (data->mlx && data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{	mlx_destroy_display(data->mlx);
		free((*data).mlx); }
		exit(0);
	return (0);
}