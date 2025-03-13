/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-s <cbrito-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:41:27 by cbrito-s          #+#    #+#             */
/*   Updated: 2025/03/13 14:06:48 by cbrito-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static bool is_valid_path(const char *file)
{
    const char *extension;

    if (!file)
        return (false);
    extension = ft_strchr(file, '.');
    return (extension && ft_strncmp(extension, MAP_EXTENSION, 4) == 0);
}

void validate_map(t_game *game, const char *file)
{
    // int player_count;
    // int exit_count;
    // int collectible_count;

    if (!is_valid_path(file))
        critical_error("ERROR: file has to be .ber", game);
    // player_count = count_itens(game, 'P');
    // exit_count = count_itens(game, 'E');
    // collectible_count = count_itens(game, 'C');
}