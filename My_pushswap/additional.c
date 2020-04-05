#include "push_swap.h"

t_p     *validation(t_p *stack)
{
    int *massiv;
    int i;

    massiv = (int*)malloc(stack->count_a * sizeof(int));
    i = 0;
    massiv = push_massiv(massiv,stack->s_a);
    find_repeats(massiv);
    massiv = quick_sort(massiv,0,stack->count_a);
    stack->min = massiv[0];
    stack->max = massiv[stack->count_a-1];
    stack->mediana = massiv[stack->count_a/2];
    put_index(&stack->s_a,massiv);
    free(massiv);
    return stack;
}


void	err(char *msg)
{
	ft_printf("%s\n",msg);
	exit(0);
}

void		print_steck(t_a *stack)
{
	while(stack != NULL)
	{
		ft_printf("%d\n",stack->f_a);
		stack = stack->next;
	}
}



void    find_repeats(int *massiv)
{
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

int    *quick_sort(int *massiv,int min,int size)
{
    int left = min;
    int pivot = min;
    int right = size - 1;
    int tmp;

    while (left < right)
    {
        if (massiv[left] <= massiv[right])
        {
            tmp = massiv[pivot];
            massiv[pivot] = massiv[left];
            massiv[left] = tmp;
            pivot ++;
            left = pivot;
        }
        left++;
    }
    if (left == right)
    {
        tmp = massiv[pivot];
        massiv[pivot] = massiv[right];
        massiv[right] = tmp;
        left = pivot;
    }
    if(left < right)
        quick_sort(massiv,left,size);
    if(left > right)
        quick_sort(massiv,0,right);
    return massiv;
}

void free_mem(t_p *stack)
{
    free_stack(stack->s_a);
    free_stack(stack->s_b);
    free(stack);
}

void	free_stack(t_a *stack)
{
    if (stack->next)
        free_stack(stack->next);
    free(stack);
}






int     *push_massiv(int *massiv,t_a *stack)
{
    t_a *head;
    int i;

    i = 0;
    head = stack;
    while(stack != NULL)
    {
        massiv[i] = stack->f_a;
        stack = stack->next;
        i++;
    }
    stack = head;
    return massiv;
}


void     put_index(t_a **stack,int *massiv)
{
    int i;
    t_a *head;

    i = 0;
    head = *stack;
    while(massiv[i])
    {
        *stack = head;
        while((*stack)->f_a != massiv[i] && stack != NULL)
        {
            (*stack) = (*stack)->next;
        }
        //if(stack->f_a == massiv[i])
        (*stack)->index = i + 1;
        i++;
    }
    *stack = head;
}

t_p     *min_max_med(t_p *new)
{
    t_a *head;
    int *massiv;
    int i;

    massiv = (int*)malloc(new->count_a * sizeof(int));
    i = 0;
    head = new->s_a;
    while(new->s_a != NULL)
    {
        massiv[i] = new->s_a->f_a;
        new->s_a = new->s_a->next;
        i++;
    }
    new->s_a = head;
    find_repeats(massiv);
    massiv = quick_sort(massiv,0,new->count_a);
    //new->max_a = massiv[new->count_a-1];
    new->mediana = massiv[new->count_a/2];
    free(massiv);
    return new;
}




















