/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-s <cbrito-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:02:47 by cbrito-s          #+#    #+#             */
/*   Updated: 2025/03/12 22:24:37 by cbrito-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_images(t_game *game)
{
	game->texture.wall =  NULL;
	game->texture.floor =  NULL;
	game->texture.exit =  NULL;
	game->texture.collectible =  NULL;
	game->texture.player =  NULL;
}

void	init_textures(t_game *game)
{
	game->texture.t_wall =  NULL;
	game->texture.t_floor =  NULL;
	game->texture.t_exit =  NULL;
	game->texture.t_collectible =  NULL;
	game->texture.t_player =  NULL;
}

void init_game(t_game *game)
{
	game->map = NULL;
	game->map_width = 0;
	game->map_height = 0;
	game->moves = 0;
	game->player.x = 0;
	game->player.y = 0;
	game->img = NULL;
	game->mlx = NULL;
	init_textures(game);
	init_images(game);
}
