/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlachhab <hlachhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:22:25 by hlachhab          #+#    #+#             */
/*   Updated: 2024/04/24 10:27:20 by hlachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_free(char **str)
{
	if (!*str)
		return ;
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

int	ft_strchr(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i + 1);
		i++;
	}
	if (c == '\0')
		return (i);
	return (0);
}

char	*ft_strjoin(char *ptr, char *line)
{
	char	*str;
	int		i;
	int		j;

	i = ft_strlen(ptr) + ft_strlen(line);
	str = malloc(i + 1);
	if (!str)
	{
		ft_free(&ptr);
		return (NULL);
	}
	i = 0;
	j = 0;
	while (ptr && ptr[i] != '\0')
	{
		str[i] = ptr[i];
		i++;
	}
	while (line[j] != '\0')
		str[i++] = line[j++];
	str[i] = '\0';
	ft_free (&ptr);
	return (str);
}
