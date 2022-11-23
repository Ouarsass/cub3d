#include "../main.h"

int isTherWallRight(t_game *game)
{
    if (game->player.x >= game->map.window_width - game->map.title_size \
    || game->player.y >= game->map.window_width - game->map.title_size)
        return TRUE;
    return FALSE;
}

int isTherWallLeft(t_game *game)
{
    if (game->player.x <= game->map.title_size  \
    || game->player.y <= game->map.title_size)
        return TRUE;
    return FALSE;
}

int isTherWallDown(t_game *game)
{
    if (game->player.x < game->map.title_size  \
    || game->player.y < game->map.title_size \
    || game->player.x >= game->map.window_height - game->map.title_size \
    || game->player.y >= game->map.window_height - game->map.title_size)
        return TRUE;
    return FALSE;
}

int isTherWallUp(t_game *game)
{
    if (game->player.x <= game->map.title_size  \
    || game->player.y <= game->map.title_size)
        return TRUE;
    return FALSE;
}