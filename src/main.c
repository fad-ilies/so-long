/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifadhli <ifadhli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 02:13:38 by ifadhli           #+#    #+#             */
/*   Updated: 2025/04/14 23:31:47 by ifadhli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>
#include <stdlib.h>

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
	{
		// printf("line -> %s\n", line);
		data->map[i++] = line;
	}
	data->map[i] = NULL;
	close(fd);
	return (0);
}
int	check_map_ok(t_data *data)
{
	if (!is_Square(data))
	{
		ft_printf("Erreur : map non carree\n"), free_map(data->map);
		return (1);
	}
	data->count = is_c(data->map);
	// printf("Avant parsing");
	if (!is_p(data->map, data) || !first_col_1(data->map) || !last_col_1(data->map) || !last_line_1(data) || !first_line_1(data) || !data->count || !is_e(data->map))
		return (ft_printf("Erreur : map invalide\n"), free_map(data->map), 1);
	// Flood fill sur copie de la map
	data->map_copy = copy_map(data);
	if (!data->map_copy)
		return (perror("Erreur copie map\n"), free_map(data->map), free(data), 1);
	flood_fill(data, data->x, data->y);
	// printf("\nApres Flood fill\n");
	// print_map(data->map_copy);
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
	if (load_map(av[1], &data))
		return (1);
	// print_map(data.map);
	// return 0;
	if (check_map_ok(&data))
		return (1);
	if (ini_mlx(&data))
		return (1);
	lets_play(&data);
	get_next_line(-1);
	exit_game(&data);
	return (0);
}
