/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 13:46:02 by clegoube          #+#    #+#             */
/*   Updated: 2017/04/11 13:23:43 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	ft_initialize_struct(t_game *game)
{
	game->player = 1;
	game->symbol = 'O';
	game->fighter = 'x';
	game->map_line = 0;
	game->piece_line = 0;
	game->map_col = 0;
	game->piece_col = 0;
	game->map = NULL;
	game->piece = NULL;
	if (!(game->coordo = (int*)malloc(sizeof(int) * 2)))
		return (0);
	game->coordo[0] = 0;
	game->coordo[1] = 0;
	game->stars = 0;
	game->strategy = 0;
	return (1);
}

void	ft_free_game(t_game *game)
{
	int i;

	i = 0;
	while (i < game->map_line)
		ft_strdel(&(game->map[i++]));
	free(game->map);
	i = 0;
	while (i < game->piece_line)
		ft_strdel(&(game->piece[i++]));
	free(game->piece);
	game->map_line = 0;
	game->piece_line = 0;
	game->map_col = 0;
	game->piece_col = 0;
	game->coordo[0] = 0;
	game->coordo[1] = 0;
	game->stars = 0;
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
		game->fighter = 'o';
	}
	while (get_next_line(0, &line) > 0)
	{
		game->strategy = game->strategy ? 0 : 1;
		// dprintf(2, "boucle1\n");
		ft_stock_struct(&line, game);
		// dprintf(2, "boucle2\n");
		ft_find_solutions(game);
		// dprintf(2, "boucle3\n");
		ft_free_game(game);
		// dprintf(2, "boucle4\n");
	}
	free(game);
	free(line);
	return (0);
}
