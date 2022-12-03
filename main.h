#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <mlx.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/time.h>
#include <math.h>
#include <stdlib.h>
# include "libft/libft.h"

#define TRUE 1
#define FALSE 0
#define PI 3.14159265359
#define TWO_PI 6.28318530718
#define FOV_ANGLE (60 * (PI / 180))
#define MINIMAP_SCALE_FACTOR 0.3

typedef	struct s_pars
{
	int		C;
	int		F;
	char	**map;
	int		len;
    char	*NO;
    char	*SO;
    char	*WE;
    char	*EA;
}			t_pars;

typedef struct s_data
{
    void *mlx;
    void *img;
    char *addr;
    int bpp;
    int zl;
    int ed;
    void *window;
    int tickslastframe;
} t_data;

typedef struct s_map
{
    int title_size;
    int num_rows;
    int num_cols;
    int window_width;
    int window_height;
    int wall;
    int player;
    int **my_map;
} t_map;

typedef struct s_player
{
    float	x;
    float	y;
    float	width;
    float	height;
    int		turnDirection;
    int		walkDirection;
    float	rotationAngle;
    float	walkSpeed;
    float	end_line;
    float	turnSpeed;
} t_player;

typedef struct s_game
{
    t_player player;
    t_map map;
    t_data data;
} t_game;

//free function
void    exit_game(t_data data);
int     ft_cross(t_data data);
void    free_mlx(t_data	data);
void    display_error(char *msg);
void    destroyWindow(void *mlx, void *window);

//draw
void     CreateWindow(t_data *mlx, t_map map);
void    draw_mini_map(t_data data, int cpm1, int cmp2, int tileColor);
void    draw_player(t_data data, t_map map, t_player *player);
void    draw_line(t_data data, t_player *player);

void    setup_map(t_map *map, char *table);
void    setup(t_player *player, t_map map);
void    processInput(t_data data);
void    render(t_data data, t_player *player, t_map map);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void    renderMap(t_data data, t_map map, t_player *player);
void    renderPlayer(t_data data, t_map map, t_player *player);
void    update (t_player *player, t_data data, t_game *game);
int     direction(int keyboard, t_game *game);
int     isTherWallRight(t_game *game);
int     isTherWallLeft(t_game *game);
int     isTherWallDown(t_game *game);
int     isTherWallUp(t_game *game);

//move player
void    moveplayer(t_player *player, t_data data);
void    move_right(t_game *game);
void    move_left(t_game *game);
void    move_up(t_game *game);
void    move_down(t_game *game);
void    move_rotation_left(t_game *game);
void    move_rotation_right(t_game *game);
void    playerPosition(t_player *player, t_map map);

//map
char	*read_file(int fd);
char	*red_line(int fd);
int     row_length(char **table);
void takeSize(char **table , t_map *map);

//libftfunction
// char	*ft_strdup(const char	*s1);
// int     ft_strlen(char	*str);
// char	*ft_strjoin(char	*s1, char	*s2);
// size_t	ft_strlcpy(char	*dst, const char	*src, size_t	size);
// static char	*this(const char *s, char c);
// static int	count_words(const char	*s, char c);
// char	**free_t(unsigned int i, char **tab);
// char	**ft_split(const char *s, char c);

//parsing
int	check_extention(char *av);
int	ft_parsing(t_pars *pars, char **av);
char	**ft_spl(char *str, char *spl);


#endif