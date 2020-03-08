#include "push_swap.h"


int main (int ac,char **av)
{
	t_p *stack;

	stack = validator(ac,av);
	//c_s(&stack->s_a);
	//c_r(&stack->s_a);
	p_a_b(&(stack->s_a),(&stack->s_b));
	p_a_b(&(stack->s_a),(&stack->s_b));
	p_a_b(&(stack->s_a),(&stack->s_b));
	p_a_b(&(stack->s_a),(&stack->s_b));
	p_a_b(&(stack->s_b),(&stack->s_a));
//	p_b(&(stack->s_a),(&stack->s_b),stack);
	print_steck(stack->s_a);
	return(0);
}
