/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitor <aitor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:02:21 by aitor             #+#    #+#             */
/*   Updated: 2025/03/03 11:12:43 by aitor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_free(char *buffer, char *buf)
{
	char	*temp;

	temp = ft_strjoin_gnl(buffer, buf);
	free(buffer);
	return (temp);
}

char	*ft_new_line(char *storage)
{
	char	*line;
	int		i;

	i = 0;
	if (!storage)
		return (NULL);
	while (storage[i] && storage[i] != '\n')
		i++;
	if (storage[i] == '\n')
		i++;
	line = ft_calloc_gnl(i + 1, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (storage[i] && storage[i] != '\n')
	{
		line[i] = storage[i];
		i++;
	}
	if (storage[i] && storage[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*ft_next(char *storage)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	if (!storage)
		return (NULL);
	while (storage[i] && storage[i] != '\n')
		i++;
	if (!storage[i])
		return (ft_free_and_null(storage));
	i++;
	if (!storage[i])
		return (ft_free_and_null(storage));
	line = malloc(sizeof(char) * (ft_strlen(&storage[i]) + 1));
	if (!line)
		return (ft_free_and_null(storage));
	j = 0;
	while (storage[i])
		line[j++] = storage[i++];
	line[j] = '\0';
	free(storage);
	return (line);
}

char	*ft_read_file(int fd, char *storage)
{
	int		bytes;
	char	*buffer;
	char	*temp_storage;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_calloc_gnl(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	bytes = read(fd, buffer, BUFFER_SIZE);
	while (bytes > 0)
	{
		buffer[bytes] = '\0';
		temp_storage = ft_free(storage, buffer);
		if (!temp_storage)
			return (free(buffer), free(storage), NULL);
		storage = temp_storage;
		if (ft_strchr_gnl(buffer, '\n'))
			return (free(buffer), storage);
		bytes = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	return (storage);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(storage);
		storage = NULL;
		return (NULL);
	}
	storage = ft_read_file(fd, storage);
	if (!storage)
		return (NULL);
	line = ft_new_line(storage);
	storage = ft_next(storage);
	return (line);
}
