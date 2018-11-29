/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_directory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprasol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 15:48:20 by kprasol           #+#    #+#             */
/*   Updated: 2018/11/29 15:48:21 by kprasol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

// void	sort_by_name(t_file  *dirs)
// {
//     int sorted;
//     t_file  *tmp;

//     sorted = 0;
//     while (1)
//     {
//         while (dirs->next->next)
//         {
//             if (ft_strcmp(dirs->pDirent->d_name, dirs->pDirent->d_name) > 1)
//                 sorted = 1;
//             else
//             {
//                 tmp = dirs->pDirent;
//                 dirs->pDirent = dirs->next->pDirent;
//                 dirs->next->pDirent = tmp;
//             }
//             dirs = dirs->next;
//         }

//     }
// }
// void	sort_by_time();

