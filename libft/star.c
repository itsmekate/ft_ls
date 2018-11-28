/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   star.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprasol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 19:29:40 by kprasol           #+#    #+#             */
/*   Updated: 2018/03/15 19:29:42 by kprasol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	*ft_strincrement(const char *str, t_flag all_fl)
{
	if (all_fl.starprecision == 2)
		str += all_fl.starprecision;
	if (all_fl.star == 2 && all_fl.minus)
		str++;
	else if (all_fl.star == 1 && all_fl.minus == 1)
		str += 2;
	else if (all_fl.star)
		str++;
	else if (all_fl.minus)
		str += all_fl.minus;
	while ((*str >= '0' && *str <= '9')
					|| *str == ' ' || *str == '+' || *str == '.' || *str == '*')
		str++;
	return (str);
}

t_flag		ft_star(const char *tmp, va_list args, t_flag fl)
{
	if (*tmp == '*')
	{
		tmp++;
		if (*tmp >= '0' && *tmp <= '9')
		{
			va_arg(args, int);
			fl.minwidth = ft_width(tmp);
			tmp += ft_num_len(fl.minwidth);
		}
		else
		{
			fl.minwidth = va_arg(args, int);
			if (fl.minwidth < 0)
			{
				fl.minwidth = -fl.minwidth;
				if (!fl.minus)
				{
					fl.minus = 1;
					fl.star = 1;
				}
			}
			fl.star++;
		}
	}
	return (fl);
}
