#include"includes/push_swap.h"
#include <stdio.h>

void		error()
{
	ft_printf("%s","ОШИБКА");
	exit(0);
}

void		print_steck(t_a *stack)
{
	while (stack ->next != NULL)
	{
		ft_printf("%d\t",stack->f_a);
		stack = stack->next;
	}
}

t_a		*create_first_stack(t_a		*stack_a,char *b)
{
		if (!(stack_a = (t_a*)malloc(sizeof(t_a))))
		return NULL;
		stack_a->f_a = ft_atoi(b);
		stack_a->next = NULL;
		return (stack_a);
}

t_a		*create_stack(t_a	*stack_a,char *b)
{
	t_a		*head;
	t_a		*tmp;

	head = stack_a;
	while(stack_a->next != NULL)
		stack_a = stack_a->next;
	if (!(tmp = (t_a*)malloc(sizeof(t_a))))
		return NULL;
	stack_a->next = tmp;
	stack_a = stack_a->next;
	stack_a->f_a = ft_atoi(b);
	stack_a->next = NULL;
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
	create_first_stack(new->s_a,b[i]);
	i++;
	while (b[i])
	{
		create_stack(new->s_a,b[i]);
		i++;
	}
	return new;
}
