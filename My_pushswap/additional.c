#include "push_swap.h"

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
/*
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
    massiv = quick_sort(massiv,0,new->count_a);
    new->min = massiv[0];
    new->max = massiv[new->count_a-1];
    new->mediana = massiv[new->count_a/2];
    i = 0;
    //ВРЕМЕННО
    while(i < (new->count_a)) {
        ft_printf("%d\t", massiv[i]);
        i++;
    }
    ft_printf("\nmin -%d\n",new->min);
    ft_printf("max -%d\n",new->max);
    ft_printf("mediana -%d\n",new->mediana);
    free(massiv);
    return new;
}*/

int     find_min(t_p    *stack)
{
    t_a *head;

    head = stack->s_a;
    stack->min = stack->s_a->f_a;
    stack->min_index = stack->s_a->index;
    stack->s_a = stack->s_a->next;
    while(stack->s_a != NULL)
    {
        if(stack->s_a->f_a < stack->min) {
            stack->min = stack->s_a->f_a;
            stack->min_index = stack->s_a->index;
        }
        stack->s_a = stack->s_a->next;
    }
    stack->s_a = head;
    return (stack->min_index);
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