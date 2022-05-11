/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-g <ralves-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:21:42 by ralves-g          #+#    #+#             */
/*   Updated: 2022/05/05 14:54:22 by ralves-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_anim	*new_module(void *new)
{		
	t_anim	*linker;

	linker = (t_anim *)malloc(sizeof(*linker));
	if (linker == NULL)
		return (0);
	linker->img = new;
	linker->next = NULL;
	return (linker);
}

void	stackadd_back(t_anim **stack, t_anim *new)
{
	t_anim	*ptr;
	void	*tmp;

	if (!new)
	{
		ft_lstclear(stack);
		write(1, "ERROR: malloc = NULL\n", 21);
		exit(1);
	}
	if (!(*stack))
	{
		(*stack) = new;
		(*stack)->next = (*stack);
		return ;
	}
	ptr = *stack;
	tmp = ptr->img;
	while (ptr->next->img != tmp)
		ptr = ptr->next;
	ptr->next = new;
	ptr->next->next = (*stack);
}

void	break_circle(t_anim **stack)
{
	t_anim	*tmp;
	void	*tmp2;

	tmp = (*stack);
	tmp2 = (*stack)->img;
	while (tmp->next->img != tmp2)
		tmp = tmp->next;
	tmp->next = NULL;
}

void	ft_lstclear(t_anim **stack)
{
	t_anim	*ptr;

	break_circle(stack);
	if (!stack || !*stack)
		return ;
	while (stack && *stack)
	{
		ptr = (*stack)->next;
		free(*stack);
		*stack = ptr;
	}
}

void	animate_collectable(void)
{
	t_objt	*tmp;

	tmp = (*objects(64));
	while (tmp)
	{
		if (tmp->type == 'C')
			tmp->img = (*collec())->img;
		tmp = tmp->next;
	}
	(*collec()) = (*collec())->next;
}
