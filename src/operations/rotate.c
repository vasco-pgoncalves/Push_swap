/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vascopinto <vascopinto@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 14:04:48 by vascopinto        #+#    #+#             */
/*   Updated: 2026/01/19 18:21:36 by vascopinto       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_rotate(t_stack **node)
{
	t_stack	*head;
	t_stack	*tail;

	if(!*node || !(*node)->next)
		return ;
	head = *node;
	*node = (*node)->next;
	tail = ft_last_node(*node);
	head->next = NULL;
	tail->next = head;
}
void	ft_ra(t_stack **stack_a)
{
	ft_rotate(stack_a);
	ft_printf("ra\n");
}
void	ft_rb(t_stack **stack_b)
{
	ft_rotate(stack_b);
	ft_printf("rb\n");
}
void	ft_rr(t_stack **stack_a, t_stack **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	ft_printf("rr\n");
}
