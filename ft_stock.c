/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 12:52:19 by clegoube          #+#    #+#             */
/*   Updated: 2017/04/22 15:55:09 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_stock_stars(t_game *game)
{
	int i;
	int j;

	i = -1;
	while (++i < game->piece_line)
	{
		j = -1;
		while (++j < game->piece_col)
			if (game->piece[i][j] == '*')
				game->stars++;
	}
}

void	ft_stock_map(char **line, t_game *game)
{
	int		i;
	char	*sub;

	i = -1;
	get_next_line(0, line);
	get_next_line(0, line);
	game->map = (char **)malloc(sizeof(char *) * (game->map_line + 1));
	while (++i < game->map_line)
	{
		game->map[i] = (char *)malloc(sizeof(char) * (ft_strlen(*line) + 1));
		sub = ft_strsub(*line, 4, ft_strlen(*line));
		ft_strcpy(game->map[i], sub);
		free(sub);
		get_next_line(0, line);
	}
	game->map[game->map_line] = NULL;
}


void	ft_stock_piece(char **line, t_game *game)
{
	int		i;
	char	**piece;
	char	*subline;
	char	*subcol;

	i = -1;
	piece = (char **)malloc(sizeof(char *) * (game->piece_line_max + 1));
	piece[game->piece_line_max] = NULL;
	while (++i < game->piece_line_max && get_next_line(0, line) > 0)
	{
		piece[i] = ft_strnew(game->piece_col_max);
		ft_strcpy(piece[i], *line);
	}
	/* Test */
	i = -1;
	dprintf(2, "Avant :\n");
	while (piece[++i])
		dprintf(2, "%s\n", piece[i]);
	/* Test */
	subline = supp_lines(game, piece);
	subcol = supp_cols(game, piece);
	game->piece_line = count_char(subline, 'y');
	game->piece_col = count_char(subcol, 'y');
	game->piece = (char **)malloc(sizeof(char *) * (game->piece_line + 1));
	game->piece[game->piece_line] = NULL;
	ft_resize_piece(game, piece, subline, subcol);

	game->center[0] = game->piece_line / 2 - game->coordo[0];
	game->center[1] = game->piece_col / 2 - game->coordo[1];
	i = -1;
	dprintf(2, "Apres :\n");
	while (game->piece[++i])
		dprintf(2, "%s\n", game->piece[i]);
	dprintf(2, "-----------------\n");
	// i = -1;
	// dprintf(2, "MAP :\n");
	// while (game->map[++i])
	// 	dprintf(2, "%s\n", game->map[i]);
}

void	ft_stock_struct(char **line, t_game *game)
{
	char **tab;

	if (ft_strstr(*line, "Plateau"))
	{
		tab = ft_strsplit(*line, ' ');
		game->map_line = ft_atoi(tab[1]);
		game->map_col = ft_atoi(tab[2]);
		free(tab);
		ft_stock_map(line, game);
	}
	if (ft_strstr(*line, "Piece"))
	{
		tab = ft_strsplit(*line, ' ');
		game->piece_line_max = ft_atoi(tab[1]);
		game->piece_col_max = ft_atoi(tab[2]);
		ft_stock_piece(&*line, game);
	}
	ft_stock_stars(game);
}
