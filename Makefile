NAME = ft_retro

SRC = main.cpp \
		Ncurse.cpp \

OBJ = $(SRC:.cpp=.o)

FLAGS = -Wall -Wextra -Werror -I.

$(NAME): $(OBJ)
	clang++ $(FLAGS) -o $(NAME) $(SRC) -lncurses

all: $(NAME)

%.o: %.c
	clang++ $(FLAGS) -o $@ -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
