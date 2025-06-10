NAME = abstractAnimal
CFLAGS = -Wextra -Wall -Werror -std=c++98
CC = c++

SRCS = AAnimal.cpp \
		Cat.cpp \
		Dog.cpp \
		Brain.cpp \
		main.cpp

OBJS = $(SRCS:.cpp=.o)

GREEN = \033[1;32m

all : $(NAME)

%.o: %.cpp
	@$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "${GREEN}abstractAnimal compiled"

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re