/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifadhli <ifadhli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 01:59:55 by ifadhli           #+#    #+#             */
/*   Updated: 2025/04/01 23:43:23 by ifadhli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H
#  define BUFFER_SIZE 5
#include "mlx.h"
#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

typedef struct s_data {
    char	**map;
	char	**map_copy;
	int	i;
	int	j;
	int	count;
	int	fd;
	
	
	        
    
} t_data;


char	*get_next_line(int fd);
int	ft_printf(const char *str, ...);

#endif
