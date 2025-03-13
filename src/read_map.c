/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-s <cbrito-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 22:30:39 by cbrito-s          #+#    #+#             */
/*   Updated: 2025/03/12 22:36:29 by cbrito-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	read_map(t_game *game, char *file)
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
			break ;
		map = ft_strjoin(map, line);
		map = ft_strjoin(map, "\n");
		free(line);
	}
	game->map = ft_split(map, '\n');
	free(map);
	close(fd);
}
