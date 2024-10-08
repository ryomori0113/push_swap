/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryomori <ryomori@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-09 03:19:41 by ryomori           #+#    #+#             */
/*   Updated: 2024-09-09 03:19:41 by ryomori          ###   #########include  */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

int	ps_atoi(const char *str)
{
	long	value;
	int		sign;

	sign = 1;
	value = 0;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		value = value * 10 + *str - '0';
		if ((sign == 1 && value > INT_MAX)
			|| (sign == -1 && value - 1 > INT_MAX))
			err_exit();
		str++;
	}
	return ((int)(value * sign));
}

bool	is_digit_str(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	if (!*str)
		return (false);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (false);
		str++;
	}
	return (true);
}

int	count_word(char **argv)
{
	int	i;
	int	j;
	int	count;

	i = 1;
	count = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == ' ')
				count++;
			j++;
		}
		i++;
		count++;
	}
	return (count);
}

void	all_free(char **result)
{
	int	i;

	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
}

bool	is_unique(t_stack *a)
{
	int	i;

	i = 0;
	while (i < a->size)
	{
		if (a->stack[i] == a->stack[a->size])
			return (false);
		i++;
	}
	return (true);
}
