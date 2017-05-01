/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resize_piece.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 12:52:19 by clegoube          #+#    #+#             */
/*   Updated: 2017/04/25 18:58:27 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"


char	*supp_cols(t_game *game, char **piece)
{
	int		i;
	int		j;
	int		count;
	char	*supp_cols;

	j = -1;
	count = 0;
	supp_cols = ft_strnew(game->piece_col_max);
	while (++j < game->piece_col_max)
	{
		i = 0;
		while (i < game->piece_line_max && piece[i][j] == '.')
			i++;
		if (i == game->piece_line_max)
		{
			if (j == count)
				count++;
			supp_cols[j] = 'n';
		}
		else
			supp_cols[j] = 'y';
	}
	game->coordo[1] = count * -1;
	return (supp_cols);
}

char	*supp_lines(t_game *game, char **piece)
{
	int		i;
	int		j;
	int		count;
	char	*supp_lines;

	i = -1;
	count = 0;
	supp_lines = ft_strnew(game->piece_line_max);
	while (++i < game->piece_line_max)
	{
		j = 0;
		while (j < game->piece_col_max && piece[i][j] == '.')
			j++;
		if (j == game->piece_col_max)
		{
			if (i == count)
				count++;
			supp_lines[i] = 'n';
		}
		else
			supp_lines[i] = 'y';

	}
	game->coordo[0] = count * -1;
	return (supp_lines);
}

int		count_char(char *s, char c)
{
	int i;
	int count;

	i = -1;
	count = 0;
	while(s[++i])
	{
		if (s[i] == c)
			count++;
	}
	return (count);
}

void	ft_resize_piece(t_game *game, char **piece, char *subline, char *subcol)
{
	int		i;
	int		j;
	int		k;
	int		l;

	k = -1;
	i = -1;
	while (++k < game->piece_line_max)
	{
		if (subline[k] == 'y')
		{
			game->piece[++i] = ft_strnew(game->piece_col);
			l = -1;
			j = 0;
			while (++l < game->piece_col_max && piece[k][l])
				if (subcol[l] == 'y')
					game->piece[i][j++] = piece[k][l];
			game->piece[i][j] = '\0';
		}
	}
	i = 0;
	while (i < game->piece_line_max)
		ft_strdel(&(piece[i++]));
	free(piece);
	ft_strdel(&(subcol));
	ft_strdel(&(subline));
}
