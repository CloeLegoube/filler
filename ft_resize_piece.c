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

void	ft_realloc_piece(t_game *game, char **piece, int subline, int subcol)
{
	int		i;

	i = 0;
	while (i < game->piece_line)
		ft_strdel(&(game->piece[i++]));
	free(game->piece);
	game->piece_line_max = game->piece_line;
	game->piece_line = game->piece_line - subline;
	// game->coordo[0] = (game->piece_line_max - game->piece_line) * -1;
	game->piece_col_max = game->piece_col;
	game->piece_col = game->piece_col - subcol;
	// game->coordo[1] = (game->piece_col_max - game->piece_col) * -1;

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



int		ft_reduce_piece_line(t_game *game, int *lines, int count)
{
	int		i;
	int		j;
	int		k;
	char	**piece;

	i = 0;
	j = 0;
	k = 0;
	piece = (char **)malloc(sizeof(char *) * (game->piece_line - count + 1));
	while (i < game->piece_line)
	{
		if (i == lines[k] && k++)
			i++;
		else
		{
			piece[j] = ft_strnew(game->piece_col + 1);
			ft_strcpy(piece[j++], game->piece[i++]);
		}
	}
	ft_realloc_piece(game, piece, count, 0);
	return (1);
}

void	ft_calcul_subline(t_game *game)
{
	int		i;
	int		j;
	int		count;
	int		start;
	int		lines[game->piece_line];

	i = -1;
	count = 0;

	while (++i < game->piece_line)
	{
		j = 0;
		while (j < game->piece_col && game->piece[i][j] == '.')
			j++;
		if (j == game->piece_col)
			lines[count++] = i;
	}
	start = -1;
	while (++start < count)
		dprintf(2, "LINE[%d]: %d\n", start, lines[start]);
	ft_reduce_piece_line(game, lines, count);

	dprintf(2, "AVANT lines[i] %d - %d - count: %d\n", lines[i], lines[i + 1] - 1, count);

	if (lines[0] == 0)
	{
		i = 0;
		count = 1;
		while (lines[i] == lines[i + 1] - 1)
		{
			dprintf(2, "lines[i] %d - %d\n", lines[i], lines[i + 1] - 1);
			count++;
			i++;
		}

	}
	dprintf(2, "count lines%d\n", count);
	game->coordo[0] = -count;
}

int		ft_reduce_piece_col(t_game *game, int *cols, int count)
{
	int		i;
	int		j;
	int		k;
	int		l;
	char	**piece;

	j = 0;
	k = 0;
	piece = (char **)malloc(sizeof(char *) * game->piece_line);
	while (j < game->piece_line)
	{
		i = 0;
		l = 0;
		piece[j] = ft_strnew(game->piece_col - count + 1);
		while (i < game->piece_col)
			if (i == cols[k] && k++)
				i++;
			else
				piece[j][l++] = game->piece[j][i++];
		piece[j++][l] = '\0';
	}
	ft_realloc_piece(game, piece, 0, count);
	return (1);
}

void	ft_calcul_subcol(t_game *game)
{
	int		i;
	int		j;
	int		count;
	int		start;
	int		cols[game->piece_col];

	count = 0;
	j = -1;
	start = -1;
	while (++j < game->piece_col)
	{
		i = 0;
		while (i < game->piece_line && game->piece[i][j] == '.')
			i++;
		if (i == game->piece_line)
			cols[count++] = j;
	}
	while (++start < count)
		dprintf(2, "COL[%d]: %d\n", start, cols[start]);
	ft_reduce_piece_col(game, cols, count);

	dprintf(2, "AVANT cols[i] %d - %d  - count: %d\n", cols[i], cols[i + 1] - 1, count);

	if (cols[0] == 0)
	{
		i = 0;
		count = 1;
		while (cols[i] == cols[i + 1] - 1)
		{
			dprintf(2, "cols[i] %d - %d\n", cols[i], cols[i + 1] - 1);
			count++;
			i++;
		}
	}
	dprintf(2, "count cols%d\n", count);
	game->coordo[1] = -count;
}
