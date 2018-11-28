/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexidecimal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprasol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 16:24:47 by kprasol           #+#    #+#             */
/*   Updated: 2018/03/12 18:16:05 by kprasol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_x(intmax_t i, t_flag *fl, int count)
{
	char	*res;

	res = ft_itoa_base_s(i, 16);
	if (fl->minus == 1)
		count = ft_print_hexmin(fl, res, count);
	else
		count = ft_print_hex(fl, res, count, 0);
	return (count);
}

int	ft_is_x(intmax_t i, t_flag *fl)
{
	int	count;

	count = 0;
	if (i == 0 && fl->precision != 0)
	{
		ft_putchr('0');
		return (1);
	}
	if (fl->h == 1)
		i = (unsigned short)i;
	else if (fl->h == 2)
		i = (unsigned char)i;
	else if (fl->l == 1)
		i = (unsigned long)i;
	else if (fl->l == 2)
		i = (unsigned long long)i;
	else if (fl->j == 1)
		i = (uintmax_t)i;
	else if (fl->z == 1)
		i = (size_t)i;
	else
		i = (unsigned int)i;
	count = put_x(i, fl, count);
	return (count);
}

int	put_x_big(intmax_t i, t_flag *fl, int count)
{
	char	*res;

	res = ft_itoa_base_s_big(i, 16);
	if (fl->minus == 1)
		count = ft_print_hexmin(fl, res, count);
	else
		count = ft_print_hex(fl, res, count, 1);
	return (count);
}

int	ft_is_x_big(intmax_t i, t_flag *fl)
{
	int	count;

	count = 0;
	if (i == 0 && fl->precision != 0)
	{
		ft_putchr('0');
		return (1);
	}
	if (fl->h == 1)
		i = (unsigned short)i;
	else if (fl->h == 2)
		i = (unsigned char)i;
	else if (fl->l == 1)
		i = (unsigned long)i;
	else if (fl->l == 2)
		i = (unsigned long long)i;
	else if (fl->j == 1)
		i = (uintmax_t)i;
	else if (fl->z == 1)
		i = (size_t)i;
	else
		i = (unsigned int)i;
	count = put_x_big(i, fl, count);
	return (count);
}
