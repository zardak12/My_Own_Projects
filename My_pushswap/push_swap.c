#include "includes/push_swap.h"
#include <stdio.h>


int main (int ac,char **av)
{
	t_p *stack;

	stack = validator(ac,av);
	print_steck(stack->s_a);

	return(0);
}
