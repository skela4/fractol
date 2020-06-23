/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 11:47:45 by aahizi-e          #+#    #+#             */
/*   Updated: 2019/07/10 15:58:51 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static int			read_fd(int fd, char **remainder, char **s, char *buff)
{
	int				r;
	char			*tmp;

	r = 0;
	tmp = NULL;
	while (!(*remainder = ft_strchr(*s, '\n'))
			&& (r = read(fd, buff, BUFF_SIZE)))
	{
		if (r < 0)
			return (-1);
		buff[r] = '\0';
		tmp = *s;
		if (!(*s = ft_strjoin(*s, buff)))
			return (1);
		ft_strdel(&tmp);
	}
	return (r);
}

static int			get_line(const int fd, char **line, char **s)
{
	int				ret;
	char			buffer[BUFF_SIZE + 1];
	char			*remain;
	char			*tmp;
	int				len;

	ret = 0;
	remain = NULL;
	tmp = NULL;
	len = 0;
	if (fd < 0 || !line || BUFF_SIZE < 1)
		return (-1);
	if ((ret = read_fd(fd, &remain, &*s, buffer)) < 0)
		return (-1);
	if (!(len = ft_strlen(*s)) && !ret)
		return (0);
	if (!(*line = ft_strndup(*s, remain ? remain - *s : len)))
		return (-1);
	tmp = *s;
	if (!(*s = ft_strdup(remain ? remain + 1 : "")))
		return (-1);
	ft_strdel(&tmp);
	return (1);
}

static	t_list		*list_file_fd(t_list **file, int fd)
{
	t_list			*file_fd;

	file_fd = *file;
	while (file_fd)
	{
		if (file_fd->content_size == (size_t)fd)
			return (file_fd);
		file_fd = file_fd->next;
	}
	ft_lstadd(&*file, ft_lstnew("", fd));
	return (*file);
}

int					get_next_line(const int fd, char **line)
{
	static	t_list	*file;
	t_list			*current_file;

	current_file = NULL;
	if (fd < 0 || !line || BUFF_SIZE < 1)
		return (-1);
	if (!file)
		if (!(file = ft_lstnew("", fd)))
			return (-1);
	if (!(current_file = list_file_fd(&file, fd)))
		return (-1);
	if (!current_file->content || !(char *)current_file->content)
		if (!(current_file->content = ft_strnew(BUFF_SIZE)))
			return (-1);
	return (get_line(fd, &*line, (char **)&current_file->content));
}
