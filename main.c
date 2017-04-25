/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 13:46:02 by clegoube          #+#    #+#             */
/*   Updated: 2017/04/25 15:02:22 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_initialize_struct(t_game *game)
{
	game->player = 1;
	game->symbol = 'O';
	game->fighter = 'x';
	game->map_line = 0;
	game->piece_line = 0;
	game->piece_line_max = 0;
	game->map_col = 0;
	game->piece_col = 0;
	game->piece_col_max = 0;
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
	int	i;

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
	char	*line;
	t_game	*game;

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
		ft_stock_struct(&line, game);
		ft_find_solutions(game);
		// ft_putstr(ft_itoa(8));
		// ft_putchar(' ');
		// ft_putstr(ft_itoa(2));
		// ft_putchar('\n');
		ft_free_game(game);
	}
	free(game);
	free(line);
	return (0);
}
