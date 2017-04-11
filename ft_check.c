/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 13:33:31 by clegoube          #+#    #+#             */
/*   Updated: 2017/04/11 20:25:46 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_check_fighter(t_game *game)
{
	int i;
	int j;

	i = -1;
	while (++i < game->map_line)
	{
		j = -1;
		while (++j < game->map_col)
		{
			if (game->map[i][j] == game->fighter)
			{
				game->position_fighter[0] = i;
				game->position_fighter[1] = j;
			}
		}
	}
}

int		ft_check_piece(int i, int j, t_game *game)
{
	int k;
	int l;
	int count;
	int touch;

	k = -1;
	count = 0;
	touch = 0;
	while (++k < game->piece_line && (k + i) < game->map_line)
	{
		l = -1;
		while (++l < game->piece_col && (l + j) < game->map_col)
		{
			if (game->piece[k][l] == '*' &&
				game->map[i + k][j + l] == game->symbol)
				touch++;
			else if (game->piece[k][l] == '*' && game->map[i + k][j + l] == '.')
				count++;
		}
	}
	if (touch == 1 && (count + touch == game->stars))
		return (1);
	return (0);
}

int		ft_check_line_up(t_game *game, int until)
{
	int i;

	i = -1;
	while (++i < game->map_line)
	{
		if ((game->map[i][until] == game->symbol) ||
			(game->map[i][until] == game->symbol + 32))
			return (1);
	}
	return (0);
}

int		ft_check_line_down(t_game *game, int until)
{
	int i;

	i = game->map_line - 1;
	while (i > 0)
	{
		if ((game->map[i][until] == game->symbol) ||
			(game->map[i][until] == game->symbol + 32))
			return (1);
		i--;
	}
	return (0);
}
