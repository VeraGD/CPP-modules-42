name = form
CFLAGS = -Wextra -Wall -Werror -std=c++98
CC = c++

SRCS = Bureaucrat.cpp \
		Form.cpp \
		main.cpp

OBJS = $(SRCS:.cpp=.o)

GREEN = \033[1;32m

all : $(name)

%.o: %.cpp
	@$(CC) $(CFLAGS) -o $@ -c $<

$(name): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(name)
	@echo "${GREEN}form compiled"

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(name)

re: fclean all

.PHONY: all, clean, fclean, re
