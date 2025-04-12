/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendu.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifadhli <ifadhli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 00:39:37 by ifadhli           #+#    #+#             */
/*   Updated: 2025/04/12 05:06:00 by ifadhli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_image(t_data *data)
{
	int	h;
	int	w;

	ft_printf("LOAD IMAGE\n");
	ft_printf("%d == ligne, %d == colonnes\n", data->lignes, data->colonnes);
	print_map(data->map);
	h = 0;
	w = 0;
	data->floor = mlx_xpm_file_to_image(data->mlx, "visu/floor.xpm", &h, &w);
	data->wall = mlx_xpm_file_to_image(data->mlx, "visu/wall.xpm", &h, &w);
	data->play = mlx_xpm_file_to_image(data->mlx, "visu/play.xpm", &h, &w);
	data->collect = mlx_xpm_file_to_image(data->mlx, "visu/collect.xpm", &h,
			&w);
	if (!data->collect || !data->play || !data->wall || !data->floor )
		ft_printf("erreur de telechargement collect / player / floor / wall");	
	data->exit = mlx_xpm_file_to_image(data->mlx, "visu/exit.xpm", &h, &w);
	if (!data->floor || !data->wall || !data->play || !data->collect
		|| !data->exit)
	{
		ft_printf("Erreur : une image n'a pas été chargée correctement.\n");
		exit(1);
	}
}

void	img_to_win(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->win, data->floor, y * TILE_SIZE, x
		* TILE_SIZE);
	if (data->map[x][y] == 'P') // P pour le joueur
	{
		mlx_put_image_to_window(data->mlx, data->win, data->play, y * TILE_SIZE,
			x * TILE_SIZE);
	}
	else if (data->map[x][y] == '1') // 1 pour les murs
		mlx_put_image_to_window(data->mlx, data->win, data->wall, y * TILE_SIZE,
			x * TILE_SIZE);
	else if (data->map[x][y] == 'C') // C pour les collectibles
		mlx_put_image_to_window(data->mlx, data->win, data->collect, y
			* TILE_SIZE, x * TILE_SIZE);
	else if (data->map[x][y] == 'E') // E pour l'exit
		mlx_put_image_to_window(data->mlx, data->win, data->exit, y * TILE_SIZE,
			x * TILE_SIZE);
}

void	map_render(t_data *data)
{
	int x;
	int y;

	x = 0;
	while (data->map[x])
	{
		y = 0;
		while (data->map[x][y])
		{
			img_to_win(data, x, y);
			y++;
		}
		x++;
	}
}