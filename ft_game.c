/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 13:33:31 by clegoube          #+#    #+#             */
/*   Updated: 2017/04/04 18:52:31 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_strategy_game(t_game *game)
{
	int i;
	int j;

	i = -1;
	// // get_next_line(0, &line)
	// ft_putchar_fd(game->symbol, 2);ft_putchar_fd('\n', 2);
	// ft_putstr_fd(ft_itoa(game->player), 2);ft_putchar_fd('\n', 2);
	// ft_putstr_fd(ft_itoa(game->X_lenght), 2);ft_putchar_fd('\n', 2);
	// ft_putstr_fd(ft_itoa(game->Y_width), 2);ft_putchar_fd('\n', 2);
	// ft_putstr_fd(ft_itoa(game->piece_lenght), 2);ft_putchar_fd('\n', 2);
	// ft_putstr_fd(ft_itoa(game->piece_width), 2);ft_putchar_fd('\n', 2);
	// while (++i < game->X_lenght)
	// {
	// 	ft_putstr_fd(game->map[i], 2);
	// 	ft_putchar_fd('\n', 2);
	// }
	// i = -1;
	// ft_putchar_fd('\n', 2);
	// while (++i < game->piece_lenght)
	// {
	// 	ft_putstr_fd(game->piece[i], 2);
	// 	ft_putchar_fd('\n', 2);
	// }
	// if (game->player == 1)
	// 	game->player = 1;
	// else
	// 	game->player = 2;
	// ft_putstr("8 2\n");



	while (++i < game->X_lenght)
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == game->symbol)
			{
				ft_putchar(i + 48 - 1);
				ft_putchar(' ');
				ft_putchar(j + 48 - 1);
				ft_putchar('\n');
			}
		}
	}

}
