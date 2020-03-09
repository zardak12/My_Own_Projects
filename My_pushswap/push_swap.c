#include "push_swap.h"


int main (int ac,char **av)
{
	t_p *stack;

	stack = validator(ac,av);
	ft_stack_five(&stack->s_a,&stack->s_b);
	print_steck(stack->s_a);
	return(0);
}
