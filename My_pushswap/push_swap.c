#include "push_swap.h"


int main (int ac,char **av)
{
	t_p *stack;

	stack = validator(ac,av);
	rr_a(&stack->s_a,stack->count_a);
	p_b(&(stack->s_a),(&stack->s_b),stack);
	p_b(&(stack->s_a),(&stack->s_b),stack);
	p_b(&(stack->s_a),(&stack->s_b),stack);
	r_b(&stack->s_a,stack->count_a,stack);
	s_b(&stack->s_a,stack->count_a,stack);
	print_steck(stack->s_b);
	return(0);
}
