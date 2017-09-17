/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkazanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 16:35:57 by dkazanov          #+#    #+#             */
/*   Updated: 2017/03/07 16:36:19 by dkazanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "./libft/libft.h"
# include <stdio.h>

typedef struct		s_lst
{
	int				x[4];
	int				y[4];
	char			*str;
	void			*blackhole;
	char			c;
	int				point;
}					t_panda;

char				*readler(int fd);
t_panda				*ft_massive_attack(char *str, int glor);
int					ft_minimal_squad(int glor);
t_panda				ft_split_coord(t_panda list, char **tmp);
t_panda				*ft_coord_cobaine(t_panda *list, int glor);
void				ft_error(void);
int					ft_drunk_valid(char *s);
void				ft_dead_tetri(char *str);
t_panda				ft_deal_with_position(t_panda list, int x, int y);
void				ft_let_us_die(t_panda *list, int squad, int glor);
char				**ft_fill_empty_souls(char **map, int size);
char				**ft_greatoz(char **map, t_panda *list, int j[2], int i);
void				ft_print_this(char **dothis);
char				*ft_cocaine_recursion(char *str, int i);
#endif
