#include "push_swap.h"

int main(int ac,char **av)
{
    t_p *checker;
    char *line;
    int c;

    if(ac > 2) {
		checker = validator(ac, av);
		while ((c = get_next_line(0, &line)) > 0) {
			exec_command(checker, line);
			free(line);
		}
		print_steck(checker->s_a);
		if (check_is_sorted(checker) == 1 && checker->s_b == NULL)
			ft_printf("%s\n", "OK");
		else
			err("KO");
		free_stack(checker);
	}
    else
		check_err(av);
    return 0;
}