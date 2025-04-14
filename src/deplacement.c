/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deplacement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifadhli <ifadhli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 00:27:47 by ifadhli           #+#    #+#             */
/*   Updated: 2025/04/14 21:52:55 by ifadhli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void	check_if_exit(t_data *data)
{
		ft_printf("%d\n", data->count);
		if (data->count == 0)
		{
			ft_printf("Felicitation tu as remporte la partie !!\n");
			exit_game(data);
		}
		else
		{
			ft_printf("La prochaine serra la bonne\n");
			return ;
		}
}
void	new_pos(t_data *data, int new_x, int new_y)
{
	if (data->map[new_x][new_y] == 'E' && data->count != 0)
		return ;
	data->map[data->x][data->y] = '0';
	data->x = new_x;
	data->y = new_y;
	data->map[data->x][data->y] = 'P';
	data->moves++;
	ft_printf("moves = %d\n", data->moves);
}
void	player_move(t_data *data, int dx, int dy)
{
	int		new_x;
	int		new_y;
	char	temp;

	new_x = data->x + dx;
	new_y = data->y + dy;
	if (new_x < 0 || new_y < 0 || new_x >= data->lignes
		|| new_y >= data->colonnes)
		return ;
	temp = data->map[new_x][new_y];
	if (temp == 'C')
	{
		data->count--;
		data->map[new_x][new_y] = '0';
	}
	if (temp == '1')
		return ;
	if (temp == 'E' && data->count == 0)
	{
		ft_printf("\n%d ICI \n", data->count);
		ft_printf("%d\n", data->count);
		check_if_exit(data);
	}

	new_pos(data, new_x, new_y);
	map_render(data);
}

int	key_move(int keycode, t_data *data)
{
	if (keycode == KEY_UP) // W
		player_move(data, -1, 0);
	else if (keycode == KEY_DOWN) // S
		player_move(data, 1, 0);
	else if (keycode == KEY_LEFT) // A
		player_move(data, 0, -1);
	else if (keycode == KEY_RIGHT) // D
		player_move(data, 0, 1);
	else if (keycode == ESC_KEY) // escape
		exit_game(data);
	return (0);
}
