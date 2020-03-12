#include "push_swap.h"


int main (int ac,char **av)
{
	t_p *stack;

	stack = validator(ac,av);
    sort_other(stack);

    print_steck(stack->s_b);
	return(0);
}
