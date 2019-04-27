/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbearded <sbearded@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 23:57:07 by sbearded          #+#    #+#             */
/*   Updated: 2019/04/27 23:01:39 by sbearded         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_list	*get_lst_cur(t_list **lst_fd, const int fd)
{
	t_list	*lst;

	lst = *lst_fd;
	while (lst)
	{
		if (lst->content_size == (size_t)fd)
			return (lst);
		lst = lst->next;
	}
	lst = ft_lstnew(NULL, 0);
	lst->content_size = (size_t)fd;
	ft_lstadd(lst_fd, lst);
	return (lst);
}

static int		get_line(t_list *lst, char **line, const int fd)
{
	char	*p;
	char	*tmp;
	char	*new;

	free(*line);
	if ((p = ft_strchr(lst->content, '\n')))
	{
		*p = '\0';
		*line = ft_strdup(lst->content);
		tmp = lst->content;
		lst->content = ft_strdup(p + 1);
		free(tmp);
		return (1);
	}
	*line = ft_strdup(lst->content);
	free(lst->content);
	lst->content = NULL;
	get_next_line(fd, &new);
	tmp = *line;
	*line = ft_strjoin(*line, new);
	free(tmp);
	free(new);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	static t_list	*lst_fd;
	t_list			*lst_cur;
	int				status;

	if (fd < 0 || BUFF_SIZE < 0 || !line)
		return (-1);
	lst_cur = get_lst_cur(&lst_fd, fd);
	*line = ft_strnew(1);
	if (lst_cur->content == NULL)
	{
		ft_bzero(buf, BUFF_SIZE + 1);
		status = read(fd, buf, BUFF_SIZE);
		if (status == 0 || status == -1)
			return (status);
		lst_cur->content = ft_strdup(buf);
	}
	status = get_line(lst_cur, line, fd);
	if (lst_cur->content && *(char*)(lst_cur->content) == '\0')
		ft_lsterase(&lst_fd, "\0", 1);
	return (status);
}
