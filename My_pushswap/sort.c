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

void        sort(t_p *stack)
{
    int i;
    int k;

    push_to_b(stack);
    if(stack->s_a->f_a == stack->min)
        c_s(&stack->s_a,1);
    p_a_b(&stack->s_b,&stack->s_a,2);
    while(stack->s_b)
    {
        check_b(stack);
        find_summa(stack->s_b);
        find_move_b(stack);
        push_to_a(stack);
        p_a_b(&stack->s_b,&stack->s_a,2);
    }
    while(stack->s_a->f_a != stack->min){
        c_r(&stack->s_a, 1);
    }
}



void    push_to_b(t_p *stack)
{
    int i;
    int b;
    t_a *head;

    i = stack->count_a / 2;
    b = 0;
    while(i - 1)
    {
        if(stack->s_a->f_a == stack->max)
            c_r(&stack->s_a,1);
        if(stack->s_a->f_a >= stack->mediana)
        {
            p_a_b(&stack->s_a,&stack->s_b,1);
            i--;
            b++;
        } else
            c_r(&stack->s_a,1);
    }
    i = stack->count_a - b;
    while(i > 2) {
        if(stack->s_a->f_a == stack->max || stack->s_a->f_a == stack->min)
            c_r(&stack->s_a,1);
        else {
            p_a_b(&stack->s_a, &stack->s_b, 1);
            i--;
        }
    }
}

void        push_to_a(t_p *stack)
{
   while(stack->rr != 0 || stack->rrr != 0)
   {
       if(stack->rr != 0)
       {
           stack->rr--;
           c_rs(&stack->s_a,&stack->s_b);
       }
       if(stack->rrr != 0)
       {
           stack->rrr--;
           c_rrs(&stack->s_a,&stack->s_b);
       }
   }
   while(stack->ra) {
       stack->ra--;
       c_r(&stack->s_a,1);
   }
    while(stack->rb) {
        stack->rb--;
        c_r(&stack->s_b,2);
    }
    while(stack->rra) {
        stack->rra--;
        c_rr(&stack->s_a,1);
    }
    while(stack->rrb) {
        stack->rrb--;
        c_rr(&stack->s_b,2);
    }
}


void     find_move_b(t_p *stack) {
    t_a *head;
    int i;

    i = stack->s_b->count.sum;
    if (stack->s_b != NULL)
    {
        head = stack->s_b;
        while (stack->s_b != NULL) {
            if (stack->s_b->count.sum < i)
                i = stack->s_b->count.sum;
            stack->s_b = stack->s_b->next;
        }
        stack->s_b = head;
        fill(stack, i);
    }
}

void    fill(t_p *stack,int i)
{
    t_a *head;

    head = stack->s_b;
    while(stack->s_b->count.sum != i)
        stack->s_b = stack->s_b->next;
    stack->rr = stack->s_b->count.rr;
    stack->rb = stack->s_b->count.rb;
    stack->ra = stack->s_b->count.ra;
    stack->rrb = stack->s_b->count.rrb;
    stack->rra = stack->s_b->count.rra;
    stack->rrr = stack->s_b->count.rrr;
    stack->s_b = head;
}

void    start_find(t_p *stack)
{
    stack->rr =  0;
    stack->rb =  0;
    stack->ra =  0;
    stack->rrb = 0;
    stack->rra = 0;
    stack->rrr = 0;
}

void     find_summa(t_a *stack)
{
    t_a *head;

    head = stack;
    while(stack) {
        while (stack->count.rb && stack->count.ra) {
            stack->count.rb--;
            stack->count.ra--;
            stack->count.rr++;
        }
        while (stack->count.rrb && stack->count.rra) {
            stack->count.rrb--;
            stack->count.rra--;
            stack->count.rrr++;
        }
        stack->count.sum = stack->count.rb + stack->count.ra + stack->count.rrb + stack->count.rra + stack->count.rrr +
                           stack->count.rr;
        stack = stack->next;
    }
    stack = head;
}
void     check_b(t_p *stack)
{
    t_a *head;
    int mediana;
    int i;

    i = 1;
    head = stack->s_b;
    stack->count_b = find_count(stack->s_b);
    mediana = stack->count_b/2;
    find_all_position(stack->s_b);
    while(stack->s_b != NULL)
    {
        count_start(stack->s_b);
        if(stack->s_b->position < mediana || stack->count_b <= 3)
            stack->s_b->count.rb = stack->s_b->position;
        else
        {
            stack->s_b->count.rrb = stack->count_b - mediana - i;
            i++;
        }
        preparation(stack,stack->s_b->f_a);
        stack->s_b = stack->s_b->next;
    }
    stack->s_b = head;
}


void     preparation(t_p *stack,int figure)
{
    int i;
    int position;
    int mediana;
    t_a *head;

    i = 0;
    head = stack->s_a;
    stack->count_a = find_count(stack->s_a);
    find_all_position(stack->s_a);
    mediana = stack->count_a/2;
    position  = find_need_value(stack,figure);
    while(stack->s_a->f_a != position)
        stack->s_a = stack->s_a->next;
    if(stack->s_a->position <= mediana)
        stack->s_b->count.ra = stack->s_a->position;
    else
    {
        stack->s_b->count.rra = stack->count_a - stack->s_a->position;
        i++;
    }
    stack->s_a = head;
}

int    find_need_value(t_p *stack,int figure)
{
    t_a *head;
    int i;
    int b;

    i = 0;
    head = stack->s_a;
    while(stack->s_a !=  NULL)
    {
        if(stack->s_a->f_a > figure)
        {
            if(i == 0)
                i = stack->s_a->f_a;
            if(stack->s_a->f_a < i && i != 0)
                i = stack->s_a->f_a;
        }
        stack->s_a = stack->s_a->next;
    }
    stack->s_a = head;
    return i;
}

void    count_start(t_a *stack)
{
    stack->count.ra = 0;
    stack->count.rb = 0;
    stack->count.rr = 0;
    stack->count.rra = 0;
    stack->count.rrb = 0;
    stack->count.rrr = 0;
    stack->count.sum = 0;
}

int    find_mediana(t_a *stack)
{
    int i;

    i = find_count(stack);
   return (i/2);
}

int        find_position(t_a *stack,int f_a)
{
    t_a *head;
    int i;

    i = 0;
    head = stack;
    while(stack->index != f_a)
    {
        i++;
        stack = stack->next;
    }
    stack = head;
    return i;
}

void        find_all_position(t_a *stack)
{
    t_a *head;
    int i;

    i = 0;
    head = stack;
    while(stack != NULL)
    {
        stack->position = i;
        i++;
        stack = stack->next;
    }
    stack = head;
}



void        rep_r(t_p *new,t_a **stack,int a,int b)
{
    while ((*stack)->f_a != b)
    {
        c_r(stack,a);
    }
}

void        rep_rr(t_a  **stack,int a,int b)
{
    while ((*stack)->f_a != b)
    {
        c_rr(stack,a);
    }
}
