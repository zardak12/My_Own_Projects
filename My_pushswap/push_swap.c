#include "push_swap.h"


int main (int ac,char **av)
{
	t_p *stack;

	stack = validator(ac,av);
	rr_a(&stack->s_a,stack->count_a);
	print_steck(stack->s_a);

	return(0);
}
