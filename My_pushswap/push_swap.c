#include "push_swap.h"


int main (int ac,char **av)
{
	t_p *stack;

	stack = validator(ac,av);
	if(stack->count_a == 3)
        ft_stack_three(&stack->s_a);
    else
        sort(stack);
    free(stack);
    print_steck(stack->s_a);
	return(0);
}