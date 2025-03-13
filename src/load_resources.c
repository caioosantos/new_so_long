/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_resources.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-s <cbrito-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:13:16 by cbrito-s          #+#    #+#             */
/*   Updated: 2025/03/13 15:37:45 by cbrito-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void    load_images(t_game *game)
{
    game->texture.wall = mlx_texture_to_image(game->mlx, game->texture.t_wall);
    game->texture.floor = mlx_texture_to_image(game->mlx, game->texture.t_floor);
    game->texture.exit = mlx_texture_to_image(game->mlx, game->texture.t_exit);
    game->texture.collectible = mlx_texture_to_image(game->mlx, game->texture.t_collectible);
    game->texture.player = mlx_texture_to_image(game->mlx, game->texture.t_player);
    if (!game->texture.wall || !game->texture.floor || !game->texture.exit || !game->texture.collectible || !game->texture.player)
        critical_error("ERROR: failed to create images", game);
}

void    load_textures(t_game *game)
{
    game->texture.t_wall = mlx_load_png("./textures/wall.png");
    game->texture.t_floor = mlx_load_png("./textures/floor.png");
    game->texture.t_exit = mlx_load_png("./textures/exit.png");
    game->texture.t_collectible = mlx_load_png("./textures/coll.png");
    game->texture.t_player = mlx_load_png("./textures/player.png");
    if (!game->texture.t_wall || !game->texture.t_floor || !game->texture.t_exit || !game->texture.t_collectible || !game->texture.t_player)
        critical_error("ERROR: failed to load textures", game);
}

void    load_resources(t_game *game)
{
    load_textures(game);
    load_images(game); 
}