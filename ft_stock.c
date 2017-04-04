/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 12:52:19 by clegoube          #+#    #+#             */
/*   Updated: 2017/04/04 18:25:20 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_stock_map(char **line, t_game *game)
{
	int i;
	char *sub;

	i = -1;
	get_next_line(0, line);
	get_next_line(0, line);
	game->map = (char **)malloc(sizeof(char *) * (game->X_lenght));
	while (++i < game->X_lenght)
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
	;
	game->piece = (char **)malloc(sizeof(char *) * (game->piece_lenght));
	while (++i < game->piece_lenght && get_next_line(0, line) > 0)
	{
		game->piece[i] = ft_strnew(game->piece_width + 1);
		ft_strcpy(game->piece[i], *line);
	}
}

void	ft_stock_struct(char **line, t_game *game)
{
	char **tab;

	if (ft_strstr(*line, "Plateau"))
	{
		tab = ft_strsplit(*line, ' ');
		game->X_lenght = ft_atoi(tab[1]);
		game->Y_width = ft_atoi(tab[2]);
		free(tab);
		ft_stock_map(line, game);
	}
	if (ft_strstr(*line, "Piece"))
	{
		tab = ft_strsplit(*line, ' ');
		game->piece_lenght = ft_atoi(tab[1]);
		game->piece_width = ft_atoi(tab[2]);
		ft_stock_piece(&*line, game);
	}
}
