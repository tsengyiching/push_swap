/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 14:55:34 by yictseng          #+#    #+#             */
/*   Updated: 2021/03/16 11:14:50 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_read_line(t_stock *save, int fd)
{
	int		ret;
	int		index_charset;
	char	*temp;
	char	buf[BUFFER_SIZE + 1];

	index_charset = ft_strchr((save->str), '\n');
	while (!index_charset && save->eof == 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		temp = save->str;
		save->str = ft_strjoin(temp, buf);
		if (temp != NULL)
			free(temp);
		if (ret == 0)
		{
			save->eof = 1;
			break ;
		}
		index_charset = ft_strchr((save->str), '\n');
	}
	return (index_charset);
}

static void	check_stdin(t_stock *save, int fd)
{
	if (save->str && save->str[0] == '\0' && fd == 0)
	{
		free(save->str);
		save->str = NULL;
	}
}		

void	find_new_line(char **line, t_stock *save, int index_charset)
{
	char	*temp;

	*line = ft_substr(save->str, 0, index_charset - 1);
	temp = ft_substr(save->str, index_charset, ft_strlen(save->str));
	free(save->str);
	save->str = temp;
}

int	get_next_line(int fd, char **line)
{
	int				index_charset;
	static t_stock	save;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!save.str)
		save.eof = 0;
	index_charset = ft_read_line(&save, fd);
	if (index_charset == -1)
		return (-1);
	index_charset = ft_strchr((save.str), '\n');
	if (index_charset > 0)
		find_new_line(line, &save, index_charset);
	else
	{
		*line = ft_substr((save.str), 0, ft_strlen(save.str));
		free(save.str);
		save.str = 0;
	}
	check_stdin(&save, fd);
	if (index_charset == 0)
		return (0);
	else
		return (1);
}
