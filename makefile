NAME = fractol
BONUS = bonus_fract
INCLUDE = fractol.h
INCLUDE_BONUS = bonus/fractol_bonus.h
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address

SRCS = ./main.c	\
	   ./math.c	\
	   ./rendring.c	\
	   ./event_handling.c	\
	   ./string.c	\
	   ./colors.c 
	
SRCS_BONUS = bonus/main.c	\
	   bonus/math.c	\
	   bonus/rendring.c	\
	   bonus/event_handling.c	\
	   bonus/string.c	\
	   bonus/colors.c 
OBJ = $(SRCS:.c=.o)
OBJ_bonus = $(SRCS_BONUS:.c=.o)

all : $(NAME)

%.o: %.c $(INCLUDE) $(INCLUDE_BONUS)
	$(CC) $(CFLAGS)  -Imlx -c $< -o $@

$(BONUS) : $(OBJ_bonus) $(INCLUDE_BONUS)

bonus : $(BONUS) $(INCLUDE_BONUS)
	$(CC) $(OBJ_bonus) -lmlx -framework OpenGL -framework AppKit -o $(BONUS)

$(NAME): $(OBJ) $(INCLUDE)
	$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean :
	rm -f $(OBJ) $(OBJ_bonus)

fclean : clean
	rm -f $(NAME) $(BONUS)

re : fclean all

.PHONY : clean