/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gotunc <gotunc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 04:21:49 by gotunc            #+#    #+#             */
/*   Updated: 2023/08/04 13:01:50 by gotunc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "get_next_line.h"

//int	ft_strlen(char *d)
//{
//	int	i;

//	i = 0;
//	while (d[i])
//		i++;
//	return (i);
//}

//char	*ft_strjoin(char const *s1, char const *s2)
//{
//	char	*d;
//	int		i;
//	int		j;

//	i = -1;
//	j = 0;
//	d = (char *)malloc((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char) + 1);
//	if (!d)
//		return (0);
//	else
//	{
//		while (s1[++i])
//			d[i] = s1[i];
//		while (s2[j])
//		{
//			d[i] = s2[j];
//			j++;
//			i++;
//		}
//		d[i] = 0;
//		return (d);
//	}
//	return (0);
//}

//char	*ft_strstr(char *str, char *to_find)
//{
//	int	i;
//	int	j;

//	i = 0;
//	j = 0;
//	if (to_find[j] == '\0')
//		return (str);
//	while (str[i] != '\0')
//	{
//		while (str[i + j] == to_find[j] && str[i + j] != '\0')
//			j++;
//		if (to_find[j] == '\0')
//			return (str + i);
//		i++;
//		j = 0;
//	}
//	return (0);
//}

//int	linecount(char *d)
//{
//	int	i;
//	int	j;

//	i = 0;
//	j = 0;
//	while (d)
//	{
//		if (d[i] == '\n')
//			j++;
//	}
//	return (j + 1);
//}
