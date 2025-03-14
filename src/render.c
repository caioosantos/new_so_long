/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-s <cbrito-s>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:09:20 by cbrito-s          #+#    #+#             */
/*   Updated: 2025/03/14 18:21:17 by cbrito-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	render_texture(t_game *game, int i, int j, mlx_image_t *texture)
{
	int	x;
	int	y;

	if (!game->mlx || !texture)
	{
		ft_printf("ERROR: render_texture failed\n");
		return ;
	}
	x = j * SIZE_WIN;
	y = i * SIZE_WIN;
	mlx_image_to_window(game->mlx, texture, x, y);
}

static void	render_floor(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			render_texture(game, i, j, game->texture.floor);
			j++;
		}
		i++;
	}
}

static void	render_walls_exit_coll(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			if (game->map[i][j] == '1')
				render_texture(game, i, j, game->texture.wall);
			else if (game->map[i][j] == 'E')
				render_texture(game, i, j, game->texture.exit);
			else if (game->map[i][j] == 'C')
				render_texture(game, i, j, game->texture.collectible);
			j++;
		}
		i++;
	}
}

static void	render_player(t_game *game)
{
	mlx_t	*mlx;
	int		x;
	int		y;

	mlx = game->mlx;
	if (!mlx)
	{
		ft_printf("ERROR: render_player failed\n");
		return ;
	}
	x = game->player.x * SIZE_WIN;
	y = game->player.y * SIZE_WIN;
	mlx_image_to_window(mlx, game->texture.player, x, y);
	game->img = game->texture.player;
}

void	render_map(t_game *game)
{
	render_floor(game);
	render_walls_exit_coll(game);
	render_player(game);
}
