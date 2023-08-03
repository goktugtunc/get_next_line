/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gotunc <gotunc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:05:58 by gotunc            #+#    #+#             */
/*   Updated: 2023/08/03 14:18:10 by gotunc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	standard_write(char *buffer, int byt, char *str)
{
	int	i;
	int	n;

	n = ft_strlen(str);
	i = 0;
	while (i < byt)
	{
		str[ft_strlen(str) - n] = buffer[i];
		i++;
		n--;
	}
}

int	new_line_cont(char *buffer, char *str, int byt)
{
	int	i;
	int nl;
	int nll;
	int eps;

	i = 0;
	nl = 0;
	nll = 0;
	eps = 0;
	while (i < byt)
	{
		if (i == (byt -1))
			eps = 1;
		if (buffer[i] == '\n')
			nl = 1;
		if (buffer[i] == 0)
			nll = 1;
		i++;
	}
	//if (nl == 1)
	//	extra_write(buffer);
	if (eps == 1 || nll == 1)
		standard_write(buffer, byt, str);
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*buffer;
	int			i;
	int			byt;

	if (fd < 0)
		return (NULL);
	i = 0;
	byt = 1;
	while (byt != 0)
	{
		buffer = malloc(BUFFER_SIZE + 1);
		buffer[BUFFER_SIZE] = 0;
		byt = read(fd, buffer, BUFFER_SIZE);
		str = malloc(10);
		if (byt == 0)
			break;
		new_line_cont(buffer, str, byt);
		free(buffer);
	}
	return (buffer);
}

int	main(void)
{
	int	fd;

	fd = open("main.txt",O_RDWR);
	printf("%s", get_next_line(fd));
	return (0);
}
