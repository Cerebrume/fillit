/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkazanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 16:39:49 by dkazanov          #+#    #+#             */
/*   Updated: 2017/03/07 16:39:54 by dkazanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_error(void)
{
	ft_putstr("error\n");
	exit(0);
}

int		main(int argc, char *argv[])
{
	int		fd;
	char	*str;
	int		glor;
	t_panda	*list;

	if (argc != 2)
	{
		ft_putstr("usege: ./fillit [filename]\n");
		exit(0);
	}
	fd = open(argv[1], O_RDONLY);
	str = readler(fd);
	glor = ft_drunk_valid(str);
	if (!(list = (t_panda *)malloc(sizeof(t_panda) * glor)))
		ft_error();
	list = ft_massive_attack(str, glor);
	list = ft_coord_cobaine(list, glor);
	ft_let_us_die(list, ft_minimal_squad(glor), glor);
	free(list);
	return (0);
}
