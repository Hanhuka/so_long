/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-g <ralves-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 14:45:01 by ralves-g          #+#    #+#             */
/*   Updated: 2022/05/05 14:55:02 by ralves-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../get_next_line.h"

char	*cpyfrm2(char *str, int start, int end)
{
	char	*cpy;
	int		citer;

	if (!str || ft_strlen(str) == 0)
		return (0);
	if (end > -1 && (end - start + 1) > 0)
		cpy = (char *)malloc(end - start + 1 + 1);
	else
		cpy = (char *)malloc(ft_strlen(str) - start + 1 + 1);
	citer = 0;
	while ((str[start] && end == -1)
		|| (str[start] && start <= end && end != -1))
	{
		cpy[citer] = str[start];
		start++;
		citer++;
	}
	cpy[citer] = 0;
	return (cpy);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		i++;
	}
	return (i);
}

static char	*joiner(char const *s1, char const *s2, int size1, int size2)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = (char *)malloc(size1 + size2 + 1);
	if (!ptr)
		return (0);
	i = 0;
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		ptr[size1 + i] = s2[i];
		i++;
	}
	ptr[size1 + i] = '\0';
	return (ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size1;
	int		size2;

	if (!s1 && s2)
		return (cpyfrm2((char *) s2, 0, -1));
	if (s1 && !s2)
		return (cpyfrm2((char *) s1, 0, -1));
	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	return (joiner(s1, s2, size1, size2));
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*chr;

	chr = b;
	i = 0;
	while (i < len)
	{		
		chr[i] = (char) c;
		i++;
	}
	return (b);
}
