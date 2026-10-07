NAME		= ft_ping

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

INC_DIR		= includes
SRC_DIR		= srcs
OBJ_DIR		= obj

SRCS		= main.c \
			  usage.c \
			  parsing.c \
			  resolve.c \
			  socket.c \
			  packet.c

OBJS		= $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
