NAME = cub
LIB = libft/libft.a
CC = gcc
CFLAGS = 
SRC = 	src/free_destroy.c \
		src/checkWall.c \
		src/read_file.c \
		src/move.c \
		src/render.c \
		src/draw.c \
		src/create.c \
		src/main.c \
		libft/ft_split.c \
		libft/ft_strchr.c \
		libft/ft_strdup.c\
		libft/ft_strjoin.c \
		libft/ft_strlen.c \
		libft/ft_strncmp.c \
		libft/ft_strtrim.c \
		libft/ft_strcmp.c \
		parsing/check_map.c \
		#parsing/ft_spl.c \




OBJECTS = $(SRC:.c=.o)

%.o: %.c $(SRC)
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

all:$(NAME)

$(LIB):
	@make -C libft

$(NAME): $(LIB) $(OBJECTS)
	@echo "\033[0;33m [Compilation ongoing ...]\033[0;37m"
	$(CC) -lmlx -framework OpenGL -framework AppKit $(CFLAGS) $(OBJECTS) -o $(NAME)
	@echo "\033[0;32m [Compilation finished ...]\033[0;37m"


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