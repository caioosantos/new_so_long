/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-s <cbrito-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 19:42:15 by cbrito-s          #+#    #+#             */
/*   Updated: 2025/03/12 22:21:45 by cbrito-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx_42/include/MLX42/MLX42.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "../libft/libft.h"
# include "../printf/ft_printf.h"

# define SIZE_WIN 64

# define MAP_EXTENSION ".ber"

# define IMG_SIZE 32

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307

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

typedef struct s_game
{
	char			**map;
	int				map_width;
	int				map_height;
	int				moves;
	t_position		player;
	t_mlx_texture	texture;
	mlx_image_t		*img;
	mlx_t			*mlx;
}	t_game;

int		handle_error(const char *msg);
void	critical_error(const char *msg, t_game *game);
void	init_game(t_game *game);

#endif
