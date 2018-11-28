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

int main(int argc, char **argv)
{
	// struct dirent *pDirent;
	// DIR *pDir;
	t_flags	*f;

	f = read_flags(argc, argv);
	print_flags(f);
	// pDir = opendir(argv[1]);
	// if (pDir == NULL)
	// {
	// 	ft_printf("Can't open dir\n");
	// 	return (1);
	// }
	// else
	// {
	// 	while((pDirent = readdir(pDir)) != NULL)
	// 	{
	// 		ft_printf("%s %d\n", pDirent->d_name, pDirent->d_reclen);
	// 	}
	// }
	// closedir(pDir);
	return (0);
}