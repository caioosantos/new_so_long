/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-s <cbrito-s>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:36:09 by cbrito-s          #+#    #+#             */
/*   Updated: 2025/03/17 19:07:45 by cbrito-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	flood_fill(t_game *game, int x, int y)
{
	if (x < 0 || y < 0 || x >= game->map_width || y >= game->map_height)
		return ;
	if (game->flood.map[y][x] == '1' || game->flood.map[y][x] == 'X')
		return ;
	game->flood.map[y][x] = 'X';
	flood_fill(game, x + 1, y);
	flood_fill(game, x - 1, y);
	flood_fill(game, x, y + 1);
	flood_fill(game, x, y - 1);
}

void	verify_flood(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			if (game->flood.map[i][j] == 'E' && game->flood.map[i][j] != 'X')
				critical_error("Exit is not reachable", game);
			if (game->flood.map[i][j] == 'C' && game->flood.map[i][j] != 'X')
				critical_error("Collectible is not reachable", game);
			j++;
		}
		i++;
	}
}

void	free_flood_map(t_game *game)
{
	int	i;

	if (!game || !game->flood.map)
		return;
	i = 0;
	while (i < game->flood.height)
	{
		if (game->flood.map[i])
		{
			free(game->flood.map[i]);
			game->flood.map[i] = NULL;
		}
		i++;
	}
	free(game->flood.map);
	game->flood.map = NULL;
}
