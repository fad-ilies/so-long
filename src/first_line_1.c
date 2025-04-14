/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_line_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifadhli <ifadhli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 00:23:08 by ifadhli           #+#    #+#             */
/*   Updated: 2025/04/14 23:29:05 by ifadhli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	first_line_1(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	printf("fiiiiirst lineee\n");
	
	if (!data->map || !data->map[0][j])
		return (0);
	while (data->map[0][j] != '\n')
	{
		ft_printf("char first line %c\n", data->map[0][j]);
		if (data->map[0][j] != '1')
			return (0);
		j++;
	}
	return (1);
}
