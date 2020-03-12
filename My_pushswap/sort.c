#include "push_swap.h"

void        ft_stack_three(t_a **stack)
{
    if((*stack)->f_a >(*stack)->next->f_a && (*stack)->f_a <(*stack)->next->next->f_a)
        c_s(stack);
    else if ((*stack)->f_a >(*stack)->next->f_a && (*stack)->f_a >(*stack)->next->next->f_a && (*stack)->next->f_a <(*stack)->next->next->f_a)
        c_r(stack);
    else if((*stack)->f_a > (*stack)->next->f_a && (*stack)->f_a >(*stack)->next->next->f_a && (*stack)->next->f_a >(*stack)->next->next->f_a)
    {
        c_s(stack);
        c_rr(stack);
    }
    else if ((*stack)->f_a < (*stack)->next->f_a && (*stack)->f_a < (*stack)->next->next->f_a && (*stack)->next->f_a > (*stack)->next->next->f_a)
    {
        c_s(stack);
        c_r(stack);
    }
    else if ((*stack)->f_a <(*stack)->next->f_a && (*stack)->f_a >(*stack)->next->next->f_a && (*stack)->next->f_a >(*stack)->next->next->f_a)
        c_rr(stack);
}

void        sort_other(t_p *new)
{
    sort_by_mediana(new->mediana,&new->s_a,&new->s_b);
}

void    sort_by_mediana(int mediana,t_a **stack,t_a **stack_b)
{
    t_a *head;

    head = *stack;
    while ((*stack)->next != NULL)
        if((*stack)->f_a > mediana)
            p_a_b(stack,stack_b);
        *stack = (*stack)->next;
    *stack = head;
}
