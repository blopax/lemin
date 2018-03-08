/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 12:48:43 by nvergnac          #+#    #+#             */
/*   Updated: 2018/01/30 21:02:40 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_check(char *str)
{
	int i;

	i = 0;
	if (str)
	{
		while (str[i] != 0)
		{
			if (str[i] == '\n')
				return (i);
			i++;
		}
	}
	return (i);
}

char		*result(char **line, char *tmp_str)
{
	char *tmp;

	tmp = 0;
	*line = ft_strnew(ft_check(tmp_str));
	ft_strncpy(*line, (const char*)tmp_str, ft_check(tmp_str));
	tmp = ft_strdup(tmp_str);
	if (tmp_str)
		free(tmp_str);
	tmp_str = ft_strsub(tmp, ft_check(tmp) + 1, ft_strlen(tmp) - ft_check(tmp));
	if (tmp)
		free(tmp);
	return (tmp_str);
}

int			get_next_line(const int fd, char **line)
{
	static char	*tmp_str[OPEN_MAX];
	t_gnl		gnl;

	if (fd < 0 || !(line) || fd >= OPEN_MAX)
		return (-1);
	if (!(tmp_str[fd]))
		tmp_str[fd] = ft_strnew(0);
	while ((gnl.ret = read(fd, gnl.buf, BUFF_SIZE)) > 0)
	{
		gnl.buf[gnl.ret] = '\0';
		gnl.tmp = ft_strdup(tmp_str[fd]);
		free(tmp_str[fd]);
		tmp_str[fd] = ft_strjoin(gnl.tmp, gnl.buf);
		free(gnl.tmp);
		if (ft_check(tmp_str[fd]) != ft_strlen(tmp_str[fd]))
			break ;
	}
	if (gnl.ret == -1)
		return (-1);
	if (gnl.ret == 0 && tmp_str[fd][0] == 0)
		return (0);
	tmp_str[fd] = result(line, tmp_str[fd]);
	return (1);
}
