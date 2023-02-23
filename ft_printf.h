/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnurlybe <mnurlybe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 20:42:23 by mnurlybe          #+#    #+#             */
/*   Updated: 2023/02/23 21:22:05 by mnurlybe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

# ifndef FLAGS
   typedef struct flags
   {
		int		is_negative;
		int		is_dash;
		int		is_zero;
		int		is_dot;
		int		is_hash;
		int		is_space;
		int		is_plus;
		int		width;
		int		pr_width;
		int		is_null_term;
   }	FLAGS;
# endif

# ifndef SPECIFIERS
   typedef struct specifiers
   {
		int		d;
		int		i;
		int		u;
		int		x;
		int		X;
		int		c;
		int		s;
		int		p;
		int		percent;
   }	SPECIFIERS;
# endif

void	ft_init(FLAGS *flags, SPECIFIERS *sp);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strchr(const char *s, int c);
int		ft_isdigit(int c);
int		ft_putstr(char *str);
size_t	ft_find_nod(unsigned int num, int system);
size_t	ft_find_nod_l(unsigned long long num, int system);
char	*ft_number_to_str(unsigned int num, char letter, int system);
char	*ft_number_to_str_l(long long unsigned num, char letter, int system);
char	*ft_get_base(char letter);
char	*ft_reverse_str(char *str_num, int i);
unsigned int	ft_make_number_positive(int num, FLAGS *flags, char letter);
int		ft_printf(const char *str, ...);
int		ft_c_s_p(char *str, FLAGS *flags, SPECIFIERS *sp);
int		ft_d_i_u(char *str, FLAGS *flags, SPECIFIERS *sp);
int		ft_hex(char *str, FLAGS *flags, SPECIFIERS *sp);
int		ft_putstr_utils(char *str, int j);
int		ft_putspace(int j);
int		ft_putzero(int j);
int		ft_putsigns(FLAGS *flags, SPECIFIERS *sp);
char	*ft_number_to_str_l(long long unsigned num, char letter, int system);
void	ft_switch_for_flags(char c, FLAGS *flags);
void	ft_switch_for_sp(char c, SPECIFIERS *sp);
void	ft_add_to_number(char c, int *prev_number);
void	ft_fill_pr_width(char c, FLAGS *flags);
void	ft_fill_width(char c, FLAGS *flags);
char	*ft_fill_flags(char *str, FLAGS *flags);
int		ft_printchar(char c);
int		ft_printstr(char *str);
int		ft_format(va_list args, SPECIFIERS sp, FLAGS flags);


#endif