#include "../main.h"

void move_right(t_game *game)
{
    float moveStep;
    float newPlayerX;

    game->player.turnDirection = +1;
    moveStep = game->player.walkSpeed * game->player.turnDirection;
    newPlayerX = game->player.x + moveStep;
    if (isTherWallRight(game))
        return ;
    game->player.x = newPlayerX;
    render(game->data, &game->player, game->map);
    game->player.turnDirection = 0;
}

void move_left(t_game *game)
{
    float moveStep;
    float newPlayerX;

    game->player.turnDirection = -1;
    moveStep = game->player.walkSpeed * game->player.turnDirection;
    newPlayerX = game->player.x + moveStep;
    if (isTherWallLeft(game))
        return ;
    game->player.x = newPlayerX;
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
    if (isTherWallUp(game))
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
    if (isTherWallDown(game))
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