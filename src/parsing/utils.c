void ft_error(void)
{
	ft_printf("Error\n");
}
void ft_is_digit(char c)
{
	if(c >= '0' && c <= '9')
		return (1);
	return (0);
}
int ft_is_signed(char c)
{
	if (c == '-' || c == '+')
		return (1);
	return (0);
}