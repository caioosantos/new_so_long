/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-s <cbrito-s>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:31:39 by cbrito-s          #+#    #+#             */
/*   Updated: 2024/11/26 15:58:17 by cbrito-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printptr(unsigned long num)
{
	int	len;

	len = 0;
	if (!num)
		return (ft_printstr("(nil)"));
	len += ft_printstr("0x");
	len += ft_printhex(num);
	return (len);
}
