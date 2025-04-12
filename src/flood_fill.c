/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifadhli <ifadhli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 00:37:39 by ifadhli           #+#    #+#             */
/*   Updated: 2025/04/13 00:45:54 by ifadhli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	flood_fill(t_data *data, int x, int y)
{
	int		wall;
	char	c;

	wall = '1';
	c = 'Z';
	if (x < 0 || y < 0 || x >= data->lignes || y >= data->colonnes)
		return (0);
	if (data->map_copy[x][y] == wall || data->map_copy[x][y] == c)
		return (0);
	data->map_copy[x][y] = c;
	ft_printf("Visite : (%d, %d)\n", x, y); // test
	flood_fill(data, x + 1, y);
	flood_fill(data, x - 1, y);
	flood_fill(data, x, y + 1);
	flood_fill(data, x, y - 1);
	return (1);
}

void	check_flood(t_data *data)
{
	int	x = 0;
	int	y = 0;

	x = 0;

	while (data->map_copy[x])
	{
		y = 0;
		while (data->map_copy[x][y])
		{
			if (data->map_copy[x][y] == 'C'
				|| data->map_copy[x][y] == 'E')
			{
				ft_printf("map pas bonne\n");
				exit_game(data);
				// return ;
			}
			y++;
		}
		x++;
	}
	ft_printf("ok cest cool");
}