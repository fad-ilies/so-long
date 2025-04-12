/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_Square.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifadhli <ifadhli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 00:35:09 by ifadhli           #+#    #+#             */
/*   Updated: 2025/04/10 01:36:44 by ifadhli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_Square(char **str)
{
	size_t	size_first_line;
	int		i;

	i = 0;
	size_first_line = ft_strlen(str[i]);
	while (str[i])
	{
		if (size_first_line != ft_strlen(str[i]))
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
