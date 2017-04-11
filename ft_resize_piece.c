/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resize_piece.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 12:52:19 by clegoube          #+#    #+#             */
/*   Updated: 2017/04/11 13:23:28 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_realloc_piece( t_game *game, char **piece, int subline, int subcol)
{
	int i;

	i = 0;
	while (i < game->piece_line)
		ft_strdel(&(game->piece[i++]));
	free(game->piece);
	game->piece_line = game->piece_line - subline;
	game->piece_col = game->piece_col - subcol;
	i = -1;
	game->piece = (char **)malloc(sizeof(char *) * (game->piece_line));
	while (++i < game->piece_line)
	{
		game->piece[i] = ft_strnew(game->piece_col + 1);
		ft_strcpy(game->piece[i], piece[i]);
	}
	i = 0;
	while (i < game->piece_line)
		ft_strdel(&(piece[i++]));
	free(piece);
}

void	ft_reduce_piece_line( t_game *game, int subline, int startline)
{
	int i;
	int j;
	int k;
	char **piece;

	i = 0;
	j = 0;
	piece = (char **)malloc(sizeof(char *) * (game->piece_line - subline));
	while (i < game->piece_line)
	{
		if (i == startline)
		{
			k = 0;
			while (k++ < subline)
				i++;
		}
		else
		{
			piece[j] = ft_strnew(game->piece_col + 1);
			ft_strcpy(piece[j++], game->piece[i++]);
		}
	}
	ft_realloc_piece(game, piece, subline, 0);
}

void	ft_reduce_piece_col( t_game *game, int subcol, int startcol)
{
	int i;
	int j;
	int k;
	int l;
	char **piece;

	j = 0;
	l = 0;
	piece = (char **)malloc(sizeof(char *) * game->piece_line);
	while (j < game->piece_line)
	{
			i = 0;
			l = 0;
			piece[j] = ft_strnew(game->piece_col - subcol + 1);
			while (i < game->piece_col)
			{
				if (i == startcol)
				{
					k = 0;
					while (k++ < subcol)
						i++;
				}
				else
					piece[j][l++] = game->piece[j][i++];
			}
			piece[j++][l] = '\0';
	}
	ft_realloc_piece(game, piece, 0, subcol);
}

void	ft_calcul_subline( t_game *game)
{
	int i;
	int j;
	int subline;
	int startline;

	subline = 0;
	startline = 0;
	i = -1;
	while (++i < game->piece_line)
	{
		j = 0;
		while (j < game->piece_col && game->piece[i][j] == '.')
			j++;
		if (j == game->piece_col)
		{
			if (subline == 0)
				startline = i;
			subline++;
		}
		else if (subline)
		{
			if (startline == 0)
				game->coordo[0] = -subline;
			ft_reduce_piece_line(game, subline, startline);
		}
	}


}

void	ft_calcul_subcol( t_game *game)
{
	int i;
	int j;
	int startcol;
	int subcol;

	subcol = 0;
	startcol = 0;
	j = -1;
	while (++j < game->piece_col)
	{
		i = 0;
		while (i < game->piece_line && game->piece[i][j] == '.')
			i++;
		if (i == game->piece_line)
		{
			if (subcol == 0)
				startcol = j;
			subcol++;
		}
		else if (subcol)
		{
			if (startcol == 0)
				game->coordo[1] = -subcol;
			ft_reduce_piece_col(game, subcol, startcol);
		}
	}
	// if (startcol == 0 && subcol)
	// 	game->coordo[1] = -subcol;
	// if (subcol)
	// 	ft_reduce_piece_col(game, subcol, startcol);

}
