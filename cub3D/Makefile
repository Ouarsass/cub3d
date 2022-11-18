CC = gcc
CFLAGS =
NAME = cub
SRC = src/free_destroy.c \
	src/move.c \
	src/render.c \
	src/draw.c \
	src/create.c \
	src/main.c


OBJECTS = $(SRC:.c=.o)

all:$(NAME)

$(NAME):$(OBJECTS)
	@echo "\033[0;33m [Compilation ongoing ...]\033[0;37m"
	$(CC) -lmlx -framework OpenGL -framework AppKit $(CFLAGS) $(OBJECTS) -o $(NAME)
	@echo "\033[0;32m [Compilation finished ...]\033[0;37m"
%.o: %.c $(SRC)
	$(CC) $(CFLAGS) -Imlx -c $< -o $@
clean:
	rm -f $(OBJECTS)
	rm -f $(OBJECTS_B)
fclean: clean
	rm -f $(NAME)
	rm -f $(B_NAME)
re: fclean all

.PHONY: all clean fclean re