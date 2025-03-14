/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-s <cbrito-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 19:49:16 by cbrito-s          #+#    #+#             */
/*   Updated: 2025/03/13 21:34:32 by cbrito-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int32_t	main(int ac, char **av)
{
	t_game	*game;

	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		return (handle_error("Memory allocation failed"));
	if (ac != 2)
	{
		free(game);
		critical_error("ERROR: wrong number of arguments", NULL);
	}
	init_game(game, av[1]);
	init_mlx(game);
	load_resources(game);
	render_map(game);
	game_hooks(game);
	mlx_loop(game->mlx);
}
