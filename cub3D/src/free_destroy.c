#include "main.h"

void	free_mlx(t_data	data)
{
	if (data.mlx)
	{
		mlx_destroy_image(data.mlx, data.img);
		mlx_destroy_window(data.mlx, data.window);
		mlx_clear_window(data.mlx, data.window);
		// free(data.mlx);
		printf("Exit Game\n");
	}
}

void exit_game(t_data data)
{
	free_mlx(data);
}

void display_error(char *msg)
{
	printf("%s",msg);
	exit(EXIT_FAILURE);
}

// int	ft_cross(t_data *data)
// {
// 	free_mlx(data);
// 	return (0);
// }

void destroyWindow(void *mlx, void *window)
{
    mlx_destroy_window(mlx, window);
}