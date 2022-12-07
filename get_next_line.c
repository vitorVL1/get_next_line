/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima <vlima@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 12:19:41 by vlima             #+#    #+#             */
/*   Updated: 2022/12/07 14:54:45 by vlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	bf[BUFFER_SIZE + 1];
	char		*str;

	str = NULL;
	if (fd < 0 || fd > FOPEN_MAX)
		return (NULL);
	if (!bf[0])
		bf[read(fd, bf, BUFFER_SIZE)] = 0;
	while (bf[0])
	{
		str = ft_strjoin(str, bf);
		if (!str)
			return (NULL);
		if (organizer(bf) == 1)
			break ;
		if (read(fd, bf, 0) < 0)
		{
			free(str);
			return (NULL);
		}
		bf[read (fd, bf, BUFFER_SIZE)] = 0;
	}
	return (str);
}
