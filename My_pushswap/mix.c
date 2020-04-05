#include "push_swap.h"

void		c_s(t_a	**stack,int index)
{
	int tmp;
	if(*stack != NULL && (*stack)->next != NULL) {
		tmp = (*stack)->f_a;
		(*stack)->f_a = (*stack)->next->f_a;
		(*stack)->next->f_a = tmp;
		if(index == 1)
		    ft_printf("%s\n","sa");
        else if(index == 2)
            ft_printf("%s\n","sb");
	}
	else
	{
		err("Ошибка");
	}
}

void		c_ss(t_a	**stack_a,t_a	**stack_b)
{
	c_s(stack_a,0);
	c_s(stack_b,0);
    ft_printf("%s\n","ss");
}

void		c_r(t_a	**stack,int index)
{
	int tmp;
	int pos;
	t_a 	*head;

	if(*stack  && (*stack)->next) {
		head = (*stack);
		/*tmp = (*stack)->f_a;
		while ((*stack)->next) {
			(*stack)->f_a = (*stack)->next->f_a;
			(*stack) = (*stack)->next;
		}
		(*stack)->f_a = tmp;
		(*stack) = head;*/
		while(head->next)
		    head = head->next;
		head->next = *stack;
		*stack = (*stack)->next;
		head = head->next;
		head->next = NULL;
        if(index == 1)
            ft_printf("%s\n","ra");
        else if(index == 2)
            ft_printf("%s\n","rb");
	}
}

void		c_rs(t_a	**stack_a,t_a	**stack_b)
{
	c_r(stack_a,0);
	c_r(stack_b,0);
	ft_printf("%s\n","rs");
}

void		c_rr(t_a	**stack,int index) {
	t_a *head;
	t_a *new;
	int tmp;
/*
	if (*stack && (*stack)->next) {
		head = *stack;
		while ((*stack)->next != NULL && (*stack)->next->next != NULL) {
			*stack = (*stack)->next;
		}
		(*stack)->next->next = head;
		new = (*stack)->next;
		(*stack)->next = NULL;
		*stack = new;
		*/
    if (*stack && (*stack)->next)
    {
        head = *stack;
        while (head->next)
        {
            new = head;
            head = head->next;
        }
        new->next = NULL;
        head->next = *stack;
        *stack = head;
    }
    if(index == 1)
        ft_printf("%s\n","rra");
    else if(index == 2)
        ft_printf("%s\n","rrb");

}


void        c_rrs(t_a    **stack_a,t_a   **stack_b)
{
	c_rr(stack_a,0);
	c_rr(stack_b,0);
	ft_printf("%s\n","rrs");
}

void        p_a_b(t_a     **take,t_a     **put,int index)
{
    t_a *tmp;

    if(*take)
    {
        tmp = *take;
        *take = (*take)->next;
        tmp->next = *put;
        *put = tmp;
    }

	if(index == 1)
        ft_printf("%s\n","pb");
	if(index == 2)
        ft_printf("%s\n","pa");
}
