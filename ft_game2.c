/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 13:33:31 by clegoube          #+#    #+#             */
/*   Updated: 2017/04/11 20:26:48 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_display_piece(int x, int y)
{
	ft_putstr(ft_itoa(x));
	ft_putchar(' ');
	ft_putstr(ft_itoa(y));
	ft_putchar('\n');
}

int		ft_direction(t_coor *struc, t_game *game, int y)
{
	int direction1;
	int direction2;

	direction1 = (game->player == 2) ? 0 : (game->map_col - 1);
	direction2 = (game->player == 2) ? (game->map_col - 1) : 1;
	if (y <= struc->coordo[1] && !ft_check_line_up(game, direction1))
		return (1);
	else if (struc->coordo[1] >= y && !ft_check_line_down(game, direction1))
		return (1);
	else if (y >= struc->coordo[1] && !ft_check_line_up(game, direction2))
		return (1);
	else if (struc->coordo[1] <= y && !ft_check_line_down(game, direction2))
		return (1);
	return (0);
}

void	ft_strategy_game(t_list **mylist, t_game *game)
{
	t_coor	*struc;
	int		x;
	int		y;
	int		yes;

	struc = (*mylist) ? (t_coor*)((*mylist)->content) : NULL;
	x = (*mylist) ? struc->coordo[0] : 0;
	y = (*mylist) ? struc->coordo[1] : 0;
	while (*mylist)
	{
		struc = (t_coor*)((*mylist)->content);
		yes = ft_direction(struc, game, y);
		x = (yes) ? struc->coordo[0] : x;
		y = (yes) ? struc->coordo[1] : y;
		*mylist = (*mylist)->next;
	}
	ft_display_piece(x, y);
}

void	ft_find_solutions(t_game *game)
{
	int		i;
	int		j;
	t_list	*mylist;
	t_coor	new;

	mylist = NULL;
	ft_stock_stars(game);
	ft_check_fighter(game);
	i = -1;
	while (++i < game->map_line)
	{
		j = -1;
		while (++j < game->map_col)
		{
			if (ft_check_piece(i, j, game))
			{
				new.coordo[0] = i + game->coordo[0];
				new.coordo[1] = j + game->coordo[1];
				ft_lstadd(&mylist, ft_lstnew(&new, sizeof(t_coor)));
			}
		}
	}
	ft_strategy_game(&mylist, game);
}
