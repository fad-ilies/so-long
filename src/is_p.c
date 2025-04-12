/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifadhli <ifadhli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 00:35:09 by ifadhli           #+#    #+#             */
/*   Updated: 2025/04/12 04:50:12 by ifadhli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_p(char **str, t_data *data)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0; // Initialisation du compteur d'apparitions de 'P'
	if (!str)
	return (ft_printf("Erreur : La map est introuvable ou vide.\n"), 0);
	while (str[i]) // Parcour des lignes de la carte
	{
		j = 0;            // Réinitialiser j pour chaque nouvelle ligne
		while (str[i][j++]) // Parcour des caractères de chaque ligne
		{
			if (str[i][j] == 'P') // Si on trouve un 'P',
			{
				count += 1;
				data->x = i; // Enregistre la position x
				data->y = j; // Enregistre la position y				
			}
		}
		i++; // Passer à la ligne suivante
	}
	if (count != 1) // Si il y a plus ou moins d'un 'P', ce n'est pas valide
		return (ft_printf("Erreur : Nombre de joueurs incorrect (%d)\n", count), 0);
	return (1); 
}
