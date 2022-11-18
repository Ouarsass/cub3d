#include "main.h"

void draw_mini_map(t_data data, int cpm1, int cmp2, int tileColor)
{
    int i;
    int j;

    i = cpm1;
    while (i < cpm1 + 40)
    {
        j = cmp2;
        while (j < cmp2 + 40)
        {
            my_mlx_pixel_put(&data, i, j, tileColor);
            j++;
        }
        i++;
    }
}

void draw_line(t_data data, t_player *player)
{
    double bx;
    double by;
    int dx;
    int dy;
    double xn;
    double yn;
    double X;
    double Y;
    int i;
    double m;

    bx = player->x + sin(player->rotationAngle) * 50;
    by = player->y + cos(player->rotationAngle) * 50;
    dx = bx - player->x;
    dy = by - player->y;

    if (abs(dx) >= abs(dy))
        m = abs(dx);
    else
        m = abs(dy);
    xn = dx / m;
    yn = dy / m;

    X = player->x;
    Y = player->y;
    i = 0;
    while (i < m)
    {
        my_mlx_pixel_put(&data, X, Y, 0x000000);
        X = X + xn;
        Y = Y + yn;
        i++;
    }
}

void draw_player(t_data data, t_player *player)
{
    int i;
    int j;
    int new_j;

    i = player->x;
    while (i < player->x + 1)
    {
        j = player->y;
        while (j < player->y + 1)
        {
            my_mlx_pixel_put(&data, i, j, 0x000000);
            j++;
        }
        i++;
    }
}