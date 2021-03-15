#include "../includes/push_swap.h"

int		return_error(void)
{
	ft_putstr_fd("Error\n", 1);
	return (1);
}

int		is_duplicate(char **argv, int i)
{
	int		j;
	int		nb;

	j = 1;
	nb = ft_atoi(argv[i]);
	while (j < i)
	{
		if (ft_atoi(argv[j]) == nb)
			return (1);
		j++;
	}
	return (0);
}

int		is_long_nb(char *str)
{
	unsigned long	nb;
	int				sign;
	int				i;

	nb = 0;
	i = 0;
	sign = 1;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	if (i > 11 || (nb > 2147483647 && sign == 1) ||
		(nb > 2147483648 && sign == -1))
		return (1);
	return (0);
}

int		check_error_nb(char **argv)
{
	int		i;
	int		j;

	i = 0;
	while (argv[++i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == '-' && j == 0)
				j++;
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (0);
			j++;
		}
		if (is_long_nb(argv[i]))
			return (0);
		else if (is_duplicate(argv, i))
			return (0);
	}
	return (1);
}

int		is_in_order(t_stack *stack_a)
{
	t_stack		*current;
	int			size_a;

	size_a = ft_list_size(stack_a);
	if (size_a == 1 || size_a ==  0)
		return (1);
	current = stack_a;
	while (current->next)
	{
		if (current->content > current->next->content)
			return (0);
		current = current->next;
	}
	return (1);
}
