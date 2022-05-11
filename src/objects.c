/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-g <ralves-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 11:45:46 by ralves-g          #+#    #+#             */
/*   Updated: 2022/05/05 14:54:22 by ralves-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_count	*counter(void)
{
	static t_count	c;

	return (&c);
}

t_imgs	*sp(void)
{
	static t_imgs	sprites;

	return (&sprites);
}

char	*x_type(void)
{
	static char	c;

	return (&c);
}

t_objt	**objects(int n)
{
	static t_objt	*obj;
	static t_objt	*obj2;
	static t_objt	*obj3;
	static t_objt	*obj4;

	if (n == 64)
		return (&obj);
	if (n == 48)
		return (&obj2);
	if (n == 32)
		return (&obj3);
	if (n == 16)
		return (&obj4);
	else
		return (NULL);
}

t_anim	**collec(void)
{
	static t_anim	*anim;

	return (&anim);
}
