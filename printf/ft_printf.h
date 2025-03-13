/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-s <cbrito-s>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:50:56 by cbrito-s          #+#    #+#             */
/*   Updated: 2024/12/04 13:48:22 by cbrito-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

# define HEX "0123456789abcdef"
# define HEX_UPPER "0123456789ABCDEF"

int		ft_printchar(int c);
int		ft_printstr(char *s);
int		ft_printnbr(int n);
int		ft_printunbr(unsigned int n);
int		ft_printhex(unsigned long hex);
int		ft_printhex_lower(unsigned int hex);
int		ft_printhex_upper(unsigned int hex);
int		ft_printptr(unsigned long num);
int		ft_printf(const char *str, ...);

#endif
