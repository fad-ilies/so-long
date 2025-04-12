/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifadhli <ifadhli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 00:23:08 by ifadhli           #+#    #+#             */
/*   Updated: 2025/04/10 23:38:48 by ifadhli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(char **str)
{
	int i;

	i = 0;
	if (!str)
		ft_printf("Erreur : La map est introuvable ou vide.\n");
	while (str[i])
	{
		ft_printf("%s\n", str[i]);
		i++;
	}
}