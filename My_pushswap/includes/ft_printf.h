/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaxime <dmaxime@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 19:50:05 by dmaxime           #+#    #+#             */
/*   Updated: 2020/02/14 17:47:50 by dmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <limits.h>
# include "libft.h"

typedef struct		s_flags
{
	int	minus;
	int	plus;
	int	space;
	int	oktorop;
	int	zero;
}					t_flag;
typedef struct		s_modificator
{
	int hh;
	int ll;
	int h;
	int l;
	int big_l;
}					t_modif;
typedef struct		s_conversion
{
	t_flag	*flag;
	t_modif	*modif;
	char	*start;
	char	sign;
	int		width;
	int		precision_set;
	int		precision;
	char	type;
}					t_conversion;
int					ft_printf(const char *format, ...);
char				*print_conv(char *str, va_list ap);
char				*parse_conv(char *str, t_conversion *conv);
void				free_conv(t_conversion *conv);
t_conversion		*init_conv(char *str);
int					get_result(int size, int to_add);
int					print_mem(void *mem, int size);
void				print_str(char *str);
void				print_char(t_conversion *conv, char c);
void				print_string(t_conversion *conv, char *str);
void				print_blank(int len, int min, char c);
intmax_t			signed_conv(t_conversion *conv, va_list ap);
uintmax_t			unsigned_conv(t_conversion *conv, va_list ap);
uintmax_t			count_digit(uintmax_t n);
void				print_unsigned(t_conversion *conv, uintmax_t num);
void				print_octal(t_conversion *conv, uintmax_t num);
void				print_hexadecimal(t_conversion *conv, uintmax_t num);
void				print_hexadecimal_big(t_conversion *conv, uintmax_t num);
void				print_num_blank(t_conversion *conv, char *str);
void				print_long_float(long double num, t_conversion *conv);
void				error(char *msg);
void				print_procent(t_conversion *conv, char c);
void				print_float(va_list ap, t_conversion *conv);
int					check_format(char *format);
char				*parse_modificator(char *str, t_modif *modif);
char				*parse_precision(char *str, t_conversion *conv);
char				*parse_width(char *str, t_conversion *conv);
char				*parse_flags(char *str, t_flag *flag);
char				*replaced(char *str, int pos, int t);
int					big_chk(long double num, t_conversion *conv);
void				sign_chk(t_conversion **conv);
char				*ft_ltoa(long long n);
#endif
