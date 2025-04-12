/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_e.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifadhli <ifadhli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 00:39:37 by ifadhli           #+#    #+#             */
/*   Updated: 2025/04/10 01:37:40 by ifadhli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_e(char **str)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (str[i])
	{
		while (str[i][j])
		{
			if (str[i][j] == 'E')
				count += 1;
			j++;
		}
		j = 0;
		i++;
	}
	if (count != 1)
		return (0);
	return (1);
}
