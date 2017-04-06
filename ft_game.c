/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 13:33:31 by clegoube          #+#    #+#             */
/*   Updated: 2017/04/06 20:21:06 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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

t_list	*ft_strategy_game(t_list **mylist, t_game *game)
{
	t_coor *struc;
	t_list *start;

	start = *mylist;
	// dprintf(2, "display: \n");
	while (*mylist)
	{
		struc = (t_coor*)((*mylist)->content);
		dprintf(2, "Coordo ==> X%d:Y%d  - Player %d: %c\n",struc->coordo[0], struc->coordo[1], game->player, game->symbol);
		*mylist = (*mylist)->next;
	}
	// dprintf(2, "Envoie des Coordo ==> X%d:Y%d \n",struc->coordo[0], struc->coordo[1]);
	ft_putstr(ft_itoa(struc->coordo[0]));
	ft_putchar(' ');
	ft_putstr(ft_itoa(struc->coordo[1]));
	ft_putchar('\n');
	return (start);
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
	// i = -1;
	// dprintf(2, "\n************* Resultat ************\n");
	// dprintf(2, "game->map_line:%d, game->map_col:%d\n", game->map_line, game->map_col);
	// while (++i < game->map_line)
	// {
	// 	dprintf(2, "%s\n", game->map[i]);
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
				new.i = i;
				new.j = j;
				// dprintf(2, "OK | GET ==> X:%d, Y:%d (i:%d,j:%d)\n", new.coordo[0], new.coordo[1], i, j);
				ft_lstadd(&mylist, ft_lstnew(&new, sizeof(t_coor)));

				/* DEBUG */
				// dprintf(2, "-\n");
				// mylist = ft_strategy_game(&mylist, game);
				// dprintf(2, "-\n");
			}
		}
	}
	dprintf(2, "-\n");
	mylist = ft_strategy_game(&mylist, game);
	dprintf(2, "-\n");
	// while (mylist)
	// {
	// 	free(mylist->content);
	// 	free(mylist);
	// 	mylist = mylist->next;
	// }
	// mylist = NULL;
}
