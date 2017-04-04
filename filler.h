/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <jjaouen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 13:00:28 by jjaouen           #+#    #+#             */
/*   Updated: 2017/04/04 17:34:01 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# define BUFF_SIZE 235

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct		s_coor
{
	char			letter;
	int				*x;
	int				*y;
	struct s_coor	*next;
}					t_coor;

typedef struct		s_var
{
	int				fd;
	int				ret;
	size_t			loop;
	size_t			x_first;
	size_t			y_first;
	char			letter;
	size_t			line;
	size_t			col;
	size_t			i;
	t_list			*new;
	int				*y;
	int				*x;
	int				n;
}					t_var;

typedef struct		s_game
{
	int		player;
	int		X_lenght;
	int		piece_lenght;
	int		Y_width;
	int		piece_width;
	char	symbol;
	char**	map;
	char**	piece;
}					t_game;

int		get_next_line(const int fd, char **line);
char	**ft_strsplit(char const *s, char c);
void	ft_stock_map(char **line, t_game *game);
void	ft_stock_piece(char **line, t_game *game);
void	ft_stock_struct(char **line, t_game *game);
void	ft_strategy_game(t_game *game);

#endif
