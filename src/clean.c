/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-s <cbrito-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 10:50:33 by cbrito-s          #+#    #+#             */
/*   Updated: 2025/03/16 23:20:39 by cbrito-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	free_map(t_game *game)
{
	int	i;

	i = 0;
	if (game->map)
	{
		while (game->map[i])
		{
			free(game->map[i]);
			i++;
		}
		free(game->map);
	}
}

void	free_images(t_game *game)
{
	if (game->mlx)
	{
		if (game->texture.wall)
			mlx_delete_image(game->mlx, game->texture.wall);
		if (game->texture.floor)
			mlx_delete_image(game->mlx, game->texture.floor);
		if (game->texture.exit)
			mlx_delete_image(game->mlx, game->texture.exit);
		if (game->texture.collectible)
			mlx_delete_image(game->mlx, game->texture.collectible);
		if (game->texture.player)
			mlx_delete_image(game->mlx, game->texture.player);
		init_images(game);
	}
}

void	free_textures(t_game *game)
{
	if (game->mlx)
	{
		if (game->texture.t_wall)
			mlx_delete_texture(game->texture.t_wall);
		if (game->texture.t_floor)
			mlx_delete_texture(game->texture.t_floor);
		if (game->texture.t_exit)
			mlx_delete_texture(game->texture.t_exit);
		if (game->texture.t_collectible)
			mlx_delete_texture(game->texture.t_collectible);
		if (game->texture.t_player)
			mlx_delete_texture(game->texture.t_player);
		init_textures(game);
	}
}

void	destroy_game(t_game *game)
{
	if (!game)
		return ;
	free_map (game);
	free_images(game);
	free_textures(game);
	if (game->mlx)
		mlx_terminate(game->mlx);
	free(game);
}
