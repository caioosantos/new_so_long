/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-s <cbrito-s>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:12:51 by cbrito-s          #+#    #+#             */
/*   Updated: 2025/03/17 19:09:58 by cbrito-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	handle_error(const char *msg)
{
	if (!msg)
		msg = "ERROR, Unknown error\n";
	ft_printf("%s\n", msg);
	return (0);
}

void	critical_error(const char *msg, t_game *game)
{
	if (!msg)
		msg = "ERROR, Unknown critical error\n";
	if (game->flood.map)
		free_flood_map(game);
	ft_printf("%s\n", msg);
	destroy_game(game);
	exit(EXIT_FAILURE);
}
