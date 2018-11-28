#include "ft_ls.h"

void	set_flag(t_flags **f)
{
	(*f) = (t_flags*)malloc(sizeof(t_flags));
	(*f)->flag_l = 0;
    (*f)->flagR = 0;
    (*f)->flag_a = 0;
    (*f)->flag_r = 0;
    (*f)->flagT = 0;
}


void	check_flag(char a, t_flags **f)
{
	if (a == 'a')
		(*f)->flag_a = 1;
	if (a == 'r')
		(*f)->flag_r = 1;
	if (a == 'l')
		(*f)->flag_l = 1;
	if (a == 'R')
		(*f)->flagR = 1;
	if (a == 't')
		(*f)->flagT = 1;
}

t_flags	*read_flags(int argc, char **argv)
{
	int 		c;
	int			i;
	t_flags		*f;

	c = 0;
	f = NULL;
	argc > 1 ? set_flag(&f) : 0;
	while (c < argc)
	{
		if (argv[c][0] == '-')
		{
			i = 1;
			while (ft_strchr("aRrtl", argv[c][i]))
			{
				check_flag(argv[c][i], &f);
				i++;
			}
		}
		c++;
	}
	return (f);
}

void	print_flags(t_flags *f)
{
	if (f != NULL)
	{
		ft_printf("FLAGS\n");
		ft_printf("a: %d\n", f->flag_a);
		ft_printf("l: %d\n", f->flag_l);
		ft_printf("r: %d\n", f->flag_r);
		ft_printf("t: %d\n", f->flagT);
		ft_printf("R: %d\n", f->flagR);
	}
}