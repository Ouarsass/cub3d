#include "main.h"

void	free_mlx(t_game *game)
{
	if (game->data.mlx)
	{
		mlx_destroy_image(game->data.mlx, game->data.img);
		mlx_clear_window(game->data.mlx, game->data.window);
		mlx_destroy_window(game->data.mlx, game->data.window);
		free_2d(game->map.my_map);
	}
}

void exit_game(t_game *game)
{
	printf("\nExit Game\n");
	free_mlx(game);
	free(game->ray);
	free(game->map.EA);
	free(game->map.WE);
	free(game->map.NO);
	free(game->map.SO);
	exit (0);
}

void display_error(char *msg)
{
	printf("%s",msg);
	exit(0);
}

int	ft_cross(t_game *game)
{
	printf("\nExit Game\n");
	free_mlx(game);
	free(game->ray);
	exit(0);
	return (0);
}

void free_check(char *str)
{
	if (str)
	{
		free(str);
		str = NULL;
	}
}