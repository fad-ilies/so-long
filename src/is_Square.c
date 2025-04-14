/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_Square.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifadhli <ifadhli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 00:35:09 by ifadhli           #+#    #+#             */
/*   Updated: 2025/04/14 23:26:03 by ifadhli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_Square(t_data *data){
	size_t	first_line;
	int		i;

	i = 0;
	first_line = ft_strlen(data->map[0]);
	
	
	while (data->map[i])
	{
		// printf("size 1line%zu\n", size_first_line);
		// printf("size nline%zu\n", ft_strlen(str[i]));
		if (first_line != ft_strlen(data->map[i]))
			return (0);
		i++;
	}
	return (1);
}

void	get_map_dimensions(t_data *data)
{
	// int	i;
	data->lignes = 0;
	data->colonnes = 0;
	while (data->map[data->lignes])
		data->lignes++;
	if (data->lignes > 0)
	{
		data->colonnes = ft_strlen(data->map[0]);
		if (data->map[0][data->colonnes - 1] == '\n')
			data->colonnes--;
	}
}
