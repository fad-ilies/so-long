/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifadhli <ifadhli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 00:27:47 by ifadhli           #+#    #+#             */
/*   Updated: 2025/04/13 00:18:29 by ifadhli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	clean_exit(t_data *data)
{
		if (data->map)
			free_map(data->map);
		if (data->map_copy)
			free_map(data->map_copy);
		if (data->mlx && data->win)
			mlx_destroy_window(data->mlx, data->win);
		if (data->mlx)
		{
			mlx_destroy_display(data->mlx);
			// free(data->mlx);
		}
	return (1);
}