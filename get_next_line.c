/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekorkmaz <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 18:00:27 by ekorkmaz          #+#    #+#             */
/*   Updated: 2022/03/07 20:47:45 by ekorkmaz         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*get_line(char *tut, int len)
{
	static int	i = 0;
	static int	turn = 0;
	char		*x;
	int			c;

	c = 0;
	x = (char *)malloc(sizeof(char) * (len + 2));
	if (!x)
		return (NULL);
	i += turn;
	while (tut[i] != '\n' && tut[i] != '\0')
	{
		x[c] = tut[i];
		i++;
		c++;
	}
	if (tut[i] == '\n')
		x[c++] = '\n';
	x[c] = '\0';
	if (turn != 1)
		turn = 1;
	return (x);
}

char	*get_next_line(int fd)
{
	char	*buf;
	int		bytes_read;
	char	*x;

	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes_read = read(fd, buf, BUFFER_SIZE);
	x = get_line(buf, (BUFFER_SIZE + 1));
	free(buf);
	return (x);
}

int main()
{
	int	fd;
	//int	fd1;

	fd = open("file.txt", O_RDONLY);
	//fd1 = open("text.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	//printf("fd1: %s", get_next_line(fd1));
	//printf("fd1: %s", get_next_line(fd1));
	//printf("fd1: %s", get_next_line(fd1));
	//printf("fd1: %s", get_next_line(fd1));
	close(fd);
	return (0);
}
