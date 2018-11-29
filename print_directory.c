/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_directory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprasol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 15:47:27 by kprasol           #+#    #+#             */
/*   Updated: 2018/11/29 15:47:28 by kprasol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void    read_dirs(DIR *pDir, t_file  **dirs)
{
    t_file  *tmp = *dirs;
    if (pDir == NULL)
	{
		ft_printf("Can't open directory\n");
		return ;
	}
    else
    {
        if ((tmp->pDirent = readdir(pDir)) != NULL)
        {
            tmp->next = (t_file*)malloc(sizeof(t_file));
            tmp = tmp->next;
        }
        while((tmp->pDirent = readdir(pDir)) != NULL)
	    { 
            tmp->next = (t_file*)malloc(sizeof(t_file));
            tmp = tmp->next;
	    }
        free(tmp);
        tmp = NULL;
    }
}

void	print_usual(t_flags	*f, t_file  *dirs)
{
    t_file  *tmp = dirs;

	while(tmp->next)
	{
		if (tmp->pDirent->d_name[0] == '.' && f && f->flag_a == 1)
			ft_printf("%s  ", tmp->pDirent->d_name);
		else if (tmp->pDirent->d_name[0] != '.')
			ft_printf("%s  ", tmp->pDirent->d_name);
        tmp = tmp->next;
	}
}

void	print_long(t_flags	*f, t_file  *dirs)
{
	t_file  *tmp = dirs;

	while(tmp->next)
	{
		if (tmp->pDirent->d_name[0] == '.' && f && f->flag_a == 1)
			ft_printf("%s  %d\n", tmp->pDirent->d_name, tmp->pDirent->d_reclen);
		else if (tmp->pDirent->d_name[0] != '.')
			ft_printf("%s  %d\n", tmp->pDirent->d_name, tmp->pDirent->d_reclen);
        tmp = tmp->next;
	}
}

void	print_dir(char **dir, t_flags	*f)
{
	DIR *pDir;
    t_file  *dirs;
    dirs = (t_file*)malloc(sizeof(t_file));

	pDir = opendir(*dir);
    read_dirs(pDir, &dirs);
    // sort_by_name(dirs);
	if (f && f->flag_l)
		print_long(f, dirs);
	else
    {
        print_usual(f, dirs);
	    ft_printf("\n");
    }
	closedir(pDir);
}
