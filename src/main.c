/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifadhli <ifadhli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 02:13:38 by ifadhli           #+#    #+#             */
/*   Updated: 2025/04/13 00:52:33 by ifadhli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>
#include <stdlib.h>

// t_data	*set_data(t_data *data)
// {
// 	// t_data	*data;

// 	// data = malloc(sizeof(t_data));
// 	// if (!data)
// 	// {
// 	// 	return (perror("Erreur allocation mémoire pour 'data'"), NULL);
// 	// }
// 	data->colonnes = 0;
// 	data->lignes = 0;
// 	data->x = 0;
// 	data->y = 0;
// 	data->moves = 0;
// 	data->map = NULL;
// 	data->map_copy = NULL;
// 	data->mlx = NULL;
// 	data->win = NULL;
// 	return (data);
// }
int	open_fil(char *av)
{
	int	fd;

	fd = open(av, O_RDONLY);
	if (fd < 0)
	{
		perror("Fichier non valide");
	}
	return (fd);
}

int	count_line(int fd)
{
	char	*line;
	int		size;

	size = 0;
	while ((line = get_next_line(fd)))
	{
		free(line);
		size++;
	}
	return (size);
}
void	allocate_map(t_data *data, int size)
{
	data->map = malloc(sizeof(char *) * (size + 1));
	if (!data->map)
	{
		perror("erreur d'allocation memoire");
		free(data);
		exit(1);
	}
}

int	load_map(char *av, t_data *data)
{
	int		fd;
	int		size;
	int		i;
	char	*line;

	fd = open_fil(av);
	if (fd < 0)
		return (1);
	size = count_line(fd);
	close(fd);
	allocate_map(data, size);
	fd = open_fil(av);
	if (fd < 0)
		return (free_map(data->map), 1);
	i = 0;
	while ((line = get_next_line(fd)))
		data->map[i++] = line;
	data->map[i] = NULL;
	close(fd);
	return (0);
}
int	check_map_ok(t_data *data)
{
	if (!is_Square(data->map))
	{
		ft_printf("Erreur : map non carrée\n"), free_map(data->map);
		return (1);
	}
	data->count = is_c(data->map);
	if (!is_p(data->map, data) || !data->count || !is_e(data->map))
		return (ft_printf("Erreur : map invalide\n"), free_map(data->map), 1);
	// Flood fill sur copie de la map
	data->map_copy = copy_map(data);
	if (!data->map_copy)
		return (perror("Erreur copie map"), free_map(data->map), free(data), 1);
	flood_fill(data, data->x, data->y);
	check_flood(data);
	return (0);
}

int	ini_mlx(t_data *data)
{
	data->lignes = 0;
	while (data->map[data->lignes])
		data->lignes++;
	data->colonnes = ft_strlen(data->map[0]);
	data->mlx = mlx_init();
	if (!data->mlx)
		return (perror("Erreur init MLX"), exit_game(data));
	get_map_dimensions(data);
	data->win = mlx_new_window(data->mlx, data->colonnes * TILE_SIZE,
			data->lignes * TILE_SIZE, "So Long");
	if (!data->win)
		return (perror("Erreur fenêtre"), clean_exit(data));
	return (0);
}

void	lets_play(t_data *data)
{
	load_image(data);
	map_render(data);
	mlx_key_hook(data->win, key_move, data);
	mlx_hook(data->win, 17, 0, close_window, data);
	mlx_loop(data->mlx);
}

#define ERR_USE "Usage : %s <map.ber>\n"

int	main(int ac, char **av)
{
	static t_data	data = {0};
	int				size;
	int				i;

	size = 0;
	i = 0;
	if (ac != 2)
		return (ft_printf(ERR_USE, av[0]), 1);
	// data = set_data(&data);
	// if (&data == NULL)
	// return (1);
	if (load_map(av[1], &data))
		return (1);
	if (check_map_ok(&data))
		return (1);
	if (ini_mlx(&data))
		return (1);
	lets_play(&data);
	get_next_line(-1);
	exit_game(&data);
	return (0);
}
