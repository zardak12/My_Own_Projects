#include "push_swap.h"

void		c_s(t_a	**stack)
{
	int tmp;
	if(*stack != NULL && (*stack)->next != NULL) {
		tmp = (*stack)->f_a;
		(*stack)->f_a = (*stack)->next->f_a;
		(*stack)->next->f_a = tmp;
	}
	else
	{
		err("Ошибка");
	}
}

void		c_ss(t_a	**stack_a,t_a	**stack_b)
{
	c_s(stack_a);
	c_s(stack_b);
}

void		c_r(t_a	**stack)
{
	int tmp;
	t_a 	*head;

	if(*stack != NULL && (*stack)->next != NULL) {
		head = (*stack);
		tmp = (*stack)->f_a;
		while ((*stack)->next != NULL) {
			(*stack)->f_a = (*stack)->next->f_a;
			(*stack) = (*stack)->next;
		}
		(*stack)->f_a = tmp;
		(*stack) = head;
	}
}

void		c_rs(t_a	**stack_a,t_a	**stack_b)
{
	c_s(stack_a);
	c_s(stack_b);
}

void		c_rr(t_a	**stack) {
	t_a *head;
	t_a *new;
	int tmp;

	if (*stack != NULL && (*stack)->next != NULL) {
		head = *stack;
		while ((*stack)->next != NULL && (*stack)->next->next != NULL) {
			*stack = (*stack)->next;
		}
		(*stack)->next->next = head;
		new = (*stack)->next;
		(*stack)->next = NULL;
		*stack = new;
	}
}

void        c_rrs(t_a    **stack_a,t_a   **stack_b)
{
	c_rr(stack_a);
	c_rr(stack_b);
}

void        p_a_b(t_a     **take,t_a     **put)
{
	t_a *tmp;

	if(*put == NULL) {
//		(*put) = ft_memalloc(sizeof(t_a));
//		(*put)->f_a = (*take)->f_a;
//		(*take) = (*put)->next;
		*put = *take;
		*take = (*take)->next;
		(*put)->next = NULL;
	}
	else
	{
		tmp = *take;
		*take =(*take)->next;
		tmp->next = *put;
		*put = tmp;
	}
}