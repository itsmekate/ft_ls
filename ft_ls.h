/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprasol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 17:03:16 by kprasol           #+#    #+#             */
/*   Updated: 2018/11/28 17:03:19 by kprasol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
#define FT_LS_H

# include <dirent.h>
# include "libft/ft_printf.h"

typedef struct	s_flags
{
    int         flag_l;
    int         flagR;
    int         flag_a;
    int         flag_r;
    int         flagT;
}               t_flags;

/*
** flags.c
*/

void	        set_flag(t_flags **f);
void	        check_flag(char a, t_flags **f);
t_flags	        *read_flags(int argc, char **argv);
void            print_flags(t_flags *f);

#endif