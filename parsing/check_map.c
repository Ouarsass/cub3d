
#include "main.h"
#include "libft/libft.h"

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

