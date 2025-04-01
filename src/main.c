/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifadhli <ifadhli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 02:13:38 by ifadhli           #+#    #+#             */
/*   Updated: 2025/04/01 23:56:32 by ifadhli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/*




// fontion qui affiche une fenetre et attend que je la ferme
int	main(void)
{
	void	*mlx;
	void	*window;

	mlx = mlx_init();
	if (!mlx)
		return (1);
	window = mlx_new_window(mlx, 800, 600, "So Long");
	if (!window)
	{
		free(mlx);
		return (1);
	}
	mlx_loop(mlx);
	return (0);
}
*/
// EXTRAIRE SUR MON TERMINAL MON FICHIER MAP.BER


int is_Square(char **str)
{
	size_t	size_first_line;
	int	i;
	
	i = 0;
	size_first_line = ft_strlen(str[i]);
	
	while(str[i])
	{
		if (size_first_line != ft_strlen(str[i]))
			return (0);
		i++;	
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_data data;
	int	fd;
	char	*line;
	int	i;
	int size  = 0;
	i = 0;
	(void)ac;
	fd = open(av[1], O_RDONLY);
	if (fd <= 0)
	{
		perror("Erreur fichier vide");
		return (1);
	}
	while((line = get_next_line(fd)) != NULL)
	{
		// ft_printf("%s", line);
		free(line);
		size++; // Compter le nbr de lignes
	}
	close(fd);
	data.map = malloc(sizeof(char * ) * (size + 1));
	i = 0;
	fd = open(av[1], O_RDONLY);
	if (fd <= 0)
	{
		perror("Erreur fichier vide");
		return (1);
	}
	while((line = get_next_line(fd)) != NULL)
	{
		data.map[i] = line;
		ft_printf("%s", data.map[i]);
		i++;
	}
	data.map[i] = NULL;
	close(fd);
	i = 0;
	ft_printf("\n");
	if (!is_Square(data.map))
		ft_printf("Pas carre");
	else
		ft_printf("carre");
		
	return (0);
}

