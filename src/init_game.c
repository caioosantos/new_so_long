/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-s <cbrito-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:02:47 by cbrito-s          #+#    #+#             */
/*   Updated: 2025/03/13 14:40:54 by cbrito-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_images(t_game *game)
{
	game->texture.wall = NULL;
	game->texture.floor = NULL;
	game->texture.exit = NULL;
	game->texture.collectible = NULL;
	game->texture.player = NULL;
}

void	init_textures(t_game *game)
{
	game->texture.t_wall = NULL;
	game->texture.t_floor = NULL;
	game->texture.t_exit = NULL;
	game->texture.t_collectible = NULL;
	game->texture.t_player = NULL;
}

void	init_game(t_game *game, const char *path)
{
	game->map = NULL;
	game->map_width = 15;
	game->map_height = 10;
	game->moves = 0;
	game->player.x = 0;
	game->player.y = 0;
	game->img = NULL;
	game->mlx = NULL;
	init_images(game);
	init_textures(game);
	read_map(game, path);
	validate_map(game, path);
}

void	read_map(t_game *game, const char *file)
{
	int		fd;
	char	*map;
	char	*line;

	fd = open(file, O_RDONLY);
	map = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		map = ft_strjoin(map, line);
		free(line);
	}
	game->map = ft_split(map, '\n');
	free(map);
	close(fd);
}
