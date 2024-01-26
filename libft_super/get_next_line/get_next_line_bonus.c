/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 20:10:17 by marboccu          #+#    #+#             */
/*   Updated: 2023/10/25 12:08:53 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*read_fd_line(int fd, char *line_read, char *buffer)
{
	ssize_t	bytes_read;
	char	*temp;

	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(buffer, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		if (!line_read)
		{
			line_read = ft_calloc(1, sizeof(char));
			if (!line_read)
				return (NULL);
		}
		temp = line_read;
		line_read = ft_strjoin(temp, buffer);
		free(temp);
	}
	free(buffer);
	return (line_read);
}

static char	*line_creator(char *line_buffer, char *line_read)
{
	ssize_t	i;
	ssize_t	len;

	i = 0;
	len = 0;
	while (line_buffer[i] != '\n' && line_buffer[i])
		i++;
	if (line_buffer[i] == '\n')
		i++;
	line_read = ft_calloc(sizeof(char), i + 1);
	if (!line_read)
		return (NULL);
	while (len < i)
	{
		line_read[len] = line_buffer[len];
		len++;
	}
	return (line_read);
}

static char	*extract_new_line(char *line_buffer)
{
	ssize_t	i;
	ssize_t	len;
	char	*new_line;

	i = 0;
	len = 0;
	if (!line_buffer)
		return (NULL);
	while (line_buffer[i] != '\n' && line_buffer[i])
		i++;
	if (line_buffer[i] == '\n')
		i++;
	new_line = ft_calloc(sizeof(char), ft_strlen(line_buffer) - i + 1);
	if (!new_line)
		return (NULL);
	while (line_buffer[i + len])
	{
		new_line[len] = line_buffer[i + len];
		len++;
	}
	free(line_buffer);
	return (new_line);
}

char	*get_next_line(int fd)
{
	static char	*save_buff[4096];
	char		*buffer;
	char		*line_read;

	line_read = NULL;
	buffer = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (read(fd, 0, 0) < 0 || fd < 0 || BUFFER_SIZE < 1 || !buffer)
	{
		free(save_buff[fd]);
		free(buffer);
		save_buff[fd] = NULL;
		buffer = NULL;
		return (NULL);
	}
	save_buff[fd] = read_fd_line(fd, save_buff[fd], buffer);
	if (*save_buff[fd] == 0)
	{
		free(save_buff[fd]);
		save_buff[fd] = 0;
		return (save_buff[fd]);
	}
	line_read = line_creator(save_buff[fd], line_read);
	save_buff[fd] = extract_new_line(save_buff[fd]);
	return (line_read);
}

// int	main(void)
// {
// 	int		fd[2];
// 	char	*line;

// 	fd[0] = open("test.txt", O_RDONLY);
// 	fd[1] = open("text.txt", O_RDONLY);
// 	line = get_next_line(fd[0]);
// 	while (line != NULL)
// 	{
// 		printf("file 1: %s", line);
// 		free(line);
// 		line = get_next_line(fd[0]);
// 	}
// 	line = get_next_line(fd[1]);
// 	while (line != NULL)
// 	{
// 		printf("file 2: %s", line);
// 		free(line);
// 		line = get_next_line(fd[1]);
// 	}
// 	close(fd[0]);
// 	close(fd[1]);
// 	return (0);
// }
