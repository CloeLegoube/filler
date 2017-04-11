/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 13:33:31 by clegoube          #+#    #+#             */
/*   Updated: 2017/04/11 15:52:37 by clegoube         ###   ########.fr       */
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

void	ft_strategy_game(t_list **mylist, t_game *game)
{
	t_coor *struc;
	int x;
	int y;
	int yes;

	struc = (*mylist) ? (t_coor*)((*mylist)->content) : NULL;
	// dprintf(2, "distance_fighter_i%d  - distance_fighter_j %d\n",struc->distance_fighter[0], struc->distance_fighter[0]);
	x = (*mylist) ? struc->coordo[0] : 0;
	y = (*mylist) ? struc->coordo[1] : 0;
	while (*mylist)
	{
		struc = (t_coor*)((*mylist)->content);
		yes = 0;
		if (y <= struc->coordo[1] && !ft_check_line_up(game, game->map_col - 1))
			yes = 1;
		else if (struc->coordo[1] >= y && !ft_check_line_down(game, game->map_col - 1))
			yes = 1;
		else if (y >= struc->coordo[1] && !ft_check_line_up(game, 0))
			yes = 1;
		else if (struc->coordo[1] <= y && !ft_check_line_down(game, 0))
			yes = 1;
		x = (yes) ? struc->coordo[0] : x;
		y = (yes) ? struc->coordo[1] : y;
		*mylist = (*mylist)->next;
	}
	// dprintf(2, "ft_display_piece x:%d, y:%d\n", x, y);
	ft_display_piece(x, y);
}

void	ft_find_solutions(t_game *game)
{
	int		i;
	int		j;
	t_list	*mylist;
	t_coor	new;
	// t_coor *struc;

	mylist = NULL;
	ft_stock_stars(game);
	ft_check_fighter(game);
	// i = -1;
	// dprintf(2, "\n************* Resultat ************\n");
	// dprintf(2, "game->map_line:%d, game->map_col:%d\n", game->map_line, game->map_col);
	// while (++i < game->map_line)
	// {
	// 	dprintf(2, "%s\n", game->map[i]);
	//
	// }
	// i = -1;
	// dprintf(2, "\nPIECE\n");
	// while (++i < game->piece_line)
	// {
	// 	dprintf(2, "%s\n", game->piece[i]);
	//
	// }
	i = -1;
	while (++i < game->map_line)
	{
		j = -1;
		while (++j < game->map_col)
		{
			// dprintf(2, "game->map_line - i:%d, game->map_col - j:%d\n", i, j);
			if (ft_check_piece(i, j, game))
			{
				new.coordo[0] = i + game->coordo[0];
				new.coordo[1] = j + game->coordo[1];
				// new.i = i;
				// new.j = j;
				// new.au_dessus = 1;
				// new.a_gauche = 1;
				// new.distance_fighter[0] = (game->position_fighter[0] - new.coordo[0]);
				// new.distance_fighter[1] = (game->position_fighter[1] - new.coordo[1]);
				// if (new.distance_fighter[0] < 0)
				// {
				// 	new.distance_fighter[0] = new.distance_fighter[0] * -1;
				// 	new.a_gauche = 0;
				// }
				// if (new.distance_fighter[1] < 0)
				// {
				// 	new.distance_fighter[1] = new.distance_fighter[1] * -1;
				// 	new.au_dessus = 0;
				// }

				// dprintf(2, "OK | GET ==> X:%d, Y:%d (i:%d,j:%d)\n", new.coordo[0], new.coordo[1], i, j);
				ft_lstadd(&mylist, ft_lstnew(&new, sizeof(t_coor)));

				/* DEBUG */
				// dprintf(2, "-\n");
				// mylist = ft_strategy_game(&mylist, game);
				// dprintf(2, "-\n");
			}
		}
	}
	ft_strategy_game(&mylist, game);
}
