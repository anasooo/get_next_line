/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asodor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:04:25 by asodor            #+#    #+#             */
/*   Updated: 2023/12/21 23:17:36 by asodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_readfile(int fd, char *buffer, char *s_buffer)
{
	int		readed;
	char	*tmp;

	readed = 1;
	while (readed != 0)
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed < 0)
			return (NULL);
		if (readed == 0)
			break ;
		buffer[readed] = '\0';
		if (!s_buffer)
			s_buffer = ft_strdup("");
		tmp = s_buffer;
		s_buffer = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = NULL;
		if (ft_strchr (buffer, '\n'))
			break ;
	}
	return (s_buffer);
}

char	*ft_getline(char **line)
{
	size_t	i;
	char	*shyata;
	char	*tmp;

	i = 0;
	while (line[0][i] != '\n' && line[0][i] != '\0')
		i++;
	if (line[0][i] == 0 || line[0][1] == 0)
		return (0);
	shyata = ft_substr(*line, i + 1, ft_strlen(*line) - i);
	if (*shyata == 0)
	{
		free(shyata);
		return (0);
	}
	tmp = *line;
	*line = ft_substr(tmp, 0, i + 1);
	free(tmp);
	line[0][i + 1] = '\0';
	return (shyata);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	static char	*s_buffer[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (0);
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (0);
	line = ft_readfile(fd, buffer, s_buffer[fd]);
	free(buffer);
	buffer = 0;
	if (!line)
	{
		free(s_buffer[fd]);
		s_buffer[fd] = NULL;
		return (0);
	}
	s_buffer[fd] = ft_getline(&line);
	return (line);
}
