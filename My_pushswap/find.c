#include "push_swap.h"

void    find_repeats(int *massiv)
{
	//можно сюда добавить на нужность нам этого
    t_a *head;
    int i;
    int j;

    i = 0;
    j = 1;
    while(massiv[i])
    {
        while(massiv[j])
        {
            if(massiv[i] == massiv[j])
                err("Error");
            j++;
        }
        i++;
    }
}

int     find_count(t_a *stack)
{
    t_a *head;
    int i;

    i = 0;
    head = stack;
    while(stack != NULL)
    {
        stack = stack->next;
        i++;
    }
    stack = head;
    return i;
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