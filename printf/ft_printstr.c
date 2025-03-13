/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-s <cbrito-s>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:06:50 by cbrito-s          #+#    #+#             */
/*   Updated: 2024/12/03 16:04:15 by cbrito-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstr(char *s)
{
	int		len;

	len = 0;
	if (!s)
		return (ft_printstr("(null)"));
	while (*s)
		len += ft_printchar(*s++);
	return (len);
}
