/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vascopinto <vascopinto@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:20:12 by vascopinto        #+#    #+#             */
/*   Updated: 2026/01/13 18:28:25 by vascopinto       ###   ########.fr       */
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

int main(int argc, char **argv)
{
	int *arr;
	int size;
	int i;

	if (argc < 2)
		return (0); // nothing to do

	// Parse input safely
	arr = ft_parse(argc, argv, &size);

	// Print numbers to verify parser works
	i = 0;
	while (i < size)
	{
		ft_putnbr_fd(arr[i], 1);  // prints number
		ft_putchar_fd('\n', 1);   // newline
		i++;
	}

	// Clean up
	free(arr);

	return (0);
}
