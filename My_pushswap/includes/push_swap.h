#ifndef PUSH_SWAP
#define PUSH_SWAP

//#define INT_MAX "2147483647"
//#define INT_MIN "-2147483647"
#include "ft_printf.h"
#include "libft.h"
#include "get_next_line.h"
#include <limits.h>

typedef struct	stack_A
{
	int f_a;
	struct stack_A *next;
}				t_a;


typedef struct	s_push_swap
{
	t_a	*s_a;
	t_a	*s_b;
}				t_p;

void			print_steck(t_a *stack);
void			err(char *msg);
t_a             *create_first_stack(t_a    **stack_a,char *b);
t_a		        *create_stack(t_a	**stack_a,char *b);
t_p				*validator(int a,char **b);
int	            ft_validation_int(const char *str);
void		    c_s(t_a	**stack);
void		    c_ss(t_a	**stack_a,t_a	**stack_b);
void		    c_r(t_a	**stack);
void		    c_rs(t_a	**stack_a,t_a	**stack_b);
void		    c_rr(t_a	**stack);
void            c_rrs(t_a    **stack_a,t_a   **stack_b);
void            p_a_b(t_a     **take,t_a     **put);
#endif
