
#include "../main.h"
#include "../libft/libft.h"


int	check_extention(char *av)
{
	int		i;
	char	*str;

	i = ft_strlen(av);
	str = av + i - 4;
	if (!ft_strncmp(str, ".cub", 4))
		return (1);
	else
		return (0);
}

int	ft_parsing(t_pars *pars, char **av)
{
	int	fd;
	char *line;

	fd = open(av[1], O_RDONLY);
	if(fd < 0)
		return (1);
	line = get_next_line(fd);
	while (line)
	{
		pars->len++;
		free(line);
		line = get_next_line(fd);


	}
	return(0);
}