/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   answer_to_life.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkazanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 16:24:52 by dkazanov          #+#    #+#             */
/*   Updated: 2017/03/12 16:24:58 by dkazanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_panda	ft_deal_with_position(t_panda list, int x, int y)
{
	int ymin;
	int xmin;
	int i;

	ymin = 223;
	xmin = 223;
	i = 0;
	while (i != 4)
	{
		if (list.x[i] < xmin)
			xmin = list.x[i];
		if (list.y[i] < ymin)
			ymin = list.y[i];
		i++;
	}
	i = 0;
	while (i != 4)
	{
		list.x[i] = list.x[i] - xmin + x;
		list.y[i] = list.y[i] - ymin + y;
		i++;
	}
	return (list);
}

char	**ft_fill_empty_souls(char **map, int size)
{
	int x;
	int y;

	y = 0;
	if (!(map = (char **)malloc(sizeof(char *) * (size + 1))))
		ft_error();
	while (y < size)
	{
		map[y] = ft_strnew(size);
		x = 0;
		while (x < size)
		{
			map[y][x] = '.';
			x++;
		}
		y++;
	}
	map[y] = NULL;
	return (map);
}

void	ft_print_this(char **dothis)
{
	int i;

	i = 0;
	while (dothis[i])
	{
		ft_putstr(dothis[i]);
		write(1, "\n", 1);
		i++;
	}
}

void	ft_let_us_die(t_panda *list, int squad, int glor)
{
	char	**dothis;
	int		i;
	int		j[2];

	j[0] = squad;
	j[1] = glor;
	i = 0;
	dothis = NULL;
	dothis = ft_fill_empty_souls(dothis, squad);
	while (!(dothis = ft_greatoz(dothis, list, j, i)))
	{
		j[0]++;
		free(dothis);
		dothis = ft_fill_empty_souls(dothis, j[0]);
	}
	ft_print_this(dothis);
}
