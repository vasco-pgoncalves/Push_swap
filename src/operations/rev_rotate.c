/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vascopinto <vascopinto@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 16:58:48 by vascopinto        #+#    #+#             */
/*   Updated: 2026/01/16 15:33:08 by vascopinto       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_rev_rotate(t_stack **node)
{
	t_stack	*prev;
	t_stack	*tail;

	if(!*node || !(*node)->next)
		return ;
	prev = *node;
	while (prev->next->next)
		prev = prev->next;
	tail = ft_last_node(*node);
	prev->next = NULL;
	tail->next = *node;
	*node = tail;
}
void	ft_rra(t_stack **stack_a)
{
	ft_rev_rotate(stack_a);
	ft_printf("rra\n");
}
void	ft_rrb(t_stack **stack_b)
{
	ft_rev_rotate(stack_b);
	ft_printf("rrb\n");
}
void	ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
	ft_rev_rotate(stack_a);
	ft_rev_rotate(stack_b);
	ft_printf("rrr\n");
}
