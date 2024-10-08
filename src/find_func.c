/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryomori <ryomori@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-09 03:19:08 by ryomori           #+#    #+#             */
/*   Updated: 2024-09-09 03:19:08 by ryomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_max(t_stack *stack)
{
	int	i;
	int	max;

	i = 0;
	max = stack->stack[0];
	while (stack->size > i)
	{
		if (stack->stack[i] > max)
			max = stack->stack[i];
		i++;
	}
	return (max);
}

int	find_min(t_stack *stack)
{
	int	i;
	int	min;

	i = 0;
	min = stack->stack[0];
	while (stack->size > i)
	{
		if (stack->stack[i] < min)
			min = stack->stack[i];
		i++;
	}
	return (min);
}

int	find_index(t_stack *stack, int nb)
{
	int	i;

	i = 0;
	while (stack->size > i)
	{
		if (stack->stack[i] == nb)
			break ;
		i++;
	}
	return (i);
}

//add times to move stack_a ,stack_b
//return most lowcost number
int	find_lcost_nb(t_stack *a, t_stack *b)
{
	int	curr_cost;
	int	min_cost;
	int	nb;
	int	i;

	i = 0;
	min_cost = INT_MAX;
	while (i < a->size)//change from a->size - 1
	{
		curr_cost = find_pos_b(b, a->stack[i]);
		if (i > a->size / 2)
			curr_cost += a->size - i;
		else
			curr_cost += i;
		if (min_cost > curr_cost)
		{
			min_cost = curr_cost;
			nb = a->stack[i];
		}
		i++;
	}
	return (nb);
}

//find the nunber of times to move to the correct position in the stack_b
int	find_pos_b(t_stack *stack_b, int nb)
{
	int	i;

	if (nb > stack_b->max || nb < stack_b->min)
		i = find_index(stack_b, stack_b->min);
	else
	{
		i = 0;
		while (i < stack_b->size)
		{
			if (stack_b->stack[i] > nb
				&& stack_b->stack[(i + 1) % stack_b->size] < nb)
				break ;
			i++;
		}
	}
	if (i > stack_b->size / 2)
		return (stack_b->size - i);
	else
		return (i);
}
