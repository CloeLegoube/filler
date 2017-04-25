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
	game->map = (char **)malloc(sizeof(char *) * (game->map_line));
	while (++i < game->map_line)
	{
		game->map[i] = (char *)malloc(sizeof(char) * (ft_strlen(*line) + 1));
		sub = ft_strsub(*line, 4, ft_strlen(*line));
		ft_strcpy(game->map[i], sub);
		free(sub);
		get_next_line(0, line);
	}
}

void	ft_stock_piece(char **line, t_game *game)
{
	int i;

	i = -1;
	game->piece = (char **)malloc(sizeof(char *) * (game->piece_line));
	while (++i < game->piece_line && get_next_line(0, line) > 0)
	{
		game->piece[i] = ft_strnew(game->piece_col + 1);
		ft_strcpy(game->piece[i], *line);
	}
	/* Test */
	i = -1;
	dprintf(2, "Avant :\n");
	while (game->piece[++i])
		dprintf(2, "%s\n", game->piece[i]);
	/* Test */
	ft_calcul_subline(game);
	ft_calcul_subcol(game);
	/* Test */
	i = -1;
	dprintf(2, "Apres :\n");
	while (game->piece[++i])
		dprintf(2, "%s\n", game->piece[i]);
	dprintf(2, "-----------------\n");
	/* Test */
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
		game->piece_line = ft_atoi(tab[1]);
		game->piece_col = ft_atoi(tab[2]);
		ft_stock_piece(&*line, game);
	}
}
