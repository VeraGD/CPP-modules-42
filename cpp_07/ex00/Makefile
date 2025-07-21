_name = whatever
CFLAGS = -Wextra -Wall -Werror -std=c++98
CC = c++

SRCS = main.cpp

OBJS = $(SRCS:.cpp=.o)

GREEN = \033[1;32m

all : $(_name)

%.o: %.cpp
	@$(CC) $(CFLAGS) -o $@ -c $<

$(_name): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(_name)
	@echo "${GREEN}whatever compiled"

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(_name)

re: fclean all

.PHONY: all, clean, fclean, re