NAME = ft_retro

SRC = main.cpp \
		Ncurse.cpp \
	Class.Aplayer.cpp \
	Class.Enemy.cpp \
	Class.Gamer.cpp \
	Class.Shoot.cpp \
	init.cpp

OBJ = $(SRC:.cpp=.o)

FLAGS = -Wall -Wextra -Werror -I.

$(NAME): $(OBJ)
	clang++ $(FLAGS) -o $(NAME) $(OBJ) -lncurses

all: $(NAME)

%.o: %.c
	clang++ $(FLAGS) -o $@ -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
