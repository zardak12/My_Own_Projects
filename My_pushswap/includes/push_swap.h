#ifndef PUSH_SWAP
#define PUSH_SWAP

#define INT_MAX 2147483647
#define INT_MIN -2147483647
#include "ft_printf.h"
#include "libft.h"
#include "get_next_line.h"

typedef struct	stack_A
{
	int f_a;
	struct stack_A *next;
}				t_a;


typedef struct	s_push_swap
{
	t_a	*s_a;
	t_a	*s_b;
	int count_a;
	int count_b;
}				t_p;

void			print_steck(t_a *stack);
t_a				*create_stack(t_a	**stack_a,char *b);
t_a				*create_first_stack(t_a		**stack_a,char *b);
t_p				*validator(int a,char **b);
int				ft_myatoi(const char *str);
void			s_a(t_a	**stack,int count);
void			s_b(t_a	**stack,int count,t_p *new);
void			r_a(t_a	**stack,int count);
void			s_s(t_a	**stack_a,t_a	**stack_b,int count,t_p *new);
void			r_b(t_a	**stack_b,int count,t_p *new);
void			r_s(t_a	**stack_a,t_a	**stack_b,int count,t_p *new);
void			err(char *msg);
void			rr_a(t_a	**stack,int count);
void			ft_lstadd_a(t_a **alst, t_a *new);
#endif
