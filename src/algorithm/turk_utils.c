/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vascopinto <vascopinto@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 12:37:45 by vascopinto        #+#    #+#             */
/*   Updated: 2026/01/21 11:32:35 by vascopinto       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack	*find_max_node(t_stack *stack)
{
	t_stack	*max;

	if(!stack)
		return(NULL);
	max = stack;
	while(stack)
	{
		if(stack->nbr > max->nbr)
			max = stack;
		stack = stack->next;
	}
	return(max);
}

t_stack	*find_min_node(t_stack *stack)
{
	t_stack	*min;

	if(!stack)
		return(NULL);
	min = stack;
	while(stack)
	{
		if(stack->nbr < min->nbr)
			min = stack;
		stack = stack->next;
	}
	return(min);
}
int	stack_len(t_stack *stack)
{
	int	len;
	
	len = 0;
	if (!stack)
		return(0);
	while(stack)
	{
		len++;
		stack = stack->next;
	}
	return(len);
}
t_stack	*ft_last_node(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

bool stack_sorted(t_stack *stack)
{
	if (!stack)
		return (true);
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (false);
		stack = stack->next;
	}
	return (true);
}
