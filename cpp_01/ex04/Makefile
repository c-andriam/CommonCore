NAME = sed_is_for_losers

SRCS = main.cpp

OBJS = $(SRCS:.cpp=.o)

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

RM =rm -f

%.o:%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all fclean clean re
