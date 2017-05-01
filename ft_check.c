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

int		ft_calcul_score(int pos_x, int pos_y, t_game *game)
{
	int i;
	int j;
	int nb_X;
	int factor;
	int count;

	i = 0;
	nb_X = 0;
	factor = game->map_line;
	count = 0;
	dprintf(2, "base:(%d, %d)\n", pos_x, pos_y);

	while (i + pos_x < game->map_line && game->map[i + pos_x])
	{
		j = 0;
		factor--;
		while (j + pos_y < game->map_col && game->map[i + pos_x][j + pos_y])
		{
			if (game->map[i + pos_x][j + pos_y] == 'X' || game->map[pos_x - i][pos_y - j] == 'x' )
				nb_X++;
			j++;
		}
		count += factor * nb_X;
		nb_X = 0;
		i++;
	}
	i = 0;
	nb_X = 0;
	factor = game->map_line;
	while (pos_x - i > 0 && game->map[pos_x - i])
	{
		j = 0;
		factor--;
		while (pos_y - j > 0 && game->map[pos_x - i][pos_y - j])
		{
			if (game->map[pos_x - i][pos_y - j] == 'X' || game->map[pos_x - i][pos_y - j] == 'x' )
				nb_X++;
			j++;
		}
		count += factor * nb_X;
		nb_X = 0;
		i++;
	}
	dprintf(2, "count :%d\n", count);
	return (count);
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
			//  dprintf(2, "ici :\n");

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

int		ft_check_line(t_game *game, int line)
{
	int i;

	i = 0;
	while (game->map[line][i])
	{
		if ((game->map[line][i] == game->symbol) ||
			(game->map[line][i] == game->symbol + 32))
			return (1);
		i++;
	}
	return (0);
}

int		ft_check_col(t_game *game, int col)
{
	int i;

	i = 0;
	while (game->map[i] && game->map[i][col])
	{
		if ((game->map[i][col] == game->symbol) ||
			(game->map[i][col] == game->symbol + 32))
			return (1);
		i++;
	}
	return (0);
}

// int		ft_check_line_down(t_game *game, int until)
// {
// 	int i;
//
// 	i = game->map_line - 1;
// 	while (i > 0 && game->map[i][until])
// 	{
// 		if ((game->map[i][until] == game->symbol) ||
// 			(game->map[i][until] == game->symbol + 32))
// 			return (1);
// 		i--;
// 	}
// 	return (0);
// }
