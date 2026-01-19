/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vascopinto <vascopinto@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 17:26:17 by vascopinto        #+#    #+#             */
/*   Updated: 2026/01/16 16:43:31 by vascopinto       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	update_positions(t_stack *stack)
{
	int len;
	int i;
	t_stack *tmp;

	len = stack_len(stack);
	i = 0;
	tmp = stack;
	while (tmp)
	{
		tmp->index = i;
		if (i <= len / 2)
			tmp->above_median = true;
		else
			tmp->above_median = false;
		tmp = tmp->next;
		i++;
	}
}
void set_targets_a_to_b(t_stack *a, t_stack *b)
{
	t_stack	*current_b;
	t_stack	*target;
	long	best_match;

	while (a)
	{
		best_match = LONG_MIN;
		current_b = b;
		target = NULL;
		while (current_b)
		{
			if (current_b->nbr < a->nbr && current_b->nbr > best_match)
			{
				best_match = current_b->nbr;
				target = current_b;
			}
			current_b = current_b->next;
		}
		if (!target)
			a->target = find_max_node(b);
		else
			a->target = target;
		a = a->next;
	}
}
void calculate_costs(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while(a)
	{
		if (a->above_median)
			a->push_cost = a->index;
		else
			a->push_cost = len_a - a->index;
		if (a->target->above_median)
			a->push_cost += a->target->index;
		else
			a->push_cost += len_b - a->target->index;
		a = a->next;
	}
}