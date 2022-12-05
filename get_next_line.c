/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima <vlima@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 12:19:41 by vlima             #+#    #+#             */
/*   Updated: 2022/12/05 15:55:23 by vlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	bf[BUFFER_SIZE];
	char		*str;
	int			i;
	int			j;

	str = NULL;
	if (!bf || BUFFER_SIZE < 1)
		return (NULL);

	str = ft_strjoin(0, bf);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	j = 0;
	while (i < BUFFER_SIZE)
	{
		str[j] = str[i];
		i++;
		j++;
	}
	str[j++] = 0;
	bf [read (fd, str, BUFFER_SIZE)] = 0;
	return (str);

}
/* 
int main()
{
	char	*line;
	int fd;
	fd = open("tst.txt",O_RDONLY);
	printf("%s",get_next_line(fd));
	line = get_next_line(fd);
} */
