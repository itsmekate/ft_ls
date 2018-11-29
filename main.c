/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprasol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 15:49:20 by kprasol           #+#    #+#             */
/*   Updated: 2018/11/28 15:49:21 by kprasol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	check_arg(int argc, char** argv, t_flags	*f)
{
	int i;
	int flags;
	char *curr;

	i = 1;
	flags = 0;
	curr = "./";
	while (i < argc)
	{
		if (argv[i][0] == '-')
			flags++;
		else
			print_dir(&argv[i], f);
		i++;
	}
	if (argc - 1 == flags || argc == 1)
		print_dir(&curr, f);
}

int main(int argc, char **argv)
{
	t_flags	*f;

	f = read_flags(argc, argv);
	// print_flags(f);
	check_arg(argc, argv, f);
	return (0);
}