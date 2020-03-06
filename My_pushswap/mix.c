#include "push_swap.h"

void	ft_lstadd_a(t_a **alst, t_a *new)
{
	new->next = *alst;
	*alst = new;
}

void		s_a(t_a	**stack,int count)
{
	int tmp;
	if(count < 2)
		err("Ошибка");
	tmp = (*stack)->f_a;
	(*stack)->f_a = (*stack)->next->f_a;
	(*stack)->next->f_a = tmp;
}

void		s_b(t_a	**stack,int count,t_p *new)
{
	s_a(stack,count);
	new->count_b = new->count_a;
}

void		s_s(t_a	**stack_a,t_a	**stack_b,int count,t_p *new)
{
	s_a(stack_a,count);
	s_b(stack_b,count,new);
}

void		r_a(t_a	**stack,int count)
{
	int tmp;
	t_a 	*head;

	head = (*stack);
	tmp = (*stack)->f_a;
	if(count < 2)
		err("Ошибка");
	while((*stack)->next != NULL)
	{
		(*stack)->f_a = (*stack)->next->f_a;
		(*stack)=(*stack)->next;
	}
	(*stack)->f_a = tmp;
	(*stack) = head;
}

void		r_b(t_a	**stack_b,int count,t_p *new)
{
	r_a(stack_b,count);
	new->count_b = new->count_a;
}

void		r_s(t_a	**stack_a,t_a	**stack_b,int count,t_p *new)
{
	r_a(stack_a,count);
	r_b(stack_b,count,new);
}

void		rr_a(t_a	**stack,int count)
{
	t_a	*head;
	t_a *new;
	int tmp;

	new = *stack;
	head = *stack;
	if(count < 2)
		err("Ошибка");
	while((*stack)->next != NULL)
	{
		(*stack) = (*stack)->next;
	}
	new = *stack;
	new->next = NULL;
	*stack = head;
	ft_lstadd_a(stack,new);
}
