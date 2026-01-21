#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

typedef struct s_stack
{
	int		nbr;
	int		index;
	int		push_cost;
	bool	above_median;
	struct	s_stack	*target;
	struct	s_stack	*next;
	struct	s_stack	*prev;
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

//operations

void	ft_push(t_stack **src, t_stack **dest);
void	ft_pa(t_stack **stack_a, t_stack **stack_b);
void	ft_pb(t_stack **stack_a, t_stack **stack_b);
void	ft_rev_rotate(t_stack **node);
void	ft_rra(t_stack **stack_a);
void	ft_rrb(t_stack **stack_b);
void	ft_rrr(t_stack **stack_a, t_stack **stack_b);
void	ft_rotate(t_stack **node);
void	ft_ra(t_stack **stack_a);
void	ft_rb(t_stack **stack_b);
void	ft_rr(t_stack **stack_a, t_stack **stack_b);
void	ft_swap(t_stack **node);
void	ft_sa(t_stack **stack_a);
void	ft_sb(t_stack **stack_b);
void	ft_ss(t_stack **stack_a, t_stack **stack_b);
t_stack	*ft_last_node(t_stack *stack);

//Turk

t_stack	*find_max_node(t_stack *stack);
t_stack	*find_min_node(t_stack *stack);
int		stack_len(t_stack *stack);
t_stack	*ft_last_node(t_stack *stack);
bool	stack_sorted(t_stack *stack);
void	sort_3(t_stack **a);
void	move_a_to_top(t_stack **a, t_stack *node);
void	move_b_to_top(t_stack **b, t_stack *node);
void	move_to_top(t_stack **stack, t_stack *node, char name);
t_stack	*get_cheapest(t_stack *a);
void	push_cheapest (t_stack **a, t_stack **b);
void	turk_loop(t_stack **a, t_stack **b);
void	init_stack(t_stack **stack, int *arr, int size);
void	set_targets_b_to_a(t_stack *b, t_stack *a);
void	set_targets_a_to_b(t_stack *a, t_stack *b);
void	update_positions(t_stack *stack);
void	calculate_costs(t_stack *a, t_stack *b);

#endif

