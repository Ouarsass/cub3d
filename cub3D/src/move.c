#include "main.h"

int isTherWall(float x, float y, t_game *game)
{
    if (x < 0 || x > game->map.window_width + 60 || y < 0 || y >= game->map.window_height + 60)
        return TRUE;
    return FALSE;
}

void move_right(t_game *game)
{
    float moveStep;
    float newPlayerX;

    game->player.turnDirection = -1;
    moveStep = game->player.walkSpeed * game->player.turnDirection;
    newPlayerX = game->player.x + moveStep;
    game->player.x = newPlayerX;
     if (isTherWall(game->player.x, game->player.y, game))
        return ;
    render(game->data, &game->player, game->map);
    game->player.turnDirection = 0;
}

void move_left(t_game *game)
{
    float moveStep;
    float newPlayerX;

    game->player.turnDirection = +1;
    moveStep = game->player.walkSpeed * game->player.turnDirection;
    newPlayerX = game->player.x + moveStep;
    game->player.x = newPlayerX;
    if (isTherWall(game->player.x, game->player.y, game))
        return ;
    render(game->data, &game->player, game->map);
    game->player.turnDirection = 0;
}

void move_up(t_game *game)
{
    float moveStep;
    float newPlayerY;

    game->player.walkDirection = -1;
    moveStep = game->player.walkDirection * game->player.walkSpeed;
    newPlayerY = game->player.y + moveStep;
    if (isTherWall(game->player.x, newPlayerY, game))
        return ;
    game->player.y = newPlayerY;
    render(game->data, &game->player, game->map);
    game->player.walkDirection = 0;
}

void move_down(t_game *game)
{
    float moveStep;
    float newPlayerY;

    game->player.walkDirection = +1;
    moveStep = game->player.walkDirection * game->player.walkSpeed;
    newPlayerY = game->player.y + moveStep;
    if (isTherWall(game->player.x, newPlayerY, game))
        return ;
    game->player.y = newPlayerY;
    render(game->data, &game->player, game->map);
    game->player.walkDirection = 0;
}

void move_rotation_left(t_game *game)
{
    game->player.turnDirection = +1;
    game->player.rotationAngle += game->player.turnDirection * game->player.turnSpeed * 0.5;
    render(game->data, &game->player, game->map);
    game->player.turnDirection = 0;
}

void move_rotation_right(t_game *game)
{
    game->player.turnDirection = -1;
    game->player.rotationAngle += game->player.turnDirection * game->player.turnSpeed * 0.5;//FPS
    render(game->data, &game->player, game->map);
    game->player.turnDirection = 0;
}