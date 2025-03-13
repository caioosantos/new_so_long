/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-s <cbrito-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:04:14 by cbrito-s          #+#    #+#             */
/*   Updated: 2025/03/13 15:04:27 by cbrito-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void init_mlx(t_game *game)
{
    int map_width;
    int map_height;

    map_width = game->map_width * SIZE_WIN;
    map_height = game->map_height * SIZE_WIN;
    game->mlx = mlx_init(map_width, map_height, "so_long", false);
    if (!game->mlx)
        critical_error("ERROR: mlx_init failed", game);
}