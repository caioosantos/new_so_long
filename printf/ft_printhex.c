/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-s <cbrito-s>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:48:57 by cbrito-s          #+#    #+#             */
/*   Updated: 2024/11/26 15:59:26 by cbrito-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhex(unsigned long hex)
{
	int	len;

	len = 0;
	if (hex >= 16)
		len += ft_printhex(hex / 16);
	len += ft_printchar(HEX[hex % 16]);
	return (len);
}

int	ft_printhex_lower(unsigned int hex)
{
	int	len;

	len = 0;
	if (hex >= 16)
		len += ft_printhex(hex / 16);
	len += ft_printchar(HEX[hex % 16]);
	return (len);
}

int	ft_printhex_upper(unsigned int hex)
{
	int	len;

	len = 0;
	if (hex >= 16)
		len += ft_printhex_upper(hex / 16);
	len += ft_printchar(HEX_UPPER[hex % 16]);
	return (len);
}
