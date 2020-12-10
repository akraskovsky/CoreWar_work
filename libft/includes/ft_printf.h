/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 15:55:22 by fprovolo          #+#    #+#             */
/*   Updated: 2020/02/04 18:44:32 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

typedef	struct	s_flags
{
	char		alt_out;
	char		zero_padding;
	char		left;
	char		first_space;
	char		sign;
	size_t		min_width;
	size_t		precision;
	int			precision_set;
	char		mod_char;
	char		mod_short;
	char		mod_long;
	char		mod_long_long;
	char		mod_long_double;
	char		mod_max;
	char		mod_size_t;
	char		conversion;
	size_t		field_len;
	int			fd;
	char		*arg;
}				t_flags;

union			u_a_double
{
	long double		a;
	unsigned char	c[16];
};

int				ft_printf(const char *str, ...);
int				ft_printf_fd(int fd, const char *str, ...);
void			init_flags(t_flags *flags);
int				parse_format(char **ptr, t_flags *flags, va_list ap);
int				get_argument(t_flags *flags, va_list ap);
int				get_int(t_flags *flags, va_list ap);
int				get_unsigned(t_flags *flags, va_list ap);
int				get_string(t_flags *flags, va_list ap);
int				get_character(t_flags *flags, va_list ap);
char			*ft_strnewfill(size_t len, char c);
void			get_f_double(t_flags *flags, va_list ap);
void			get_ef_double(t_flags *flags, va_list ap);
void			get_gf_double(t_flags *flags, va_list ap);
int				ft_printf_l_double(long double i, t_flags *flags);
int				ft_printf_f_double(double i, t_flags *flags);
int				ft_printf_e_double(double i, t_flags flags);
int				ft_printf_le_double(long double i, t_flags flags);
int				ft_printf_g_double(double i, t_flags *flags);
int				ft_printf_lg_double(long double i, t_flags *flags);
char			*ft_char_from_union(int *sign, long double i);
char			*ld_char_ten(long double i, char *all, char *res, \
						t_flags *flags);
char			*ft_nan_inf(double i, t_flags flags);
int				filler_nan_helper(char *res, char *fill, t_flags d);
int				ft_nan(char *r, t_flags d, int sign, char *all);
char			*get_double_bin(union u_a_double u_double);
char			*ft_mantisa(char *all);
char			*ft_mant_exp(int exponent, char *str_man);
int				ft_exponent(char *all);
int				find_e(char *str, double num);
int				flag_f(char *res, t_flags flags, int sign);
int				flag_e_helper1(int i_width, int len, int *add);
int				flag_e(char *res, int ex, t_flags flags, int sign);
char			*width(int len, char c);
void			filler_f(char *res, char *fill, t_flags flags, int sign);
void			round_norm(char *str);
int				normalize_helper1(char *str);
void			normalize_helper2(char *str);
char			*normalize(char *str);
char			*cut_zero_before(char *mant);
void			more_rounding(char *mant, int i);
void			tryrounding(char *mant, int p);
void			rounding_all(char *mant, int precision);
char			*ft_bank_rounding(char *mant, size_t precision, int pre_set);
void			calc_div_helper(char *mant, int i);
void			calc_div_helper2(int i, char *mant, int old_temp);
char			*calc_div_by_half(char *mant);
char			*mult2_mant_expnegative(char *res, char *mant, int exponent);
char			*mult2_mant_exppositive(char *res, char *mant, int exponent);
void			ft_putnbr_e(int n);
char			*ft_straddzero(char *mant, int zeros);
char			*cut_zeros_before(char *mant);
char			*cut_z_after(char *mant);
char			*ft_cut_zero(char *res);
char			*calc_add(char *two, char *res);
void			negative2power(char *res, int power);
char			*calc_negative2power(int power);
char			*mant_bin_to_ten(char *str_mant);
char			*calc_mult2(char *res);
char			*f_dealer(int exponent, char *all, char *res, long double i);
void			without_dot(long double num, char *res);
char			*put_dot(char *res, int power);
int				find_e_helper(int i, int j, char *str);
void			filler(char *res, char *fill, t_flags flags, int *add);
int				ft_set_colors(char **ptr, t_flags *flags);
int				ft_atoi_base(const char *str, int str_base);
char			*ft_e_helper(int *sign, double i);
char			*ft_e_helper1(double i, char *res, char *all);
char			*ft_e_helper2(double i, char *res, t_flags *flags);
char			*ft_le_helper1(long double i, char *res, char *all);
int				ft_get_exp_for_e(double i);
int				ft_get_exp_for_le(long double i);
void			rounding_dot_5(char *mant, int i);
void			trim_length(t_flags *flags);

#endif
