#include "push_swap.h"

void	err(char *msg)
{
	ft_printf("%s\n",msg);
	exit(0);
}

//void		print_steck(t_a *stack)
//{
//	if(stack)
//	{
//		ft_printf("%d\n",stack->f_a);
//		print_steck(stack->next);
//	}
//}

void		print_steck(t_a *stack)
{
	while(stack != NULL)
	{
		ft_printf("%d\n",stack->f_a);
		stack = stack->next;
	}
}

//должны создать массив отсрортировать его найти в в нем миниальное максимальное и медиану и вернуть это в структуре new
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
    new->mediana = (massiv[new->count_a/2] + massiv[new->count_a/2 -1])/2;
    i = 0;
    while(i < (new->count_a)) {
        ft_printf("%d\t", massiv[i]);
        i++;
    }
    ft_printf("\nmin -%d\n",new->min);
    ft_printf("max -%d\n",new->max);
    ft_printf("mediana -%d\n",new->mediana);
    free(massiv);
    return new;
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