/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarsas <mouarsas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 00:42:02 by mouarsas          #+#    #+#             */
/*   Updated: 2022/12/03 02:34:54 by mouarsas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"
#include <stdio.h>
#include <mlx.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/time.h>
#include <math.h>
#include <stdlib.h>
# include "../libft/libft.h"
#include "get_next_line/get_next_line.h"

int	check_extention(char *av)
{
	int		i;
	char	*str;

	i = ft_strlen(av);
	str = av + i - 4;
	if (!ft_strncmp(str, ".cub", 4))
		return (0);
	else
		return (1);
}

void	free_2d(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	init(t_pars *texturs)
{
	texturs->NO = NULL;
	texturs->SO = NULL;
	texturs->WE = NULL;
	texturs->EA = NULL;
	texturs->C = 0;
	texturs->F = 0;
}

void	*stock_texturs(t_pars *text, char **spl)
{
	if (!ft_strcmp(spl[0], "NO") && text->NO == NULL)
		text->NO = spl[1];
	else if (!ft_strcmp(spl[0], "NO") && text->NO)
		return (printf("Error: duplicated\n"), exit(1), NULL);
	if (!ft_strcmp(spl[0], "SO") && text->SO == NULL)
		text->SO = spl[1];
	else if (!ft_strcmp(spl[0], "SO") && text->SO)
		return (printf("Error: duplicated\n"), exit(1), NULL);
	if (!ft_strcmp(spl[0], "WE") && text->WE == NULL)
		text->WE = spl[1];
	else if (!ft_strcmp(spl[0], "WE") && text->WE)
		return (printf("Error: duplicated\n"), exit(1), NULL);
	if (!ft_strcmp(spl[0], "EA") && text->EA == NULL)
		text->EA = spl[1];
	else if (!ft_strcmp(spl[0], "EA") && text->EA)
		return (printf("Error: duplicated\n"), exit(1), NULL);
	return (NULL);
}

void	line_C_and_F(t_pars *map)
{
	char 	**my_map;
	int		i;

	i = -1;
	my_map = map->map;
	while (my_map[++i])
	{
		if (!(ft_strcmp(my_map[i], "F") && ft_strcmp(my_map[i], "C")))
		{
			puts("here");
		}
	}
}

void	*check_C_and_F(t_pars *text, char *map)
{
	char **spl;

	spl = ft_spl(map, ", \t\n\v\r");
	if (!spl)
		exit(1);
	// if (i != 4 ) {
	// 	puts("ERROR");
	// 	exit(1);
	// }
	if (spl[0] && !ft_strcmp(spl[0], "F") && !ft_strcmp(spl[0], "C"))
	{
		
	}
	line_C_and_F(text); ///////////// provisior //////
	return (NULL);
	// 10*256*256+100*256+15
}

void	*check_texture(t_pars *text, char *map)
{
	char **spl;

	spl = ft_spl(map, " \n\t\v\r");
	if (!spl)
		exit(1);
	if (spl[0] && !(ft_strcmp(spl[0], "NO") && ft_strcmp(spl[0], "SO") \
		&& ft_strcmp(spl[0], "WE") && ft_strcmp(spl[0], "EA")))
	{
		if(spl[1] && !spl[2] && !ft_strncmp((spl[1] + ft_strlen(spl[1]) - 4), ".xpm", 4))
		{
			stock_texturs(text, spl);
			// printf("in++++++++\n");
		}
		else if (spl[2])
			return (printf("Error: in map"), free_2d(spl), exit(1), NULL);
		else
			return (printf("Error: file is not extension '.xpm'"), free_2d(spl), exit(1), NULL);
	}
	check_C_and_F(text, map);
	
	return (NULL);
}


int	ft_parsing(t_pars *pars, char **av)
{
	int		fd;
	char	*line;
	int		i = 0;

	fd = open(av[1], O_RDWR);
	if(fd < 0)
		return (1);
	line = get_next_line(fd);
	while (line)
	{
		pars->len++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
	if (pars->len == 0)
		return (printf("Error\nEmpty map"), 1);
	pars->map = (char **)malloc(sizeof(char *) * pars->len + 1);
	if (!pars->map)
		return (printf("Error: map is not allocated\n"), 1);
	fd = open(av[1], O_RDWR);
	if (0 > fd)
		return (1);
	while (i < pars->len - 1)
	{
		pars->map[i] = get_next_line(fd);
		i++;
	}
	i = -1;
	init(pars);
	while (pars->map[++i])
	{
		check_texture(pars, pars->map[i]);
			// printf("%s", pars->map[i]);
			// return (1);
	}
	return(0);
}

int	main(int ac, char **av)
{
	int fd;
	t_pars pars;

	if (ac != 2)
		return (printf("Error\nCheking the arguments"), 1);
	fd = open(av[1], O_RDWR);
	if (fd < 0)
		return (printf("Error: in File Descriptor"), 1);
	close(fd);
	if (check_extention(av[1]))
		display_error("Error\nExtention");
	if (ft_parsing(&pars, av))
		return (1);
}
