/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 13:46:02 by clegoube          #+#    #+#             */
/*   Updated: 2017/04/04 18:35:27 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_initialize_struct(t_game *game)
{
	game->player = 1;
	game->symbol = 'O';
	game->X_lenght = 0;
	game->piece_lenght = 0;
	game->Y_width = 0;
	game->piece_width = 0;
	game->map = NULL;
	game->piece = NULL;
}

void	ft_free_game(t_game *game)
{
	int i;

	i = 0;
	while (i < game->X_lenght)
		ft_strdel(&(game->map[i++]));
	free(game->map);
	i = 0;
	while (i < game->piece_lenght)
		ft_strdel(&(game->piece[i++]));
	free(game->piece);
	game->X_lenght = 0;
	game->piece_lenght = 0;
	game->Y_width = 0;
	game->piece_width = 0;
}

int		main(void)
{
	int i;
	char *line;
	t_game *game;

	i = 1;
	line = NULL;
	if (!(game = (t_game*)malloc(sizeof(t_game))))
		return (0);
	ft_initialize_struct(game);
	get_next_line(0, &line);
	if (ft_strstr(line, "p2"))
	{
		game->player = 2;
		game->symbol = 'X';
	}
	while (get_next_line(0, &line) > 0)
	{
		ft_stock_struct(&line, game);
		ft_strategy_game(game);
		ft_free_game(game);
	}
	free(game);
	free(line);
	return (0);
}
