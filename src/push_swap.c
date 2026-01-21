/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vascopinto <vascopinto@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 17:22:34 by vascopinto        #+#    #+#             */
/*   Updated: 2026/01/21 11:21:36 by vascopinto       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int main(int argc, char **argv)
{
    int     *arr;
    int     size;
    t_stack *a = NULL;
    t_stack *b = NULL;

    if (argc < 2)
        return (0);
    arr = ft_parse(argc, argv, &size);
    init_stack(&a, arr, size);
    init_stack(&b, NULL, 0);
    if (!stack_sorted(a))
        turk_loop(&a, &b);
    //free_stack(&a);
    //free_stack(&b);
    free(arr);
    return (0);
}
void	init_stack(t_stack **stack, int *arr, int size)
{
	t_stack	*node;
	t_stack	*last;
	int		i;

	*stack = NULL;
	if (!arr || size <= 0)
		return;
	last = NULL;
	i = 0;
	while (i < size)
	{
		node = malloc(sizeof(t_stack));
		if (!node)
			return;
		node->nbr = arr[i++];
		node->index = 0;
		node->push_cost = 0;
		node->above_median = false;
		node->target = NULL;
		node->next = NULL;
		node->prev = last;
		if (last)
			last->next = node;
		else
			*stack = node;
		last = node;
	}
}


