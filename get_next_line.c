/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 13:21:02 by clegoube          #+#    #+#             */
/*   Updated: 2017/04/03 15:56:34 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		get_lines(char *stock, char **line)
{
	char	*tmp;

	if ((tmp = ft_strchr(stock, '\n')))
	{
		*line = ft_strsub(stock, 0, tmp - stock);
		stock = ft_strcpy(stock, tmp + 1);
		tmp = NULL;
		return (1);
	}
	return (0);
}

int		ret_inf_zero(char *stock, char **line, int ret)
{
	char	*tmp;

	if (ret == -1)
		return (-1);
	if (ft_strcmp(stock, "\0") != 0)
	{
		if ((tmp = ft_strchr(stock, '\n')) != NULL)
		{
			*line = ft_strsub(stock, 0, (tmp - stock));
			stock = ft_strcpy(stock, tmp + 1);
			return (1);
		}
		if (tmp == NULL && ft_strcmp(stock, "\0") != 0)
		{
			*line = ft_strsub(stock, 0, ft_strchr(stock, '\0') - stock);
			stock = ft_strcpy(stock, ft_strchr(stock, '\0'));
			return (1);
		}
		free(tmp);
	}
	return (0);
}

int		get_next_line(int const fd, char **line)
{
	static char	*stock;
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
	int			ret;

	if (stock)
		if (get_lines(stock, line))
			return (1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp = (stock) ? ft_strjoin(stock, buf) : ft_strdup(buf);
		free(stock);
		stock = ft_strdup(tmp);
		free(tmp);
		if (get_lines(stock, line))
			return (1);
	}
	return (ret_inf_zero(stock, line, ret));
}
