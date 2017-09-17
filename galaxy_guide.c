/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   galaxy_guide.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkazanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 16:37:37 by dkazanov          #+#    #+#             */
/*   Updated: 2017/03/07 16:38:14 by dkazanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_panda		ft_split_coord(t_panda list, char **tmp)
{
	int x;
	int y;
	int j;

	y = 0;
	j = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (tmp[y][x] == 'x')
			{
				list.x[j] = x;
				list.y[j] = y;
				j++;
			}
			x++;
		}
		y++;
	}
	return (list);
}

t_panda		*ft_coord_cobaine(t_panda *list, int glor)
{
	int	i;

	i = 0;
	while (i < glor)
	{
		list[i] = ft_split_coord(list[i], ft_strsplit(list[i].str, '\n'));
		free(list[i].str);
		i++;
	}
	return (list);
}
