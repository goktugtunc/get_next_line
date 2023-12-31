/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gotunc <gotunc@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 11:55:43 by gotunc            #+#    #+#             */
/*   Updated: 2023/08/08 11:55:50 by gotunc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*delline(char *line)
{
	char	*buff;
	int		i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i])
	{
		free(line);
		return (NULL);
	}
	i++;
	buff = ft_substr(line, i, (ft_strlen(line) - i));
	if (!buff)
		return (NULL);
	free(line);
	return (buff);
}

char	*getline(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!(buffer[i]))
		return (NULL);
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\n')
		line = ft_substr(buffer, 0, i + 1);
	else
		line = ft_substr(buffer, 0, i);
	if (!line)
		return (NULL);
	return (line);
}

char	*readfile(int fd, char *buffer)
{
	char	*buff;
	int		byte;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	byte = 1;
	while (!ft_strchr(buffer, '\n') && byte != 0)
	{
		byte = read(fd, buff, BUFFER_SIZE);
		if (byte == -1)
		{
			free(buff);
			free(buffer);
			return (NULL);
		}
		buff[byte] = '\0';
		buffer = ft_strjoin(buffer, buff);
	}
	free(buff);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = readfile(fd, buffer);
	if (!buffer)
		return (NULL);
	line = getline(buffer);
	buffer = delline(buffer);
	return (line);
}
