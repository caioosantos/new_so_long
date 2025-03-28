/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-s <cbrito-s>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 19:42:15 by cbrito-s          #+#    #+#             */
/*   Updated: 2025/03/18 14:01:19 by cbrito-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "../lib/libft/libft.h"
# include "../lib/printf/ft_printf.h"

# define SIZE_WIN 64
# define MAP_EXTENSION ".ber"

# define W MLX_KEY_W
# define A MLX_KEY_A
# define S MLX_KEY_S
# define D MLX_KEY_D
# define UP MLX_KEY_UP
# define DOWN MLX_KEY_DOWN
# define LEFT MLX_KEY_LEFT
# define RIGHT MLX_KEY_RIGHT
# define ESC MLX_KEY_ESCAPE

typedef struct s_file
{
	int	fd;
}	t_file;

typedef struct s_mlx_texture
{
	mlx_image_t		*wall;
	mlx_image_t		*floor;
	mlx_image_t		*exit;
	mlx_image_t		*collectible;
	mlx_image_t		*player;
	mlx_texture_t	*t_wall;
	mlx_texture_t	*t_floor;
	mlx_texture_t	*t_exit;
	mlx_texture_t	*t_collectible;
	mlx_texture_t	*t_player;
}	t_mlx_texture;

typedef struct s_position
{
	int	x;
	int	y;
}	t_position;

typedef struct s_flood
{
	int		**map;
	int		width;
	int		height;
}	t_flood;

typedef struct s_game
{
	char			**map;
	int				map_width;
	int				map_height;
	int				moves;
	t_position		player;
	t_mlx_texture	texture;
	mlx_t			*mlx;
	t_file			file;
	t_flood			flood;
}	t_game;

// erro
int		handle_error(const char *msg);
void	critical_error(const char *msg, t_game *game);

// clean
void	destroy_game(t_game *game);
void	free_images(t_game *game);
void	free_textures(t_game *game);

// init
void	init_game(t_game *game, const char *path);
void	init_images(t_game *game);
void	init_textures(t_game *game);

// validate
void	validate_map(t_game *game, const char *file);

// utils
void	find_player(t_game *game);
int		count_itens(t_game *game, char c);
void	disable_instance(mlx_image_t *image, int x, int y);

// mlx
void	init_mlx(t_game *game);

// load
void	load_resources(t_game *game);

// render
void	render_map(t_game *game);

// hook
void	key_hook(mlx_key_data_t key_args, void *param);

// flood
void	flood_fill(t_game *game, int x, int y);
void	verify_flood(t_game *game);
void	free_flood_map(t_game *game);

#endif
