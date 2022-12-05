/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima <vlima@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:29:13 by vlima             #+#    #+#             */
/*   Updated: 2022/12/05 14:45:05 by vlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;

	while (s[i] != '\n' || s[i] != '\0')
	{
		i++;
	}
	if (s[i] == '\n')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	j = 0;
	i = 0;
	if (!str)
		return (NULL);
	while (s1[i] != '\0')
	{
	str[j] = s1[i];
			i++;
			j++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		str[j] = s2[i];
			i++;
			j++;
	}
	str[j] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;

	while (s)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i + 1]);
		if ((char)c == s[i])
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}
