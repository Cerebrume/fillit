/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validotrone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkazanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 16:40:46 by dkazanov          #+#    #+#             */
/*   Updated: 2017/03/07 16:40:49 by dkazanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_curve_check(char *read_b)
{
	int i;
	int n;
	int j;

	i = 0;
	n = 0;
	j = 0;
	while (read_b[i] != '\0')
	{
		if (read_b[i] == '\n')
		{
			n++;
			j = n % 4;
			if (read_b[i + 1] == '\n' && j == 0)
			{
				n = 0;
				i++;
			}
			else if (read_b[i + 1] == '\n')
				ft_error();
		}
		i++;
	}
}

void		ft_drunk_cicle(char *s, int *dt, int *sp, int *nl)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '.')
			(*dt)++;
		else if (s[i] == '#')
			(*sp)++;
		else if (s[i] == '\n')
			(*nl)++;
		else
			ft_error();
		i++;
	}
	if ((*sp) < 4)
		ft_error();
}

static void	ft_damn_val(char *s)
{
	int i;
	int sym;

	i = 0;
	sym = -1;
	while (s[i] != '\0')
	{
		if (s[i] == '\n' && s[i + 1] == '\n')
			i++;
		sym++;
		if (s[i] == '\n' && s[i + 1] != '\n' && s[i + 1] != '\0')
		{
			if (sym != 4)
				ft_error();
			sym = -1;
		}
		i++;
	}
}

int			ft_drunk_valid(char *s)
{
	int dt;
	int sp;
	int nl;

	dt = 0;
	sp = 0;
	nl = 0;
	ft_curve_check(s);
	ft_drunk_cicle(s, &dt, &sp, &nl);
	ft_damn_val(s);
	if (dt % 4 || sp % 4 || ((nl + 1) % 5))
		ft_error();
	return (sp / 4);
}

void		ft_dead_tetri(char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i] != '#')
		i++;
	str[i] = 'x';
	str = ft_cocaine_recursion(str, i);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 'x')
			j++;
		i++;
	}
	if (j != 4)
		ft_error();
}
