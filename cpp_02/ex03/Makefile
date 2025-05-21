NAME = bsp
CFLAGS = -Wextra -Wall -Werror
CC = c++

SRCS = Fixed.cpp \
		Point.cpp \
		bsp.cpp \
		main.cpp

OBJS = $(SRCS:.cpp=.o)

GREEN = \033[1;32m

all : $(NAME)

%.o: %.cpp
	@$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "${GREEN}bsp compiled"

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re