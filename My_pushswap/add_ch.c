#include "push_swap.h"
 void  exec_command(t_p *stack,char *command)
 {
    if(ft_strequ(command,"sa"))
        c_s(&stack->s_a,0);
    else if(ft_strequ(command,"sb"))
         c_s(&stack->s_b,0);
    else if(ft_strequ(command,"ss") )
         c_ss(&stack->s_a,&stack->s_b,0);
    else if(ft_strequ(command,"ra"))
         c_r(&stack->s_a,0);
    else if(ft_strequ(command,"rb"))
         c_r(&stack->s_b,0);
    else if(ft_strequ(command,"rr") )
         c_rs(&stack->s_a,&stack->s_b,0);
    else if(ft_strequ(command,"rra") )
         c_rr(&stack->s_a,0);
    else if(ft_strequ(command,"rrb") )
         c_rr(&stack->s_b,0);
    else if(ft_strequ(command,"rrr") )
         c_rrs(&stack->s_a,&stack->s_b,0);
    else if(ft_strequ(command,"pb"))
         p_a_b(&stack->s_a,&stack->s_b,0);
    else if(ft_strequ(command,"pa") )
         p_a_b(&stack->s_b,&stack->s_a,0);
    else
        err("KO");
 }

 int        check_is_sorted(t_p *checker)
 {
    t_a *head;
    int size;
    int prev;
    int i;

    head = checker->s_a;
    while(checker->s_a != NULL)
	{
    	if(checker->s_a->f_a < checker->s_a->next->f_a)
    		checker->s_a = checker->s_a->next;
    	else
    		return -1;
	}
    checker->s_a = head;
    /*head = checker->s_a->next;

    prev = checker->s_a->f_a;
    size =  find_count(checker->s_a);
    while(i < size)
    {
        if(head->f_a < prev)
            return -1;
        prev  = head->f_a;
        head = head->next;
        i++;
    }
    */
    return 1;
 }