NAME = cub3D
CC = gcc
LIB = libft/libft.a
CFLAGS = -Wall -Werror -Wextra
SRC =	src/free_destroy.c \
		parsing/get_next_line/get_next_line.c \
		parsing/get_next_line/get_next_line_utils.c \
		parsing/check_map.c \
		parsing/ft_spl.c \
		src/process_input.c \
		src/setup_map.c \
		src/castRays.c \
		src/texture.c \
		src/read_file.c \
		src/move.c \
		src/render.c \
		src/draw.c \
		src/create.c \
		src/hori_vert-Intercestion.c \
		src/main.c


OBJECTS = $(SRC:.c=.o)

all:$(NAME)

$(LIB):
	@make -C libft

$(NAME): $(LIB) $(OBJECTS)
	@echo "\033[0;33m [Compilation ongoing ...]\033[0;37m"
	$(CC) -lmlx -framework OpenGL -framework AppKit libft/libft.a $(CFLAGS) $(OBJECTS) -o $(NAME)
	@echo "\033[0;32m [Compilation finished ...]\033[0;37m"
%.o: %.c $(SRC)
	$(CC) $(CFLAGS) -Imlx -c $< -o $@
clean:
	@make clean -C libft
	rm -f $(OBJECTS)
	rm -f $(OBJECTS_B)
fclean: clean
	@make fclean -C libft
	rm -f $(NAME)
	rm -f $(B_NAME)
re: fclean all

.PHONY: all clean fclean re