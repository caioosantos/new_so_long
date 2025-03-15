/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-s <cbrito-s>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 13:35:20 by cbrito-s          #+#    #+#             */
/*   Updated: 2025/03/15 17:17:28 by cbrito-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	count_itens(t_game *game, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			if (game->map[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	find_player(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			if (game->map[i][j] == 'P')
			{
				game->player.x = j;
				game->player.y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	disable_instance(mlx_image_t *image, int x, int y)
{
	size_t	i;
	int		t_x;
	int		t_y;

	i = 0;
	t_x = x * SIZE_WIN;
	t_y = y * SIZE_WIN;
	while (i <= image->count)
	{
		if (image->instances[i].x == t_x && image->instances[i].y == t_y)
		{
			image->instances[i].enabled = false;
			break ;
		}
		i++;
	}
}
