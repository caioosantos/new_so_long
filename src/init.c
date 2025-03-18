/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-s <cbrito-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:02:47 by cbrito-s          #+#    #+#             */
/*   Updated: 2025/03/17 22:37:05 by cbrito-s         ###   ########.fr       */
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

static void	height_width(t_game *game, const char *file)
{
	char	*line;
	int		len;

	game->file.fd = open(file, O_RDONLY);
	while (1)
	{
		line = get_next_line(game->file.fd);
		if (!line)
			break ;
		len = ft_strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			line[len - 1] = '\0';
		game->map_height++;
		if (game->map_width < (int)ft_strlen(line))
			game->map_width = ft_strlen(line);
		free(line);
	}
	close(game->file.fd);
}

static void	read_map(t_game *game, const char *file)
{
	char	*map;
	char	*line;
	char	*tmp;

	game->file.fd = open(file, O_RDONLY);
	if (!game->file.fd)
		critical_error("Failed to open file", game);
	map = ft_strdup("");
	while (1)
	{
		line = get_next_line(game->file.fd);
		if (!line)
			break ;
		tmp = map;
		map = ft_strjoin(tmp, line);
		free(tmp);
		tmp = map;
		map = ft_strjoin(tmp, "\n");
		free(tmp);
		free(line);
	}
	game->map = ft_split(map, '\n');
	free(map);
	close(game->file.fd);
}

void	init_game(t_game *game, const char *path)
{
	game->map = NULL;
	game->map_width = 0;
	game->map_height = 0;
	game->moves = 0;
	game->player.x = 0;
	game->player.y = 0;
	game->mlx = NULL;
	init_images(game);
	init_textures(game);
	height_width(game, path);
	read_map(game, path);
	find_player(game);
	validate_map(game, path);
}
