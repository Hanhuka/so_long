/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   side_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-g <ralves-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 11:56:30 by ralves-g          #+#    #+#             */
/*   Updated: 2022/05/05 14:54:22 by ralves-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	int		size;
	int		i;

	size = 0;
	while (s1[size] != '\0')
		size++;
	ptr = malloc(size + 1);
	if (!ptr)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

static int	num_size(int n)
{
	int	size;

	size = 0;
	if (n < 0)
	{
		size++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

static char	*converter(int n, char *result, int size)
{
	if (n < 0)
	{
		result[0] = '-';
		n *= -1;
	}
	result[size - 1] = '\0';
	while (n > 0)
	{
		result[size - 2] = n % 10 + '0';
		n /= 10;
		size--;
	}
	return (result);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		num;
	int		size;

	num = n;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == -0)
		return (ft_strdup("0"));
	size = (num_size(num) + 1);
	result = malloc((size) * 1);
	if (!result)
		return (0);
	return (converter(n, result, size));
}

void	printf_side_info(t_win *win)
{
	char	*str;
	char	*str2;
	char	*stps;

	str = ft_itoa((*counter()).collect);
	str2 = ft_strjoin("left = ", str);
	stps = ft_itoa((*steps()));
	mlx_put_image_to_window((*win).mlx, (*win).mlx_win, (*sp()).side_info,
		(*win).width, 0);
	mlx_string_put((*win).mlx, (*win).mlx_win, (*win).width + 50, 280,
		0x00780EFD, "collectables");
	mlx_string_put((*win).mlx, (*win).mlx_win, (*win).width + 50, 300,
		0x00780EFD, str2);
	mlx_string_put((*win).mlx, (*win).mlx_win, (*win).width + 150, 200,
		0x00FFFFFF, stps);
	free(str);
	free(str2);
	free(stps);
}
