/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-g <ralves-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 12:41:30 by ralves-g          #+#    #+#             */
/*   Updated: 2022/05/05 14:55:02 by ralves-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../get_next_line.h"

/*char	*till_nl(int fd, char *buf) // SEM STRUCT
{
	char	*join1;
	char	*join2;
	char	*added;
	int		i;

	i = 0;
	join1 = cpyfrm2(buf, 0, -1);
	join2 = (char *)malloc(BUFFER_SIZE + 1);
	ft_memset(join2, 0, BUFFER_SIZE + 1);
	i = read(fd, join2, BUFFER_SIZE);
	if (i == 0)
	{
		free(join1);
		free(join2);
		return (NULL);
	}
	added = ft_strjoin(join1, join2);
	free(join1);
	free(join2);
	return (added);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*rtval;
	char		*changer;
	size_t		i;
	
	if (BUFFER_SIZE < 1 || fd < 0)
		return (0);
	i = 0;
	while (!buf || buf[i] != '\n')
	{
		while (i < ft_strlen(buf) && buf[i] != '\n')
			i++;
		if (buf != NULL && buf[i] == '\n')
			break ;
		changer = cpyfrm2(buf, 0, -1);
		free(buf);
		buf = till_nl(fd, changer);
		if (buf == NULL)
			break ;
		free(changer);
	}
	if (buf == NULL && i == ft_strlen(changer))
		return (changer);
	changer = cpyfrm2(buf, i + 1, -1);
	rtval = cpyfrm2(buf, 0, i);
	free(buf);
	if (changer != NULL)
		buf = cpyfrm2(changer, 0, -1);
	free(changer);
	return (rtval);
}*/

struct s_gnl
{
	char	*buf;
	char	*changer;
	size_t	i;
};

char	*till_nl(int fd, char *buf)
{
	char	*join1;
	char	*join2;
	char	*added;
	int		i;

	i = 0;
	join1 = cpyfrm2(buf, 0, -1);
	join2 = (char *)malloc(10 + 1);
	ft_memset(join2, 0, 10 + 1);
	i = read(fd, join2, 10);
	if (i == 0)
	{
		free(join1);
		free(join2);
		return (NULL);
	}
	added = ft_strjoin(join1, join2);
	free(join1);
	free(join2);
	return (added);
}

struct s_gnl	bruh(int fd, char *buf)
{
	struct s_gnl	one;

	one.buf = cpyfrm2(buf, 0, -1);
	one.i = 0;
	while (!one.buf || one.buf[one.i] != '\n')
	{
		while (one.i < ft_strlen(one.buf) && one.buf[one.i] != '\n')
			one.i++;
		if (one.buf != NULL && one.buf[one.i] == '\n')
			break ;
		one.changer = cpyfrm2(one.buf, 0, -1);
		free(one.buf);
		one.buf = till_nl(fd, one.changer);
		if (one.buf == NULL)
			break ;
		free(one.changer);
	}
	return (one);
}

char	*get_next_line(int fd)
{
	static char		*buf;
	struct s_gnl	two;

	if (10 < 1 || fd < 0)
		return (0);
	two = bruh(fd, buf);
	free(buf);
	buf = cpyfrm2(two.buf, 0, -1);
	free(two.buf);
	if (buf == NULL && two.i == ft_strlen(two.changer))
		return (two.changer);
	two.changer = cpyfrm2(buf, two.i + 1, -1);
	two.buf = cpyfrm2(buf, 0, two.i);
	free(buf);
	if (two.changer != NULL)
		buf = cpyfrm2(two.changer, 0, -1);
	free(two.changer);
	return (two.buf);
}
