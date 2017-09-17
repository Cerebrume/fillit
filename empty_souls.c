/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty_souls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkazanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 16:57:16 by dkazanov          #+#    #+#             */
/*   Updated: 2017/03/12 16:57:21 by dkazanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	char	**ft_stolen_life(char **map, t_panda *list, int max)
{
	int x;
	int y;
	int i;

	y = 0;
	i = 0;
	while (y < max)
	{
		x = 0;
		while (x < max)
		{
			if (list->x[i] == x && list->y[i] == y)
			{
				map[y][x] = list->c;
				i++;
			}
			x++;
		}
		y++;
	}
	return (map);
}

static	char	**ft_back_to_school(char **map, t_panda *list, int max)
{
	int x;
	int y;

	y = 0;
	while (y < max)
	{
		x = 0;
		while (x < max)
		{
			if (map[y][x] == list->c)
				map[y][x] = '.';
			x++;
		}
		y++;
	}
	return (map);
}

static	char	**ft_is_wegood(char **map, t_panda *list, int max)
{
	int x;
	int y;
	int i;

	y = 0;
	i = 0;
	while (y < max)
	{
		x = 0;
		while (x < max)
		{
			if (list->x[i] == x && list->y[i] == y && map[y][x] != '.')
				return (0);
			else if (list->x[i] == x && list->y[i] == y)
				i++;
			x++;
		}
		y++;
	}
	if (i < 4)
		return (0);
	map = ft_stolen_life(map, list, max);
	return (map);
}

char			**ft_greatoz(char **map, t_panda *list, int j[2], int i)
{
	int		c[2];
	char	**tmp;

	if (i == j[1])
		return (map);
	tmp = NULL;
	c[0] = 0;
	while (c[0] < j[0])
	{
		c[1] = 0;
		while (c[1] < j[0])
		{
			list[i] = ft_deal_with_position(list[i], c[1], c[0]);
			if ((tmp = ft_is_wegood(map, &list[i], j[0])))
			{
				if (ft_greatoz(map, list, j, (i + 1)))
					return (tmp);
				else
					ft_back_to_school(map, &list[i], j[0]);
			}
			c[1]++;
		}
		c[0]++;
	}
	return (tmp);
}
