/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vascopinto <vascopinto@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 17:46:53 by vascopinto        #+#    #+#             */
/*   Updated: 2026/01/07 18:32:55 by vascopinto       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_push(t_stack **src, t_stack **dest)
{
	t_stack	*tmp_src;
	t_stack *tmp_dest;
	
	if(!*src)
		return;
	tmp_src = *src;
	*src = tmp_src->next;
	tmp_dest = *dest;
	*dest = tmp_src;
	tmp_src->next = tmp_dest;
}
void	ft_pa(t_stack **stack_a, t_stack **stack_b)
{
	ft_push(stack_b, stack_a);
	ft_printf("pa\n");
}
void	ft_pb(t_stack **stack_a, t_stack **stack_b)
{
	ft_push(stack_a, stack_b);
	ft_printf("pb\n");
}