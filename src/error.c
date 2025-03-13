/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-s <cbrito-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:12:51 by cbrito-s          #+#    #+#             */
/*   Updated: 2025/03/13 11:09:39 by cbrito-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int handle_error(const char *msg)
{
	if (!msg)
		msg = "ERROR, Unknown error\n";
	ft_printf("%s\n", msg);
	return (0);
}

void critical_error(const char *msg, t_game *game)
{
	(void)game;
	if (!msg)
		msg = "ERROR, Unknown critical error\n";
	ft_printf("%s\n", msg);
	// destroy_game(game);
	exit(EXIT_FAILURE);
}
