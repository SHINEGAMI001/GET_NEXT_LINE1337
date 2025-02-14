/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlachhab <hlachhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 22:28:16 by hlachhab          #+#    #+#             */
/*   Updated: 2024/04/26 18:39:01 by hlachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_getnewline(char	*str)
{
	char	*res;
	int		i;
	int		pos;

	i = 0;
	pos = ft_strchr(str, '\0');
	res = malloc((pos + 1) * sizeof(char));
	if (!res)
		return (0);
	while (str && str[i] && str[i] != '\n')
	{
		res[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		res[i] = '\n';
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_nextline(char *str)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
		i++;
	if (str[i] == '\0')
	{
		ft_free(&str);
		return (str);
	}
	res = malloc(sizeof(char) * (ft_strlen(str + i) + 1));
	if (res == NULL)
		return (NULL);
	j = 0;
	while (str[i] != '\0')
		res[j++] = str[i++];
	res[j] = '\0';
	ft_free(&str);
	return (res);
}

char	*read_line(int fd, char *str)
{
	char	*res;
	ssize_t	n;

	n = BUFFER_SIZE;
	res = (char *)malloc((BUFFER_SIZE + 1));
	if (!res)
		return (NULL);
	while (n != 0)
	{
		n = read(fd, res, BUFFER_SIZE);
		if (n == 0)
			break ;
		res[n] = '\0';
		str = ft_strjoin(str, res);
		if (!str)
		{
			ft_free (&res);
			return (NULL);
		}
		if (ft_strchr(res, '\n'))
			break ;
	}
	ft_free (&res);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		ft_free(&str);
		return (NULL);
	}
	str = read_line(fd, str);
	if (str == NULL)
		return (NULL);
	line = ft_getnewline(str);
	if (!line)
	{
		ft_free(&str);
		return (NULL);
	}
	str = ft_nextline(str);
	return (line);
}

// int main()
// {
// 	int	fd = open("tests/read_error.txt", O_RDONLY);
// 	// printf("fd = %d\n", fd);
// 	printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	close (fd);
// 	return (0);
// }