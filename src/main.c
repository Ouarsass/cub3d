#include "../main.h"

int row_length(char **table)
{
    int i;

    i = 0;
    while(table[i])
        i++;
    return (i);
}

// void verif_map(t_map *map)
// {
//     int i;
//     int j;

//     i = 0;
//     while (i < map->num_rows)
//     {
//         j = 0;
//         while (j < map->num_cols)
//         {
//             if (map->my_map[i][j] == '1')
//                 map->wall++;
//             else if (map->my_map[i][j] == 'P')
//                 map->player++;
//         }
//     }
// }

void takeSize(char **table , t_map *map)
{
    int i;

    i = 0;
    map->num_rows = row_length(table);
    if (map->num_rows == 0)
        display_error("free Map");
    map->num_cols = ft_strlen(table[0]);
    while (i < map->num_rows)
    {
        if (ft_strlen(table[i]) != map->num_cols)
            display_error("Error in Size Map");
        i++;
    }
    map->title_size = 60;
    map->window_height = map->num_rows * map->title_size; // 780
    map->window_width = map->num_cols * map->title_size; // 1200
}

void fillMap(char *line, int *buff, t_map *map)
{
    int i;

    i = 0;
    while (line[i] && i < map->num_cols)
    {
        if (line[i] == '0')
            buff[i] = 0;
        else if (line[i] == '1')
            buff[i] = 1;
        else if (line[i] == 'P')
            buff[i] = 2;
        else if (line [i] == ' ')
            buff[i] = -1;
        else
            display_error("Parsing Error\n");
        i++;
    }
}

void    setup_map(t_map *map, char *table)
{
    char **str;
    int **map_tab;
    int i;
    int j;

    str = ft_split(table, '\n');
    if (!str)
        display_error("Error in Map");
    takeSize(str, map);
    map_tab = (int **)malloc((map->num_rows) * sizeof(int *));
    if (!map_tab)
        display_error("Map Allocation error\n");
    map_tab[map->num_rows] = NULL;
    i = 0;
    while (i < map->num_rows)
    {
        map_tab[i] = (int *) malloc((map->num_cols) * sizeof(int));
        if (!map_tab[i])
            display_error("Map allocation error\n");
        fillMap(str[i], map_tab[i], map);
        i++;
    }
    map->my_map = map_tab;
    // free(map_tab);
    // free(str);
}

int	direction(int keyboard, t_game *game)
{
	if (keyboard == 53)
		exit_game(game->data);
	if (keyboard == 0)
        move_left(game);
	else if (keyboard == 2)
        move_right(game);
	else if (keyboard == 13)
        move_up(game);
	else if (keyboard == 1)
        move_down(game);
    else if (keyboard == 123)
        move_rotation_left(game);
    else if (keyboard == 124)
        move_rotation_right(game);
	return (0);
}

void update (t_player *player, t_data data, t_game *game)
{
    mlx_hook(game->data.window, 17, 0L, &ft_cross, game);
    mlx_hook(game->data.window, 2, 1L << 0, direction, game);
}

int main(int argc, char **av)
{
    int         fd;
    t_data      mlx;
    t_player    player;
    t_game      game;
    t_map       map;
    char        *table;
	t_pars		pars;

    table = read_file(fd);
    if (!table)
        display_error("Error in read File\n");
    setup_map(&map, table);
    CreateWindow(&mlx, map);
    setup(&player, map);

    render(mlx, &player, map);
    game.data = mlx;
    game.map = map;
    game.player = player;
    update(&game.player, mlx, &game);
    mlx_loop(game.data.mlx);
    return (0);
}
