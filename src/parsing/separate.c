/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vascopinto <vascopinto@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 14:00:50 by vascopinto        #+#    #+#             */
/*   Updated: 2026/01/09 16:55:29 by vascopinto       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

char	**ft_separate(int argc, char **argv)
{
	int i;
	char **split;
	char **out;

	i = 1;
	out = NULL;
	if (argc < 2)
		return (NULL);
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (!split)
			ft_error ();
		out = join_strings(out, split);
		i++;
	}
	if (!out || !out[0])
		ft_error();
	return(out);
}
char	**join_strings(char **a, char **b)
{
	char	**final;
	int		size_a;
	int		size_b;

	size_a = 0;
	size_b = 0;
	if (a)
		while (a[size_a])
			size_a++;
	while (b[size_b])
		size_b++;
	final = malloc(sizeof(char *) * (size_a + size_b + 1));
	if (!final)
		ft_error();
	join_strings2(final, a, b);
//	free(a);
//	free(b);
	return (final);
}
void	join_strings2(char **final, char **a, char **b)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (a)
		while (a[i])
		{
			final[i] = a[i];
			i++;
		}
	while (b[j])
	{
		final[i + j] = b[j];
		j++;
	}
	final[i + j] = NULL;
}

