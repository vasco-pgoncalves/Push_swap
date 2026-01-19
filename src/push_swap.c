/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vascopinto <vascopinto@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 17:22:34 by vascopinto        #+#    #+#             */
/*   Updated: 2026/01/14 17:27:20 by vascopinto       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int main(int argc, char **argv)
{
	int		*arr;
	int		size;
	t_stack	a;
	t_stack	b;

	if (argc < 2)
		return (0);
	arr = ft_parse(argc, argv, &size);
	init_stack(&a, arr, size);
	init_stack(&b, NULL, 0);
	if (!is_sorted(&a))
		turk_sort(&a, &b);
	free_stack(&a);
	free_stack(&b);
	free(arr);
	return (0);
}
