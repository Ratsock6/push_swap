NAME 		= push_swap

CC 			= cc
RM			= rm -f

CFLAGS 		+= -Wall -Wextra -Werror
CLINKS		= -ldl -lglfw -pthread -lm

FT			= libft
LIBFT		= $(FT)/libft.a

SRC 		= src/main.c \
				src/utils.c \
				src/utils2.c \
				src/list_utils.c \
				src/sort.c \
				src/reverse_rotate.c \
				src/rotate.c \
				src/push.c \
				src/swap.c \
				src/big_sort.c \
				src/radix_sort.c
OBJ 		= $(SRC:.c=.o)

all: $(NAME)

bonus: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LIBFT) $(CLINKS)

$(LIBFT): $(FT)
	$(MAKE) -C $(FT)

$(FT):
	git clone https://github.com/Ratsock6/libft.git $(FT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	if [ -d "$(FT)" ]; then $(MAKE) clean -C $(FT); fi
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFT)

clear: fclean
	$(RM) -r $(FT)

re: fclean all

.PHONY:		all bonus clear clean fclean re
