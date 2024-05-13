# ATTENTION POUR LE DEBUGGER IL FAUT UN -G3 DANS LE CSS! ENLEVER POUR LA CORR
CC = gcc -g3
CFLAGS = -Wall -Wextra -Werror
SRCS_1 = src/push_swap/push_swap.c
SRCS_2 = src/push_swap/help.c \
         src/push_swap/sort.c \
         src/push_swap/utils.c \
         src/push_swap/commands.c \
		 src/push_swap/commands_2.c \

LIBFT_PATH = Libft
LIBFT_ARCHIVE = $(LIBFT_PATH)/libft.a
EXEC_NAME = push_swap


all: $(EXEC_NAME)

$(EXEC_NAME): $(SRCS_1) $(SRCS_2) $(LIBFT_ARCHIVE)
	$(CC) $(CFLAGS) -o $@ $(SRCS_1) $(SRCS_2) -L$(LIBFT_PATH) -lft

$(LIBFT_ARCHIVE):
	$(MAKE) -C $(LIBFT_PATH)

clean:
	$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	rm -f $(EXEC_NAME)

re: fclean all

.PHONY: all clean fclean re bonus
