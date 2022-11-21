#include "main.h"

char	*ft_strdup(const char	*s1)
{
	char	*tab;
	size_t	i;
	size_t	length;

	length = ft_strlen(s1);
	tab = malloc(length + 1 * sizeof(char));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < length)
	{
		tab[i] = s1[i];
		++i;
	}
	tab[i] = '\0';
	return (tab);
}
