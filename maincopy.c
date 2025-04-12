// #include "so_long.h"
// #include <fcntl.h>
// #include <stdlib.h>

// int	main(int ac, char **av)
// {
// 	t_data	*data;
// 	int		fd;
// 	char	*line;
// 	int		size;
// 	int		i;

// 	size = 0;
// 	i = 0;
// 	if (ac != 2)
// 	{
// 		ft_printf("Usage : %s <map.ber>\n", av[0]);
// 		return (1);
// 	}
// 	data = malloc(sizeof(t_data));
// 	if (!data)
// 		return (perror("Erreur allocation mémoire pour 'data'"), 1);
// 	// Initialisation des champs
// 	data->x = 0;
// 	data->y = 0;
// 	data->moves = 0;
// 	data->map = NULL;
// 	data->map_copy = NULL;
// 	data->mlx = NULL;
// 	data->win = NULL;
// 	fd = open(av[1], O_RDONLY);
// 	if (fd < 0)
// 		return (perror("Erreur ouverture fichier"), free(data), 1);
// 	while ((line = get_next_line(fd)))
// 	{
// 		free(line);
// 		size++;
// 	}
// 	close(fd);
// 	data->map = malloc(sizeof(char *) * (size + 1));
// 	if (!data->map)
// 		return (perror("Erreur allocation map"), free(data), 1);
// 	fd = open(av[1], O_RDONLY);
// 	if (fd < 0)
// 		return (perror("Erreur ouverture fichier"), free_map(data->map),
// 			free(data), 1);
// 	while ((line = get_next_line(fd)))
// 		data->map[i++] = line;
// 	data->map[i] = NULL;
// 	// for (int i = 0; data->map[i]; ++i)
// 	//     printf("%s\n", data->map[i]);
// 	close(fd);
// 	// Vérification de forme et contenu
// 	if (!is_Square(data->map))
// 		return (ft_printf("Erreur : map non carrée\n"), free_map(data->map),
// 			free(data), 1);
// 	data->count = is_c(data->map);
// 	if (!is_p(data->map, data) || !data->count || !is_e(data->map))
// 		return (ft_printf("Erreur : map invalide\n"), free_map(data->map),
// 			free(data), 1);
// 	// Flood fill sur copie de la map
// 	data->map_copy = copy_map(data);
// 	if (!data->map_copy)
// 		return (perror("Erreur copie map"), free_map(data->map), free(data), 1);
// 	flood_fill(data, data->x, data->y);
// 	check_flood(data);
// 	// Dimensions de la map
// 	data->lignes = i;
// 	data->colonnes = ft_strlen(data->map[0]);
// 	// Initialisation MLX
// 	data->mlx = mlx_init();
// 	if (!data->mlx)
// 		return (perror("Erreur init MLX"), free_map(data->map),
// 			free_map(data->map_copy), free(data), 1);
// 	get_map_dimensions(data);
// 	data->win = mlx_new_window(data->mlx, data->colonnes * TILE_SIZE,
// 			data->lignes * TILE_SIZE, "So Long");
// 	if (!data->win)
// 		return (perror("Erreur fenêtre"), mlx_destroy_display(data->mlx),
// 			free(data->mlx), free_map(data->map), free_map(data->map_copy),
// 			free(data), 1);
// 	load_image(data);
// 	map_render(data);
// 	mlx_key_hook(data->win, key_move, data);
// 	mlx_hook(data->win, 17, 0, close_window, data);
// 	mlx_loop(data->mlx);
// 	return (0);
// }