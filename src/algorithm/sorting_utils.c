/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vascopinto <vascopinto@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 19:34:22 by vascopinto        #+#    #+#             */
/*   Updated: 2026/01/21 13:13:12 by vascopinto       ###   ########.fr       */
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
t_stack	*get_cheapest(t_stack *a)
{
	t_stack	*cheapest;
	int	min_cost;

	min_cost = INT_MAX;
	cheapest = NULL;
	while (a)
	{
		if (a->push_cost < min_cost)
		{
			min_cost = a->push_cost;
			cheapest = a;
		}
		a = a->next;
	}
	return (cheapest);
}
