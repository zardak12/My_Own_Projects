#include "push_swap.h"
void		s_a(t_a	**stack)
{
	int tmp;

		tmp = (*stack)->f_a;
		(*stack)->f_a = (*stack)->next->f_a;
		(*stack)->next->f_a = tmp;
}


