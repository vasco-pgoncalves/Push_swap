/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   idk.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vascopinto <vascopinto@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 19:34:22 by vascopinto        #+#    #+#             */
/*   Updated: 2026/01/16 17:36:38 by vascopinto       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_3(t_stack **a)
{
	t_stack *max;

	max = find_max_node(*a);
	if ((*a)->nbr == max->nbr)
		ft_ra(a);
	else if ((*a)->next->nbr == max->nbr)
		ft_rra(a);
	if ((*a)->nbr > (*a)->next->nbr)
		ft_sa(a);
}

void	move_a_to_top(t_stack **a, t_stack *node)
{
	while (*a != node)
	{
		if (node->above_median)
			ft_ra(a);
		else
			ft_rra(a);
	}
}

void	move_b_to_top(t_stack **b, t_stack *node)
{
	while (*b != node)
	{
		if (node->above_median)
			ft_rb(b);
		else
			ft_rrb(b);
	}
}

void	move_to_top(t_stack **stack, t_stack *node, char name)
{
	if (name == 'a')
		move_a_to_top(stack, node);
	else if (name == 'b')
		move_b_to_top(stack, node);
}
