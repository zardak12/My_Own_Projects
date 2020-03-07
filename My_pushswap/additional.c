#include "push_swap.h"

void	err(char *msg)
{
	ft_printf("%s\n",msg);
	exit(0);
}
void		print_steck(t_a *stack)
{
	if(stack)
	{
		ft_printf("%d\n",stack->f_a);
		print_steck(stack->next);
	}
}
