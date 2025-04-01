/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifadhli <ifadhli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 00:37:39 by ifadhli           #+#    #+#             */
/*   Updated: 2025/04/01 22:59:06 by ifadhli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int flood_fill(int x, int y, int target, char c)
{
    int wall;
    
    wall = '1';
    c = 'Z';
    if (map[x][y] == wall || map[x][y] == c)
        return (0);
    map[x][y] = c;
    flood_fill(x + 1, y, c);
    flood_fill(x - 1, y, c);
    flood_fill(x, y + 1, c);
    flood_fill(x, y - 1, c);
    return (0);
}