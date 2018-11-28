/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprasol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 18:37:40 by kprasol           #+#    #+#             */
/*   Updated: 2018/02/15 17:02:04 by kprasol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <wchar.h>

typedef struct		s_type
{
	int				h;
	int				l;
	int				i;
	int				z;
	int				j;
	int				minus;
	int				plus;
	int				zero;
	int				hash;
	int				space;
	int				minwidth;
	int				precision;
	int				star;
	int				starprecision;
}					t_flag;

int					g_exit;
void				ft_null_flag(t_flag *fl);
int					ft_strlen_print(char *str);
t_flag				ft_write_flags(const char *str, va_list args);
int					ft_width(const char *str);
void				ft_putchr(int c);
void				ft_putnbr_print(ssize_t n);
int					ft_putstr_print(char *str);
void				ft_putzero(int j);
void				ft_putspace(int j);
void				*ft_memset(void *b, int c, size_t len);
int					ft_num_len(long long n);
int					ft_atoi(const char *str);
const char			*ft_strincrement(const char *str, t_flag all_fl);
char				*ft_strchr(const char *s, int c);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_itoa_base_s(uintmax_t value, int base);
char				*ft_itoa_base_s_big(uintmax_t value, int base);
t_flag				ft_star(const char *tmp, va_list args, t_flag fl);
int					print_unicode(unsigned int i);
int					ft_is_s(char *str, t_flag *fl);
int					ft_is_c(intmax_t c, t_flag *fl);
int					ft_is_d(intmax_t i, t_flag *fl);
int					ft_is_o(intmax_t i, t_flag *fl);
int					ft_is_o_big(intmax_t i, t_flag *fl);
int					ft_is_d_big(intmax_t i, t_flag *fl);
int					ft_is_x(intmax_t i, t_flag *fl);
int					ft_is_x_big(intmax_t i, t_flag *fl);
int					ft_is_u(intmax_t i, t_flag *fl);
int					ft_is_u_big(intmax_t i, t_flag *fl);
int					ft_is_p(intmax_t i, t_flag *fl);
int					ft_is_c_big(unsigned int i);
int					ft_is_s_big(wchar_t *i, t_flag *fl);
int					ft_is_per(t_flag *fl);
int					ft_putuni(wchar_t *i, int count, t_flag *fl);
int					ft_printbigs(wchar_t *i, t_flag *fl);
int					ft_printbigs_min(wchar_t *i, t_flag *fl);
int					ft_print(t_flag *fl, char *res, int count, int minus);
int					ft_print_min(t_flag *fl, char *res, int count, int minus);
int					ft_print_hex(t_flag *fl, char *res, int count, int big);
int					ft_print_hexmin(t_flag *fl, char *res, int count);
int					ft_print_point(t_flag *fl, char *res, int count);
int					ft_print_octal(t_flag *fl, char *res, int count);
int					ft_print_octalmin(t_flag *fl, char *res, int count);
int					ft_other_chars(char c, int count, t_flag fl);
int					ft_unicodesize(wchar_t *i);
int					str_zero(t_flag *fl);
int					ft_printf(const char *str, ...);

#endif
