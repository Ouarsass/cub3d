#include "main.h"

void setup(t_player *player, t_map map)
{
    // initialize and setup game objects
    player->x = map.window_width / 2;
    player->y = map.window_height / 2;
    player->width = 1;
    player->height = 1;
    player->turnDirection = 0;
    player->walkDirection = 0;
    player->rotationAngle = PI / 2;
    player->walkSpeed = 30;
    player->turnSpeed = 45 * (PI / 180);
}

void renderMap(t_data data, t_map map)
{
    int i;
    int j;

    const int my_map[13][20] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ,1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};


    for (i = 0; i < map.num_rows; i++)
    {
        for (j = 0; j < map.num_cols; j++)
        {
            int tileColor ;

            if (my_map[i][j] != 0)
                tileColor = 0x000000;
            else
                tileColor = 0xFFFFFF;
            draw_mini_map(data, j * map.title_size, i * map.title_size , tileColor);
        }
    }
}

void renderPlayer(t_data data, t_player *player)
{
    draw_player(data, player);
    draw_line(data, player);
}

void render(t_data data, t_player *player, t_map map)
{
    renderMap(data, map);
    renderPlayer(data, player);
    mlx_put_image_to_window(data.mlx, data.window, data.img, 0, 0);
}