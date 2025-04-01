/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifadhli <ifadhli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 00:27:47 by ifadhli           #+#    #+#             */
/*   Updated: 2025/04/01 23:47:14 by ifadhli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "so_long.h"

char **copy_map(t_data *data) 
{
    int i;
    int j;
    
    i = 0;
    while (data->map)
        i++;
    data->map_copy = malloc(sizeof(char *) * (i + 1));
    if (!data->map_copy)
        return(NULL);
    j = 0;
    while (j < i)
    {
        data->map_copy[j] = ft_strdup(data->map[j]);
        if (!data->map_copy[j])
        {
            free_copy(data->map_copy);
            return (NULL);
        }
        j++;
    }
    data->map_copy[i] = NULL;
    return (data->map_copy);
}