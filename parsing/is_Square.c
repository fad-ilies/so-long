/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_Square.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifadhli <ifadhli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 00:35:09 by ifadhli           #+#    #+#             */
/*   Updated: 2025/03/29 00:43:44 by ifadhli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int is_Square(char **str)
{
	int	size_first_line;
	int	i;
	
	i = 0;
	size_first_line = ft_strlen(str[i]);
	
	while(str[i])
	{
		if (size_first_line != ft_strlen(str[i]))
			return (0);
		i++;	
	}
	return (1);
}