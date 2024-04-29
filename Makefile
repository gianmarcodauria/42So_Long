
CC = gcc

CFLAGS = -Wall -Wextra -Werror
MFLAGS = -L./mlx -lmlx_Linux -lXext -lX11 -lm -lbsd

LIBFTDIR = ./libft
MLXDIR = ./mlx

SRCS = dotber_check.c fd2m_shapech_wallech.c flooddy.c init.c main_game.c pnec_check.c position.c free_me.c start_game.c

OBJS = $(SRCS:%.c=%.o)

NAME = so_long

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(MLXDIR) -I$(LIBFTDIR) -c $< -o $@

$(NAME): $(OBJS)
	make -C $(MLXDIR)
	make -C $(LIBFTDIR)
	$(CC) $(OBJS) -L$(LIBFTDIR) -lft $(MFLAGS) -o $(NAME)

clean:
	rm -rf $(OBJS)
	make fclean -C $(LIBFTDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

# //MIO MAKE

# NAME = so_long

# SRCS = dotber_check.c fd2m_shapech_wallech.c flooddy.c init.c main_game.c pnec_check.c position.c free_me.c

# OBJS = $(SRCS:.c=.o)

# CC = gcc

# RM = rm -rf

# CFLAGS = -Wall -Werror -Wextra
# MFLAGS = -L./mlx -lmlx_Linux -lXext -lX11 -lm -lbsd

# .c.o:
# 		${CC} ${CFLAGS} -g -c $< -o ${<:.c=.o}

# $(NAME): $(OBJS)
# 		make -C libft/
# 		make -C mlx/
# 		$(CC) $(CFLAGS) -lft $(MFLAGS) $(SRCS) -o $(NAME) libft/libft.a

# all:	$(NAME)

# clean:
# 		$(RM) $(OBJS)
# 		make fclean -C libft
# 		make fclean -C ./mlx

# fclean: clean
# 		$(RM) $(NAME)
# 		make fclean -C libft

# re: 	fclean all

# .PHONY: all clean fclean re
