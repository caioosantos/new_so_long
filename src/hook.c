/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-s <cbrito-s>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 20:51:29 by cbrito-s          #+#    #+#             */
/*   Updated: 2025/03/15 17:18:14 by cbrito-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static bool	verify_path(t_game *game, int x, int y)
{
	if (x < 0 || y < 0 || x >= game->map_width || y >= game->map_height)
		return (false);
	if (game->map[y][x] == '1')
		return (false);
	return (true);
}

static void	check_exit(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'E' && count_itens(game, 'C') == 0)
	{
		ft_printf("You win!!!\n");
		mlx_close_window(game->mlx);
	}
}

static void	verify_collectables(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'C')
	{
		game->map[y][x] = '0';
		disable_instance(game->texture.collectible, x, y);
	}
}

static void	move_player(t_game *game, int x, int y)
{
	if (verify_path(game, x, y))
	{
		if (!game->texture.player)
			critical_error("Player image not initialized", game);
		if (!game->texture.player->instances)
			critical_error("Player instances not initialized", game);
		verify_collectables(game, x, y);
		game->player.x = x;
		game->player.y = y;
		game->texture.player->instances[0].x = x * SIZE_WIN;
		game->texture.player->instances[0].y = y * SIZE_WIN;
		game->moves++;
		ft_printf("Moves: %d\n", game->moves);
		check_exit(game, x, y);
	}
}

void	key_hook(mlx_key_data_t key_args, void *param)
{
	t_game	*game;
	int		x;
	int		y;

	game = (t_game *)param;
	x = game->player.x;
	y = game->player.y;
	if (key_args.key == ESC)
		mlx_close_window(game->mlx);
	else if ((key_args.key == W || key_args.key == UP)
		&& key_args.action != 0)
		move_player(game, x, y - 1);
	else if ((key_args.key == A || key_args.key == LEFT)
		&& key_args.action != 0)
		move_player(game, x - 1, y);
	else if ((key_args.key == S || key_args.key == DOWN)
		&& key_args.action != 0)
		move_player(game, x, y + 1);
	else if ((key_args.key == D || key_args.key == RIGHT)
		&& key_args.action != 0)
		move_player(game, x + 1, y);
}
