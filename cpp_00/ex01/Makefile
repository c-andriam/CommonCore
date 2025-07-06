NAME = phonebook

SRC_DIR = ./src

SRCS = $(SRC_DIR)/Contact.cpp $(SRC_DIR)/PhoneBook.cpp \
	   $(SRC_DIR)/phonebook.cpp

OBJ_DIR = ./obj

OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(filter $(SRC_DIR)/%, $(SRCS))) \

OBJ_SUBDIRS = $(sort $(dir $(OBJS)))

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -f

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_SUBDIRS)

$(OBJ_SUBDIRS):
	@mkdir -p $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR) $(OBJ_SUBDIRS)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ_DIR) $(OBJ_SUBDIRS) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	@if [ -d $(OBJ_DIR) ]; then \
		$(RM) $(OBJS); \
		find $(OBJ_DIR) -type d -empty -delete; \
		$(RM) $(OBJ_DIR); \
	fi

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
