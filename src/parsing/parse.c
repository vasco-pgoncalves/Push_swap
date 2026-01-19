/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vascopinto <vascopinto@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:20:12 by vascopinto        #+#    #+#             */
/*   Updated: 2026/01/14 17:10:47 by vascopinto       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int *ft_parse(int argc, char **argv, int *out_size)
{
	char **token;
	int   *arr;
	int    i;

	token = ft_separate(argc, argv);
	if (!token || !token[0])
		ft_error();
	*out_size = ft_split_size(token);
	arr = malloc(sizeof(int) * (*out_size));
	if (!arr)
		ft_error();
	i = 0;
	while (i < *out_size)
	{
		if (!ft_is_valid_number(token[i]))
		{
			//ft_free_split(token);
			free(arr);
			ft_error();
		}
		arr[i] = ft_atoi_range(token[i]);
		i++;
	}
	ft_check_duplicates(arr, *out_size);
	//ft_free_split(token);
	return (arr);
}

