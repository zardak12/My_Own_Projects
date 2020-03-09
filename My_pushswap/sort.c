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

void        ft_stack_five(t_a **stack_1,t_a **stack_2)
{
    find_min(stack_1,stack_2);
    find_min(stack_1,stack_2);
//    ft_stack_three(stack_1);
//    p_a_b(stack_2,stack_1);
//    p_a_b(stack_2,stack_1);
//    c_s(stack_1);
}

void        find_min(t_a    **stack1,t_a    **stack_2)
{
    t_a *min;
    t_a **tmp;

    *tmp = *stack1;
    min = *tmp;
    while(*tmp != NULL)
    {
        if((*tmp)->f_a < (min)->f_a)
            min = *tmp;
        *tmp = (*tmp)->next;
    }
    p_a_b(tmp,stack_2);
}