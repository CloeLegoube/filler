/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 13:33:31 by clegoube          #+#    #+#             */
/*   Updated: 2017/04/09 19:55:12 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

// void	ft_find_last_turn(t_game *game)
// {
// 	int i;
// 	int j;
//
// 	i = -1;
// 	while (++i < game->map_line)
// 	{
// 		j = -1;
// 		while (++j < game->map_col)
// 		{
// 			if (game->map[i][j] == game->fighter)
// 			{
// 				game->position_fighter[0] = i;
// 				game->position_fighter[1] = j;
// 			}
// 		}
// 	}
// }
//
int		ft_check_piece(int i, int j, t_game *game)
{
	int k;
	int l;
	int count;
	int touch;

	k = -1;
	count = 0;
	touch = 0;
	while (++k < game->piece_line && (k + i) < game->map_line )
	{
		l = -1;
		while (++l < game->piece_col && (l + j) < game->map_col)
		{
			if (game->piece[k][l] == '*' && game->map[i + k][j + l] == game->symbol)
				touch++;
			else if (game->piece[k][l] == '*' && game->map[i + k][j + l] == '.')
				count++;
		}
	}
	if (touch == 1 && (count + touch == game->stars))
		return (1);
	return (0);
}
//
//
// int 	ft_check_line_up(t_game *game, int until)
// {
// 	int i;
//
// 	i = -1;
// 	while (++i < game->map_line)
// 	{
// 		if ((game->map[i][until] == game->symbol) ||
// 			(game->map[i][until] == game->symbol + 32))
// 			return (1);
// 	}
// 	return (0);
// }
//
//
// int 	ft_check_line_down(t_game *game, int until)
// {
// 	int i;
//
// 	i = game->map_line - 1;
// 	while (i > 0)
// 	{
// 		if ((game->map[i][until] == game->symbol) ||
// 			(game->map[i][until] == game->symbol + 32))
// 			return (1);
// 		i--;
// 	}
// 	return (0);
// }
//
// t_list	*ft_strategy_game(t_list **mylist, t_game *game)
// {
// 	t_coor *struc;
// 	t_list *start;
// 	int x;
// 	int y;
// 	int z;
// 	int h;
// 	int count;
//
// 	start = *mylist;
// 	game->strategy = game->strategy;
// 	// dprintf(2, "display: \n");
// 	struc = (t_coor*)((*mylist)->content);
// 	// dprintf(2, "distance_fighter_i%d  - distance_fighter_j %d\n",struc->distance_fighter[0], struc->distance_fighter[0]);
// 	count = struc->distance_fighter[0] + struc->distance_fighter[1];
// 	x = struc->coordo[0];
// 	y = struc->coordo[1];
// 	z = struc->coordo[0];
// 	h = struc->coordo[1];
// 	while (*mylist)
// 	{
// 		struc = (t_coor*)((*mylist)->content);
//
// 		// if (((struc->distance_fighter[0] + struc->distance_fighter[1]) < count) &&
// 		// 	((game->strategy && struc->au_dessus) || (!game->strategy && !struc->au_dessus)))
// 		dprintf(2, "\n Solution ==> X%d:Y%d :  ",struc->coordo[0], struc->coordo[1]);
//
// 		if (y <= struc->coordo[1] && !ft_check_line_up(game, game->map_col - 1))
// 		{
// 				x = struc->coordo[0];
// 				y = struc->coordo[1];
// 				dprintf(2, "OK Solution 1");
// 				// dprintf(2, "OK Solution 1 ==> X%d:Y%d\n",struc->coordo[0], struc->coordo[1]);
//
// 				// count  = struc->distance_fighter[0] + struc->distance_fighter[1];
// 		}
// 		else if (struc->coordo[1] >= y && !ft_check_line_down(game, game->map_col - 1))
// 		{
// 				x = struc->coordo[0];
// 				y = struc->coordo[1];
// 				dprintf(2, "OK Solution 2");
// 				// dprintf(2, "Solution 2 ==> X%d:Y%d\n",struc->coordo[0], struc->coordo[1]);
//
// 				// count  = struc->distance_fighter[0] + struc->distance_fighter[1];
// 				// dprintf(2, "Coordo ==> X%d:Y%d  - Player %d: %c\n",struc->coordo[0], struc->coordo[1], game->player, game->symbol);
// 		}
// 		else if (y >= struc->coordo[1] && !ft_check_line_up(game, 0))
// 		{
// 				x = struc->coordo[0];
// 				y = struc->coordo[1];
// 				dprintf(2, "OK Solution 3");
// 				// dprintf(2, "OK Solution 1 ==> X%d:Y%d\n",struc->coordo[0], struc->coordo[1]);
//
// 				// count  = struc->distance_fighter[0] + struc->distance_fighter[1];
// 		}
// 		else if (struc->coordo[1] <= y && !ft_check_line_down(game, 0))
// 		{
// 				x = struc->coordo[0];
// 				y = struc->coordo[1];
// 				dprintf(2, "OK Solution 4");
// 				// dprintf(2, "Solution 2 ==> X%d:Y%d\n",struc->coordo[0], struc->coordo[1]);
//
// 				// count  = struc->distance_fighter[0] + struc->distance_fighter[1];
// 				// dprintf(2, "Coordo ==> X%d:Y%d  - Player %d: %c\n",struc->coordo[0], struc->coordo[1], game->player, game->symbol);
// 		}
// 		// else
// 		// {
// 		// 	x = struc->coordo[0];
// 		// 	y = struc->coordo[1];
// 		//
// 		// }
//
// 		*mylist = (*mylist)->next;
// 	}
// 	// x = (x > z) ? x : z;
// 	// y = (y > h) ? y : h;
// 	// dprintf(2, "\nEnvoie des Coordo ==> X%d:Y%d \n",x, y);
// 	ft_display_piece(x, y);
// 	return (start);
// }

void	ft_display_piece(int x, int y)
{
	ft_putstr(ft_itoa(x));
	ft_putchar(' ');
	ft_putstr(ft_itoa(y));
	ft_putchar('\n');
}


int	ft_left_down(t_game *game)
{
	int		i;
	int		j;

	i = -1;
	while (++i < game->map_line)
	{
		j = -1;
		while (++j < game->map_col)
		{
			if (ft_check_piece(i, j, game))
			{
				// dprintf(2, "ft_left_down ==> i:%d, j:%d\n", i, j);
				// dprintf(2, "ft_left_down ==> coordoi:%d, coordoj:%d\n", game->coordo[0], game->coordo[1]);
				ft_display_piece(i + game->coordo[0], j + game->coordo[1]);
				return (1);
				i = game->map_line;
				j = game->map_col;
			}
		}
	}
	return (0);
}

int	ft_right_up(t_game *game)
{
	int		i;
	int		j;

	i = game->map_line - 1;
	while (i > 0)
	{
		j = game->map_col - 1;
		while (j > 0)
		{
			if (ft_check_piece(i, j, game))
			{
				// dprintf(2, "ft_right_up ==> i:%d, j:%d\n", i, j);
				ft_display_piece(i + game->coordo[0], j + game->coordo[1]);
				return (1);
				i = 0;
				j = 0;
			}
			j--;
		}
		i--;
	}
	return (0);
}

void	ft_find_solutions(t_game *game)
{
	int		i;
	// int		j;
	t_list	*mylist;
	// t_coor	new;
	// t_coor *struc;

	mylist = NULL;
	ft_stock_stars(game);
	// ft_find_last_turn(game);
	i = -1;
	dprintf(2, "\n************* Resultat ************\n");
	dprintf(2, "game->map_line:%d, game->map_col:%d\n", game->map_line, game->map_col);
	while (++i < game->map_line)
	{
		dprintf(2, "%s\n", game->map[i]);

	}
	i = -1;
	dprintf(2, "\nPIECE\n");
	while (++i < game->piece_line)
	{
		dprintf(2, "%s\n", game->piece[i]);

	}
	dprintf(2, "\nPoint[0][fin] : %c, %c, %c\n", game->map[0][game->map_col - 1], game->symbol, game->symbol + 32);

	if  ((game->map[0][game->map_col - 1] != game->symbol) &&
		(game->map[0][game->map_col - 1] != game->symbol + 32))
		{
			dprintf(2, "\nBoule 1\n");
			if (!ft_left_down(game))
				ft_right_up(game);

		}
	else if ((game->map[game->map_line - 1][game->map_col - 1] != game->symbol) &&
		(game->map[game->map_line - 1][game->map_col - 1] != game->symbol + 32))
		{
			dprintf(2, "\nBoule 2");
			dprintf(2, "\nPoint[fin][fin] : %c, %c, %c\n", game->map[game->map_line - 1][game->map_col - 1], game->symbol, game->symbol + 32);
			if (!ft_right_up(game))
				ft_left_down(game);
		}
	else{
		if (!ft_left_down(game))
			ft_right_up(game);
	}

	// else
	// 	ft_right_up(game);



	// dprintf(2, "-\n");
	// mylist = ft_strategy_game(&mylist, game);
	// dprintf(2, "-\n");
	// while (mylist)
	// {
	// 	free(mylist->content);
	// 	free(mylist);
	// 	mylist = mylist->next;
	// }
	// mylist = NULL;
}
