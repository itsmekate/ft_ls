/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprasol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 18:37:07 by kprasol           #+#    #+#             */
/*   Updated: 2018/02/03 18:37:09 by kprasol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_width(const char *str)
{
	int w;

	w = ft_atoi(str);
	return (w);
}

int	print_min_width(t_flag *fl, char *res, int j, int count)
{
	if (fl->precision > ft_strlen_print(res))
	{
		count = fl->precision - ft_strlen_print(res);
		ft_putzero(fl->precision - ft_strlen_print(res));
	}
	count += ft_putstr_print(res) + j;
	(fl->plus) ? j-- : 0;
	(fl->zero == 1 && fl->minus != 1) ? ft_putzero(j) : ft_putspace(j);
	free(res);
	return (count);
}

int	print_min_nw(t_flag *fl, char *res, int count)
{
	if (fl->precision > ft_strlen_print(res))
	{
		count += fl->precision - ft_strlen_print(res);
		ft_putzero(fl->precision - ft_strlen_print(res));
	}
	count += ft_putstr_print(res);
	free(res);
	return (count);
}

int	ft_print_min(t_flag *fl, char *res, int count, int minus)
{
	int j;

	if ((fl->precision == 0 && ft_strcmp(res, "0") == 0))
		j = fl->minwidth;
	else if (fl->precision > ft_strlen_print(res))
		j = fl->minwidth - fl->precision + fl->plus;
	else
		j = fl->minwidth - ft_strlen_print(res);
	(fl->plus == 1 && !minus) ? j -= write(1, "+", 1) : 0;
	(minus == 1) ? j -= write(1, "-", 1) : 0;
	if (fl->minwidth != 0 && j > 0)
		return (print_min_width(fl, res, j, count));
	else
		return (print_min_nw(fl, res, count));
}
