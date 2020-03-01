#include "includes/push_swap.h"
#include <stdio.h>
void		error()
{
	ft_printf("%s","ОШИБКА");
	exit(0);
}
void		*print_steck(t_a *stack)
{
	while (stack != NULL)
	{
		printf("%d\t",stack);
		stack= stack->next;
	}
}

t_a		*create_stack(t_a	*stack_a)
{
	if (!(stack_a = (t_a*)malloc(sizeof(t_a))))
		return NULL;
	stack_a->f_a = 0;
	stack_a->next = NULL;
	return stack_a;
}

t_p		*create_list(t_p	*new)
{
	if (!(new = (t_p*)malloc(sizeof(t_p))))
		return NULL;
	new->s_a = create_stack(new->s_a);
	return new;
}

t_p		*validator2(int a,char **b)
{
	t_p *new;
	t_p *head;
	int i;

	head = NULL;
	i = 1;
	create_list(new);
	head = new;
	if (a < 2)
		return NULL;
	while (b[i])
	{
		new->s_a->f_a = ft_atoi(b[i]);
		new->s_a->next = NULL;
		new->s_a = new->s_a->next;
		i++;
	}
	free(new);
	return head;
}

int		*validator(int a,char **b)
{
	int *massiv;
	int i;
	int j;
	int k;

	i = 1;
	k = 0;
	ft_strnew(massiv);
	while(b[i])
	{
		j = ft_atoi(b[i]);
		//if (j > INT_MAX || j <INT_MIN)
		//	error();
		massiv[k] = j;
		i++;
		k++;
	}
	return (massiv);
}


int main (int ac,char **av)
{
	t_p *stack;
	int *massiv;
	int *j;

	massiv = validator(ac,av);
	printf("%d",massiv);
	//stack= validator(ac,av);
	//print_steck(stack->s_a);

	return(0);
}