/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validade.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vascopinto <vascopinto@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:24:43 by vascopinto        #+#    #+#             */
/*   Updated: 2026/01/13 18:37:51 by vascopinto       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_numbers(int argc, char **argv)
{
	char	**token;
	int		i;

	i = 0;
	token = ft_separate(argc, argv);
	if (!token || !token[0])
		ft_error();
	i = 0;
	while (token[i])
	{
		if (!ft_is_valid_number(token[i]))
		{
			//FREE
			ft_error();
		}
		i++;
	}
	return (1);
}
int	ft_is_valid_number(char *s)
{
	int i;

	i = 0;

	if (!s || !s[0])
		return (0);
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (!s[i])
		return(0);
	while (s[i])
	{
		if (!ft_is_digit(s[i]))
			return (0);
		i++;
	}
	return (1);
}