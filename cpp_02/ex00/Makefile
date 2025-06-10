NAME = fixedPoint
CFLAGS = -Wextra -Wall -Werror -std=c++98
CC = c++

SRCS = Fixed.cpp \
		main.cpp

OBJS = $(SRCS:.cpp=.o)

GREEN = \033[1;32m

all : $(NAME)

%.o: %.cpp
	@$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "${GREEN}fixedPoint compiled"

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re