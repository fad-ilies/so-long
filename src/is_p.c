/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifadhli <ifadhli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 00:35:09 by ifadhli           #+#    #+#             */
/*   Updated: 2025/04/14 21:24:56 by ifadhli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int	is_p(char **str, t_data *data)
// {
// 	int	i;
// 	int	j;
// 	int	count;

// 	i = 0;
// 	count = 0; // Initialisation du compteur d'apparitions de 'P'
// 	if (!str)
// 	return (ft_printf("Erreur : La map est introuvable ou vide.\n"), 0);
// 	while (str[i]) // Parcour des lignes de la carte
// 	{
// 		j = 0;            // Réinitialiser j pour chaque nouvelle ligne
// 		while (str[i][j]) // Parcour des caractères de chaque ligne
// 		{
// 			if (str[i][j] == 'P') // Si on trouve un 'P',
// 			{
// 				count += 1;
// 				data->x = i; // Enregistre la position x
// 				data->y = j; // Enregistre la position y				
// 			}
// 			j++;
// 		}
// 		i++; // Passer à la ligne suivante
// 	}
// 	if (count != 1) // Si il y a plus ou moins d'un 'P', ce n'est pas valide
// 		return (ft_printf("Erreur : Nombre de joueurs incorrect (%d)\n", count), 0);
// 	return (1); 
// }

int	is_p(char **map, t_data *data)
{
	int	i = 0;
	int	j;
	int	found = 0;

	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				if (found)
					return (0); // déjà trouvé un P
				data->x = i;
				data->y = j;
				found = 1;
			}
			j++;
		}
		i++;
	}
	return (found); // 1 si trouvé, 0 sinon
}
