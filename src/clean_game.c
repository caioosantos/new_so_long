/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-s <cbrito-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 10:50:33 by cbrito-s          #+#    #+#             */
/*   Updated: 2025/03/13 11:07:04 by cbrito-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void free_map(t_game *game)
{
    int i;

    i = 0;
    while (i < game->map_height)
    {
        free(game->map[i]);
        i++;
    }
    free(game->map);
}

void destroy_game(t_game *game)
{
    if (!game)
        return;
    free_map(game);
}