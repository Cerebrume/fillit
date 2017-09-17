/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moon_reader_pro.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkazanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 16:40:24 by dkazanov          #+#    #+#             */
/*   Updated: 2017/03/07 16:40:27 by dkazanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		*ft_cocaine_recursion(char *str, int i)
{
	if (str[i + 1] == '#' && str[i + 1] >= 0)
	{
		str[i + 1] = 'x';
		str = (ft_cocaine_recursion(str, (i + 1)));
	}
	if (str[i - 1] == '#' && str[i - 1] >= 0)
	{
		str[i - 1] = 'x';
		str = (ft_cocaine_recursion(str, (i - 1)));
	}
	if (str[i + 5] == '#' && str[i + 5] >= 0)
	{
		str[i + 5] = 'x';
		str = (ft_cocaine_recursion(str, (i + 5)));
	}
	return (str);
}

char		*readler(int fd)
{
	char	*tmp;
	int		i;
	int		read_c;
	char	*teranius;
	char	buff[1];

	i = 0;
	if (fd < 0)
		ft_error();
	tmp = (char *)malloc(sizeof(char) * 546);
	while ((read_c = read(fd, &buff[0], 1)))
	{
		tmp[i] = buff[0];
		i++;
		if (i > 546)
			ft_error();
	}
	tmp[i] = '\0';
	teranius = ft_strdup(tmp);
	free(tmp);
	return (teranius);
}

t_panda		*ft_massive_attack(char *str, int glor)
{
	t_panda	*tmp;
	int		i;
	char	c;
	int		j;

	tmp = (t_panda *)malloc(sizeof(t_panda) * glor);
	if (tmp == NULL)
		ft_error();
	i = 0;
	j = 0;
	c = 64;
	while (i < glor)
	{
		tmp[i].str = ft_strndup(&str[j], 20);
		ft_dead_tetri(tmp[i].str);
		tmp[i].c = ++c;
		j += 21;
		i++;
	}
	return (tmp);
}

int			ft_minimal_squad(int glor)
{
	int size;

	size = 2;
	while (size * size < glor)
		size++;
	return (size);
}
