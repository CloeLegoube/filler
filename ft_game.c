/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 13:33:31 by clegoube          #+#    #+#             */
/*   Updated: 2017/04/04 20:19:29 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_check_piece(int *i, int *j, t_game *game)
{
	// *i = *i + 3;
	// *j = *j + 3;
	// if (game->player == 1)
	// 	game->player = 1;
	// else
	// 	game->player = 2;
	int k;
	int l;
	int count;
	int touch;

	k = -1;
	count = 0;
	touch = 0;
	while (++k < game->piece_lenght)
	{
		l = -1;
		while (++l < game->piece_width)
		{
			if (game->piece[k][l] == '*' && game->map[*i + k][*j + l] == game->symbol)
				touch++;
			else if (game->piece[k][l] == '*' && game->map[*i + k][*j + l] == '.')
				count++;
			else if (game->piece[k][l] == '.' && game->map[*i + k][*j + l] == game->symbol)
				count++;
			else if (game->piece[k][l] == '.' && game->map[*i + k][*j + l] == '.')
				count++;
		}
	}
	dprintf(2, "multi : %d - count + 1 : %d - touch : %d \n",game->piece_lenght * game->piece_width, count + 1, touch );
	if (touch == 1 && (count + 1) == (game->piece_lenght * game->piece_width))
		return (1);
	return (0);
}

void	ft_strategy_game(t_game *game)
{
	int i;
	int j;

	i = -1;
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
	while (++i < game->piece_lenght)
	{
		ft_putstr_fd(game->piece[i], 2);
		ft_putchar_fd('\n', 2);
	}
	i = -1;



	while (++i < game->X_lenght)
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == game->symbol && ft_check_piece(&i, &j, game))
			{
				ft_putstr(ft_itoa(i));
				ft_putchar(' ');
				ft_putstr(ft_itoa(j));
				ft_putchar('\n');
				dprintf(2, "OK \n");
				break;
			}
			j++;
			dprintf(2, "FAIL \n");
		}
	}

}
