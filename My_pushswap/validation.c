#include"push_swap.h"
#include <stdio.h>

int	ft_myatoi(const char *str)
{
	int sign;
	int num;
	int i;

	if (ft_strlen(str) == 0)
		return (0);
	i = 0;
	num = 0;
	sign = 1;
	if (str[i++] == '-')
		sign = -sign;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	if (num == 0 || num > INT_MAX || num < INT_MIN)
		error("Ошибка");
	return (sign * num);
}

void		print_steck(t_a *stack)
{
	if(stack)
	{
		ft_printf("%d\n",stack->f_a);
		print_steck(stack->next);
	}
}

t_a		*create_first_stack(t_a		**stack_a,char *b)
{
		if (!((*stack_a) = (t_a*)malloc(sizeof(t_a))))
		return NULL;
		(*stack_a)->f_a = ft_atoi(b);
		(*stack_a)->next = NULL;
		return (*stack_a);
}

t_a		*create_stack(t_a	**stack_a,char *b)
{
	t_a		*head;
	t_a		*tmp;

	head = *stack_a;
	while((*stack_a)->next != NULL)
		*stack_a = (*stack_a)->next;
	if (!(tmp = (t_a*)malloc(sizeof(t_a))))
		return NULL;
	tmp->next = NULL;
	(*stack_a)->next = tmp;
	*stack_a = (*stack_a)->next;
	(*stack_a)->f_a = ft_atoi(b);
	(*stack_a)->next = NULL;
	(*stack_a) = head;
	return head;
}

t_p		*validator(int a,char **b)
{
	t_p *new;
	int i;

	i = 1;
	if (a < 2)
		return NULL;
	if (!(new = (t_p*)malloc(sizeof(t_p))))
		return NULL;
	create_first_stack(&new->s_a,b[i]);
	i++;
	while (b[i])
	{
		create_stack(&(new->s_a),b[i]);
		i++;
	}
	return new;
}
