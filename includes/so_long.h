/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifadhli <ifadhli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 01:59:55 by ifadhli           #+#    #+#             */
/*   Updated: 2025/04/14 23:27:46 by ifadhli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define TILE_SIZE 64  // nbr de pixel pour les img
# define KEY_UP 119    // W
# define KEY_DOWN 115  // S
# define KEY_LEFT 97   // A
# define KEY_RIGHT 100 // D
# define ESC_KEY 65307 // Échap
//# define ERR_USE "Usage : %s <map.ber>\n";

# define BUFFER_SIZE 5
# include "ft_printf.h"
# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_data
{
	char	**map;
	char	**map_copy;
	int		x;
	int		y;
	int		count;
	int		fd;
	int		lignes;
	int		colonnes;
	int		moves;
	void	*mlx;
	void	*win;
	void	*floor;
	void	*wall;
	void	*play;
	void	*collect;
	void	*exit;
}			t_data;

char		**copy_map(t_data *data);
char		*get_next_line(int fd);
int			ft_printf(const char *str, ...);
int			is_Square(t_data *data);
int			first_col_1(char **str);
int			first_line_1(t_data *data);
int			last_col_1(char **str);
int			last_line_1(t_data *data);
int			flood_fill(t_data *data, int x, int y);
int			is_p(char **str, t_data *data);
int			is_c(char **str);
int			is_e(char **str);
int			key_move(int keycode, t_data *data);
int			exit_game(t_data *data);
int			close_window(t_data *data);
int			load_map(char *av, t_data *data);
int			open_fil(char *av);
int			count_line(int fd);
int			check_map_ok(t_data *data);
int			clean_exit(t_data *data);
void		free_map(char **str);
void		print_map(char **str);
void		load_image(t_data *data);
void		img_to_win(t_data *data, int x, int y);
void		map_render(t_data *data);
void		get_map_dimensions(t_data *data);
void		player_move(t_data *data, int dx, int dy);
void		check_flood(t_data *data);
void		allocate_map(t_data *data, int size);
int			check_map_ok(t_data *data);
int			clean_exit(t_data *data);
void		lets_play(t_data *data);

#endif
