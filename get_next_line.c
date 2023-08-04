/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gotunc <gotunc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:05:58 by gotunc            #+#    #+#             */
/*   Updated: 2023/08/04 21:54:07 by gotunc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*str;
	char		*d;

	if (fd < 0 || read(fd, 0, 0) == 0 || BUFFER_SIZE < 1)
		return (0);
	d = malloc(sizeof(char) * (BUFFER_SIZE + 1));
}
