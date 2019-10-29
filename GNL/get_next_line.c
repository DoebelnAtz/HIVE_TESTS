/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadlercr <aadlercr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:52:32 by aadlercr          #+#    #+#             */
/*   Updated: 2019/10/28 10:43:31 by aadlercr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int						find_char(const char *str, char c)
{
	unsigned int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i + 1);
		i++;
	}
	return (0);
}

void					copy_to_char(char **line, char *content, char c)
{
	int		i;

	i = 0;
	while (content[i] && content[i] != c)
	{
		(*line)[i] = content[i];
		i++;
	}
	(*line)[i] = '\0';
}

static t_list			*get_fd(t_list **file, int fd)
{
	t_list				*current;

	current = *file;
	while (current)
	{
		if ((int)current->content_size == fd)
			return (current);
		current = current->next;
	}
	current = ft_lstnew("", fd);
	ft_lstadd(file, current);
	current = *file;
	return (current);
}

int						create_line(char **line, t_list *ptr, int r)
{
	int		i;
	char	*tmp;

	tmp = *line;
	if ((i = ft_strlen(ptr->content)) < r)
	{
		i = r;
	}
	if (!(*line = (char *)ft_strnew(i + 1)))
		return (-1);
	copy_to_char(line, ptr->content, '\n');
	if ((tmp = ft_strchr(ptr->content, '\n')))
	{
		if (!(tmp = ft_strdup(tmp + 1)))
			return (-1);
		free(ptr->content);
		ptr->content = tmp;
	}
	else
		ft_strclr(ptr->content);
	return (1);
}

int						get_next_line(const int fd, char **line)
{
	static t_list		*stack;
	int					r;
	char				buf[BUFF_SIZE + 1];
	char				*to_free;
	t_list				*tmp;

	if (fd < 0 || !line || read(fd, buf, 0) < 0)
		return (-1);
	tmp = get_fd(&stack, fd);
	while (!find_char(tmp->content, '\n') && (r = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[r] = '\0';
		to_free = tmp->content;
		if (!(tmp->content = ft_strjoin(tmp->content, buf)))
			return (-1);
		free(to_free);
	}
	if (!ft_strlen(tmp->content) && !r)
	{
		ft_strclr(*line);
		return (0);
	}
	return (create_line(line, tmp, r));
}
