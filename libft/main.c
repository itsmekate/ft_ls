/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprasol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 18:36:43 by kprasol           #+#    #+#             */
/*   Updated: 2018/03/12 18:12:34 by kprasol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check1(const char *str, int count, va_list args, t_flag fl)
{
	if (*str == 'U')
		count += ft_is_u_big(va_arg(args, uintmax_t), &fl);
	else if (*str == 'x')
		count += ft_is_x(va_arg(args, uintmax_t), &fl);
	else if (*str == 'X')
		count += ft_is_x_big(va_arg(args, intmax_t), &fl);
	else if (*str == 'p')
		count += ft_is_p(va_arg(args, intmax_t), &fl);
	else if (*str == 'C')
		count += ft_is_c_big(va_arg(args, unsigned int));
	else if (*str == 'D')
		count += ft_is_d_big(va_arg(args, intmax_t), &fl);
	else if (*str == 'S')
		count += ft_is_s_big(va_arg(args, wchar_t *), &fl);
	else
		count = 0;
	return (count);
}

int	ft_check2(const char *str, int count, va_list args, t_flag fl)
{
	if (*str == 's' && fl.l == 1)
		count += ft_is_s_big(va_arg(args, wchar_t *), &fl);
	else if (*str == 's')
		count += ft_is_s(va_arg(args, char *), &fl);
	else if (*str == 'c' && fl.l == 1)
		count += ft_is_c_big(va_arg(args, unsigned int));
	else if (*str == 'c')
		count += ft_is_c(va_arg(args, intmax_t), &fl);
	else if (*str == 'd' || *str == 'i')
		count += ft_is_d(va_arg(args, intmax_t), &fl);
	else if (*str == '%')
		count += ft_is_per(&fl);
	else if (*str == 'o')
		count += ft_is_o(va_arg(args, intmax_t), &fl);
	else if (*str == 'O')
		count += ft_is_o_big(va_arg(args, intmax_t), &fl);
	else if (*str == 'u')
		count += ft_is_u(va_arg(args, uintmax_t), &fl);
	else if (!ft_strchr("cCsSdDioOuUxXp%hljz", *str) && fl.minwidth != 0)
		count += ft_other_chars(*str, count, fl);
	else if (!ft_strchr("cCsSdDioOuUxXp%hljz", *str))
		count += write(1, &(*str), 1);
	else
		count = 0;
	return (count);
}

int	ft_read(va_list args, const char *str, int count)
{
	t_flag all_fl;

	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (!*str)
				return (count);
			all_fl = ft_write_flags(str, args);
			str += all_fl.j + all_fl.h + all_fl.z + all_fl.l + all_fl.hash;
			str += all_fl.plus + all_fl.space + all_fl.zero;
			str = ft_strincrement(str, all_fl);
			count = ft_check1(str, count, args, all_fl)
					+ ft_check2(str, count, args, all_fl);
			if (g_exit == -1)
				return (-1);
		}
		else
			count += write(1, &(*str), 1);
		if ((count != 0 || all_fl.precision != 0
					|| all_fl.precision != -1) && ft_strcmp(str, "") != 0)
			str++;
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, str);
	count = ft_read(args, str, count);
	va_end(args);
	return (count);
}
