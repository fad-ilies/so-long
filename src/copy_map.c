/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifadhli <ifadhli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 00:27:47 by ifadhli           #+#    #+#             */
/*   Updated: 2025/04/12 04:37:57 by ifadhli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

char	**copy_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	if (!data->map)
	{
		ft_printf("map d'orine pas bonne");
		return (NULL);
	}
	while (data->map[i])
		i++;
	data->map_copy = malloc(sizeof(char *) * (i + 1));
	if (!data->map_copy)
		return (free_map(data->map_copy), NULL);
	j = 0;
	while (j < i)
	{
		data->map_copy[j] = ft_strdup(data->map[j]);
		if (!data->map_copy[j])
			return (free_map(data->map_copy), NULL);
		j++;
	}
	data->map_copy[i] = NULL;
	return (data->map_copy);
}
