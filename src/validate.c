/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-s <cbrito-s>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:41:27 by cbrito-s          #+#    #+#             */
/*   Updated: 2025/03/17 19:11:46 by cbrito-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static bool	is_valid_path(const char *file)
{
	const char	*extension;

	if (!file)
		return (false);
	extension = ft_strchr(file, '.');
	return (extension && ft_strncmp(extension, MAP_EXTENSION, 4) == 0);
}

static bool	validate_map_chars(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			if (game->map[i][j] != '0' && game->map[i][j] != '1'
				&& game->map[i][j] != 'C' && game->map[i][j] != 'E'
				&& game->map[i][j] != 'P')
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

static bool	validate_map_walls(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			if (i == 0 || i == game->map_height - 1)
			{
				if (game->map[i][j] != '1')
					return (false);
			}
			else if (j == 0 || j == game->map_width - 1)
			{
				if (game->map[i][j] != '1')
					return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}

static bool	validate_map_accessiblity(t_game *game)
{
	int	i;
	int	j;

	game->flood.width = game->map_width;
	game->flood.height = game->map_height;
	game->flood.map = (int **)ft_calloc(game->map_height, sizeof(int *));
	i = 0;
	while (i < game->map_height)
	{
		game->flood.map[i] = (int *)ft_calloc(game->map_width, sizeof(int));
		j = 0;
		while (j < game->map_width)
		{
			game->flood.map[i][j] = game->map[i][j];
			j++;
		}
		i++;
	}
	flood_fill(game, game->player.x, game->player.y);
	verify_flood(game);
	free_flood_map(game);
	return (true);
}

void	validate_map(t_game *game, const char *file)
{
	if (!is_valid_path(file))
		critical_error("ERROR: file has to be .ber", game);
	if (game->map_width == game->map_height)
		critical_error("ERROR: map is not rectangular", game);
	if (count_itens(game, 'P') != 1)
		critical_error("ERROR: player not found or more than one player", game);
	if (count_itens(game, 'E') != 1)
		critical_error("ERROR: exit not found or more than one exit", game);
	if (count_itens(game, 'C') < 1)
		critical_error("ERROR: collectibles not found", game);
	if (!validate_map_chars(game))
		critical_error("ERROR: invalid characters in map", game);
	if (!validate_map_walls(game))
		critical_error("ERROR: map is not surrounded by walls", game);
	if (!validate_map_accessiblity(game))
		critical_error("ERROR: map is not accessible", game);
}
