/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 10:46:43 by yictseng          #+#    #+#             */
/*   Updated: 2021/03/15 10:46:44 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

char	*ft_strch(const char *s)
{
	if (s == NULL)
		return (NULL);
	while (*s)
	{
		if (*s == '\n')
			return ((char*)s);
		s++;
	}
	return (NULL);
}

int		new_line(char ***tmp, char **line)
{
	int		stop;
	char	*dash;

	stop = 0;
	while ((**tmp)[stop] != '\n' && (**tmp)[stop] != '\0')
		stop++;
	if ((**tmp)[stop] == '\n')
	{
		*line = ft_substr((**tmp), 0, stop);
		dash = ft_strdup(&((**tmp)[stop + 1]));
		free(**tmp);
		**tmp = dash;
	}
	else
	{
		*line = ft_strdup(**tmp);
		free(**tmp);
		**tmp = NULL;
		return (0);
	}
	return (1);
}

int		check_end(char **tmp, int len, char **line)
{
	if (len < 0)
		return (-1);
	else if (len == 0 && (*tmp) == NULL)
	{
		*line = ft_strdup("");
		return (0);
	}
	else
		return (new_line(&tmp, line));
}

int		get_next_line(int fd, char **line)
{
	int				len;
	char			buffer[2048 + 1];
	static char		*tmp;
	char			*dash;

	if (fd == -1 || line == NULL)
		return (-1);
	while (!ft_strch(tmp))
	{
		if ((len = read(fd, buffer, 2048)) > 0)
		{
			buffer[len] = '\0';
			if (tmp == NULL)
				tmp = ft_strdup(buffer);
			else
			{
				dash = ft_strjoin(tmp, buffer);
				free(tmp);
				tmp = dash;
			}
		}
		else
			break ;
	}
	return (check_end(&tmp, len, line));
}
