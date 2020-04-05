#include"push_swap.h"

int	ft_validation_int(const char *str)
{
	int sign;
	int num;
	int i;

	if (ft_strlen(str) == 0)
		return (0);
	i = 0;
	num = 0;
	sign = 1;
	if (str[i] == '-') {
		i++;
		sign = -sign;
	}

	while (str[i] >= '0' && str[i] <= '9' && str[i]) {
		num = num * 10 + (str[i] - '0');
		i++;
	}
	if(str[i] != '\0')
		err("Скажи,честно y тебя руки из жопы растут?Цифры братан цифры....");
	if ((num > INT_MAX) || (num <= INT_MIN))
		error("Слишком дохуя братан");
	return (sign * num);
}

t_a		*create_first_stack(t_a    **stack_a,char *b)
{
        int a;

        a = 1;
		if (!((*stack_a) = (t_a*)malloc(sizeof(t_a))))
			return NULL;
		(*stack_a)->f_a = ft_validation_int(b);
		(*stack_a)->next = NULL;
		return (*stack_a);
}

t_a		*create_stack(t_a	**stack_a,char *b,int figure)
{
	t_a		*head;
	t_a		*tmp;

	head = *stack_a;
	while((*stack_a)->next != NULL)
		*stack_a = (*stack_a)->next;
	if (!(tmp = (t_a*)malloc(sizeof(t_a))))
		return NULL;
	tmp->next = NULL;
	(*stack_a)->next = tmp;
	*stack_a = (*stack_a)->next;
	(*stack_a)->f_a = ft_validation_int(b);
	(*stack_a)->next = NULL;
	(*stack_a)= head;
	return head;
}

t_p		*validator(int a,char **b)
{
	t_p *new;
	int i;

	i = 1;
	if (a < 2)
		return NULL;
	if (!(new = (t_p*)malloc(sizeof(t_p))))
		return NULL;
	create_first_stack(&new->s_a,b[i]);
	i++;
	while (b[i])
	{

		create_stack(&new->s_a,b[i],i);
		i++;
	}
	new->count_a = i - 1;
	validation(new);
	return new;
}
