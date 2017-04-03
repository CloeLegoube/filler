/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 13:46:02 by clegoube          #+#    #+#             */
/*   Updated: 2017/04/03 19:36:54 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_initialize_struct(t_game *game)
{
	game->player = 1;
	game->symbol = 'O';
	game->X_lenght = 0;
	game->piece_lenght = 0;
	game->Y_width = 0;
	game->piece_width = 0;
}

void	ft_go_next_line(int count, char **line)
{
	int i;

	i = 0;
	while (i < count)
	{
		get_next_line(0, line);
		i++;
	}
}

int		main(void)
{
	int i;
	char *line;
	char **tab;
	t_game *game;

	i = 1;
	if (!(game = (t_game*)malloc(sizeof(t_game))))
		return (0);
	if (!(line = (char*)malloc(sizeof(char))))
		return (-1);

	while (get_next_line(0, &line))
	{
		ft_initialize_struct(game);
		if (ft_strstr(line, "p1"))
			ft_go_next_line(2, &line);
		else if (ft_strstr(line, "p2"))
		{
			game->player = 2;
			game->symbol = 'X';
			ft_go_next_line(1, &line);
		}
		if (ft_strstr(line, "Plateau"))
		{
			tab = ft_strsplit(line, ' ');
			game->X_lenght = ft_atoi(tab[1]);
			game->Y_width = ft_atoi(tab[2]);
			free(tab);
			ft_go_next_line(game->X_lenght + 1, &line);
		}
		if (ft_strstr(line, "Piece"))
		{
			tab = ft_strsplit(line, ' ');
			// ft_print_words_tables(tab);
			game->piece_lenght = ft_atoi(tab[1]);
			game->piece_width = ft_atoi(tab[2]);
			free(tab);
			ft_go_next_line(game->piece_lenght + 1, &line);
		}
		ft_putstr("8 2\n");
		free(game);
	}



	return (0);
}
