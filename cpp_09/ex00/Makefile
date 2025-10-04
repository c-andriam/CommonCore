NAME = btc

SRCS = main.cpp BitcoinExchange.cpp

OBJS = ${SRCS:.cpp=.o}

CXX = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -rf

all: $(NAME)

%.o:%.cpp
	$(CXX) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CXX) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
