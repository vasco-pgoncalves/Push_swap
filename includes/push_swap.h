#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

typedef struct s_stack
{
	int		a_value;
	int		b_value;
	struct	s_stack	*next;
}t_stack;

//Parsing

void	ft_check_duplicates(int *arr, int size);
int		ft_atoi_range(const char *nptr);
int		*ft_parse(int argc, char **argv, int *out_size);
char	**ft_separate(int argc, char **argv);
char	**join_strings(char **a, char **b);
void	join_strings2(char **final, char **a, char **b);
void	ft_error(void);
int		ft_is_digit(char c);
int		ft_is_signed(char c);
int		size_ab(char *a);
int		ft_split_size(char **split);
int		ft_numbers(int argc, char **argv);
int		ft_is_valid_number(char *s);



#endif

