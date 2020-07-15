#ifndef PUSH_SWAP
#define PUSH_SWAP

#define INT_MAX "2147483647"
#define INT_MIN "-2147483647"
#include "ft_printf.h"
#include "libft.h"
#include "get_next_line.h"
#include <limits.h>

typedef struct s_count
{
    int rr;
    int rrr;
    int ra;
    int rb;
    int rra;
    int rrb;
    int sum;
}               Сount;

typedef struct	stack_A
{
	int f_a;
	int index;
	int position;
    Сount count;
	struct stack_A *next;
}				t_a;



typedef struct	s_push_swap
{
	t_a	*s_a;
	t_a	*s_b;
	int count_a;
	int count_b;
	int max;
	int min;
	int mediana;
	int rr;
	int ra;
	int rb;
	int rra;
	int rrb;
	int rrr;
}				t_p;


void			print_steck(t_a *stack);
void			err(char *msg);
t_a             *create_first_stack(t_a    **stack_a,char *b);
t_a		        *create_stack(t_a	**stack_a,char *b,int figure);
t_p				*validator(int a,char **b);
int	            ft_validation_int(const char *str);
void		    c_s(t_a	**stack,int index);
void		    c_ss(t_a	**stack_a,t_a	**stack_b,int index);
void		    c_r(t_a	**stack,int index);
void		    c_rs(t_a	**stack_a,t_a	**stack_b,int index);
void		    c_rr(t_a	**stack,int index);
void            c_rrs(t_a    **stack_a,t_a   **stack_b,int index);
void            p_a_b(t_a     **take,t_a     **put,int index);
void            ft_stack_three(t_a **stack);
t_p             *min_max_med(t_p *new);
int             *quick_sort(int *massiv,int min,int size);
void            sort_other(t_p *new);
void            sort_by_mediana(int mediana,t_a **stack,t_a **stack_b);
int             find_min(t_p    *stack);
void            rep_r(t_p *new,t_a **stack,int a,int b);
void            rep_rr(t_a  **stack,int a, int b);
void            find_repeats(int *massiv);
void            sort_stack_by_min(t_p *new);
void            new_index(t_p *new,t_a **stack);
int             find_max(t_p    *stack);
t_a             *sort_stack_a(t_p *new);
t_a             *sort_stack_b(t_p *new);
t_a             *sort_stack_by_max(t_p *new);
void            free_mem(t_p *stack);
void	        free_stack(t_p *stack);
void            exec_command(t_p *stack,char *command);
void            find_summa(t_a *stack);
void            check_b(t_p *stack);
int             find_need_value(t_p *stack,int figure);
void            count_start(t_a *stack);
int             find_position(t_a *stack,int f_a);
int             find_count(t_a *stack);
void            preparation(t_p *stack,int figure);
int             find_mediana(t_a *stack);
void            find_all_position(t_a *stack);
void            push_to_b(t_p *stack);
void            sort(t_p *stack);
int             *push_massiv(int *massiv,t_a *stack);
t_p             *validation(t_p *stack);
void            put_index(t_a **stack,int *massiv);
void            find_move_b(t_p *stack);
void            fill(t_p *stack,int i);
void            push_to_a(t_p *stack);
void            start_find(t_p *stack);
int             check_is_sorted(t_p *checker);
void 			ft_stack_five(t_p *stack);
int				check_on_order(t_a *stack);
void			check_err(char **av);
#endif
