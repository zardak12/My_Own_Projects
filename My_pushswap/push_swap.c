#include "push_swap.h"


int main (int ac,char **av)
{
	t_p *stack;

	if(ac > 2) {
        stack = validator(ac, av);
        if (stack->count_a == 3)
            ft_stack_three(&stack->s_a);
		else if (stack->count_a == 5) {
			ft_stack_five(stack);
		}
        else
            sort(stack);
        free_stack(stack);
    } else
        err("Error");

//	ft_printf("%s\n","START\n");
//    print_steck(stack->s_a);
//	ft_printf("%s\n","END\n");
	return(0);
}