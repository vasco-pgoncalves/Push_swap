/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vascopinto <vascopinto@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 11:36:21 by vascopinto        #+#    #+#             */
/*   Updated: 2026/01/21 11:36:33 by vascopinto       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void set_targets_b_to_a(t_stack *b, t_stack *a)
{
	t_stack *cur;
	t_stack *target;
	long best;

	while (b)
	{
		best = LONG_MAX;
		cur = a;
		target = NULL;
		while (cur)
		{
			if (cur->nbr > b->nbr && cur->nbr < best)
			{
				best = cur->nbr;
				target = cur;
			}
			cur = cur->next;
		}

		if (!target)
			b->target = find_min_node(a);
		else
			b->target = target;
		b = b->next;
	}
}
