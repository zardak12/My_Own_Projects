#include "push_swap.h"

void        ft_stack_three(t_a **stack)
{
    if((*stack)->f_a >(*stack)->next->f_a && (*stack)->f_a <(*stack)->next->next->f_a)
        c_s(stack,1);
    else if ((*stack)->f_a >(*stack)->next->f_a && (*stack)->f_a >(*stack)->next->next->f_a && (*stack)->next->f_a <(*stack)->next->next->f_a)
        c_r(stack,1);
    else if((*stack)->f_a > (*stack)->next->f_a && (*stack)->f_a >(*stack)->next->next->f_a && (*stack)->next->f_a >(*stack)->next->next->f_a)
    {
        c_s(stack,1);
        c_rr(stack,1);
    }
    else if ((*stack)->f_a < (*stack)->next->f_a && (*stack)->f_a < (*stack)->next->next->f_a && (*stack)->next->f_a > (*stack)->next->next->f_a)
    {
        c_s(stack,1);
        c_r(stack,1);
    }
    else if ((*stack)->f_a <(*stack)->next->f_a && (*stack)->f_a >(*stack)->next->next->f_a && (*stack)->next->f_a >(*stack)->next->next->f_a)
        c_rr(stack,1);
}


void        sort_other(t_p *new)
{
    int a;

    a =0;
    while(new->s_a != NULL)
    {
        a = find_min(new);
        if (a < new->count_a/2)
            rep_r(new,a);
        else
            rep_rr(&new->s_a,a);
        p_a_b(&new->s_a,&new->s_b,"pb");
        new->count_a = find_count(new->s_a);
    }
    while(new->s_b != NULL)
    {
        p_a_b(&new->s_b,&new->s_a,"pa");
    }

}

void        rep_r(t_p *new,int a)
{
    while (new->s_a->f_a != new->min)
    {
        c_r(&new->s_a,1);
    }
}

void        rep_rr(t_a  **stack,int a)
{
    while((*stack)->index != a)
    {
        c_rr(stack,1);
    }
}

