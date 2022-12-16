/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmorm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarsas <mouarsas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 21:44:23 by mouarsas          #+#    #+#             */
/*   Updated: 2022/12/15 21:45:08 by mouarsas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*pars_Map_norm_again(t_pars *stock, char *str, int *j, int *i, char **av)
{
	int	fd;

	fd = open(av[1], O_RDWR);
	if (0 > fd)
		return (printf("Error\n file discriptor"), exit(1), NULL);
	while (*i <= stock->only_map_len )
	{
		if ((str = get_next_line(fd)) == NULL)
			break;
		if (ft_strncmp(str, "\n", 1) == 0 || ft_strncmp(str, "NO", 2) == 0 || 
			ft_strncmp(str, "SO", 2) == 0 || ft_strncmp(str, "WE", 2) == 0 ||
			ft_strncmp(str, "EA", 2) == 0 || ft_strncmp(str, "C", 1) == 0 || 
			ft_strncmp(str, "F", 1) == 0 )
		{
			(*i)++;
			free(str);
			continue;
		}
		stock->only_map[*j] = str;
		(*i)++;
		(*j)++;
	}				
	stock->only_map[*j] = NULL;
	stock->height = *j;
	return (NULL);
}
