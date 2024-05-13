NAME = fractol
INCLUDE = fractol.h
CFLAGS = -Wall -Wextra -Werror

SRCS = ./main.c\
	   ./math.c	\
	   ./rendring.c	\
	   ./event_handling.c	\
	   ./string.c	\
	   ./colors.c 
	

OBJ = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

all : $(NAME)

$(NAME): $(OBJ) $(INCLUDE)
	$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
